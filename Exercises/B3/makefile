all: sort

.outputFolder:
	mkdir -p out
	
sort: .outputFolder
	clang -std=c++17 -lstdc++ -lm sort.cpp -Wall -Wextra -Werror -o out/sort
	./out/sort
