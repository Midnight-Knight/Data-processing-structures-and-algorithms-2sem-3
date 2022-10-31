#include "Hash.h"

Hash::Hash(unsigned int N)
{
	this->N = N;
	A = new Hospital*[N];
	for (unsigned int i = 0; i < N; ++i)
	{
		A[i] = nullptr;
	}
}

void Hash::Add(int id)
{
	unsigned int hashid = func(id);
	if (A[hashid] != 00000000000000000000000000000000)
	{
		Hospital* Buf = A[hashid];
		A[hashid] = new Hospital;
		A[hashid]->further = Buf;
	}
	else
	{
		A[hashid] = new Hospital;
	}
	A[hashid]->id = id;
	cout << "Введите код болезни: ";
	int code;
	cin >> code;
	A[hashid]->code = code;
	cout << "Введите фамилию врача: ";
	string TwoName;
	cin >> TwoName;
	A[hashid]->TwoNameDoctor = TwoName;
}

void Hash::Add(int id, int code, string TwoName)
{
	unsigned int hashid = func(id);
	if (A[hashid] != 00000000000000000000000000000000)
	{
		Hospital* Buf = A[hashid];
		A[hashid] = new Hospital;
		A[hashid]->further = Buf;
	}
	else
	{
		A[hashid] = new Hospital;
	}
	A[hashid]->id = id;
	A[hashid]->code = code;
	A[hashid]->TwoNameDoctor = TwoName;
}

void Hash::Get(int id)
{
	unsigned int hashid = func(id);
	if (A[hashid] == 00000000000000000000000000000000)
	{
		cout << "Запись отсутствует!" << endl;
		return;
	}
	Hospital* Buf = A[hashid];
	while (Buf->id != id)
	{
		if (Buf->further != 00000000000000000000000000000000)
		{
			Buf = Buf->further;
		}
		else
		{
			cout << "Запись отсутствует!" << endl;
			return;
		}
	}
	cout << "ячейка: " << hashid << endl;
	cout << "id: " << Buf->id << endl;
	cout << "code: " << Buf->code << endl;
	cout << "Two Name: " << Buf->TwoNameDoctor << endl << endl;
}

void Hash::NewInfo(int id)
{
	unsigned int hashid = func(id);
	if (A[hashid] == 00000000000000000000000000000000)
	{
		cout << "Запись отсутствует!" << endl;
		return;
	}
	Hospital* Buf = A[hashid];
	while (Buf->id != id)
	{
		if (Buf->further != 00000000000000000000000000000000)
		{
			Buf = Buf->further;
		}
		else
		{
			cout << "Запись отсутствует!" << endl;
			return;
		}
	}
	cout << "ячейка: " << hashid << endl;
	cout << "id: " << Buf->id << endl;
	cout << "code: " << Buf->code << " заменить на ";
	int code;
	cin >> code;
	Buf->code = code;
	cout << "Two Name: " << Buf->TwoNameDoctor << " заменить на ";
	string TwoName;
	cin >> TwoName;
	Buf->TwoNameDoctor = TwoName;
	cout << endl;
}

void Hash::Del(int id)
{
	unsigned int hashid = func(id);
	if (A[hashid] == 00000000000000000000000000000000)
	{
		cout << "Запись отсутствует!" << endl;
		return;
	}
	Hospital* Buf2 = nullptr;
	Hospital* Buf1 = A[hashid];
	while (Buf1->id != id)
	{
		if (Buf1->further != 00000000000000000000000000000000)
		{
			Buf2 = Buf1;
			Buf1 = Buf1->further;
		}
		else
		{
			cout << "Запись отсутствует!" << endl;
			return;
		}
	}
	if (Buf2 == 00000000000000000000000000000000)
	{
		A[hashid] = Buf1->further;
		delete Buf1;
	}
	else
	{
		Buf2->further = Buf1->further;
		delete Buf1;
	}
	cout << "Запись удалена!" << endl;
}

unsigned int Hash::getHash()
{
	return N;
}

Hospital* Hash::getHospital(int id)
{
	unsigned int hashid = func(id);
	if (A[hashid] == 00000000000000000000000000000000)
	{
		cout << "Запись отсутствует!" << endl;
		return nullptr;
	}
	Hospital* Buf = A[hashid];
	while (Buf->id != id)
	{
		if (Buf->further != 00000000000000000000000000000000)
		{
			Buf = Buf->further;
		}
		else
		{
			cout << "Запись отсутствует!" << endl;
			return nullptr;
		}
	}
	return A[hashid];
}

Hospital* Hash::getHospitalCell(unsigned int cell)
{
	if ((A[cell] == 00000000000000000000000000000000) || (cell >= N))
	{
		cout << "Запись отсутствует!" << endl;
		return nullptr;
	}
	else
	{
		return A[cell];
	}
}

unsigned int Hash::func(unsigned int id)
{
	unsigned int idK = ((int)log10(id) + 1);
	unsigned int hashid = 0;
	for (unsigned int i = 1; i <= idK; ++i)
	{
		hashid += id % 10;
		id /= 10;
	}
	return hashid %= N;
}
