# 📄 get_next_line – Read a File Line by Line in C

`get_next_line` is a 42 School project focused on implementing a function that reads a file or input line by line, handling dynamic memory allocation and buffer management without using standard C functions.

The goal is to master **file descriptors**, **buffered input**, and **efficient memory handling** in pure C.

The bonus part must behave like the mandatory part but adding up functionality to handle multiple file descriptors opened at once. The bonus function must also deal with only one static variable.

---

## 🛠️ Skills & Concepts

- File descriptors and low-level I/O
- Static variables and memory persistence
- Dynamic memory allocation (`malloc`, `free`)
- String manipulation
- Buffer management
- Linked lists (Bonus)
- Multi-descriptor handling (Bonus)

---

## 🧠 What I Learned

- Handling partial reads and buffer overflows
- Managing multiple open file descriptors in parallel
- Writing modular and reusable utility functions
- Preventing memory leaks and segmentation faults

---

## ⚙️ How to Use

1. Clone the repository :

```bash
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
make
```
2. Include the header in your code :

```bash
#include "get_next_line.h"
```

3. Link the library when compiling :

```bash
gcc your_program.c get_next_line.c get_next_line_utils.c -I. -D BUFFER_SIZE=42
```
📌 You can define BUFFER_SIZE when compiling to change how much is read at once.

