CXX = g++
CXXFLAGS = -std=c++17 -g
OBJECTS = w5_p2.o SpellChecker.o Movie.o Book.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = output

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
