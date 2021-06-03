#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct Node {
	T value;
	Node<T> *left = NULL;
	Node<T> *right = NULL;
	Node<T>(T x, Node<T> *left = NULL, Node<T> *right = NULL) :value(x), left(left), right(right) {}
};
string serialByPre(Node<int> *head) {
	if (head == NULL) {
		return "#_";
	}
	string res = to_string(head->value) + "_";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}

string serialByLevel(Node<int> *head){
	if (head == NULL) {
		return "#_";
	}
	string res = to_string(head->value) + "_";
	queue<Node<int>*> que;
	que.push(head);
	while (!que.empty())
	{
		head = que.front();
		que.pop();
		if (head->left != NULL) {
			res += to_string(head->left->value) + "_";
			que.push(head->left);
		}
		else {
			res += "#_";
		}
		if (head->right != NULL) {
			res += to_string(head->right->value) + "_";
			que.push(head->right);
		}
		else {
			res += "#_";
		}
	}
	return res;
}
vector<string> split(string str, string base) {
	vector<string> res;
	str += base;
	int pos;
	for (int i = 0; i <str.length(); i++) {
		pos = str.find(base, i);
		if (pos < str.length())
		{
			string s = str.substr(i, pos - i);
			res.push_back(s);
			i = pos + base.length() - 1;
		}
	}
	return res;
}

Node<int>* reconpre(queue<string> queue) {
	string value = queue.front();
	queue.pop();
	if (value == "#") {
		return NULL;
	}
	Node<int>* head = new Node<int>(atoi(value.c_str()));
	head->left = reconpre(queue);
	head->right = reconpre(queue);
	return head;
}

Node<int>* reconBypre(string prestr) {
	vector<string> values;
	values = split(prestr, "_");
	queue<string> queue;
	for (int i = 0; i<values.size(); i++)queue.push(values[i]);
	return reconpre(queue);
}
Node<int>* reconByLevel(string prestr) {
	vector<string> values;
	values = split(prestr, "_");
	int index = 0;
	Node<int>* head = new Node<int>(atoi(values[index++].c_str()));
	queue<Node<int>*> que;
	if (head != NULL) {
		que.push(head);
	}
	Node<int>* c = NULL;
	while (!que.empty()) {
		c = que.front();
		que.pop();
		if(values[index]!="#")
		c->left = new Node<int>(atoi(values[index++].c_str()));
		else c->left = NULL;
		if(values[index]!="#")
		c->right = new Node<int>(atoi(values[index++].c_str()));
		else c->right = NULL;
		if (c->left != NULL)que.push(c->left);
		if(c->right!=NULL)que.push(c->right);
	}
	return head;
}
int main()
{
	Node<int> *bt = new Node<int>(5);
	bt->left = new Node<int>(7);
	bt->right = new Node<int>(8);
	string res = serialByPre(bt);
    Node<int> *m = NULL;
	m = reconByLevel (res);
	cout << m->left->value;
	return 0;
}