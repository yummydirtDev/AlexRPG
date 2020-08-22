  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -O3 -Wall -std=c++17

  # the build target executable:
  TARGET = alexrpg

  STUFF = ./game/*.cpp ./alexsaveload/*.cpp

  all: $(TARGET)

  $(TARGET): ./game/*.cpp ./alexsaveload/*.cpp
	$(CC) $(CFLAGS) $(STUFF) -o $(TARGET)

  clean:
	$(RM) $(TARGET)
