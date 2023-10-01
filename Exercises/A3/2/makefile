PROGRAM   = root_of_quadratic_function
CXX       = clang++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): root_of_quadratic_function.cpp
	$(CXX) root_of_quadratic_function.cpp -o $(PROGRAM)

.PHONY: clean 

clean:
	-rm -f *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

