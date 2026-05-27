# minitalk

> A tiny client/server messaging system in C that transmits strings **bit-by-bit using UNIX signals**.

![Language](https://img.shields.io/badge/language-C-blue)
![IPC](https://img.shields.io/badge/topic-IPC%20%7C%20signals-informational)
![Project](https://img.shields.io/badge/42%20School-minitalk-black)

## Overview

`minitalk` is a classic 42 School project that builds a minimal inter-process communication (IPC) layer using only POSIX signals (`SIGUSR1`, `SIGUSR2`).

It consists of:

- a **server** that prints its PID and receives messages
- a **client** that encodes a string into bits and sends them to the server

This project demonstrates understanding of:

- signal handling (`signal` / `sigaction`)
- bitwise operations and encoding/decoding
- process identifiers (PIDs)
- reliability concerns (ordering, acknowledgements — often in bonus)

**Repository:** `otelliq/minitalk`  
**Default branch:** `main`

## Tech stack

- C (POSIX)
- Makefile build
- UNIX signals

## Key features

- Client sends a message to server using only signals
- Server reconstructs bytes from incoming bits and prints the resulting string
- Bonus sources included (separate bonus client/server + headers)

## Screenshots

> No screenshots provided yet.

Suggested screenshots to add:
- server PID output
- client sending a message
- server printing reconstructed text

## Installation & setup

### Prerequisites

- `make`
- `cc` / `gcc` / `clang`
- A UNIX-like OS (Linux/macOS)

### Build

From the repository root:

```bash
make -C minitalk
```

This typically produces:

- `server`
- `client`

(Names may vary depending on the Makefile rules.)

## Usage

### 1) Start the server

```bash
./server
```

It will print a PID, for example:

```text
Server PID: 12345
```

### 2) Send a message from the client

```bash
./client 12345 "hello from signals"
```

### Bonus

If your Makefile supports a bonus target:

```bash
make -C minitalk bonus
```

## Project structure

```text
.
└── minitalk/
    ├── Makefile
    ├── server.c
    ├── client.c
    ├── utils.c
    ├── server_bonus.c
    ├── client_bonus.c
    ├── minitalk.h
    ├── minitalk_bonus.h
    └── ...
```

## License

No license file is currently included in this repository.

If you want this to be usable outside of an academic context, consider adding a `LICENSE` file (MIT/Apache-2.0 are common choices) and updating this section accordingly.
