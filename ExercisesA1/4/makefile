PROGRAM   = triangle_circumradius
CXX       = clang++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): triangle_circumradius.cpp
	$(CXX) triangle_circumradius.cpp -o $(PROGRAM)

.PHONY: clean 

clean:
	-rm -f *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

