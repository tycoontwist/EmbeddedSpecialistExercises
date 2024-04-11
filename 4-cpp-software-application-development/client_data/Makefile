# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra

COMMON_DIR = ../common
SERVER_DIR = .
INC_DIR = -I$(COMMON_DIR)

# Source files
COMMON_SRC = $(wildcard $(COMMON_DIR)/*.cpp)
CLIENT_SRC = $(wildcard $(CLIENT_DIR)/*.cpp)

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
CLIENT_OBJ = $(CLIENT_SRC:.cpp=.o)

# Executable name
EXEC_CLIENT = client

all: $(EXEC_CLIENT)

$(EXEC_CLIENT): $(SERVER_OBJ) $(COMMON_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(COMMON_DIR) -c $< -o $@

client:
	g++ -o client client_data/main.cpp common/*.cpp

clean:
	rm -f $(COMMON_OBJ) $(SERVER_OBJ) $(EXEC_CLIENT)
