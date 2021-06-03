#include<bits/stdc++.h>
using namespace std;
struct Node {
	//bool have_value;
	int value;
	Node* left=NULL;
	Node* right=NULL;
	Node* pre = NULL;
	Node* next = NULL;
	Node(int x) :value(x) {}
};
void preOrdercur(Node* head)
{
	if (head == NULL)return;
	cout << head->value << " ";
	preOrdercur(head->left);
	preOrdercur(head->right);
}
Node* prenode=NULL;
void inOrdercur(Node *head)
{
	if (head == NULL)return;
	preOrdercur(head->left);
	cout << head->value << " ";
	/*head->pre = prenode;
	prenode->next = head;*/
	preOrdercur(head->right);
}
void posOrdercur(Node *head)
{
	if (head == NULL)return;
	preOrdercur(head->left);
	preOrdercur(head->right);
	cout << head->value << " ";
}

int main()
{
	Node *s = new Node(5);
	s->left=new Node(1);
	s->left->right =new Node( 3);
	preOrdercur(s);
	cout << 1;
	return 0;
}