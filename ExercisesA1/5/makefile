PROGRAM   = circumcenter_innercenter_distance
CXX       = clang++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): circumcenter_innercenter_distance.cpp
	$(CXX) circumcenter_innercenter_distance.cpp -o $(PROGRAM)

.PHONY: clean 

clean:
	-rm -f *.o $(PROGRAM) 

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)

