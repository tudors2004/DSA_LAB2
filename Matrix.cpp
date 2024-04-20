#include "Matrix.h"
#include <exception>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
	//complexitate: Theta(1)
	nrLin = nrLines;
	nrCol = nrCols;
	size = 0;
	head = nullptr;
	tail = nullptr;
}

int Matrix::nrLines() const {
	//complexitate: Theta(1)
	return nrLin;
}

int Matrix::nrColumns() const {
	//complexitate: Theta(1)
	return nrCol;
}

TElem Matrix::element(int i, int j) const {
	//complexitati: BestCase:Theta(1) // cand lista e goala sau elementul e la inceputul listei
	//AvgCase: Theta(n) // n e nr de elem din lista
	//WorstCase: Theta(n) // cand elementul nu exista sau e la sfarsitul listei
	if (i < 0 || j < 0 || i >= nrLin || j >= nrCol) {
		throw invalid_argument("Invalid position");
	}
	Tuple* current = head;
	while (current != nullptr) {
		if (current->line == i && current->col == j) {
			return current->value;
		}
		current = current->next;
	}
	// daca elementul este gasit returnez valoarea acestuia, daca nu returnez nulltelem
	return NULL_TELEM;
}
TElem Matrix::modify(int i, int j, TElem e) {
	//complexitati:BestCase: Theta(1) // cand lista e goala sau primul elem e modificat
	//AvgCase: Theta(n) // toata lista trebuie parcursa
	//WorstCase: Theta(n)
	if (i < 0 || j < 0 || i >= nrLin || j >= nrCol) {
		throw invalid_argument("Invalid position");
	}
	if (size == 0) { // verificam daca matricea e goala
		Tuple* newTuple = new Tuple{i, j, e, nullptr, nullptr};
		head = newTuple;
		tail = newTuple;
		size++;
		return NULL_TELEM;
	}
	Tuple* current = head;
	while (current != nullptr) {
		if (current->line == i && current->col == j) {
			TElem oldValue = current->value;
			if (e == 0) {
				if (current == head) {
					head = current->next; // capul listei e mutat la urmatorul element
					if (head != nullptr) { // daca lista nu devine goala actualizez legatura inapoi
						head->prev = nullptr;
					} else {
						tail = nullptr;
					}
				} else if (current == tail) {
					tail = current->prev; // coada listei e mutata la elementul anterior
					tail->next = nullptr; // actualizez legatura catre urmatorul element
				} else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				delete current; // dupa ce sterg elementul dealoc memoria
				size--;
			} else {
				current->value = e; // valoarea noua va fi e
			}
			return oldValue;
		}
		current = current->next;
	}
	if (e == 0) { // daca noua valoare e este 0 atunci returnez nulltelem
		return NULL_TELEM;
	}
	Tuple* newTuple = new Tuple{i, j, e, nullptr, nullptr};
	// daca elementul nu a fost gasit si noua valoare e nu e zero atunci creez un tuplu nou
	if (head == nullptr) {
		head = newTuple;
		tail = newTuple;
	} else {
		current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newTuple;// legatura catre urmatorul element
		newTuple->prev = current;// //legatura catre elementul anterior
		tail = newTuple;
	}
	size++;
	return NULL_TELEM;
}

Matrix Matrix::transpusa() const {
	Matrix transpusa(nrCol, nrLin); // transpusa va avea nr de linii egal cu nr de coloane a matricei
	// parcurg matricea si adaug elemente in transpusa
	for (int i = 0; i < nrLin; ++i) {
		for (int j = 0; j < nrCol; ++j) {
			transpusa.modify(j, i, element(i, j)); // schimb pozitiile liniei cu ale coloanei si invers
		}
	}
	return transpusa;
}


Matrix::~Matrix() {
	//complexitate: Theta(n)
	//se dealoca memoria ocupata de fiecare tuplu si seteaza capul si coada la nimic
	Tuple* current = head;
	Tuple* next = nullptr;
	while(current != nullptr){
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
}
