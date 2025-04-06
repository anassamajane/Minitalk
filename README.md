# Minitalk

This repository contains two versions of my 42 school **Minitalk** project — a small inter-process communication project using **UNIX signals**. The goal is to send messages between a client and server process using `SIGUSR1` and `SIGUSR2`.

## 🧠 What is Minitalk?

Minitalk is about simulating communication between two programs (client and server) **only using signals**, where:
- `SIGUSR1` represents a binary `0`
- `SIGUSR2` represents a binary `1`

The client encodes and sends characters bit by bit, and the server reconstructs and prints the message.

---

## 📂 Repository Structure

### `minitalk_115%/`  
> ✅ **Validated with 115%**

- Used the basic `signal()` function for signal handling.
- Implemented a minimal bonus:
  - ✅ Unicode support (wide characters are handled).
  - ❌ Did **not** implement acknowledgment signals (server confirming receipt of each character).

### `minitalk_125%/`  
> ✅ **Validated with 125% (Full Bonus)**

- Uses `sigaction()` for more reliable and extended signal handling.
- Implemented the full bonus:
  - ✅ Unicode support.
  - ✅ Acknowledgment mechanism (server sends a signal back to confirm each character received).
  - ✅ Handles interruptions more gracefully and uses `siginfo_t` for advanced control.

---

## 💡 Why Two Versions?

I wanted to:
- First build a clean and understandable version using `signal()` (115%).
- Then improve it by exploring `sigaction()` and implementing the full bonus (125%).

This gives others a chance to learn both approaches side by side.

---

## 🛠️ How to Use

Each version contains its own `client.c`, `server.c`, and `Makefile`.  
To run either version:

```bash
cd minitalk_125%    # or cd minitalk_115%
make
./server            # run the server and note the PID
./client <PID> "Hello from the client!"
```

## 🧷 Notes

- The **server must be started first** to receive signals from the client.
- The **client sends each character bit by bit** using `SIGUSR1` (for 0) and `SIGUSR2` (for 1).
- The **server reconstructs each byte** from the bits it receives, then prints the character.
- In the `minitalk_125%` version:
  - A **confirmation signal** (acknowledgment) is sent back from the server to the client after each character.
  - This prevents the client from sending data too quickly and overwhelming the server.
- Unicode characters are handled correctly in both versions.
- `sigaction()` (used in the 125% version) provides better control than `signal()` and avoids issues with older signal handling.
