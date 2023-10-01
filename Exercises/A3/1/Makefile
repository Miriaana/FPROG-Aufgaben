PROGRAM   = pythagoras
CXX       = clang++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): pythagoras.cpp
	$(CXX) pythagoras.cpp -o $(PROGRAM)

.PHONY: clean 

clean:
	-rm -f *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


