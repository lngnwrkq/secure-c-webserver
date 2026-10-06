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




