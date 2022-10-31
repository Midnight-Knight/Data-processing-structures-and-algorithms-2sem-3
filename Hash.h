#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "Hospital.h"
#include <string>

using namespace std;

class Hash
{
protected:
	unsigned int N;
	Hospital **A;
	unsigned int func(unsigned int id);
public:
	Hash(unsigned int N);
	void Add(int id);
	void Add(int id, int code, string TwoName);
	void Get(int id);
	void NewInfo(int id);
	void Del(int id);

	unsigned int getHash();

	Hospital* getHospital(int id);
	Hospital* getHospitalCell(unsigned int cell);
};



#endif 