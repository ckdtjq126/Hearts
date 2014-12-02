CXX = g++					# compiler
CXXFLAGS = -g -Wall -MMD			# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS1 = p4driver.o Card.o CardPile.o Deck.o Player.o HumanPlayer.o RandomPlayer.o SmartPlayer.o Trick.o Options.o
EXEC1 = Hearts

OBJECTS = ${OBJECTS1}
EXECS = ${EXEC1}
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"

.PHONY : all clean

all : ${EXECS}

${EXEC1} : ${OBJECTS1}				# link step
	${CXX} ${CXXFLAGS} $^ -o $@

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}
