# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra

COMMON_DIR = ../common
SERVER_DIR = .
INC_DIR = -I$(COMMON_DIR)

# Source files
COMMON_SRC = $(wildcard $(COMMON_DIR)/*.cpp)
SERVER_SRC = $(wildcard $(SERVER_DIR)/*.cpp)

# Object files
COMMON_OBJ = $(COMMON_SRC:.cpp=.o)
SERVER_OBJ = $(SERVER_SRC:.cpp=.o)

# Executable name
EXEC_SERVER = server

all: $(EXEC_SERVER)

$(EXEC_SERVER): $(SERVER_OBJ) $(COMMON_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(COMMON_DIR) -c $< -o $@

clean:
	rm -f $(COMMON_OBJ) $(SERVER_OBJ) $(EXEC_SERVER)
