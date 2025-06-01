# Principles of Operating Systems – Detailed Notes

## Module I: Introduction (15%)

### 1. What is an Operating System (OS)?

- Software that acts as an intermediary between users and computer hardware.
- Manages hardware resources and provides services for computer programs.

### 2. Functions of an Operating System

- Process management
- Memory management
- File system management
- Device management
- Security and protection
- User interface

### 3. Classification of Operating Systems

- **Batch OS**: Executes batches of jobs with minimal user interaction.
- **Interactive OS**: Allows user interaction with running programs.
- **Time Sharing OS**: Multiple users access the system simultaneously by sharing time slices.
- **Real-Time OS**: Provides immediate processing for time-critical tasks (e.g., embedded systems).
- **Multiprocessor OS**: Supports systems with multiple CPUs.
- **Multiuser OS**: Allows multiple users to use the system at the same time.
- **Multithreaded OS**: Supports multiple threads of execution within a process.

### 4. Operating System Structure

- **Monolithic Kernel**: All OS services run in kernel space (e.g., Linux).
- **Microkernel**: Minimal kernel, with most services running in user space (e.g., Minix).

### 5. System Components

- Process management
- Main memory management
- File system
- I/O system
- Secondary storage management
- Networking
- Protection system
- Command interpreter system

### 6. Operating System Services

- Program execution
- I/O operations
- File system manipulation
- Communication
- Error detection
- Resource allocation
- Accounting
- Security

---

## Module II: Process Management (20%)

### 1. Process Concept

- A process is a program in execution.
- Consists of program code, current activity, and process state.

### 2. Process States

- New, Ready, Running, Waiting, Terminated

### 3. Process Synchronization

- Ensures orderly execution of processes sharing resources.
- **Critical Section Problem**: Section of code where shared resources are accessed.
- **Mutual Exclusion**: Only one process can enter the critical section at a time.

### 4. Classical Synchronization Problems

- Producer-Consumer Problem
- Reader-Writer Problem
- Dining Philosophers Problem

### 5. Process Scheduling

- Decides which process runs at a given time.
- **Process Transitions**: Movement between states (Ready, Running, Waiting, etc.)
- **Scheduling Algorithms**: Determines order of execution.

### 6. Interprocess Communication (IPC)

- Mechanisms for processes to communicate and synchronize.
- Methods: Shared memory, message passing

### 7. Threads and Their Management

- Thread: Lightweight process, shares resources with other threads in the same process.
- Thread creation, scheduling, and synchronization.

### 8. Security Issues

- Protecting processes from unauthorized access and interference.

---

## Module III: CPU Scheduling (15%)

### 1. Scheduling Concepts

- Deciding which process gets the CPU and for how long.

### 2. Techniques of Scheduling

- **Preemptive Scheduling**: OS can suspend a running process.
- **Non-Preemptive Scheduling**: Process runs until it finishes or blocks.

### 3. Scheduling Algorithms

- **First-Come-First-Serve (FCFS)**
- **Shortest Job First (SJF)/Shortest Request Next**
- **Highest Response Ratio Next (HRRN)**
- **Round Robin (RR)**
- **Priority Scheduling**
- **Least Complete Next**
- **Shortest Time to Go**
- **Long, Medium, Short Scheduling**

### 4. Deadlock

- **System Model**: Resources, processes, and their relationships.
- **Deadlock Characterization**: Mutual exclusion, hold and wait, no preemption, circular wait.
- **Prevention, Avoidance, Detection**: Strategies to handle deadlocks.
- **Recovery from Deadlock**: Killing processes, resource preemption.

---

## Module IV: Memory Management (15%)

### 1. Memory Partition

- Dividing memory into fixed or variable-sized partitions.

### 2. Memory Management Techniques

- **Paging**: Divides memory into fixed-size pages.
- **Segmentation**: Divides memory into variable-sized segments.
- **Virtual Memory**: Uses disk as an extension of RAM.
- **Demand Paging**: Loads pages into memory only when needed.

### 3. Page Replacement Algorithms

- **FIFO (First-In-First-Out)**
- **LRU (Least Recently Used)**
- **Optimal Algorithm**

---

## Module V: File and Device Management (15%)

### 1. Types of Files

- Text, binary, executable, etc.

### 2. File Access Methods

- Sequential, direct, indexed

### 3. File Allocation Methods

- **Contiguous Allocation**
- **Linked Allocation**
- **Indexed Allocation**

### 4. I/O Devices

- Types: Input, output, storage devices
- **Device Controllers**: Interface between devices and OS
- **Device Drivers**: Software to control devices

### 5. Directory Structure

- **Single Level**
- **Tree Structured**
- **Acyclic Graph**
- **General Graph**

### 6. File Protection

- Mechanisms to control access to files

---

## Module VI: Shell Introduction and Shell Scripting (20%)

### 1. What is a Shell?

- Command-line interpreter between user and OS.
- Types: Bourne shell (sh), C shell (csh), Korn shell (ksh), Bash, etc.

### 2. Editors in Linux

- vi, nano, emacs, etc.
- vi editor modes: command, insert, last-line

### 3. Shell Scripting Basics

- Writing and executing shell scripts
- Shell variables: user-defined and system variables

### 4. System Calls

- Interface for programs to request services from OS

### 5. Pipes and Filters

- Pipes: Connect output of one command to input of another
- Filters: Commands that process data (e.g., grep, cut, tr)

### 6. Decision Making and Loops in Shell Scripts

- if-else, switch, for, while, until

### 7. Functions in Shell Scripts

- Defining and calling functions

### 8. Utility Programs

- cut, paste, join, tr, uniq, grep

### 9. Case Studies

- Study of available operating systems (Linux, Unix, etc.)

---

# End of Notes

---

These notes are organized module-wise for easy study and revision. Expand on any section as needed for deeper understanding or add your own examples and diagrams for better retention.
