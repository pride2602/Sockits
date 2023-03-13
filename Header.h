#pragma once
#include <iostream>

void join(node* t) // ������� ����� t � t->link
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
void split(node* t, int k) // ��������� ���� t �� k-�� ������� �����
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
