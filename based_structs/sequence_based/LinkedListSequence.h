#ifndef LINKED_LIST_SEQUENCE
#define LINKED_LIST_SEQUENCE
#include "..\Sequence.h"
#include "..\LinkedList.h"

template<class T>
class LinkedListSequence :public Sequence<T>
{
	LinkedList<T>* list;
public:
	LinkedListSequence(T* Items, int count)
	{
		//this->SetName("LinkedList");
		list = new LinkedList<T>(Items, count);
	}
	LinkedListSequence()
	{
		//this->SetName("LinkedList");
		list = new LinkedList<T>;
	}
	LinkedListSequence(const LinkedListSequence<T>& List)
	{
		//this->SetName("LinkedList");
		list = new LinkedList<T>(*List.list);
	}
	virtual ~LinkedListSequence()
	{
		delete list;
	}

	T Get(int Index)
	{
		return list->Get(Index);
	}
	T GetFirst()
	{
		return list->GetFirst();
	}
	T GetLast()
	{
		return list->GetLast();
	}
	Sequence<T>* GetSubSequence(int startIndex, int endIndex)
	{
		LinkedListSequence<T>* listSPtr = new LinkedListSequence<T>;
		delete listSPtr->list;
		listSPtr->list = this->list->GetSubList(startIndex, endIndex);
		return listSPtr;
	}
	size_t GetLenght()
	{
		return list->GetLenght();
	}

	void Append(T Item)
	{
		list->Append(Item);
	}
	void Prepend(T Item)
	{
		list->Prepend(Item);
	}
	void InsertAt(T Item, int Index)
	{
		list->InsertAt(Item, Index);
	}
	Sequence<T>* Concat(LinkedListSequence<T>* List)
	{
		LinkedListSequence<T>* listS = new LinkedListSequence<T>;
		delete listS->list;
		listS->list = new LinkedList<T>(this->list->Concat(*List->list));
		return listS;
	}
	void Set(size_t index, T item)
	{
		list->Set(index, item);
	}
	void DeleteLast()
	{
		list->delete_last();
	}
};

#endif 