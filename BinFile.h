#ifndef BINFILE_H
#define BINFILE_H
#include <iostream>
#include <fstream>
#include "Hospital.h"
#include "Hash.h"

using namespace std;

void CreateBinFile(string name, Hash* A);
void ReadBinFile(string name);
void PoiskBinFile(string name, int id);
void Replace(string name);

Hash* getBinFile(string name, Hash* A);



#endif BINFILE_H