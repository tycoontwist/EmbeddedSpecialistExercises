# Select ubuntu as the base image
FROM ubuntu:latest

# Copy the source files to the container
COPY . /app
WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential

ARG GIT_HASH

# Set the environment variable
ENV GIT_HASH=$GIT_HASH

# Build the client and server
RUN make

# Set the entry point to keep the container alive
CMD tail -f /dev/null