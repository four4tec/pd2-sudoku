main:givequestion.cpp solve.cpp Sudoku.o
	g++ -o givequestion givequestion.cpp Sudoku.o
	g++ -o solve solve.cpp Sudoku.o
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
