#ifndef __LIST_H__
#define __LIST_H__

#include<iostream>
using namespace std;
#include<assert.h>

typedef int DataType;

struct ListNode
{
	ListNode(DataType x)
	:_data(x)
	, _next(NULL)
	, _prev(NULL)
	{}
	DataType _data;
	ListNode* _next;
	ListNode* _prev;
};

class List
{
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{}

	~List()
	{
		clear();
	}

	List(const List& s)
		:_head(NULL)
		,_tail(NULL)
	{
		ListNode* cur = s._head;
		while (cur)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
		
	}

		//传统写法
	List& operator=(const List& s)
	{
		if (this != &s)
		{
			clear();
			ListNode* cur = s._head;
			while (cur)
			{
				this->PushBack(cur->_data);
				cur = cur->_next;
			}
			
		}
	}

	////现代写法
	//List& operator=(List s)   这种写法不正确，这样前驱指针是没办法处理的
	//{
	//	swap(_head, s._head);
	//	swap(_tail, s._tail);
	//	return *this;
	//}

	void PushBack(DataType x)
	{
		//分析 1.没有一个节点 2.一个节点 3.一个以上节点
	
		if (_head == NULL)
		{
			_head = new ListNode(x);
			_tail = _head;
		}
		else
		{
			ListNode* tmp = new ListNode(x);
			_tail->_next = tmp;
			tmp->_prev= _tail;
			_tail = tmp;
		}
	}

	void PopBack()
	{
		//分析 1.没有节点 2.一个节点 3.一个以上节点

		if (_head == _tail)
		{
			if (_head != NULL)
			{
				delete[] _head;
				_head = NULL;
				_tail = NULL;
			}
		}
		else
		{
			ListNode* cur = _tail->_prev;
			delete[] _tail;
			_tail = cur;
			_tail->_next = NULL;
		}
	}

	void insert(DataType pos,DataType x)
	{
		//分析 1.没有节点 2.一个节点 3.一个以上节点

		assert(pos);
		if (_head == _tail)
		{
			/*if (_head)
			{
				ListNode* tmp = new ListNode(x);
				_tail->_next = tmp;
				_tail = tmp;
				_tail->_prev = _head;
			}
			else*/
			PushBack(x);
		}
		else
		{

			ListNode* cur = _head;
			 while (--pos)
			{
				cur = cur->_next;
			}
			ListNode* next = cur->_next;

			ListNode* tmp = new ListNode(x);
			cur->_next = tmp;
			tmp->_prev = cur;

			next->_prev = tmp;
			tmp->_next = next;
		}
	}

	void clear()
	{
		ListNode* cur = _head;
		while (cur)
		{
			ListNode* del = cur;
			cur = cur->_next;
			delete[] del;
		}
	}

	void PrintList()
	{
		ListNode* cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout << "NULL" << endl;
	}

	void Reserve()
	{
		swap(_head->_data, _tail->_data);
		ListNode* cur = _head;
		ListNode* next = _tail;
		while (cur)
		{
			swap(cur->_next, next->_prev);
			cur = cur->_next;
			next = next->_prev;
		}
	}

private:
	ListNode* _head;
	ListNode* _tail;
};


void ListTest1()
{
	List s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	s1.PrintList();

	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();

	//s1.PrintList();

	s1.insert(3, 10);
	s1.insert(4, 19);
	s1.PrintList();

	s1.Reserve();
	s1.PrintList();

}

#endif //__LIST_H__