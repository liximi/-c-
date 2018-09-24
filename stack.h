#pragma once
#include<iostream>
using namespace std;

template<class L>
struct stackNode
{
	L data;
	stackNode<L>* next;
};

template<class T>
class stack
{
private:
	stackNode<T>* top;
public:
	stack();
	~stack();
	void push(T x);
	void pop();
	bool isEmpty();
	T getTop();
	
};

template <class T>
stack<T>::stack()
{
	top = NULL;
	cout << "stack对象已构建。" << endl;
}

template <class T>
stack<T>::~stack()
{
	stackNode<T>* p = NULL;
	while (top != NULL)
	{
		p = top;
		top = top->next;
		delete p;
	}
	cout << "stack对象已删除。" << endl;
}

template <class T>
void stack<T>::push(T x)
{
	stackNode<T>* p = new stackNode<T>;
	p->data = x;
	p->next = top;
	top = p;
}

template <class T>
void stack<T>::pop()
{
	stackNode<T>* p = top;
	top = top->next;
	delete p;
}

template <class T>
bool stack<T>::isEmpty()
{
	return top == NULL;
}

template <class T>
T stack<T>::getTop()
{
	return top->data;
}
