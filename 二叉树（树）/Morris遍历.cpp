#include<bits/stdc++.h>
using namespace std;
struct BTree
{
	int val;
	BTree *left, *right;
	BTree() :left(NULL), right(NULL){}
};
BTree* create_node(int level, string pos)
{
	int data;
	BTree *node = new BTree;
	int a[] = { 100,99,98,97,0,0,20,0,0,10,0,0,5,1,0,0,2,0,0 };
	static int t = 0;
	cout << "please enter data:level " << level << " " << pos << "--->值为:" << a[t] << endl;
	data = a[t++];
	if (data == 0)
	{
		return NULL;
	}
	node->val = data;
	node->left = create_node(level + 1, "left");
	node->right = create_node(level + 1, "right");
	return node;
}
void morris(BTree* root) {
	if (root == NULL)return;
	BTree* head = new BTree;
	head = root;
	BTree* mostright = new BTree;
	while (head != NULL) {
		if (head->left != NULL) {
			mostright = head->left;
			while (mostright->right != NULL&&mostright->right!=head)mostright = mostright->right;
			if (mostright->right == NULL) {
				mostright->right = head;
				//cout << head->val << "  ";   //前序
				head = head->left;
				continue;
			}
			else {
				mostright->right = NULL;
				//cout << head->val << "  ";  //中序
			}
		}
		else {
			//cout << head->val << "  ";  //前序和中序中没有左孩子的顶点都在此时打印
		}
		head = head->right;
	}
}
int main()
{
	BTree* root = new BTree;
	root = create_node(1, "root");
	morris(root);
}