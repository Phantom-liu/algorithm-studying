#include<bits/stdc++.h>
using namespace std;
struct BStree {
	int value=0;
	BStree* leftc;
	BStree* rightc;
	BStree():leftc(NULL), rightc(NULL) {}
	BStree(int a,BStree* left=NULL,BStree* right=NULL) {
		value = a;
		leftc = left;
		rightc = right;
	}
};
BStree*root = new BStree();
void insertBST(int value,BStree* &head) {
	if (head == NULL)
	{
		head = new BStree(value);
	}
	else if (value < head->value)
		insertBST(value, head->leftc);
	else
		insertBST(value, head->rightc);
}
void CreateBST(int* data,int n)
{
	for (int i = 0; i < n; i++) {
		insertBST(data[i], root);
	}
}
bool searchBST(int value, BStree* &head) {
	if (head->value == value) {
		return true;
	}
	if (!head->leftc)
		searchBST(value, head->leftc);
	if (!head->rightc)
		searchBST(value, head->rightc);
	return false;
}
//remove未写完
bool removeBST(int value, BStree* &head) {
	if (head->value == value) {
		if (!head->leftc)head = head->leftc;
		else if (!head->rightc)head = head->rightc;
		else delete head;
		return true;
	}
	if (!head->leftc)
		removeBST(value, head->leftc);
	if (!head->rightc)
		removeBST(value, head->rightc);
	return false;
}
int main()
{
	int a[16];
	root = NULL;
	for (int i = 0; i < 15; i++)a[i] = rand() % 15;
	CreateBST(a, 15);
	cout <<root->value<<endl;
	//removeBST(11,root);
	cout << root->value;
	return 0;
}