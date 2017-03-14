#include "grid.h"
#include "dictionary.h"
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
        s >> rows;
        s >> cols;
        g.resize(rows,cols);

        while(getline(f,str)){
            istringstream s(str);

            while(s >> temp){
                g[n][m] = temp;
                m++;
            }
            n++;
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
	int i2 = 0, j2 = 0, dir = 0, found;
	cout << "Cols " << cols << " Rows " << rows << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			key += g2[i][j];
			found = dict.binary_search(key);
			if (found != -1)
			{
				cout << key << endl;
			}
			while (dir < 8)
			{
				cout << "Key: " << key << endl;
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
				}
				if (i2 > rows)
				{
					i2 = 0;
				}

				if (i2 < 0)
				{
					i2 = rows;
				}

				if (j2 > cols)
				{
					j2 = 0;
				}

				if (j2 < 0)
				{
					j2 = cols;
				}
				if (j2 == j && i2 == i)
				{
					dir++;
					key = "";
					continue;
				}
				key += g2[i2][j2];
				found = dict.binary_search(key);
				if (found != -1)
				{
					cout << key << endl;
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
    //d.sort_words();
    cout << "Input grid file name";
    cin >> str;
    g.read(str);

    findMatches(d,g);
}

int main(){
    search();
	system("pause");
    return 0;
}