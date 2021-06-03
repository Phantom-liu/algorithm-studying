#include<bits/stdc++.h>
using namespace std;
struct Node {
	int value;
	Node *left=NULL;
	Node *right=NULL;
	Node *parent=NULL;
	Node(int data) :value(data) {}
};
Node* getleft(Node *head) {
	while (head->left!= NULL) {
			head = head->left;
	}
	return head;
}
Node* getnext(Node *head) {
	if (head->right != NULL)return getleft(head->right);
	else {
		while (head->parent != NULL) {
			Node *top = NULL;
			top = head;
			head = head->parent;
			if (top == head->left)return head;
		}
		cout << "blank";
		return NULL;
	}
}

int main(){
	Node *s1 = new Node(5);
	s1->left=new Node(7);
	s1->left->parent = s1;
	s1->right= new Node(3);
	s1->right->parent = s1;
	int m=getnext(s1->right)->value;
	cout << m;
	return 0;

}