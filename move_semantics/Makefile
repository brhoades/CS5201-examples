# Billy Rhoades
# SP2016 Move Semantics Example
# 2/6/16
# CS5201
CXX=/usr/bin/g++
CFLAGS=-g -Wall -W -pedantic-errors -std=c++11

SOURCES = $(wildcard *.cpp) $(wildcard *.h) 
OBJECTS = regular.o example.o movesemantics.o

.SUFFIXES: .cpp
.cpp.o: $<
	$(CXX) -c $(CFLAGS) -o $@ $<

defualt: all

all: pdf

clean:
	-@ rm -f $(OBJECTS) example_printout.pdf example_printout.aux

pdf: example
	-@echo "Outputting to files..."
	-@echo "$$ $(CXX) $(CFLAGS) *.cpp" > output.txt
	-@echo -e "$$ ./example\n" >> output.txt
	-@./example >> output.txt
	-@echo "Creating PDF"
	-@pdflatex example_printout.tex &> /dev/null
	-@echo "Done!"

example: $(OBJECTS)
	$(CXX) $(CFLAGS) $? -o $@

movesemantics.o: movesemantics.cpp movesemantics.h
example.o: example.cpp
regular.o: regular.cpp regular.h
