# Linux Study

## 2026-10-01

### Today

- Linux terminal setup
- GitHub repository setup
- Git basic workflow

### What I learned

- git status:             Check changes 
- git add . :             Stage chages
- git commit -m "메모" :  Commit changes
- git push  :             Upload changes

---------------------

## 2026-10-02

### Today

- pwd, ls, mkdir, touch, rm, cd, 
- man, --help, mv, 
- apt, sudo

### What I learned

- pwd: Current Position
- ls: File list
- mkdir: Make directory
- mv: Renaming or Change file location
- touch: Make file
- rm: Remove file or directory
- cd: Change Current Position

- man, help: Instruction
- sudo: root privileges
- apt : Package Manager  

- (parameter): Can offer many options

- nano: Edit Tool
- cat: Read a file
- grep: Find a word in file



### Practice

- Make dir and rename, move position
- Download packages by using sudo and apt
- Read ls help Instruction
- store a famous story in my file by using nano
- Find a word on my file 

---------------------
## 2026-10-06

### Today
- CLI, stdin, stdout, stderr
- Redirection, Pipeline
- argc, argv
- Shell, Kernel
- bash, zsh
- head

### What I learned

- CLI: Uses fewer CPU and Memory resources than GUI and can work efficiently by combining commands

- stdin: Standard input (0)
- stdout: Standard output (1)
- stderr: Standard Error (2)

- ">" : Redirect stdout to a file
- ">>" : Append output to the end of a file
- "2>" : Redirect stderr to a file
- "<" : Use a file as stdin

- "|" : Connect stdout of one program to stdin of another program

- argc: Number of arguments
- argv: 
+ Arguments passed when the program starts
+ Pass values that the program needs when starting
- stdin:
+ Input data while the program is running

- ./qkrwngnl hello
  + "hello" is passed through argv(argc: 2 argv[0]:, ./qkrwngnl, argv[1]: hello)

- ./qkrwngnl < input.txt
  +  The contents of input.txt are passed through stdin

- Shell: Interprets user commands and runs programs
- Kernel: Manages CPU, Memory, Disk, Network, and Hardware

- bash, zsh: Types of shell

- head: Prints the first 10 lines of a file

### Practice

- Stored more than 100 lines of text in Linux using nano
- Used head to print the first 10 lines of the saved file
- Redirected the stdout of head directly into another file
- Redirected stdout and stderr to files
- Understood the relationship between Shell, Kernel, and Hardware
---------------------
## 2026-10-14 ~ 2026-10-15

### Today
- shell script
- struct of directory(/home, /etc)
- process, ps aux, htop, htop
- locate, find
- background, foreground, fg(%), jobs
- Daemon
- Cron

### What I learned
- Run multiple commands using a shell script
- /home: User home directory, /etc: System settings, /root: Root
/bin: Basic commands
- ps aux: Show all running processes
- htop: Show processes and system usage in real time
- locate: Find files using the plocate database
- find: Search files directly in directories(-type f,d)
- whereis: Find command, source and manual 
- foreground: Run a process in the terminal
- background: Run a process without blocking the terminal
- jobs(Show background), fg(Move a job to foreground), bg(Resume a stopped job in background)
- Daemon: Run a process in background to provide a service(ex: cron)
- Cron: Run commands periodically
(min, hour, day, month, weekday, commands)

### Practice
- Learned how CPU, RAM, and SSD/HDD work when running a program 
- Installed Apache2 web server
- Used ps aux | grep apache2 to check running Apache2 process
(apache2: respond http request)
- Made a cron job to save the current date and time to date.log every minute
- Used tail to check the saved logs
---------------------
## 2026-10-16

### Today
- Add user(id, who, root)
- Permission(rwx, chmod)
- How the Internet works(Client, Server, DNS, Domain, IP address)
- Public address, Private address
- apache2, elinks
- Configuration(/etc)

### What I learned
- id: Show user ID and group ID
- who: Show current id
- Root: Super User
- Permission(r: read, w: write, x: execute | ex rw-r--r--: User can read and write, group, other can read)
- Internet: A global network of connected networks
- Network: Connected devices 
- Server: Receive reuests and send responses
- IP address: Address used for network communication
- Domain: Web name
- DNS: Find the IP address of a domain name
- /etc: Store system configuration files
- localhost: Hostname that refers to my own computer
- apache2: Web Server
- elinks: Web browser

### Practice
- Made files and directories and changed permissions using chmod
- Used the root account
- Studied how the Internet and networks work
- Sent HTTP requests and received responses using elinks and Apache2 on my computer
- Checked my computer's public and private IP addresses
- Checked the apache2 configuration file in /etc to find the DocumnetRoot
- Renamed a web file(Index.html) and checked how the server responded
- Found the Apache2 log file and monitored logs in real time using tail -f




