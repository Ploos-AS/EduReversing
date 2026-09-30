FROM debian:bookworm-slim AS r2-build

ARG DEBIAN_FRONTEND=noninteractive
ARG RADARE2_VERSION=6.2.2

RUN apt-get update && apt-get install -y --no-install-recommends build-essential ca-certificates curl pkg-config python3 xz-utils && rm -rf /var/lib/apt/lists/*
RUN curl --fail --location --show-error "https://github.com/radareorg/radare2/releases/download/6.2.2/radare2-6.2.2.tar.xz" -o /tmp/r2.tar.xz && mkdir /src && tar -xJf /tmp/r2.tar.xz -C /src --strip-components=1 && cd /src && ./configure --prefix=/usr/local && make -j2 && make install DESTDIR=/r2-root

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
       gcc-mingw-w64-x86-64 \
       binutils-mingw-w64-x86-64 \
       gdb \
       make \
       cmake \
       file \
       strace \
       ltrace \
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

COPY --from=r2-build /r2-root/ /
RUN echo "/usr/local/lib" > /etc/ld.so.conf.d/radare2.conf \
    && ldconfig \
    && r2 -v | grep -F "6.2.2"

RUN useradd --create-home --shell /bin/bash student

WORKDIR /work
USER student

CMD ["/bin/bash"]
