#include <iostream>
#include "Hash.h"
#include <Windows.h>
#include "BinFile.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Hash* A = new Hash(5);
	A->Add(12349);
	A->Add(123495);
	A->Add(1234955);
	cout << endl;
	CreateBinFile("One.dat", A);
	ReadBinFile("One.dat");
	A->Add(456);
	CreateBinFile("Two.dat", A);
	ReadBinFile("Two.dat");
	A->Del(456);
	CreateBinFile("Two.dat", A);
	ReadBinFile("Two.dat");
	cout << endl;
	PoiskBinFile("One.dat", 123495);
	cout << endl;
	PoiskBinFile("One.dat", 123496);
	cout << endl;
	Replace("One.dat");
	cout << endl;
	ReadBinFile("One.dat");
	cout << endl;
	return 0;
}