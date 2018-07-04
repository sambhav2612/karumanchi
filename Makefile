CC=g++
OPTS=-g -O -Wall
CFLAGS=$(OPTS)
LDFLAGS=

DIRS=./ch1-introduction ./ch10-sorting ./ch2-recursion-and-backtracking ./ch3-linked-lists ./ch4-stacks ./ch5-queues ./ch6-trees ./codechef/arrays ./misc
HEADERS=./includes
SRC=$(wildcard $(DIRS)/**/*.cpp)
OBJ=$(patsubst $(DIRS)/%.cpp, obj/%.o, $(SRC))

all: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o all

obj/%.o: $(DIRS)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: $(patsubst %.cpp, %.clean, $(wildcard *.cpp))
	rm -f *.exe