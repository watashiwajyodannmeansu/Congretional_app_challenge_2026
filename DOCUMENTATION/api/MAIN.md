# Documentation for the "main_api.c" file in the directory "api"

## The main_api.c file is the source code for the main api of Volun. This is essential to operating the app, and must be started to start the app

---

## ARGV

---

## argv[1]

> Port number to host a server socket on.
***must be unsigned short int, or else program will exit with a status of 1. Must be present, or else program will exit with status of 1.***

---

## argv[2]

> IP to connect to.
***an IP, or else program will exit with a status of 2. Must be present, or else program will exit with status of 2.***

---

## argv[3]

> Port number for server socket.
***must be unsigned short int, or else program will exit with a status of 3. Must be present, or else program will exit with status of 3.***

---

## SOCKET

---

## HOW TO USE

### Open socket on port $argv[1]$.

### Send a 1024 byte buffer of use name through socket, and follow the documented instructions.

---

## b"genkey"

> Generates a key to share with the server

*takes input of unsigned 1 byte buffer*

**returns unsigned 1 byte buffer by socket**

---

## b"send"

> Sends a document to the server

*takes input of 1024 byte buffers until '\0' is recieved*

**returns uint64_t (unsigned long int) (64 bits or 8 bytes) count of how many buffers were sent by socket**

---

## b"recv"

*takes uint64_t (unsigned long int) (64 bits or 8 bytes) buffer for how many bytes to recieve*

**returns buffer of given bytes**

---

## FUNCTIONS

---



---