all: testPureFunctions pokerHands

.outputFolder:
	mkdir -p out

testPureFunctions: .outputFolder
	clang -std=c++17 -lstdc++ -lm testPureFunctions.cpp -Wall -Wextra -Werror -o out/testPureFunctions
	./out/testPureFunctions

pokerHands: .outputFolder
	clang -std=c++17 -lstdc++ -lm pokerHands.cpp -Wall -Wextra -Werror -o out/pokerHands
	./out/pokerHands
