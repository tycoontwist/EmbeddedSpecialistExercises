# Select ubuntu as the base image
FROM ubuntu:latest

# Get the GIT_HASH
ARG GIT_HASH

# Set the environment variable
ENV GIT_HASH=$GIT_HASH

# Copy the source files to the container
COPY . /app
WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    wget

# Build the client and server
RUN make

# Download the Bootlin toolchain
RUN wget https://toolchains.bootlin.com/downloads/releases/toolchains/aarch64/tarballs/aarch64--glibc--stable-2024.02-1.tar.bz2

# Extract the toolchain
RUN tar -xvf aarch64--glibc--stable-2024.02-1.tar.bz2

ENV PATH="/app/aarch64--glibc--stable-2024.02-1/bin:${PATH}"

# Set the entry point to keep the container alive
CMD tail -f /dev/null