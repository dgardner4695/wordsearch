#include "grid.h"
#include "dictionary.h"
#include <fstream>
#include <sstream>
#include <iostream>

void grid::read(string fileName) {
    ifstream f;
    string str;
    char temp;
    int n = 0;
    f.open(fileName);
    if(f.is_open()){
        while(getline(f,str)){
            istringstream s(str);

            if(n >= grid.rows()){
                grid.resize(grid.rows() + 1, 0);
            }

            while(s >> temp){
                grid[n].push_back(temp);
                std::cout << temp << " " << n << std::endl;
            }
            n++;
        }
    }
    else{
        std::cout << "Error reading from file";
    }
}
matrix<char> grid::getGrid(){
    return grid;
}

static void findMatches(dictionary dict, grid g){

}

static void search(){
    dictionary d;
    grid g;
    string str;

    d.read_words();
    d.sort_words();

    cout << "Input grid file name";
    cin >> str;
    g.read(str);

    findMatches(d,g);
}

int main(){
    search();

    return 0;
}