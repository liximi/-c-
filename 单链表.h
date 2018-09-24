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
	node<T>* Node;//��ʱ�ڵ�
	node<T>* lastnode;//ͷ�ڵ�
	node<T>* headnode;//β�ڵ�
public:
	list();//��ʼ��
	~list();
	unsigned int getLength();//����Ԫ�صĸ���
	void add(T x);//��β���Ԫ��
	void traversal();//��������������ӡ
	bool isEmpty();//�ж������Ƿ�Ϊ��
	node<T>* find(T x);//���ҵ�һ��ֵΪx�Ľڵ�,���ؽڵ�ĵ�ַ,�Ҳ�������NULL
	void Delete(T x);//ɾ����һ��ֵΪx�Ľڵ�
	void insert(T x, node<T>* p);//��p�ڵ�����ֵΪx�Ľڵ�
	void insertHead(T x);//�������ͷ������ڵ�
};




template<class T>
list<T>::list()
{
	length = 0;
	Node = NULL;
	lastnode = NULL;
	headnode = NULL;
	cout << "�������ѹ��졣" << endl;
}

template<class T>
list<T>::~list()
{
	cout << "��������ɾ����" << endl;
}

template<class T>
unsigned int list<T>::getLength() {
	return length;
}

template<class T>
void list<T>::add(T x) {
	Node = new node<T>;//����һ���µĽڵ�
	Node->number = x;//�½ڵ㸳ֵΪx
	if (lastnode == NULL)//���û��β�ڵ�������Ϊ��,node��Ϊͷ���,����β�ڵ�
	{
		headnode = Node;
		lastnode = Node;
		++length;//Ԫ�ظ���+1
		cout << "��ӳɹ�" << endl;
	}
	else//�������ǿ�
	{
		if (length < maxLength)
		{
			lastnode->next = Node;//node��Ϊβ�ڵ����һ���ڵ�
			lastnode = Node;//node�����β�ڵ�,��β�ڵ㸳ֵΪnode
			++length;//Ԫ�ظ���+1
			cout << "��ӳɹ�" << endl;
		}
		else cout << "���ʧ�ܣ���������" << endl;
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
		cout << "��" << i + 1 << "������:" << Node->number << endl;
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
			cout << "���ҵ�" << endl;
			return  Node;
		}
		Node = Node->next;
	}
	Node = NULL;
	cout << "δ�ҵ�" << endl;
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
		cout << "ɾ���ɹ�" << endl;
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
			cout << "ɾ���ɹ�" << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "û�ҵ����ֵ" << endl;
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
		cout << "����ɹ�" << endl;
	}
	else cout << "����ʧ�ܣ���������" << endl;
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
		cout << "ͷ�ڵ����ɹ�" << endl;
	}
	else cout << "����ʧ�ܣ���������" << endl;
}