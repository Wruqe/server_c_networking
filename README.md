# cNetworking

This project was built as a personal learning exercise to understand network programming in C.

The main goal was to get hands-on practice with low-level networking concepts such as:

- creating sockets
- binding to a port
- listening for incoming TCP connections
- accepting client requests
- receiving data from a socket
- sending a simple HTTP response back to the client

## What This Project Does

The project currently contains a basic TCP server in `server.c` that listens on port `3000` and responds with:

```text
Hello, world!
```

It also includes `connections.sh`, a small helper script intended to fire multiple requests at the server to observe how it behaves under several connections.

## Why I Made It

I made this project to learn how network programming works in C at a lower level instead of relying on higher-level frameworks or libraries. The focus here was learning the core system calls and understanding how a simple server handles connections.

## Run It

Compile the server:

```bash
cc server.c -o server
```

Start the server:

```bash
./server
```

In another terminal, test it with:

```bash
curl http://127.0.0.1:3000/
```

## Notes

This is a learning project, so the code is intentionally simple and meant for experimentation rather than production use.
# server_c_networking
