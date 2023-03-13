#include <iostream>
#include "Header.h"


using namespace std;



struct node // ��������� ��� ������������� ����� ������
{
	char* key;
	int len;
	node* link;
	node* next;
	node(char* x, int n) : len(n), link(0), next(0)
	{
		key = new char[n];
		strncpy(key, x, n);
	}
	~node() { delete[] key; }
};
int prefix(char* x, int n, char* key, int m) // ����� ����������� ������ �������� ����� x � key
{
	for (int k = 0; k < n; k++)
		if (k == m || x[k] != key[k])
			return k;
	return n;
}
node* find(node* t, char* x, int n = 0) // ����� ����� x � ������ t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return 0;
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) return find(t->next, x, n); // ������ � ������
	if (k == n) return t;
	if (k == t->len) return find(t->link, x + k, n - k); // ������ � ������� ������
	return 0;
}

node* insert(node* t, char* x, int n = 0) // ������� ����� x � ������ t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return new node(x, n);
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) t->next = insert(t->next, x, n);
	else if (k < n)
	{
		if (k < t->len) // ����� ��� ���?
			split(t, k);
		t->link = insert(t->link, x + k, n - k);
	}
	return t;
}

node* remove(node* t, char* x, int n = 0) // �������� ����� x �� ������ t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return 0;
	int k = prefix(x, n, t->key, t->len);
	if (k == n) // �������� �����
	{
		node* p = t->next;
		delete t;
		return p;
	}
	if (k == 0) t->next = remove(t->next, x, n);
	else if (k == t->len)
	{
		t->link = remove(t->link, x + k, n - k);
		if (t->link && !t->link->next) // � ���� t ������� ������������ ����?
			join(t);
	}
	return t;
}
