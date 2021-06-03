#include<bits/stdc++.h>
using namespace std;
const int mi = -1e6;
const int mx = 1e6;
template <typename T>
struct Node {
	T value;
	Node<T> *left = NULL;
	Node<T> *right = NULL;
	Node<T>(T x, Node<T> *left = NULL, Node<T> *right = NULL) : value(x), left(left), right(right) {}
};
template <typename T>
int isB(Node<T>* head) {
	if (head == NULL) {
		return 0;
	}
	int a=isB(head->left);
	int b=isB(head->right);
	if (a == -1 || b == -1)return -1;
	if (abs(a - b) > 1)return -1;
	return max(a+1, b+1);
}
bool isBST(Node<int>* head){
	if (head == NULL)return true;
	bool res = true;
	Node<int> *pre = NULL;
	Node<int> *cur1 = head;
	Node<int> *cur2 = NULL;
	while (cur1 != NULL) {
		cur2 = cur1->left;
		if (cur2 != NULL) {
			while (cur2->right != NULL && cur2->right != cur1)
			{
				cur2 = cur2->right;
			}
			if (cur2->right == NULL) {
				cur2->right = cur1; cur1 = cur1->left;
				continue;
			}
			else {
				cur2->right = NULL;
			}
		}
		if(pre!=NULL&&pre->value>cur1->value){
			res = false;
		}
		pre = cur1;
		cur1 = cur1->right;		
	}
	return res;
}
bool isBST2(Node<int> *head){
	bool start=false;
	int s;
	if (head != NULL) {
		stack<Node<int>*> sk;
		while(head!=NULL||!sk.empty()){
			if (head != NULL) {
				sk.push(head);
				head = head->left;
			}
			else {
				head = sk.top();
				sk.pop();
				if (start) {
					if (head->value < s)return false;
				}
				s = head->value;
				start = true;
				head = head->right;
			}
		}
	}
	return true;
}

bool isCBT(Node<int>* head) {
	bool leaf = false;
	Node<int>* l = NULL;
	Node<int>* r = NULL;
	queue<Node<int>*> que;
	que.push(head);
	while (!que.empty()) {
		head = que.front();
		que.pop();
		l = head->left; r = head->right;
		if ((l != NULL || r != NULL) && leaf||l==NULL&&r!=NULL) {
			return false;
		}
		if (l != NULL)que.push(l);
		if (r != NULL)que.push(r);
		else leaf = true;
	}
	return true;
}

int main()
{
	Node<int> *bt = new Node<int>(4);
	bt->left = new Node<int>(7);
	bt->left->left = new Node<int>(6);
	//bt->right = new Node<int>(7);
	bool c = isCBT(bt);
	cout << c;
	return 0;
}