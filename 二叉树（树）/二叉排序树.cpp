#include<bits/stdc++.h>
using namespace std;
struct BStree {
	int value = 0;
	BStree* leftc;
	BStree* rightc;
	BStree() :leftc(NULL), rightc(NULL) {}
	BStree(int a, BStree* left = NULL, BStree* right = NULL) {
		value = a;
		leftc = left;
		rightc = right;
	}
};
BStree*root = new BStree();
void insertBST(int value, BStree* head) {
	if(head==NULL){
		root=new BStree(value);
		return; 
	} 
	BStree *p=NULL;
	while (head != NULL&&value != head->value) {
		p=head;
		if (value > head->value) {
			head = head->rightc;
		}
		else {
			head = head->leftc;
		}
	}
	if(head==NULL){
		if(value>p->value)p->rightc=new BStree(value);
		else p->leftc=new BStree(value);
	}
}
void CreateBST(int* data, int n)
{
	for (int i = 0; i < n; i++) {
		insertBST(data[i], root);
	}
}
bool searchBST(int value, BStree* head) {
	while (head != NULL&&value != head->value) {
		if (value > head->value) {
			head = head->rightc;
		}
		else {
			head = head->leftc;
		}
	}
	if (head != NULL)return true;
	else return false;
}
bool removeBST(int value, BStree* head) {
	while (head != NULL&&value != head->value) {
		if (value > head->value) {
			head = head->rightc;
		}
		else {
			head = head->leftc;
		}
	}
	if (head == NULL)return false;
	if (head->leftc == NULL) {
		*head = *head->rightc;
	}
	else if (head->rightc == NULL) {
		*head = *head->leftc;
	}
	else {	//找前驱或后继结点 这里我们用后继
		BStree *tmp = head;
		head = head->rightc;
		BStree *p;
		while (head->leftc != NULL) {
			p = head;
			head = head->leftc;
		}
		tmp->value = head->value;
		p->leftc = head->rightc;
	}
	return true;
}
int main()
{
	int a[16];
	root = NULL;
	for (int i = 0; i < 15; i++)a[i] = rand() % 15;
	CreateBST(a, 15);
	cout<<searchBST(14,root)<<endl; 
	cout<<searchBST(11,root)<<endl; 
	cout << root->value << endl;
	insertBST(13, root);
	//removeBST(11, root);
	//cout << root->rightc->leftc->value << endl << endl << endl;
	//for (int i = 0; i < 15; i++)cout << a[i] << endl;
	return 0;
}
