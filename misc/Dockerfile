FROM ubuntu:focal
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y && apt-get install -y git gcc cmake make g++ device-tree-compiler
RUN apt-get install -y gcc-riscv64-unknown-elf gcc-riscv64-linux-gnu g++-riscv64-linux-gnu
