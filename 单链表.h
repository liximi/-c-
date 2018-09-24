#pragma once
#include<iostream>
using namespace std;


template<class S>
struct node
{
	node* next;
	S number;
};


template<class T>
class list
{
private:
	unsigned const int maxLength = 100;
	unsigned int length;
	node<T>* Node;//临时节点
	node<T>* lastnode;//头节点
	node<T>* headnode;//尾节点
public:
	list();//初始化
	~list();
	unsigned int getLength();//链表元素的个数
	void add(T x);//表尾添加元素
	void traversal();//遍历整个链表并打印
	bool isEmpty();//判断链表是否为空
	node<T>* find(T x);//查找第一个值为x的节点,返回节点的地址,找不到返回NULL
	void Delete(T x);//删除第一个值为x的节点
	void insert(T x, node<T>* p);//在p节点后插入值为x的节点
	void insertHead(T x);//在链表的头部插入节点
};




template<class T>
list<T>::list()
{
	length = 0;
	Node = NULL;
	lastnode = NULL;
	headnode = NULL;
	cout << "单链表已构造。" << endl;
}

template<class T>
list<T>::~list()
{
	cout << "单链表已删除。" << endl;
}

template<class T>
unsigned int list<T>::getLength() {
	return length;
}

template<class T>
void list<T>::add(T x) {
	Node = new node<T>;//申请一个新的节点
	Node->number = x;//新节点赋值为x
	if (lastnode == NULL)//如果没有尾节点则链表为空,node既为头结点,又是尾节点
	{
		headnode = Node;
		lastnode = Node;
		++length;//元素个数+1
		cout << "添加成功" << endl;
	}
	else//如果链表非空
	{
		if (length < maxLength)
		{
			lastnode->next = Node;//node既为尾节点的下一个节点
			lastnode = Node;//node变成了尾节点,把尾节点赋值为node
			++length;//元素个数+1
			cout << "添加成功" << endl;
		}
		else cout << "添加失败，链表已满" << endl;
	}
}

template<class T>
void list<T>::traversal() {
	if (length == 0)
	{
		cout << "empty." << endl;
		return;
	}
	Node = headnode;
	for (unsigned int i = 0; i < length; i++)
	{
		cout << "第" << i + 1 << "个数据:" << Node->number << endl;
		Node = Node->next;
	}
	Node = NULL;
}

template<class T>
bool list<T>::isEmpty()
{
	return length == 0;
}

template<class T>
node<T>* list<T>::find(T x)
{
	Node = headnode;
	for (unsigned int i = 0; i < length; i++)
	{
		if (Node->number == x)
		{
			cout << "已找到" << endl;
			return  Node;
		}
		Node = Node->next;
	}
	Node = NULL;
	cout << "未找到" << endl;
	return NULL;
}

template<class T>
void list<T>::Delete(T x) {
	Node = find(x);
	node<T>* temp = headnode;
	if (Node == temp)
	{
		headnode = headnode->next;
		delete Node;
		length--;
		cout << "删除成功" << endl;
		return;
	}
	for (unsigned int i = 0; i < length; i++)
	{
		if (temp->next == Node)
		{
			temp->next = Node->next;
			Node->next = NULL;
			delete Node;
			length--;
			cout << "删除成功" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "没找到这个值" << endl;
	return;
}

template<class T>
void list<T>::insert(T x, node<T>* p)
{
	if (length < maxLength)
	{
		Node = new node<T>;
		Node->number = x;
		Node->next = p->next;
		p->next = Node;
		Node = NULL;
		length++;
		cout << "插入成功" << endl;
	}
	else cout << "插入失败，链表已满" << endl;
}

template<class T>
void list<T>::insertHead(T x)
{
	if (length < maxLength)
	{
		Node = new node<T>;
		Node->number = x;
		Node->next = headnode;
		headnode = Node;
		Node = NULL;
		length++;
		cout << "头节点插入成功" << endl;
	}
	else cout << "插入失败，链表已满" << endl;
}