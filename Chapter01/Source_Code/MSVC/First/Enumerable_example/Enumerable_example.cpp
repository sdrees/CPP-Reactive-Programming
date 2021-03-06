// Enumerable_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include "../Common2.h"
using namespace std;


class ConcreteEnumberable : public IEnumerable<int>
{
	int  *numberlist;
	int _count;
	friend class Enumerator;
public:
	ConcreteEnumberable(int numbers[], int count):numberlist(numbers),_count(count){}
	~ConcreteEnumberable() {}
	class Enumerator : public IEnumerator<int> {
		int *inumbers, icount, index;
	public:
		Enumerator(int *numbers, int count):inumbers(numbers),icount(count),index(0) {}
		bool HasMore() { return index < icount; }
		int next() { return (index < icount) ? inumbers[index++] : 0xFFFF; }
		~Enumerator() {}
	};
	IEnumerator<int> *GetEnumerator() { return new Enumerator(numberlist, _count); }
};





int main()
{
	int x[] = { 1,2,3,4,5 };
	ConcreteEnumberable *t = new ConcreteEnumberable(x, 5);
    IEnumerator<int>  * numbers = t->GetEnumerator();
	while (numbers->HasMore())
		cout << numbers->next() << endl;
	delete numbers;
	delete t;
	return 0;
}

