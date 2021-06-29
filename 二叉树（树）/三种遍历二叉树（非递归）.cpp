#include<bits/stdc++.h>
using namespace std;
template <class T>
struct Node {
	T value;
	Node<T> *left = NULL;
	Node<T> *right = NULL;
	Node(T x, Node<T> *left = NULL, Node<T> *right = NULL) :value(x), left(left), right(right) {}
};
template <class T>
bool operator!=(Node<T> a, Node<T> b) {
	if (a.value == b.value&&a.left == b.left&&a.right == b.right)
		return false;
	else return true;
}
template<class T>
void preOrdercur(Node<T> *head)
{
	if (head != NULL) {
		stack<Node<T>*> stack;
		stack.push(head);
		while (!stack.empty()) {
			head = stack.top();
			cout << head->value << "  ";
			stack.pop();
			if (head->right != NULL) {
				stack.push(head->right);
			}
			if (head->left != NULL) {
				stack.push(head->left);
			}
		}
	}
}
template<class T>
void inOrdercur(Node<T> *head)
{
	if (head != NULL) {
		stack<Node<T>*> stack;
		while (!stack.empty() || head != NULL) {
			if (head != NULL) {
				stack.push(head);
				head = head->left;
			}
			else {
				Node<T> *s = stack.top();
				stack.pop();
				cout << s->value << "  ";
				head = s->left;
			}
		}
	}
}
template<class T>
void posOrdercur2(Node<T> *head)
{
	if (head != NULL) {
		stack<Node<T>*> stack;
		stack.push(head);
		Node<T> *c = NULL;
		while (!stack.empty()) {
			c = stack.top();
			if (c->left != head && c->left != NULL && c->right != head) {
				stack.push(c->left);
			}
			else if (head != c->right&&c->right != NULL) {
				stack.push(c->right);
			}
			else {
				cout << c->value << " ";
				head = stack.top();
				stack.pop();
			}
		}
	}
}
template<class T>
void posOrdercur(Node<T> *head) {
	if (head != NULL) {
		stack<Node<T>*> s1;
		stack<Node<T>*> s2;
		s1.push(head);
		while (!s1.empty()) {
			head = s1.top();
			s1.pop();
			s2.push(head);
			if (head->left != NULL)s1.push(head->left);
			if (head->right != NULL)s1.push(head->right);
		}
		while (!s2.empty()) {
			cout << s2.top()->value << "  ";
			s2.pop();
		}
	}
}

int main()
{
	Node<T> *bt = new Node<T>(5);
	bt->left = new Node<T>(7);
	bt->right = new Node<T>(8);
	posOrdercur2(bt);
	return 0;
}