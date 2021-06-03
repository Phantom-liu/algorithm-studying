#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct Node {
	T value;
	Node<T> *left = NULL;
	Node<T> *right = NULL;
	Node<T>(T x, Node<T> *left = NULL, Node<T> *right = NULL) : value(x), left(left), right(right) {}
};
template <typename T>
int Nodenum(Node<T> *head) {
	if (head == NULL)return 0;
	return bs(head, 1, mostleftlevel(head, 1));
}
template <typename T>
int bs(Node<T>* head, int l, int h) {
	if (l == h) return 1;
	if (mostleftlevel(head->right, l + 1) == h) {
		return (1 << (h - 1) + bs(head->right, l + 1, h));
	}
	else {
		return (1 << (h - l - 1)) + bs(head->left, l + 1, h);
	}
}
template <typename T>
int mostleftlevel(Node<T>* head, int level) {
	while (head != NULL) {
		level++;
		head = head->left;
	}
	return level - 1;
}

int h = 0;
template <typename T>
int  curcount(Node<T> *head)
{
	if (head == NULL)return h;
	curcount(head->left);
	curcount(head->right);
	return ++h;
}
int main()
{
	Node<int> *bt = new Node<int>(4);
	bt->left = new Node<int>(7);
	bt->left->left = new Node<int>(6);
	int m = curcount(bt);
	cout << m;
	return 0;
}
