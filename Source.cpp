#include <iostream>
#define use_CRT_SECURE_NO_WARNIGNS

using namespace std;

struct node // структура для представления узлов дерева
{
	int t;
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

void split(node* t, int k) // разбиение узла t по k-му символу ключа
{
	node* p = new node(t->key + k, t->len - k);
	p->link = t->link;
	t->link = p;
	char* a = new char[k];
	strncpy(a, t->key, k);
	delete[] t->key;
	t->key = a;
	t->len = k;
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
};


void join(node* t) // слияние узлов t и t->link
{
	node* p = t->link;
	char* a = new char[t->len + p->len];
	strncpy(a, t->key, t->len);
	strncpy(a + t->len, p->key, p->len);
	delete[] t->key;
	t->key = a;
	t->len += p->len;
	t->link = p->link;
	delete p;
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
