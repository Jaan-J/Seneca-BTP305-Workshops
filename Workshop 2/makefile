CXX = g++
CXXFLAGS = -std=c++17 -g
OBJECTS = StringSet.o TimedEvents.o w2_p2.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = output

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
