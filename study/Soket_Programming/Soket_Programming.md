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

Today, I learned the basic structure of socket programming and understood how servers and clients establish connections and communicate.

I also practiced Linux file I/O to understand how file descriptors and system calls work.
--------------------
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