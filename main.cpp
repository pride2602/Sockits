#include <iostream>
#include "Header.h"


using namespace std;



struct node // структура для представления узлов дерева
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
int prefix(char* x, int n, char* key, int m) // длина наибольшего общего префикса строк x и key
{
	for (int k = 0; k < n; k++)
		if (k == m || x[k] != key[k])
			return k;
	return n;
}
node* find(node* t, char* x, int n = 0) // поиск ключа x в дереве t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return 0;
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) return find(t->next, x, n); // поищем у сестры
	if (k == n) return t;
	if (k == t->len) return find(t->link, x + k, n - k); // поищем у старшей дочери
	return 0;
}

node* insert(node* t, char* x, int n = 0) // вставка ключа x в дерево t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return new node(x, n);
	int k = prefix(x, n, t->key, t->len);
	if (k == 0) t->next = insert(t->next, x, n);
	else if (k < n)
	{
		if (k < t->len) // режем или нет?
			split(t, k);
		t->link = insert(t->link, x + k, n - k);
	}
	return t;
}

node* remove(node* t, char* x, int n = 0) // удаление ключа x из дерева t
{
	if (!n) n = strlen(x) + 1;
	if (!t) return 0;
	int k = prefix(x, n, t->key, t->len);
	if (k == n) // удаление листа
	{
		node* p = t->next;
		delete t;
		return p;
	}
	if (k == 0) t->next = remove(t->next, x, n);
	else if (k == t->len)
	{
		t->link = remove(t->link, x + k, n - k);
		if (t->link && !t->link->next) // у узла t имеется единственная дочь?
			join(t);
	}
	return t;
}
