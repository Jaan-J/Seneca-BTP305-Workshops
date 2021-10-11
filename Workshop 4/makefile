CXX = g++
CXXFLAGS = -std=c++17 -g
OBJECTS = w4_p2.o ConfirmationSender.o Reservation.o Restaurant.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = output

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
