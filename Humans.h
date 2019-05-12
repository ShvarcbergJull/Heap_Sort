#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include "sort.h"

using namespace std;

class Human
{
private:
	char* data;

public:
	Human(const char* indata)
	{
		data = new char[strlen(indata) + 1];
		for (int i = 0; i < strlen(indata); i++)
			data[i] = indata[i];
		if (data[strlen(indata) - 1] == '\r')
			data[strlen(indata) - 1] = 0;
		else
			data[strlen(indata)] = 0;
	}

	char* getData()
	{
		return (*this).data;
	}

	bool operator ==(const Human& hum) const
	{
		if (strcmp((*this).data, hum.data) == 0)
			return true;
		return false;
	}

	bool operator >(const Human& hum) const
	{
		if (strcmp((*this).data, hum.data) > 0)
			return true;
		return false;
	}

	bool operator <(const Human& hum) const
	{
		if (strcmp((*this).data, hum.data) < 0)
			return true;
		return false;
	}

	bool operator <=(const Human& hum) const
	{
		if (strcmp((*this).data, hum.data) <= 0)
			return true;
		return false;
	}

	bool operator >=(const Human& hum) const
	{
		if (strcmp((*this).data, hum.data) >= 0)
			return true;
		return false;
	}

	void operator =(const Human& hum)
	{
		data = new char[strlen(hum.data) + 1];
		for (int i = 0; i < strlen(hum.data); i++)
			data[i] = hum.data[i];
		data[strlen(hum.data)] = 0;
	}

	/*~Human()
	{
		delete[] data;
	}*/
};

ofstream& operator<<(ofstream& out, Human& hum)
{
	out << hum.getData();
	return out;
}

bool readHumans(const char* filename, SortVector<Human>& humans)
{
	char* buffer = new char[STR_LENGHT + 1];
	//ifstream in(filename);
	ifstream in;
	in.open(filename, ios::binary);
	if (!in.is_open())
		return false;
	while (!in.eof())
	{
		buffer[0] = 0;
		int n = strlen(buffer);
		in.getline(buffer, STR_LENGHT, '\n');
		int i = 0;
		Human hum = Human(buffer);
		humans.push_back(hum);
	}
	in.close();
	return true;
}


bool writeHumans(const char* filename, const SortVector<Human>& humans)
{
	ofstream out(filename);
	if (!out.is_open())
		return false;
	for (int i = 0; i < humans.size(); i++)
	{
		Human hum = humans[i];
		int n = strlen(hum.getData());
		out << hum << endl;
	}
	out.close();
	return true;
}
