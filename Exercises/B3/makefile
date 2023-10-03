all: sort

.outputFolder:
	mkdir -p out
	
sort: .outputFolder
	g++ -std=c++17 -lstdc++ -lm sortTests.cpp -Wall -Werror -Wextra -Wno-unused-parameter -o out/sort
	./out/sort

