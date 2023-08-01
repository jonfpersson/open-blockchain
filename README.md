# Blockchain Project

Welcome to the Blockchain project! This project demonstrates a simple implementation of a blockchain using C++. The code provided in this repository allows you to create blocks, link them together, and verify the integrity of the blockchain.

## Table of Contents

- [Blockchain Project](#blockchain-project)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Usage](#usage)
  - [Dependencies](#dependencies)
  - [How It Works](#how-it-works)
  - [Contributing](#contributing)

## Introduction

Blockchain is a decentralized and distributed ledger technology that enables secure and transparent data storage and management. Each block in a blockchain contains data, a timestamp, and a cryptographic hash of the previous block. This linkage of blocks through their hashes creates an immutable and tamper-proof chain of information.

## Usage

To use the blockchain code provided, follow these steps:

1. Clone or download this repository to your local machine.
2. Open the C++ source files in your preferred C++ compiler or IDE.
3. Compile and run the `main.cpp` file.
4. The program will create a simple blockchain with three blocks and validate its integrity.

## Dependencies

This project relies on the following standard C++ libraries:

- iostream
- string
- vector
- ctime
- sstream
- iomanip
- openssl/sha.h

Make sure you have a compatible C++ compiler installed that supports these libraries.

## How It Works

The `block` class represents a single block in the blockchain. Each block contains the following components:

- `prev_hash`: The hash of the previous block in the chain. This ensures the immutability of the blockchain.
- `data`: The data stored in the block. In this example, it is a simple string.
- `timestamp`: The timestamp of when the block was created, represented as a Unix timestamp (std::time_t).
- `hash`: The cryptographic hash of the current block's data, timestamp, and previous block's hash.

The `hashString` function within the `block` class uses the SHA-256 hashing algorithm from the OpenSSL library to calculate the hash of a given input.

The `isChainValid` function in `main.cpp` checks the integrity of the blockchain by verifying whether the hash of each block is correctly calculated and whether the previous block's hash matches the hash stored in the current block.

## Contributing

Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.