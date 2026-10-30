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
-------------
## 2026-10-28

### Today

- Network Layer
- MAC Address vs IP Address
- IPv4 and IPv6
- IPv4 Header
- IP Fragmentation
- MTU (Maximum Transmission Unit)
- IPv6 Header
- ARP (Address Resolution Protocol)
- Communication Between Different LANs

### What I learned

- Network Layer:
  - The third layer of the OSI model
  - Uses IP addresses to send packets between networks
  - Finds a path to the destination network

- MAC Address vs IP Address:
  - MAC Address: Used to deliver frames on a local link
  - IP Address: Used to identify the source and destination across networks
  - A MAC Address is usually assigned to a network interface
  - An IP Address can be set manually or assigned by DHCP

- IP (Internet Protocol):
  - A protocol used at the Network Layer
  - Uses IP addresses to deliver packets
  - Two main versions: IPv4 and IPv6

- IPv4:
  - Uses 32-bit IP addresses
  - Usually written in dotted decimal format
  - Example: 192.168.0.10
  - Has about 4.3 billion possible addresses
  - Supports routing and fragmentation

- MTU (Maximum Transmission Unit):
  - The maximum size of a packet that a network link can carry
  - A common Ethernet MTU is 1500 Bytes

- IPv4 Header:
  - Minimum size: 20 Bytes
  - Maximum size: 60 Bytes
  - Contains information needed to deliver an IP packet

- IPv4 Header Fields:
  - Version (4 bits): Shows the IP version
  - IHL (4 bits): Shows the header length
  - Service Type (8 bits): Shows packet priority and congestion information
  - Total Length (16 bits): Shows the total packet size
  - Identification (16 bits): Helps identify packet fragments
  - Flags (3 bits): Controls fragmentation
  - Fragment Offset (13 bits): Shows the position of a fragment
  - TTL (8 bits): Limits how many routers a packet can pass
  - Protocol (8 bits): Identifies the next protocol, such as TCP or UDP
  - Header Checksum (16 bits): Detects errors in the IP header
  - Source IP (32 bits): Source IP address
  - Destination IP (32 bits): Destination IP address
  - Options: Additional information
  - Padding: Makes the header length a multiple of 4 Bytes

- IP Fragmentation:
  - Divides a large IPv4 packet into smaller fragments when needed
  - Each fragment has its own IP header
  - The destination host puts the fragments back together

- Fragmentation Flags:
  - DF (Don't Fragment): Prevents fragmentation when set to 1
  - MF (More Fragments): Shows whether more fragments follow
  - Fragment Offset: Shows where a fragment belongs in the original packet

- TTL (Time To Live):
  - Decreases by 1 at each router
  - A packet is discarded when the TTL reaches 0
  - Prevents packets from moving around the network forever

- IPv6:
  - Uses 128-bit IP addresses
  - Written in hexadecimal format
  - Usually has eight groups of 16 bits
  - Provides a much larger address space than IPv4
  - Has a fixed 40-Byte base header

- IPv6 Header Fields:
  - Version (4 bits): Shows the IP version
  - Traffic Class (8 bits): Shows packet priority and congestion information
  - Flow Label (20 bits): Identifies packets in the same flow
  - Payload Length (16 bits): Shows the payload size
  - Next Header (8 bits): Identifies the next header or protocol
  - Hop Limit (8 bits): Limits how many routers a packet can pass
  - Source IP (128 bits): Source IPv6 address
  - Destination IP (128 bits): Destination IPv6 address

- IPv4 vs IPv6:
  - IPv4 uses 32-bit addresses
  - IPv6 uses 128-bit addresses
  - IPv4 has a variable header size
  - IPv6 has a fixed 40-Byte base header
  - IPv6 does not have a Header Checksum
  - IPv6 uses Extension Headers for extra information
  - IPv6 routers do not fragment packets

- ARP (Address Resolution Protocol):
  - Finds a MAC Address using an IPv4 Address
  - Used on a local network
  - Helps a host send an Ethernet Frame to the correct device

- ARP Process:
  - A host sends an ARP Request as a broadcast
  - The device with the target IP sends an ARP Reply
  - The host saves the IP-to-MAC mapping in its ARP cache

- Communication Between Different LANs:
  - Example: Host A -> Router A -> Router B -> Host B
  - Host A knows the destination IP Address of Host B
  - Host A finds Router A's MAC Address using ARP
  - Host A sends an Ethernet Frame to Router A
  - Router A checks the Destination IP Address
  - Router A finds Router B's MAC Address using ARP if needed
  - Router A forwards the packet to Router B
  - Router B checks the Destination IP Address
  - Router B finds Host B's MAC Address using ARP if needed
  - Router B sends the Frame to Host B
  - Each router uses ARP on its local Ethernet link when needed
  - The Source and Destination MAC Addresses change at each routed Ethernet link
  - The Destination IP Address stays the same during normal routing
  - ARP is not needed again if the MAC Address is already in the ARP cache

- IPv6 Neighbor Discovery:
  - IPv6 does not use ARP
  - It uses NDP to find the MAC Address of a neighbor

### Practice

- Compared MAC Addresses and IP Addresses
- Studied the role of the Network Layer
- Compared IPv4 and IPv6 addresses
- Drew the IPv4 Header and checked the size of each field
- Learned how MTU and IP Fragmentation work
- Studied DF, MF and Fragment Offset
- Learned why TTL is needed
- Drew the IPv6 Header and checked its fields
- Compared the IPv4 and IPv6 Headers
- Studied how ARP Request and ARP Reply work
- Traced packet delivery between hosts on the same LAN
- Traced packet delivery from Host A to Host B through two routers
- Studied how ARP finds the next device's MAC Address
- Compared how MAC Addresses and IP Addresses are used during routing
-------------
## 2026-10-30

### Today

- Static and Dynamic IP Addresses
- DHCP
- Classless Addressing
- Subnet Mask and CIDR
- Subnetting
- Public and Private IP Addresses
- NAT
- Routing
- Routing Table and Default Route
- Static and Dynamic Routing
- AS (Autonomous System)
- RIP, OSPF and BGP
- BGP Path Attributes

### What I learned

- Static IP Address:
  - An IP address set manually
  - Usually stays the same until it is changed
  - Often used for servers and network devices

- Dynamic IP Address:
  - An IP address assigned automatically
  - Usually assigned by a DHCP server
  - Can change when it is assigned again

- DHCP (Dynamic Host Configuration Protocol):
  - Automatically gives network settings to a host
  - Can provide an IP address, Subnet Mask, Default Gateway and DNS server
  - Uses four main steps: Discover, Offer, Request and ACK

- DHCP Discover:
  - The client looks for a DHCP server
  - Usually sends a broadcast message
  - The source IP is 0.0.0.0 during initial setup

- DHCP Offer:
  - The DHCP server offers an available IP address
  - Also provides other network settings

- DHCP Request:
  - The client requests the offered IP address
  - Usually uses a broadcast during initial setup

- DHCP ACK:
  - The server confirms the IP address assignment
  - The client can use the assigned settings

- Classless Addressing:
  - Divides networks without using fixed class sizes
  - Uses CIDR to show the network prefix length
  - Allows more flexible use of IP addresses

- Subnet Mask:
  - Separates the Network part and Host part of an IP address
  - Network bits are 1
  - Host bits are 0
  - Uses a bitwise AND operation to find the Network Address

- CIDR (Classless Inter-Domain Routing):
  - Uses /n to show the number of network bits
  - Example: 192.168.0.2/25
  - /25 means 25 network bits and 7 host bits
  - Subnet Mask: 255.255.255.128
  - Network Address: 192.168.0.0
  - Broadcast Address: 192.168.0.127
  - Usable Host Range: 192.168.0.1 - 192.168.0.126
  - Usable Hosts: 2^7 - 2 = 126

- Public IP Address:
  - Used for communication on the public Internet
  - Publicly routed addresses must be globally unique

- Private IP Address:
  - Used inside private networks
  - Not directly routed on the public Internet
  - Common private IPv4 ranges:
    - 10.0.0.0/8
    - 172.16.0.0/12
    - 192.168.0.0/16

- NAT (Network Address Translation):
  - Translates IP addresses between networks
  - Commonly used to connect private networks to the Internet
  - NAPT can also translate port numbers

- Routing:
  - Selects a path to the destination network
  - Routers use Routing Tables to forward packets
  - Two main types: Static Routing and Dynamic Routing

- Routing Table:
  - Stores routes to different networks
  - Contains Destination, Subnet Mask, Gateway, Interface and Metric
  - Uses the longest matching prefix first
  - When routes have the same prefix, Metric can help choose a route

- Default Route:
  - Written as 0.0.0.0/0 in IPv4
  - Used when no more specific route matches
  - Usually sends packets to the Default Gateway

- Static Routing:
  - Routes are set manually by an administrator
  - Simple and easy to control
  - Needs manual changes when the network changes

- Dynamic Routing:
  - Routers exchange routing information automatically
  - Can update routes when the network changes
  - Uses protocols such as RIP, OSPF and BGP

- AS (Autonomous System):
  - A group of networks managed under one routing policy
  - Used to organize routing on the Internet

- IGP (Interior Gateway Protocol):
  - Used for routing inside an AS
  - Examples: RIP and OSPF

- EGP (Exterior Gateway Protocol):
  - Used for routing between ASes
  - BGP is the main protocol used for this purpose

- RIP (Routing Information Protocol):
  - A Distance Vector routing protocol
  - Uses Hop Count to choose routes
  - Usually prefers the route with fewer hops
  - Supports up to 15 hops for a reachable route

- OSPF (Open Shortest Path First):
  - A Link State routing protocol
  - Uses link costs to find the best path
  - Shares network information inside an area
  - Uses areas to manage large networks
  - An ABR connects different OSPF areas

- BGP (Border Gateway Protocol):
  - Used to exchange routing information between ASes
  - Uses routing policies and path information
  - Does not always choose the shortest AS_PATH
  - Routers can form BGP peer connections

- iBGP:
  - BGP communication inside the same AS

- eBGP:
  - BGP communication between different ASes

- BGP Path Attributes:
  - Help BGP choose and manage routes

- AS_PATH:
  - Shows the AS numbers in the path
  - Helps detect routing loops
  - Used when selecting a BGP route

- NEXT_HOP:
  - Shows the next-hop IP address used to reach a route
  - Helps routers find where to forward packets

- LOCAL_PREF:
  - Shows the preferred route inside an AS
  - A higher value is usually preferred
  - Helps choose an outgoing path from the AS
  - Can be more important than AS_PATH length

### Practice

- Compared Static and Dynamic IP Addresses
- Studied the four steps of DHCP
- Learned why DHCP uses broadcast messages
- Studied Subnet Masks and CIDR notation
- Converted an IP address and Subnet Mask into binary by hand
- Used a bitwise AND operation to calculate a Network Address
- Practiced subnetting with 192.168.0.2/25
  - Calculated the Network Address: 192.168.0.0
  - Calculated the Broadcast Address: 192.168.0.127
  - Found the usable Host Range: 192.168.0.1 - 192.168.0.126
  - Calculated the number of usable hosts: 126
- Compared Public and Private IP Addresses
- Studied how NAT works
- Read a Routing Table example
- Learned how the Default Route works
- Compared Static and Dynamic Routing
- Studied AS and routing protocols
- Compared RIP, OSPF and BGP
- Learned how OSPF uses areas and link costs
- Studied iBGP and eBGP
- Learned AS_PATH, NEXT_HOP and LOCAL_PREF