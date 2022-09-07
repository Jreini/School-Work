CXX = g++

FLAGS = -W -Wall -Wextra -Wpedantic -std=c++11

LIBRARIES = -lpthread

.PHONY: default run

default: run

run:
	${CXX} ${FLAGS} main.cpp ${LIBRARIES} -o program

clean:
	-@rm -rf *.o program core

