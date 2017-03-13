#ifndef WORDSEARCH_GRID_H
#define WORDSEARCH_GRID_H

#include <vector>
#include <ostream>

using namespace std;

class grid {
public:
    void read(string fileName);
private:
    vector<vector<char>> grid;
};


#endif //WORDSEARCH_GRID_H
