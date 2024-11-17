CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror=vla -MMD
EXEC = ../exec/cc3k
SRC = $(wildcard *.cc)
OBJECTS = $(SRC:.cc=.o)
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

	rm -f ${OBJECTS} ${DEPENDS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -f ${OBJECTS} ${DEPENDS}
