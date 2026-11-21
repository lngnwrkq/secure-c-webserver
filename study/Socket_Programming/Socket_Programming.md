# Socket Programming Basics

**Study Material:** 윤성우의 열혈 TCP/IP 소켓 프로그래밍  

### 2026-11-17
**Code I Wrote and Practiced:** `Soket_Programming_Code/11-17`

## Today
- Learned the overall concept and process of socket programming.
- Understood how servers and clients communicate using sockets.
- Studied the basic functions used in server and client sockets.
- Learned about Linux file descriptors and system calls.
- Practiced basic file I/O programming in C.

## What I Learned

### 1. Overview of Socket Programming

Socket programming allows programs to communicate over a network.

- A server waits for connection requests from clients.
- A client requests a connection to the server.
- After the connection is established, both sides can send and receive data.
- A socket provides an interface for network communication.

### 2. Server Socket Process

- `socket()`: Creates a socket.
- `bind()`: Assigns an IP address and port number to a socket.
- `listen()`: Makes a socket ready to accept connection requests.
- `accept()`: Accepts a client connection and returns a new socket descriptor.

**Server Flow:**

`socket() → bind() → listen() → accept() → Data Transfer → close()`

### 3. Client Socket Process

- `socket()`: Creates a socket.
- `connect()`: Requests a connection to a server using its IP address and port number.

**Client Flow:**

`socket() → connect() → Data Transfer → close()`

### 4. Linux File Descriptors

Linux uses file descriptors to manage open files and sockets.

A file descriptor is a non-negative integer that identifies an open file or socket.

- `0`: Standard Input (stdin)
- `1`: Standard Output (stdout)
- `2`: Standard Error (stderr)

### 5. Linux File I/O

- `open()`: Opens or creates a file.
- `read()`: Reads data from a file descriptor.
- `write()`: Writes data to a file descriptor.
- `close()`: Closes a file descriptor.

Linux files and sockets can use many of the same system calls because both are managed through file descriptors.

## Practice

- Built a simple file I/O program in C using Linux system calls such as `open()`, `write()`, and `close()` to create a text file and write "Hello, World!" into it.

## Summary

- Today, I learned the basic structure of socket programming and understood how servers and clients establish connections and communicate.
- I also practiced Linux file I/O to understand how file descriptors and system calls work.

---

### 2026-11-18
**Code I Wrote and Practiced:** `Soket_Programming_Code/11-18`

## Today
- Studied socket creation and the differences between TCP and UDP.
- Learned how to assign IP addresses and port numbers to sockets.
- Studied `sockaddr_in` and the purpose of padding.
- Understood TCP segments, MSS, and how `read()` works.
- Learned network byte order and IPv4 address conversion.
- Practiced socket creation, address binding, and byte order conversion in C.

## What I Learned

### 1. Socket Creation

`socket(domain, type, protocol)` creates a socket.

- `domain`: Selects the protocol family (`PF_INET`, `PF_INET6`).
- `type`: Selects the socket type (`SOCK_STREAM`, `SOCK_DGRAM`).
- `protocol`: Selects the communication protocol (TCP or UDP).

**TCP (`SOCK_STREAM`)**
- Reliable and ordered data transfer.
- Does not preserve message boundaries.
- Provides a byte stream.

**UDP (`SOCK_DGRAM`)**
- Does not guarantee delivery or order.
- Preserves datagram boundaries.
- Has less communication overhead.

### 2. TCP Segments, MSS, and read()

TCP is a byte-stream protocol.

- MSS (Maximum Segment Size) defines the maximum TCP payload size in one segment.
- TCP divides data into segments while considering MSS and other network conditions.
- The receiver processes TCP segments and provides an ordered byte stream to the application.
- The application does not see TCP segment boundaries through `read()`.

**Relationship Between write() and read()**

- One `write()` call does not always create one TCP segment.
- Multiple `write()` calls may be combined into fewer segments.
- One `write()` call may be divided into multiple TCP segments.
- One `read()` call may receive data from multiple TCP segments.
- The buffer size passed to `read()` limits how many bytes can be read in one call.
- `read()` may return fewer bytes than the requested buffer size.

**Example:**

Even if the sender calls `write()` 17 times, the receiver may read all the data with a single `read()` call if the data is available and the receiving buffer is large enough.

If the buffer is too small, multiple `read()` calls are required.

Therefore:

`One write() != One read()`

**Important Difference**

- MSS determines the maximum TCP payload size per segment.
- The `read()` buffer size determines the maximum number of bytes the application can read in one call.
- MSS does not determine how many bytes `read()` returns.

Because TCP does not preserve application message boundaries, applications need their own rules to identify complete messages.

For example, HTTP uses `Content-Length` to specify the message body length.

### 3. Socket Address Assignment

`struct sockaddr_in` stores IPv4 socket address information.

- `sin_family`: Address family (2 bytes).
- `sin_port`: Port number (2 bytes).
- `sin_addr`: IPv4 address (4 bytes).
- `sin_zero[8]`: Padding bytes (8 bytes).

**Why Does sockaddr_in Have Padding?**

- `sockaddr` is a general-purpose socket address structure.
- Different address families use different address structures.
- On Linux, IPv4 `sockaddr_in` is typically 16 bytes.
- The address family, port, and IPv4 address occupy 8 bytes.
- `sin_zero[8]` adds another 8 bytes to make the structure 16 bytes.
- This supports layout compatibility with the generic `sockaddr` structure.
- The padding does not store useful IPv4 address information.

The `bind()` function accepts a pointer to `struct sockaddr`.

Therefore, an IPv4 address structure is passed using a pointer cast.

```c
bind(sock, (struct sockaddr *)&addr, sizeof(addr));
```

**Socket Address Binding Process**

1. Create a socket using `socket()`.
2. Initialize a `sockaddr_in` structure.
3. Set the address family, IP address, and port number.
4. Assign the address to the socket using `bind()`.

**Process:**

`socket() → Address Initialization → bind()`

### 4. Network Byte Order

Different systems may store multi-byte integers in different byte orders.

- Big Endian: Stores the most significant byte first.
- Little Endian: Stores the least significant byte first.
- Network byte order uses Big Endian.

**Conversion Functions**

- `htons()`: Host to network (16-bit).
- `htonl()`: Host to network (32-bit).
- `ntohs()`: Network to host (16-bit).
- `ntohl()`: Network to host (32-bit).

Port numbers use 16 bits, while IPv4 addresses use 32 bits.

### 5. Internet Address Initialization

- `inet_addr()`: Converts an IPv4 string into a binary address in network byte order.
- `inet_aton()`: Converts an IPv4 string and stores the result in an address structure.
- `atoi()`: Converts a numeric string into an integer.
- `INADDR_ANY`: Allows a server to bind to all local IPv4 interfaces.

`inet_addr()` and `inet_aton()` already produce network-byte-order IPv4 addresses, so an additional `htonl()` is not needed.

## Practice

- Wrote and practiced C programs using `inet_addr()`, `inet_aton()`, network byte order conversion functions, and socket APIs to create sockets and assign IP addresses and port numbers.

## Summary

Today, I learned how sockets are created and how IP addresses and port numbers are assigned.

I also understood the purpose of `sockaddr_in` padding and the relationship between TCP segments, MSS, and `read()`.

Finally, I practiced IPv4 address conversion, network byte order conversion, and socket address binding in C.

---

### 2026-11-19 ~ 2026-11-20
**Code I Wrote and Practiced:** `Soket_Programming_Code/11-19,Soket_Programming_Code/11-20`

## Today

- Studied the layers of the TCP/IP protocol stack.
- Learned how TCP servers and clients establish connections.
- Understood the difference between listening sockets and connected sockets.
- Studied the structure and limitations of an iterative server.
- Practiced handling TCP byte-stream data with `read()` and `write()`.

## What I Learned

### 1. TCP/IP Protocol Stack

The TCP/IP stack divides network communication into layers with different responsibilities.

Application Layer
       ↑
Transport Layer (TCP / UDP)
       ↑
Internet Layer (IP)
       ↑
Link Layer


### 2. Basic Structure of a TCP Server

A TCP server waits for connection requests and exchanges data with connected clients.

socket() → bind() → listen() → accept() → read()/write() → close()

1. **`socket()` — Create a socket**  
   Creates a TCP socket and returns a file descriptor.
2. **`bind()` — Assign an address**  
   Associates an IP address and port number with the server socket.
3. **`listen()` — Prepare for connections**  
   Makes the socket a listening socket and sets a `backlog` value for the pending connection queue.
4. **`accept()` — Accept a connection**  
   Accepts a pending connection and returns a **new connected socket** for that client.
5. **`read()` / `write()` — Exchange data**  
   Reads and writes data through the connected socket.
6. **`close()` — Close a socket**  
   Closes a socket when it is no longer needed.

#### Listening Socket vs. Connected Socket

- **Listening socket:** Waits for new client connections after `listen()`.
- **Connected socket:** Returned by `accept()` and used to communicate with one specific client.
- Closing a connected socket does not close the listening socket. The server can call `accept()` again.

#### `listen()` and Backlog

listen(sv_sock, 5);

- `5` does **not** mean the server processes five clients at the same time.
- On Linux, `backlog` mainly limits the queue of completed connections waiting for `accept()`. Kernel settings also affect its behavior.

### 3. Basic Structure of a TCP Client

socket() → connect() → read()/write() → close()

1. **`socket()`**: Create a socket for communication.
2. **`connect()`**: Request a connection using the server's IP address and port.
3. **`read()` / `write()`**: Exchange data with the server.
4. **`close()`**: Close the socket after communication.

The server uses `bind()`, `listen()`, and `accept()` to receive connection requests. The client uses `connect()` to request a connection.

### 4. Iterative Server

An **iterative server handles one client at a time**, then moves to the next client.

```text
socket()
   ↓
bind()
   ↓
listen()
   ↓
accept() ←─────────┐
   ↓                │
read() / write()    │
   ↓                │
close(cl_sock) ─────┘

When the server stops: close(sv_sock)
```

- A loop allows the server to accept clients sequentially.
- The current client must be handled before the application processes the next one.
- Other connections may wait in the pending queue, but this server does not handle several clients at the same time.

### 5. TCP Byte Streams and Partial Reads

TCP provides a **byte stream**. One `write()` call does **not** always match one `read()` call.

For example, a client may write 100 bytes, but the server may read them in smaller pieces.

```text
Client: write(..., 100)
Server: read() → 40 bytes
        read() → 30 bytes
        read() → 30 bytes
        Total     100 bytes


- The third argument in `read(fd, buf, 100)` is the **maximum number of bytes requested**, not a promise to return 100 bytes.
- The return value of `read()` is the number of bytes actually read by that call.
- When the expected length is known, the program can **track the total received bytes** and continue reading from the next buffer position.
- `read()` returns `0` at EOF and `-1` on error.
- Applications need a **fixed length, length header, or delimiter** to know where a complete message ends.
```



## Practice

## 2026-11-19 | Built a TCP Echo Server from Scratch

- Wrote a TCP echo server and client by myself.
- Used `socket()`, `bind()`, `listen()`, `accept()`, and `connect()` to establish connections.
- Used `read()` and `write()` to receive a message and send it back to the client.
- Practiced an iterative server structure that handles clients one by one.

**Code I Wrote and Practiced:** `Client.c`, `Server.c`

## 2026-11-20 | Improved the Echo Client and Started a Calculator Server

- Studied the limitations of calling `read()` only once in the original echo client.
- Improved the client by calling `read()` repeatedly and **tracking the total number of received bytes**.
- Used the saved byte count as a **buffer offset**, so newly received bytes are stored after previously received data.
- Designed and wrote a TCP calculator server and client from scratch.
- Used `strcat()` to build the input message, then `strtok()` and `atoi()` to split and convert operands on the server.
- Used `switch()` to build the calculation logic.
- Practiced debugging C programs using GDB.
- Used `break`, `run`, `next`, `print`, and `continue` commands.
- Set breakpoints and executed code step by step.
- Tracked changes in the `temp` and `op` arrays to verify how `fgets()` and `strcat()` work.
- Analyzed the program's execution flow and string handling through debugging.
- **Completed the first calculation exchange**, but the second request and error handling are still incomplete.


**Code I Wrote and Practiced:** `Client_V2.c`, `Calculator_cl.c`, `Calculator_sv.c` *(Calculator project incomplete)*

## Next Plan

## 2026-11-21 | Planned

- Complete the TCP calculator server and client.
- Fix the issue where operand prompts appear without waiting for input during the second calculation.
- Check `scanf()` / `fgets()` input handling and the server's connection closing behavior.
- Write concept notes about why one `read()` call may not receive a complete TCP message.
- Review TCP byte streams, partial reads, cumulative byte counts, and buffer offsets.
- Test calculation results and organize the source code.
- Organize and clean up the calculator server code.

---

### 2026-11-21

**Code I Wrote and Practiced:** `Soket_Programming_Code/11-20, 11-21`

## Today

- Reviewed the communication structure of TCP echo servers and clients.
- Studied TCP byte streams and partial data reception using `read()`.
- Compared the echo client from the textbook with my improved `Client_V2.c`.
- Analyzed the communication protocol of the calculator server in the textbook.
- Compared the textbook's calculator implementation with my own implementation.
- Reviewed data sizes, buffer offsets, and pointer arithmetic.

## What I Learned

# 1. TCP Echo Server

## 1.1. Textbook Implementation

### Basic Structure

A TCP echo server receives data from a client and sends the same data back to the client.

Communication process:

1. The server calls `socket()`, `bind()`, and `listen()`.
2. The server accepts a client connection using `accept()`.
3. The client sends a message using `write()`.
4. The server receives the message using `read()`.
5. The server sends the received data back using `write()`.
6. The client receives the returned data using `read()`.

### Limitations of the Original Echo Client

TCP is a byte-stream protocol. Therefore, one `write()` call does not always match one `read()` call.

For example, even if a client sends 100 bytes, the server may receive the data in several parts.

```text
write() : 100 bytes

read()  : 40 bytes
read()  : 30 bytes
read()  : 30 bytes

Total   : 100 bytes
```

If the client calls `read()` only once, it may not receive the complete message.

### Improved Echo Client in the Textbook

The textbook solves this problem by repeatedly calling `read()` until the expected number of bytes has been received.

```c
str_len = write(sock, message, strlen(message));

recv_len = 0;

while (recv_len < str_len)
{
    recv_cnt = read(
        sock,
        &message[recv_len],
        BUF_SIZE - 1
    );

    if (recv_cnt == -1)
        error_handling("read() error!");

    recv_len += recv_cnt;
}

message[recv_len] = '\0';
```

**Main Variables**

- `str_len`: Number of bytes actually sent by the `write()` call.
- `recv_len`: Total number of bytes received so far.
- `recv_cnt`: Number of bytes received by the current `read()` call.

**Core Principle**

The program uses `recv_len` to remember how many bytes have already been received.

The next `read()` call starts writing data at `&message[recv_len]`.

This prevents newly received data from overwriting previous data.

The receiving loop ends when `recv_len` reaches `str_len`.

---

## 1.2. My Implementation

**Code:** `Client_V2.c`

I improved the echo client by managing the total number of received bytes and using buffer offsets.

The main idea is:

1. Track the total number of bytes received.
2. Move the next writing position after the previously received data.
3. Request only the remaining number of bytes.
4. Repeat until the expected amount of data has been received.

The following example shows the main idea of my implementation.

```c
int check_p = 0;

while (check_p < expected_size)
{
    int len = read(
        sock,
        message + check_p,
        expected_size - check_p
    );

    if (len <= 0)
        break;

    check_p += len;
}
```

*This example explains the buffer-offset logic I implemented. Some variable names and details may differ from my original source code.*

### 1. Buffer Offset: `message + check_p`

This moves the buffer pointer by the number of bytes already received.

As a result, new data is stored immediately after the previous data.

### 2. Remaining Size: `expected_size - check_p`

This calculates how many more bytes need to be received.

For example, if the expected size is 100 bytes and 40 bytes have already been received, the next `read()` call requests at most 60 bytes.

---

## 1.3. Comparison: Textbook vs. My Implementation

| Feature | Textbook | My Implementation |
| --- | --- | --- |
| Received byte counter | `recv_len` | `check_p` |
| Buffer offset | `message + recv_len` | `message + check_p` |
| Read request size | `BUF_SIZE - 1` | Remaining expected bytes |
| Loop condition | `recv_len < str_len` | `check_p < expected_size` |
| Partial read handling | Repeated `read()` | Repeated `read()` |
| Buffer management | Fixed maximum size per call | Adjusted remaining size |
| EOF handling | No explicit handling for `read() == 0` | Checks `read() <= 0` |

### Difference 1. The Third Argument of `read()`

The textbook uses:

```c
read(sock, &message[recv_len], BUF_SIZE - 1);
```

The important point is that the buffer position changes, but the maximum read request size remains the same.

For example:

```text
BUF_SIZE = 1024

Already received = 100 bytes

Next buffer position = message[100]

Textbook's next read request = 1023 bytes
```

However, the available space starting from `message[100]` is smaller than 1023 bytes.

If more data than expected arrives, the program may write beyond the buffer boundary.

The textbook's code can work correctly when the echo server returns exactly the expected data.

However, it is not a fully safe approach when unexpected data is received.

### Difference 2. Calculating the Remaining Bytes

My approach uses:

```c
read(sock, message + check_p, expected_size - check_p);
```

Example:

```text
Expected size: 100 bytes

First read():
Received = 40 bytes
check_p = 40

Second read() request:
100 - 40 = 60 bytes

Second read():
Received = 30 bytes
check_p = 70

Third read() request:
100 - 70 = 30 bytes
```

This approach manages both the buffer position and the remaining number of bytes.

It prevents the program from requesting more data than the expected remaining message length.

The program must still ensure that `expected_size` does not exceed the actual buffer capacity.

### Difference 3. Handling `read() == 0`

The textbook checks whether `read()` returns `-1`.

```c
if (recv_cnt == -1)
    error_handling("read() error!");
```

However, it does not explicitly handle a return value of `0`.

For a TCP socket, `read()` returning `0` means the peer has finished sending data and the receiving side has reached EOF.

If the loop is still waiting for additional bytes, it may continue indefinitely because the received byte counter does not increase.

The return values should be handled as follows:

- `read() > 0`: Data was successfully received.
- `read() == 0`: The peer has closed its sending side.
- `read() == -1`: An error occurred.

### Conclusion: Echo Server

By analyzing the textbook and my implementation, I learned two important concepts.

1. TCP applications need to manage the total number of received bytes because partial reads can occur.
2. Safe buffer management requires checking both the next writing position and the remaining buffer space.

I also understood the difference between two expressions:

- `BUF_SIZE - 1`: Reserves space for the null terminator.
- `expected_size - check_p`: Calculates the remaining number of bytes to receive.

These expressions serve different purposes.

---

# 2. TCP Calculator Server

## 2.1. Textbook Implementation

The calculator server in the textbook sends calculation requests using **binary data instead of text strings**.

### Communication Protocol

The textbook organizes the request message in the following order:

```text
[Operand Count] [Operand 1] ... [Operand N] [Operator]
      1B           4B × N                       1B
```

The total message size is:

```text
1 + 4 × N + 1

= 4N + 2 bytes
```

- Operand count: 1 byte
- Each operand: 4 bytes
- Operator: 1 byte

For example, if there are three operands:

```text
[3] [10] [20] [30] [+]
 1    4    4    4    1   bytes

Total = 14 bytes
```

### Why Is the Operand Count Stored in One Byte?

The textbook converts the operand count into a `char` value.

```c
opmsg[0] = (char)opnd_cnt;
```

Although an `int` usually occupies 4 bytes, a small integer value does not always require 4 bytes of storage.

A `char` can also store integer values.

Therefore, the textbook stores the operand count in one byte, assuming the count is within the supported range.

### Storing Operands in a Character Array

The textbook uses a character array to store binary data.

```c
#define OPSZ 4

char opmsg[BUF_SIZE];
```

Each operand is stored in a 4-byte area.

The textbook uses a technique similar to:

```c
scanf("%d", (int*)&opmsg[1 + i * OPSZ]);
```

The memory structure is:

```text
opmsg[0]     : Operand count (1 byte)

opmsg[1~4]   : First operand (4 bytes)

opmsg[5~8]   : Second operand (4 bytes)

opmsg[9~12]  : Third operand (4 bytes)

opmsg[13]    : Operator (1 byte)
```

The pointer is cast to `int*` so that the program can store an integer in the selected memory area.

This technique depends on assumptions about memory alignment and integer representation. A more portable implementation would use `memcpy()` to place integer bytes into the character buffer.

### Calculating the Transmission Size

The textbook uses:

```c
opnd_cnt * OPSZ + 2
```

Since `OPSZ = 4`:

```text
opnd_cnt × 4 + 2

= 1 byte for the operand count
+ 4 bytes for each operand
+ 1 byte for the operator
```

For three operands:

```text
3 × 4 + 2 = 14 bytes
```

This was an important part of understanding the textbook code.

The additional `2` represents the operand count and the operator, which each occupy one byte.

Unlike a fixed-size message, this approach sends only the required amount of data.

### Receiving Data on the Server

The server first receives the operand count.

```c
read(cl_sock, &opnd_cnt, 1);
```

After receiving the count, the server can calculate how much data remains.

```text
Remaining data size = opnd_cnt × 4 + 1
```

The operand count has already been received.

Therefore, the server only needs to receive the operands and the operator.

The server then processes the data and performs the calculation.

### Sending the Calculation Result

The server sends the result as a binary integer.

```c
write(cl_sock, &result, sizeof(result));
```

On a system where `int` occupies 4 bytes, the result is transmitted as 4 bytes.

---

## 2.2. My Implementation

**Code:** `Calculator_cl.c`, `Calculator_sv.c`

Unlike the textbook, I designed my calculator server to send operands and operators as a single text string.

### Communication Protocol

The client combines operands and an operator into one string separated by spaces.

For example:

```text
Operand count: 3

Operand 1: 10
Operand 2: 20
Operand 3: 30

Operator: +

Message: "10 20 30 +"
```

The client sends a fixed-size 100-byte message.

```c
write(sock, op, 100);
```

The server receives the complete 100-byte request using a loop.

```c
while (check_p < 100)
{
    str_len = read(
        cl_sock,
        message + check_p,
        100 - check_p
    );

    if (str_len <= 0)
        break;

    check_p += str_len;
}
```

### Building the Message on the Client

The client receives operands using `fgets()` and appends them to the message buffer using `strcat()`.

```c
strcat(op, temp);
strcat(op, " ");
```

Finally, the operator is added.

```c
strcat(op, operator);
```

This creates a complete calculation request as a text string.

### Parsing the Message on the Server

The textbook stores operands directly as binary integers.

My implementation instead separates the received text into individual tokens.

I used `strtok()` to split the message using spaces.

```c
char *ptr = strtok(message, " ");
```

Each operand is then converted from a string into an integer.

```c
op[i] = atoi(ptr);
ptr = strtok(NULL, " ");
```

The program counts the operands until it finds an operator.

### Performing Calculations

I used a `switch` statement to select the arithmetic operation.

**Addition**

The result starts at 0, and each operand is added.

**Multiplication**

The result starts at 1 because multiplying by 0 would always produce 0.

**Subtraction**

The result starts with the first operand, and the remaining operands are subtracted one by one.

### Sending and Receiving the Result

The server sends the result as a binary integer, similar to the textbook.

```c
write(cl_sock, &sum, sizeof(sum));
```

On the client side, I implemented a loop to handle partial reads.

```c
while (check_p < 4)
{
    len = read(
        sock,
        (char*)INT_op + check_p,
        4 - check_p
    );

    if (len <= 0)
        break;

    check_p += len;
}
```

### Why Did I Use `(char*)`?

The `INT_op` array contains integers.

When pointer arithmetic is performed on an `int*`, the pointer moves by the size of an integer.

However, TCP data is received as bytes.

Casting the pointer to `char*` allows the program to move the memory address one byte at a time.

For example:

```text
check_p = 2

INT_op + 2
→ Moves 8 bytes
  (if sizeof(int) is 4)

(char*)INT_op + 2
→ Moves exactly 2 bytes
```

This allows each new `read()` call to store data immediately after the bytes received earlier.

### Repeated Calculations

I designed my calculator server to process multiple calculations using a single TCP connection.

```text
socket()
   ↓
bind()
   ↓
listen()
   ↓
accept()
   ↓
while (1)
   ├── read()
   ├── Parse message
   ├── Calculate
   └── write()
   ↓
close()
```

The client can send additional calculation requests without creating a new connection each time.

I also added a termination feature that allows the client to send `q` to request shutdown.

---

## 2.3. Comparison: Textbook vs. My Implementation

| Feature | Textbook | My Implementation |
| --- | --- | --- |
| Data format | Binary data | Text string |
| Operand count | Stored in the first byte | Counted while parsing tokens |
| Operand storage | 4 bytes per integer | Numbers converted into strings |
| Operator storage | Final byte | Final string token |
| Request size | `4N + 2` bytes | Fixed 100 bytes |
| Data separation | Byte positions and sizes | Spaces and `strtok()` |
| Integer conversion | Not needed for binary operands | Uses `atoi()` |
| Result transmission | Binary integer | Binary integer |
| Result reception | Integer result | Repeated reads with byte offsets |
| Main advantage | Efficient data transmission | Easy-to-read and debug messages |

### Difference 1. Binary Data vs. Text Strings

**Textbook**

The textbook stores and sends integer values directly as binary data.

This avoids the need to convert numbers into strings and parse them again.

**My Implementation**

My calculator sends a readable string such as:

```text
10 20 30 +
```

The server uses `strtok()` and `atoi()` to process the request.

This requires additional string operations but makes the message easier to inspect during debugging.

### Difference 2. Variable-Length vs. Fixed-Length Messages

**Textbook**

```c
opnd_cnt * OPSZ + 2
```

The request size depends on the number of operands.

The program sends only the number of bytes required for the request.

**My Implementation**

```c
write(sock, op, 100);
```

The client always attempts to send 100 bytes.

This simplifies the protocol but may waste bandwidth when the actual message is short.

The program also needs to validate the input length to prevent buffer-related problems.

### Difference 3. How the Server Determines the Operand Count

**Textbook**

The operand count is stored in the first byte.

Therefore, the server knows how many operands to receive after reading the count.

**My Implementation**

The server separates the message into tokens using `strtok()`.

It counts the operand tokens until it finds an arithmetic operator.

### Difference 4. Debugging and Readability

**Textbook**

The binary protocol is more compact and avoids unnecessary string conversion.

However, binary data is harder to inspect directly as readable text.

**My Implementation**

The text-based protocol makes it easier to inspect received messages using GDB or Wireshark.

For example:

```text
message = "10 20 30 +"
```

However, additional validation is needed for string lengths, token formats, and integer conversion errors.

---

## 2.4. Further Improvements

Both programs were developed as learning exercises.

Several improvements are still needed for more reliable communication.

- Handle `read() == 0` correctly when the peer closes its sending side.
- Check whether `write()` actually sends all requested bytes.
- Validate operands and arithmetic operators.
- Prevent buffer overflow during string concatenation.
- Consider integer size and network byte order when transmitting binary data.
- Distinguish between client disconnection and server termination.
- Verify that the expected number of bytes has been received before processing a message.

---

## Summary

TCP provides a byte stream, so one `write()` call does not always correspond to one `read()` call.

To receive complete data reliably, a program must track the total number of received bytes and calculate how many bytes remain.

While reviewing the textbook's echo client, I noticed that the buffer offset changes during repeated reads, but the maximum read request size remains unchanged.

This helped me understand why both the receiving position and the remaining buffer capacity should be considered.

I also studied two different approaches to implementing a TCP calculator server.

The textbook uses a binary protocol with the following message size:

```text
1 + 4N + 1 = 4N + 2 bytes
```

My implementation uses a fixed-size 100-byte text message and parses operands using `strtok()` and `atoi()`.

By comparing these implementations, I learned that **TCP applications must define their own message formats, lengths, and boundaries**.

The most important lesson was understanding not only how to send and receive data, but also why the communication protocol must be carefully designed.