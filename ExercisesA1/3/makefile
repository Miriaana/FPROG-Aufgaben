PROGRAM   = median_t
CXX       = clang++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): median_t.cpp
	$(CXX) median_t.cpp -o $(PROGRAM)

.PHONY: clean 

clean:
	-rm -f *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

