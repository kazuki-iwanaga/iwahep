FROM ubuntu:22.04

LABEL maintainer="kazuki-iwanaga"

RUN apt update && apt install -y --no-install-recommends \
    build-essential \
    cmake \
    ca-certificates \
    git

WORKDIR /home/work