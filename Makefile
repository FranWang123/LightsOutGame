CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=cell.o grid.o main.o subject.o textdisplay.o window.o graphicsdisplay.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q2b

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm *.o a4q2b

.PHONY: clean
