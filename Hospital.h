#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include <string>

using namespace std;

struct Hospital
{
	int id = 0;
	int code = 0;
	string TwoNameDoctor = "";
	Hospital* further = nullptr;
};

#endif