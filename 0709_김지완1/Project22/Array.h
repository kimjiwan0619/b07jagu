#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename Type>
class Array
{
private:
	Type * p;

public:
	Array() {};
	~Array() 
	{
		delete [] p;
	}
	
	Type Get();
};

template <typename Type>
Type Array<Type>::Get()
{
	cout << "ũ���?" << endl;
	int size;
	cin >> size;
	p = new Type[size];
	

	for (int i = 0;i < size;++i)
	{
		cout << "ó�־� �̻�����" << endl;
		Type a;
		cin >> a;
		p[i] = a;
	}
	for (int i = 0;i < size;++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}


