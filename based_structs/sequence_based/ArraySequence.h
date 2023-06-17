#ifndef ARRAY_SEQUENCE
#define ARRAY_SEQUENCE
#include "..\Sequence.h"
#include "..\DynamicArray.h"

template<class T>
class ArraySequence :public Sequence<T>
{
	DynamicArray<T>* arrayS;
public:
	ArraySequence()
	{
		//this->SetName("DynamicArray");
		arrayS = new DynamicArray<T>(0);
	}
	ArraySequence(T* Items, int count)
	{
		//this->SetName("DynamicArray");
		arrayS = new DynamicArray<T>(Items, count);
	}
	ArraySequence(const ArraySequence<T>& Array)
	{
		//this->SetName("DynamicArray");
		arrayS = new DynamicArray<T>(*Array.arrayS);
	}
	virtual ~ArraySequence()
	{
		delete arrayS;
	}

	T GetFirst()
	{
		return arrayS->Get(0);
	};
	T GetLast()
	{
		return arrayS->Get(arrayS->GetSize()-1);
	};
	T Get(int Index)
	{
		return arrayS->Get(Index);
	};
	void Set(size_t index, T item)
	{
		arrayS->Set(index, item);
	}
	Sequence<T>* GetSubSequence(int startIndex, int endIndex)
	{
		arrayS->Get(startIndex);
		arrayS->Get(endIndex);
		if (startIndex > endIndex)
		{
			int t = startIndex;
			startIndex = endIndex;
			endIndex = t;
		}
		T* items = new T[endIndex - startIndex + 1];
		for (size_t i = startIndex; i < endIndex + 1; i++)
		{
			items[i - startIndex] = arrayS->Get(i);
		}
		ArraySequence<T>* arrOutS = new ArraySequence(items, endIndex - startIndex + 1);
		delete[] items;
		return arrOutS;
	};
	size_t GetLenght()
	{
		return arrayS->GetSize();
	};

	void Append(T Item) 
	{
		arrayS->Resize(arrayS->GetSize() + 1);
		arrayS->Set(arrayS->GetSize() - 1, Item);
	};
	void Prepend(T Item) 
	{
		arrayS->Resize(arrayS->GetSize() + 1);
		for (size_t i = 0; i < arrayS->GetSize() - 1; i++)
		{
			arrayS->Set(arrayS->GetSize() - 1 - i, arrayS->Get(arrayS->GetSize() - 2 - i));
		}
		arrayS->Set(0, Item);
	};
	void InsertAt(T Item, int Index) 
	{
		arrayS->Resize(arrayS->GetSize() + 1);
		for (size_t i = 0; i < arrayS->GetSize() - 1 - Index; i++)
		{
			arrayS->Set(arrayS->GetSize() - 1 - i, arrayS->Get(arrayS->GetSize() - 2 - i));
		}
		arrayS->Set(Index, Item);
	};
};

#endif