all: sort incrementAll staticAccess pureFunction number

.outputFolder:
	mkdir -p out

sort: .outputFolder
	clang -std=c++17 -lstdc++ sort.cpp -o out/sort
	./out/sort

incrementAll: .outputFolder
	clang -std=c++17 -lstdc++ incrementAll.cpp -o out/incrementAll
	./out/incrementAll

staticAccess: .outputFolder
	clang -std=c++17 -lstdc++ staticAccess.cpp -o out/staticAccess
	./out/staticAccess

pureFunction: .outputFolder
	clang -std=c++17 -lstdc++ pureFunction.cpp -o out/pureFunction
	./out/pureFunction

number: .outputFolder
	clang -std=c++17 -lstdc++ number.cpp -o out/number
	./out/number
