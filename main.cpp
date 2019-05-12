#include <iostream>
#include <locale.h>
#include "sort.h"
#include "Humans.h"

using namespace std;

int main()
{
	SortVector<Human> humans;
	const char* filename = "tel.txt";

	if (!readHumans(filename, humans))
	{
		cout << "Can't open input file: filename" << endl;
		return -1;
	}
	humans.sort();
	if (!writeHumans(filename, humans))
	{
		cout << "Can't open input file: filename" << endl;
		return -2;
	}

	system("pause");
	return 0;
}
