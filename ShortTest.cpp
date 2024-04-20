#include <assert.h>
#include "Matrix.h"
#include <iostream>
using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
}

void testTranspusa(){
	Matrix m(2,3);
	m.modify(0, 0, 1);
	m.modify(0, 1, 2);
	m.modify(0, 2, 3);
	m.modify(1, 0, 4);
	m.modify(1, 1, 5);
	m.modify(1, 2, 6);

	Matrix transpusa = m.transpusa();

	assert(transpusa.nrLines() == 3);
	assert(transpusa.nrColumns() == 2);

	assert(transpusa.element(0, 0) == 1);
	assert(transpusa.element(0, 1) == 4);
	assert(transpusa.element(1, 0) == 2);
	assert(transpusa.element(1, 1) == 5);
	assert(transpusa.element(2, 0) == 3);
	assert(transpusa.element(2, 1) == 6);
	cout<<"Test transpusa"<<endl;
}