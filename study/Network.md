# Network Study(자료: 혼자 공부하는 네트워크)

## 2026-10-21

### Today

- Network Basics
- LAN, WAN, Internet
- Node, Host, Link
- Circuit Switching, Packet Switching
- Packet Switch
- Header, Payload, Trailer
- Protocol
- OSI Reference Model
- TCP/IP Model
- PDU
- Encapsulation, Decapsulation
- Traffic, Utilization, Bandwidth, Throughput

### What I learned

- Network:
  - Devices and networks connected together to communicate and exchange data

- LAN:
  - Local Area Network
  - Network in a relatively small area

- WAN:
  - Wide Area Network
  - Connects networks over a large area

- Internet:
  - Many different networks connected together globally

- Node:
  - A device connected to a network

- Host:
  - An end device that sends or receives data

- Intermediate Node:
  - Network devices between hosts
  - Router, Switch

- Link:
  - Communication path or medium between network devices


- Circuit Switching:
  - Makes and reserves a communication path before communication starts
  - The reserved network resources are used during communication
  - Delay and transmission performance can be relatively stable
  - Traditional telephone networks are a representative example


- Packet Switching:
  - Divides data into small units called Packets
  - Packets are sent through shared network links
  - Packets can use the same route or different routes depending on the network situation
  - Modern Internet communication uses Packet Switching


- Packet Switch:
  - A network device that forwards data toward the destination
  - Router and Switch are representative network devices


- Packet / Frame Structure:

  - Header:
    - Contains control information
    - Can contain source and destination information

  - Payload:
    - Actual data that we want to send

  - Trailer:
    - Additional information added at the end of some PDUs
    - Ethernet Frame uses FCS for error detection

  - Not every network layer adds a Trailer


- Protocol:
  - Rules used when network devices communicate
  - Similar to using the same language and rules when people communicate

- Protocol Examples:
  - HTTP
  - TCP
  - UDP
  - IP
  - Ethernet
  - ARP


- OSI Reference Model:
  - A conceptual model that divides network communication into 7 layers
  - Each layer has its own role
  - Data moves through these layers when it is sent and received


- Layer 1 - Physical Layer:
  - Sends raw Bits through physical media
  - Converts data into electrical, optical, or wireless signals
  - Deals with cables, connectors, signals and transmission
  - PDU: Bits


- Layer 2 - Data Link Layer:
  - Handles communication between devices on the same local network
  - Uses MAC Address to identify devices on the local network
  - Creates Frames
  - Detects transmission errors using methods such as FCS
  - Switch mainly works at this layer
  - PDU: Frame


- Layer 3 - Network Layer:
  - Handles communication between different networks
  - Uses IP Address for logical addressing
  - Determines the path toward the destination
  - Handles Routing and Packet Forwarding
  - Router mainly works at this layer
  - PDU: Packet


- Layer 4 - Transport Layer:
  - Handles End-to-End communication between applications
  - Uses Port Numbers to identify applications
  - Can divide application data into smaller units and reassemble it at the destination

  - TCP:
    - Provides reliable and ordered delivery
    - PDU: Segment

  - UDP:
    - Provides simpler communication without TCP's reliability mechanisms
    - PDU: Datagram


- Layer 5 - Session Layer:
  - Creates, manages and terminates communication sessions between applications
  - Manages the communication state between applications
  - Can manage synchronization during communication


- Layer 6 - Presentation Layer:
  - Handles the format and representation of data
  - Makes sure both sides can understand the data
  - Handles Encoding and data format conversion
  - Can handle Encryption, Decryption and Compression


- Layer 7 - Application Layer:
  - Closest layer to the user's application
  - Provides Network Services used by applications
  - Application protocols work at this layer
  - Examples: HTTP, HTTPS, DNS, SMTP, FTP


- TCP/IP Model:
  - A practical model used for Internet communication

- Network Access / Link Layer:
  - Roughly corresponds to OSI Physical + Data Link Layers

- Internet Layer:
  - Corresponds to OSI Network Layer

- Transport Layer:
  - Corresponds to OSI Transport Layer

- Application Layer:
  - Combines OSI Session + Presentation + Application Layers


- PDU:
  - Protocol Data Unit
  - Name of the data unit handled at each layer

- Application / Presentation / Session:
  - Data

- Transport:
  - TCP: Segment
  - UDP: Datagram

- Network:
  - Packet / IP Datagram

- Data Link:
  - Frame

- Physical:
  - Bits


- Encapsulation:
  - Sender sends data from the upper layer to the lower layer
  - Each layer treats the data received from the upper layer as Payload
  - Each layer adds its own control information such as a Header
  - Data Link Layer can also add a Trailer

- Encapsulation Flow:
  - Data
  - Segment / Datagram
  - Packet
  - Frame
  - Bits


- Decapsulation:
  - Opposite process of Encapsulation
  - Receiver processes data from the lower layer to the upper layer
  - Each layer checks and removes its own control information


- Traffic:
  - Amount or load of data flowing through a network

- Utilization:
  - Percentage of available network capacity currently being used

- Bandwidth:
  - Maximum theoretical transmission capacity of a network link

- Throughput:
  - Actual amount of data successfully transferred per unit of time


### Practice

- Learned basic Network structure
- Compared Circuit Switching and Packet Switching
- Learned Header, Payload and Trailer
- Studied the roles of OSI 7 Layers
- Compared OSI Model and TCP/IP Model
- Learned PDU of each layer
- Traced Encapsulation and Decapsulation
- Compared Traffic, Utilization, Bandwidth and Throughput