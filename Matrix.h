#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {

private:
	struct Tuple {
		int line;
		int col;
		TElem value;
		Tuple* next; //pointer la urmatorul element in ordine lexicografica
		Tuple* prev; //pointer la elementul anterior in ordine lexicografica
	};

	int nrLin; //nr de linii din matrice
	int nrCol; //nr de coloane din matrice
	Tuple* head; //pointer la capul listei de tupluri
	Tuple* tail; //pointer la coada listei de tupluri
	int size; //nr de elemente nenule din matrice

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;
	Matrix transpusa() const;
	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	// destructor
	~Matrix();

};
