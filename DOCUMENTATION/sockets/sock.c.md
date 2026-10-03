# Documentation for the sock.c file in the directory "utils"

---

## mktcpsocket

> Makes a TCP socket.
**returns int fd**
*No arguments*
Speed unknown.
Finished.

---

## mkudpsocket

> Makes a UDP socket.
**returns int fd**
*No arguments*
Speed unknown.
Finished.

---

## bindsocket

> Binds a socket to a port.
**returns 0 or exits with status of 1**
*int argument fd, int argument port*
Speed unknown.
Finished.

---

## acceptsocket

> Accepts connections, and sets \*outfd to the accepted fd
**returns struct sockaddr\_in6**
*int argument fd, int pointer argument outfd*
Speed unknown.
Finished.

---

## connectsocket

> Connects a socket to an ip and port
**returns 0 or exits with status of 1**
*int argument fd, int argument port, char pointer (string) argument ip*
Speed unknown.
Finished.

---

## closesocket

> Closes a socket
**returns 0 or exits with status of 1**
*int argument fd*
Speed unknown.
Finished.

---
