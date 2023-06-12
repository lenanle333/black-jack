#include <iostream>
#include "masterClass.h"

masterClass::masterClass() = default;

/* Prints all elements of the list to the screen */
void masterClass::print(std::list<T> list) {
	for (auto e : list) {
		std::cout << e << std::endl;
	}
}
/* Add an element to the list */
void masterClass::add() {

}
/* Removes an element from the list */
void masterClass::remove() {

}

int main() {
	std::list<std::string> list = { "b", "c","d" };
	print(list);
	return 0;
}