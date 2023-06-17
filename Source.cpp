#include <iostream>
#include "tree/tree.h"
#include "old_structs/MyStack.h"

int f(int a)
{
	return a * 2;
}

int main()
{
		tree<int> first(10);
		first.insert(5);
		first.insert(15);
		first.insert(3);
		first.insert(8);
		first.insert(12);
		first.insert(17);
		std::cout << first.search(5) << " " << first.search(12) << "\n";


		tree<int>* second;
		first.delete_item(5, &second);
		ArraySequence<int>* arr = (second)->KLP();
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << arr->Get(i) << " ";
		}
		delete second;
		delete arr;
}