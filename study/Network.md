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
-------------
## 2026-10-27

### Today

- Ethernet
- Ethernet Cable Types
- Twisted Pair Cable, Coaxial Cable, Optical Fiber
- SMF, MMF
- Ethernet Frame
- NIC
- Hub, CSMA/CD
- Switch
- MAC Address Table
- Learning, Flooding, Forwarding, Filtering, Aging
- VLAN
- Access Port, Trunk Port
- Port-based VLAN, MAC-based VLAN

### What I learned

- Ethernet:
  - A network technology used mainly in wired LANs
  - Works at the Physical and Data Link Layers

- Ethernet Name:
  - 10: 10 Mbps
  - 10G: 10 Gbps
  - BASE: Baseband transmission
  - T: Twisted Pair Cable
  - Example: 10BASE-T, 10GBASE-SR

- Twisted Pair Cable:
  - Copper cable with twisted wires
  - Commonly uses an RJ-45 connector
  - Twisting wires helps reduce noise

- Shielding Types:
  - UTP: Unshielded Twisted Pair
  - STP: Braided Twisted Pair
  - FTP: Foil Twisted Pair
  - S/FTP: Outer braided shield and foil around each pair

- CAT (Category):
  - Shows the performance standard of a twisted pair cable
  - Examples: Cat5e, Cat6, Cat6a

- Optical Fiber:
  - Uses light signals to send data
  - Used for high-speed and long-distance communication

- SMF (Single Mode Fiber):
  - Has a small core
  - Supports a single light mode
  - Mainly used for long-distance communication

- MMF (Multi Mode Fiber):
  - Has a larger core
  - Supports multiple light modes
  - Mainly used for shorter distances

- Ethernet Frame:
  - A data unit used at the Data Link Layer
  - Contains MAC addresses, Data and FCS

- Ethernet Frame Structure:
  - Preamble: 7 Bytes
  - SFD: 1 Byte
  - Destination MAC: 6 Bytes
  - Source MAC: 6 Bytes
  - Type/Length: 2 Bytes
  - Data: 46-1500 Bytes (including Padding)
  - FCS: 4 Bytes

- Preamble:
  - Repeats the bit pattern 10101010
  - Helps the receiver synchronize with the signal

- SFD (Start Frame Delimiter):
  - Marks the start of the Ethernet Frame

- MAC Address:
  - Identifies a network interface
  - Used to send Frames on a local network

- Type/Length:
  - Type: Shows the protocol inside the Data field
  - Length: Shows the data length

- Data / Payload:
  - Contains data from the upper layer
  - Usually contains an IP Packet
  - Maximum size is normally 1500 Bytes
  - Padding is added when the data is too small

- FCS (Frame Check Sequence):
  - Uses CRC to detect errors
  - The receiver checks the FCS
  - A damaged Frame is normally discarded

- NIC (Network Interface Card):
  - Connects a computer to a network
  - Has a MAC Address
  - Sends and receives network signals and Frames

- Hub:
  - Works at the Physical Layer
  - Sends received signals to other ports
  - Does not use MAC Addresses
  - Uses Half-Duplex communication
  - Collisions can happen

- CSMA/CD:
  - Used in shared Half-Duplex Ethernet
  - Checks whether the medium is being used
  - Detects collisions
  - Stops transmission and tries again after a random wait

- Switch:
  - Mainly works at the Data Link Layer
  - Uses MAC Addresses to forward Frames
  - Supports Full-Duplex communication
  - Uses a MAC Address Table

- MAC Address Table:
  - Stores MAC Addresses and their connected ports
  - Helps the Switch find the correct output port

- Learning:
  - The Switch learns the Source MAC Address and incoming port

- Flooding:
  - Sends a Frame to other ports in the same VLAN when the Destination MAC is unknown

- Forwarding:
  - Sends a Frame to the correct port using the MAC Address Table

- Filtering:
  - Does not send a Frame to ports that do not need it

- Aging:
  - Removes old dynamic MAC Address entries from the table
  - Helps the Switch update its information

- VLAN (Virtual Local Area Network):
  - Divides one physical LAN into separate logical LANs
  - Each VLAN has its own Broadcast Domain
  - Communication between different VLANs normally needs Routing

- Port-based VLAN:
  - Assigns a VLAN to each Switch port

- Access Port:
  - Usually belongs to one VLAN
  - Commonly used to connect PCs

- Trunk Port:
  - Carries Frames from multiple VLANs through one link
  - Commonly used between Switches
  - Uses VLAN Tags to identify VLANs

- 802.1Q VLAN Tag:
  - Adds 4 Bytes to an Ethernet Frame
  - Placed between Source MAC and Type/Length
  - Identifies the VLAN of a Frame

- MAC-based VLAN:
  - Assigns VLANs based on MAC Addresses
  - A device can keep its VLAN when it moves to another port if the Switch is configured to support it

### Practice

- Studied Ethernet and different cable types
- Compared Twisted Pair and Optical Fiber
- Compared SMF and MMF
- Drew the Ethernet Frame structure and checked each field size
- Learned how FCS detects errors
- Compared NIC, Hub and Switch
- Studied how CSMA/CD handles collisions
- Traced how a Switch learns MAC Addresses
- Understood Learning, Flooding, Forwarding, Filtering and Aging
- Studied how VLANs divide a Broadcast Domain
- Compared Port-based VLAN and MAC-based VLAN