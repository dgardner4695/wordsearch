#ifndef WORDSEARCH_GRID_H
#define WORDSEARCH_GRID_H

#include <vector>
#include <ostream>
#include "d_matrix.h"

using namespace std;

class grid {
public:
    void read(string fileName);
    matrix<char> getGrid();
private:
	matrix<char> g;
};


#endif //WORDSEARCH_GRID_H
