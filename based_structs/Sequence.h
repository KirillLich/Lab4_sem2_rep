#ifndef SEQUENCE
#define SEQUENCE

template<class T>
class Sequence
{
	//std::string name;
//protected:
//	void SetName(std::string Name) { name = Name; };
public:
	virtual ~Sequence() {};
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual T Get(int Index) = 0;
	virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) = 0;
	virtual size_t GetLenght() = 0;

	virtual void Append(T Item) = 0;
	virtual void Prepend(T Item) = 0;
	virtual void InsertAt(T Item, int Index) = 0;
	virtual void Set(size_t index, T item) = 0;
};

#endif