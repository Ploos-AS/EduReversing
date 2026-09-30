FROM debian:bookworm-slim

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
       bash \
       build-essential \
       binutils \
       binutils-multiarch \
       gcc \
       g++ \
       gdb \
       make \
       cmake \
       file \
       strace \
       ltrace \
       radare2 \
       nasm \
       yasm \
       python3 \
       python3-pip \
       git \
       curl \
       ca-certificates \
       xxd \
       jq \
       less \
       vim-tiny \
    && rm -rf /var/lib/apt/lists/*

RUN useradd --create-home --shell /bin/bash student

WORKDIR /work
USER student

CMD ["/bin/bash"]
