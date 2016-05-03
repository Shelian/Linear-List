#ifndef __SLIST_H__
#define __SLIST_H__

#include<iostream>
using namespace std;
#include<assert.h>

typedef int Datatype;

class SListNode
{
	friend class SList;
public:
	SListNode(Datatype x)
		:_data(x)
		, _next(NULL)
	{}

private:
	Datatype _data;
	SListNode* _next;
};

class SList
{
public:
	SList()
		:_head(NULL)
		, _tail(NULL)
	{}


	~SList()
	{
		SListNode* cur = _head;
		while (cur)
		{
			SListNode* del = cur;
			cur = cur->_next;
			delete[] del;
		}
		_head = NULL;
		_tail = NULL;
	}

	SList(const SList& s)
		:_head(NULL)
		, _tail(NULL)
	{
		SListNode* cur = s._head;
		while (cur)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	/*SList& operator=(const SList& s)
	{
		if (this != &s)
		{
			SListNode* cur = _head;
			while (cur)
			{
				SListNode* del = cur;
				delete[] del;
				cur = cur->_next;
			}
			SListNode* cur = s._head;
			while (cur)
			{
				this->PushBack(cur->_data);//没有判断没有节点的情况
				cur = cur->_next;
			}
		}
		return *this;
	}*/
	SList& operator=(SList s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
		return *this;
	}

	void PushBack(Datatype x)
	{
		if (_head == NULL)
		{
			_head = new SListNode(x);
			_tail = _head;
		}
		else
		{
			_tail->_next = new SListNode(x);
			_tail = _tail->_next;
		}
	}

	void PrintSList()
	{
		SListNode* cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout <<"NULL"<<endl;
	}

	void Clear()
	{
		SListNode* cur = _head;
		while (cur)
		{
			SListNode* del = cur;
			cur = cur->_next;
			delete[] del;
		}
		_head = NULL;
		_tail = NULL;
	}

	void PopBack()
	{
		if (_head == NULL)
		{
		}

		else if (_head == _tail)
		{
			delete[] _head;
			_head = NULL;
			_tail = NULL;
		}
		
		else
		{
			SListNode* cur = _head;

			while (cur)
			{
				SListNode* next = cur->_next;
				if (next == _tail)
				{
					delete[] _tail;
					_tail = cur;
					cur->_next = NULL;
					return;
				}
				cur = cur->_next;
			}
		}
	}

private:
	SListNode* _head;  
	SListNode* _tail;
};

void SListTest1()
{
	SList s1;
	s1.PushBack(1); 
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	s1.PrintSList();

	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();

	s1.PrintSList();
}

#endif //_SLIST_H__