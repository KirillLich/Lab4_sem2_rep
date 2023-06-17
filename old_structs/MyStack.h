#ifndef MY_STACK
#define MY_STACK
#include "../based_structs/sequence_based/LinkedListSequence.h"

template<class T>
class myStack
{
	LinkedListSequence<T>* stack_items;

public:
	myStack()
	{
		stack_items = new LinkedListSequence<T>;
	}
	myStack(myStack<T> &s)
	{
		stack_items = new LinkedListSequence<T>(*s.stack_items);
	}
	~myStack()
	{
		delete stack_items;
	}
	T take()
	{
		return stack_items->GetLast();
	}
	void push(T item)
	{
		stack_items->Append(item);
	}
	myStack<T>* push_stack(myStack<T> &another_stack)
	{
		LinkedListSequence<T>* out_list = (LinkedListSequence<T>*)stack_items->Concat(another_stack.stack_items);
		myStack<T>* out = new myStack;
		out->stack_items = out_list;
		return out;
	}
	void pop()
	{
		stack_items->DeleteLast();
	}
	
};

#endif