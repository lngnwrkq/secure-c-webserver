# Lightweight Secure C Web Server Engine

A lightweight HTTP/1.1 web server implemented from scratch in C on Linux.

The purpose of this project is not only to build a working web server,
but also to understand how server architecture affects performance,
resource usage, and security.

The project will be developed step by step from a basic TCP server
to multiple concurrent server architectures.

---

## Project Goals

The main goals of this project are:

- Build an HTTP/1.1 web server from scratch in C
- Understand Linux system and network programming
- Implement multiple server concurrency architectures
- Compare their performance under the same workload
- Analyze memory and input-handling vulnerabilities
- Reproduce security problems and verify fixes
- Containerize the server with Docker
- Deploy the final server on AWS EC2

The project focuses on understanding how the server works internally,
rather than simply making it work.

---

## Server Architectures

The same HTTP server functionality will be implemented using four different architectures.

### 1. Single Thread

A single thread processes client requests sequentially.

This is the simplest architecture,
but one slow request may delay other clients.

---

### 2. Thread-per-Connection

A new thread is created for each client connection.

This allows multiple clients to be handled concurrently,
but a large number of connections may increase:

- Thread creation overhead
- Memory usage
- Context switching
- CPU usage

---

### 3. Thread Pool

A fixed number of worker threads are created in advance.

Incoming client tasks are stored in a task queue
and processed by available worker threads.

Main concepts:

- Worker Threads
- Task Queue
- Mutex
- Condition Variable
- Thread Synchronization

This architecture will be compared with Thread-per-Connection
to analyze resource usage and performance.

---

### 4. epoll Event-Driven Server

The final server architecture will use Linux epoll
and non-blocking I/O.

Instead of creating one thread for every connection,
a small number of threads can monitor and handle many file descriptors.

Main concepts:

- File Descriptor
- Non-blocking I/O
- epoll
- Event Loop
- Event-Driven Architecture

The goal is to compare this architecture
with thread-based server models under high concurrency.

---

## Performance Benchmark

All server architectures will provide approximately the same functionality
and will be tested under similar conditions.

Load-testing tools will generate many HTTP requests
and concurrent connections automatically.

Planned tools:

- wrk
- ApacheBench (ab)

### Metrics

The following metrics will be measured:

- Requests Per Second (RPS)
- Average Latency
- P95 Latency
- P99 Latency
- CPU Usage
- Memory Usage
- Concurrent Connection Handling

The comparison will follow this structure:

```text
Single Thread
      vs
Thread-per-Connection
      vs
Thread Pool
      vs
epoll