#pragma once
#include <list>

template <typename T> class data;
class masterClass {

public:
	masterClass();
	void print();
	void add();
	void remove();

private:
	std::list<T> data;
};