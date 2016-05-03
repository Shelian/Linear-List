#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<iostream>
using namespace std;
#include<assert.h>
typedef int DataType;

class SeqList
{
public:
	SeqList()
		:_array(NULL)
		, _size(0)
		, _capacity(0)
	{}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;
		}
	}
	//传统写法
	/*SeqList(const SeqList& s) //传统写法
		:_array(new DataType[s._size])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		memcpy(_array, s._array, sizeof(DataType)* s._size);
	}*/

	//现代写法
	SeqList(SeqList& s)
		:_array(new DataType[s._size])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		swap(_array, s._array);
	}
	//传统写法
	/*SeqList& operator=(const SeqList& s)
	{
		if (this != &s)
		{
			DataType* tmp = new DataType[s._size];
			delete[] _array;
			_array = tmp;
			_size = s._size;
			_capacity = s._capacity;
			memcpy(tmp, s._array,sizeof(DataType) * _size);
		}

		return *this;
	}*/

	//现代写法
	SeqList& operator=(SeqList s)
	{
		if (this != &s)
		{
			swap(_array, s._array);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		return *this;
	}

	void PushBack(DataType x)
	{
		CheckCapacity();
		_array[_size++] = x;
	}

	void PopBack()
	{
		//1.一个也没有 2.有一个 3.一个或以上
		if (_size > 0)
		{
			--_size;
		}
	}

	void insert(DataType pos,DataType x)
	{
		assert(pos);
		int i = 0;
		++_size;
		for (i = _size; i >= pos; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[pos] = x;
	}

	void find(DataType x)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_array[i] == x)
			{
				cout << "这个数存在下标为：" << i << endl;
				return;
			}
		}
		cout << "这个数不存在！" <<endl;
	}

	void CheckCapacity()
	{
		if (_size >= _capacity)
		{
			_capacity = 2 * _capacity + 3;
			_array = (DataType*)realloc(_array, _capacity*sizeof(DataType));
		}
	}

	void PrintSeqList()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};



void SeqListTest1()
{
	SeqList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	s1.PrintSeqList();

	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	s1.insert(3, 6);
	s1.find(6);

	s1.PrintSeqList();
}

#endif //__SEQLIST_H__