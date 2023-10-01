all: immutability loop join compare functionalSum

.outDir:
	mkdir -p out

immutability: .outDir
	clang -std=c++17 -lstdc++ immutability.cpp -o out/immutability
	./out/immutability

loop: .outDir
	clang -std=c++17 -lstdc++ loop.cpp -o out/loop	
	./out/loop

join: .outDir
	clang -std=c++17 -lstdc++ join.cpp -o out/join
	./out/join

compare: .outDir
	clang -std=c++17 -lstdc++ compare.cpp -o out/compare
	./out/compare

functionalSum: .outDir
	clang -std=c++17 -lstdc++ functionalSum.cpp -o out/functionalSum
	./out/functionalSum
