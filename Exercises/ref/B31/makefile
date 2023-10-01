all: ticTacToeResult ticTacToeResultWithClasses fromClassToFunctions

.outputFolder:
	mkdir -p out
	
ticTacToeResult: .outputFolder
	clang -std=c++17 -lstdc++ -lm ticTacToeResult.cpp -Wall -Wextra -Werror -o out/ticTacToeResult
	./out/ticTacToeResult

ticTacToeResultWithClasses: .outputFolder
	clang -std=c++17 -lstdc++ -lm ticTacToeResultWithClasses.cpp -Wall -Wextra -Werror -o out/ticTacToeResultWithClasses
	./out/ticTacToeResultWithClasses

fromClassToFunctions: .outputFolder
	clang -std=c++17 -lstdc++ -lm fromClassToFunctions.cpp -Wall -Wextra -Werror -o out/fromClassToFunctions
	./out/fromClassToFunctions
