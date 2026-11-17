# Socket Programming Basics

**Study Material:** 윤성우의 열혈 TCP/IP 소켓 프로그래밍  
**Source Code:** `Soket_Programming_Code/`
### 2026-11-17

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