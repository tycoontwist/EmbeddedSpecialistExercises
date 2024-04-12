all: client server

all_cross_compile: client_cc server_cc

client_cc:
	export CROSS_COMPILE=aarch64-linux-; make client

server_cc:
	export CROSS_COMPILE=aarch64-linux-; make server

client:
	cd client_data; make client

server:
	cd server_data; make server

clean:
	cd client_data; make clean
	cd server_data; make clean
