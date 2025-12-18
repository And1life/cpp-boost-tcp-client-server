# cpp-boost-tcp-client-server

A simple TCP client–server application written in modern C++ using Boost.Asio.  
The project demonstrates how to build a blocking TCP echo-like service with clear separation between server and client logic.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg)]()

---

## 📋 Requirements

Before you start, make sure you have the following installed:

- C++17 or later  
- CMake 3.16+  
- Boost (Boost.Asio, Boost.System)

---

## 🚀 Quick Start

### Step 1: Clone the Repository

```bash
git clone git@github.com:And1life/cpp-boost-tcp-client-server.git
cd cpp-boost-tcp-client-server
```

### Step 2: 🔨 Build with CMake

```bash
mkdir build
cmake -B build
cmake --build build
```
After a successful build you will get two executables in the `build/` directory:

- `server`
- `client`

---

## ▶️ Usage

### 1. Run the server

```bash
./build/server
```

The server starts listening on the port defined in `server.cpp` (by default `1234`) and prints:

```bash
The server is running. Waiting for connection...
```

For each client it accepts the connection and then processes multiple messages from that client until the client disconnects.

### 2. Run the client

In another terminal:

```bash
./build/client
```

The client connects to the host and port defined in `client.cpp` (by default `127.0.0.1:1234`) and then you can send messages:

```bash
Print message: hello
Response from the server: Message received!
Print message: second line
Response from the server: Message received!
```

If you type `^C` (or close the client), the client closes the TCP connection and the server prints that the client disconnected.

---

## 📦 Design overview

- `TCPServer`
  - Holds a `boost::asio::ip::tcp::acceptor`.
  - Accepts a client connection and processes it in a read loop:
    - Reads a line with `boost::asio::read_until(socket, buf, '\n')`.
    - Logs the received message.
    - Sends a confirmation message back with `boost::asio::write`.
  - Keeps the connection open until the client closes it (EOF).

- `TCPClient`
  - Resolves host/port configured in code using `boost::asio::ip::tcp::resolver`.
  - Connects to the server with `boost::asio::connect`.
  - `send_message()`:
    - Writes `message + '\n'` to the socket.
    - Waits for a single-line response from the server using `read_until`.
    - Prints the reply to the console.
  - Gracefully handles server-side EOF.

---

## 📁 Project Structure

```
cpp-boost-tcp-client-server/
|── apps/
|   ├── client_app.cpp      # Client entry point (main)
|   └── server_app.cpp      # Server entry point (main)
├── include/
│   ├── TCPClient.hpp       # Main Client class
│   └── TCPServer.hpp       # Main Serverclass
├── src/
│   ├── client.cpp          # Client implementation
│   └── server.cpp          # Server implementation
├── .gitignore              # File to ignore unnecessary files                
├── CMakeLists.txt          # Build configuration
└── README.md               # This file
```


## 🔮 Possible extensions

- Pass host and port via command-line arguments instead of hardcoding.
- Switch to asynchronous API (`async_accept`, `async_read`, `async_write`) to support many clients concurrently.
- Add logging and configurable log levels.
- Implement a richer text protocol (commands, error handling, etc.).

---

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Commit with Conventional Commits:
   ```bash
   git commit -m "feat(Server): add feature description"
   ```
4. Push and create a Pull Request

**Commit Types:**
- `feat:` new feature
- `fix:` bug fix
- `test:` add or update tests
- `docs:` documentation changes
- `refactor:` code refactoring

---

## 📝 License

This project is distributed under the **MIT License** — free for educational and commercial use.

```
MIT License

Copyright (c) 2025 Anatoly Dmitriev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software...
```

See [LICENSE](LICENSE) file for full text.

---

## 📞 Feedback

Have questions or suggestions?

- 🐛 [Report Issues](https://github.com/And1life/cpp-boost-tcp-client-server/issues)
- 💬 Discussion (if enabled)
- 📧 Email: and1life@yandex.ru

---

**Thank you for using cpp-boost-tcp-client-server!** ⭐

If this project was helpful, please star it on GitHub! 🌟