# Compiler
CXX = $(CROSS_COMPILE)g++

# Compiler flags
CXXFLAGS = -Wall -Wextra

COMMON_DIR = ../common
CLIENT_DIR = .
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

$(EXEC_CLIENT): $(CLIENT_OBJ) $(COMMON_OBJ)
	$(CXX) $(CXXFLAGS) -o ../$@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(COMMON_DIR) -c $< -o $@

clean:
	rm -f $(COMMON_OBJ) $(CLIENT_OBJ) ../$(EXEC_CLIENT)
