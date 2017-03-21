#include "grid.h"
#include "dictionary.h"
#include "heap.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void grid::read(string fileName) {
    ifstream f;
    string str;
    char temp;
    int n = 0;
    int m = 0;
    f.open(fileName);
    if(f.is_open()){
        istringstream s(str);
        int rows;
        int cols;
        f >> rows;
        f >> cols;
		cout << rows << cols << endl;
        g.resize(rows+1,cols+1);

        while(getline(f,str)){
            istringstream s(str);

            while(s >> temp){
				cout << temp;
                g[n][m] = temp;
                m++;
            }
            n++;
			m = 0;
			cout << endl;
        }
    }
    else{
        std::cout << "Error reading from file";
    }
}
matrix<char> grid::getGrid(){
    return g;
}

static void findMatches(dictionary dict, grid g){
	matrix<char> g2 = g.getGrid();
	int cols = g2.cols();
	int rows = g2.rows();
	string key = "";
	int i2 = 0, j2 = 0, dir, found;
	for (int i = 0; i < rows; i++)
	{
		i2 = i;
		for (int j = 0; j < cols; j++)
		{
			j2 = j;
			dir = 0;
			key += g2[i2][j2];
			while (dir < 8)
			{
				switch (dir)
				{
				case 0: //RIGHT
					j2++;
					break;
				case 1: //DOWN RIGHT
					i2++;
					j2++;
					break;
				case 2: //DOWN
					i2++;
					break;
				case 3: //DOWN LEFT
					i2++;
					j2--;
					break;
				case 4: //LEFT
					j2--;
					break;
				case 5: //UP LEFT
					i2--;
					j2--;
					break;
				case 6: //UP
					i2--;
					break;
				case 7: //UP RIGHT
					i2--;
					j2++;
					break;
				}
				if (i2 >= rows)
				{
					i2 = 0;
				}

				if (i2 < 0)
				{
					i2 = rows-1;
				}

				if (j2 >= cols)
				{
					j2 = 0;
				}

				if (j2 < 0)
				{
					j2 = cols-1;
				}
				if (j2 == j && i2 == i)
				{
					dir++;
					key = "";
					continue;
				}
				key += g2[i2][j2];
				if (key.length() >= 5)
				{
					found = dict.binary_search(key);
				}
				else
				{
					continue;
				}
				if (found != -1)
				{
					cout << "Found " << key << endl;
				}
			}
		}
	}
}

static void search(){
    dictionary d;
    grid g;
    string str;

    d.read_words();
    d.sort_words();
    cout << "Input grid file name: ";
    cin >> str;
    g.read(str);

    findMatches(d,g);
}

int main(){
    dictionary dict;
    dict.read_words();
    cout << "Before Sorting: " << endl << dict;

    dict.dictHeapSort();

    cout << "After Sorting " << endl << dict;

}