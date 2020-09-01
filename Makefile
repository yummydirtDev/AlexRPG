  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -O3 -Wall -std=c++17

  # the build target executable:
  TARGET = alexrpg

  # the source code files
  STUFF = ./src/game/logic/*.cpp ./src/game/systems/*.cpp ./src/alexsaveload/*.cpp

  all: $(TARGET)

  $(TARGET): ./src/game/logic/*.cpp ./src/game/systems/*.cpp ./src/alexsaveload/*.cpp
	$(CC) $(CFLAGS) $(STUFF) -o $(TARGET)

  clean:
	$(RM) $(TARGET)
