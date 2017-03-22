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
		std::cout << "Error reading from file" << endl;
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
	int choice;
    dictionary d;
    grid g;
    string str;

    d.read_words();
	cout << "Choose a search algorithm to use: " << endl;
	cout << "1. Selection Sort" << endl;
	cout << "2. Quick Sort" << endl;
	cout << "3. Heap Sort" << endl;
	cin >> choice;
	while (choice > 3 || choice < 1)
	{
		cout << "Invalid choice, choose again: " << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		d.sort_words();
		break;
	case 2:
		d.quick_sort(d.get_words(), 0, d.get_words().size() - 1);
		break;
	case 3:
		d.dictHeapSort();
	}
	cout << "Sorted" << endl;
    cout << "Input grid file name: ";
    cin >> str;
    g.read(str);

    findMatches(d,g);
}

int main()
{
	search();
	system("pause");
	return 0;
}