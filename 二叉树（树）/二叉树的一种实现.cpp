#include<iostream>
#include<queue>
#include<list>
#include<stack>
#include<unordered_map>
using namespace std;
template <class T>
struct Node {		//���Ľ��
	T value;
	int level;		//������ڲ��� ���߶� ��0��ʼ
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	Node(T x = 0, int l = 0) :value(x), level(l), left(nullptr), right(nullptr) {}
};
template <class T>
class BinaryTree {
public:
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	void levelOrder() { levelOrder(root); }
	int getLeaves() { return leaves; }
	int getsize() { return size; }
	int getwide() { return wide; }
	void clear() { clear(root); }
	void getroad(T to) { getroad(root, to); }
	bool insert(T d, T f = 0, int pos = 0) { return insert(root, d, f, pos); }		//����dΪ����f�ĺ��� 0��ʾ���� 1��ʾ�Һ���
	BinaryTree() :size(0), wide(0), height(-1), leaves(0), root(nullptr) {}
	~BinaryTree() { destroy(root); }
private:
	void clear(Node<T> *head);		//����������ʼ��Ϊ�����ݵ����
	void destroy(Node<T> *head);		//ɾ��������
	void preOrder(Node<T> *head);
	void inOrder(Node<T> *head);
	void postOrder(Node<T> *head);
	void postOrder2(Node<T> *head);		//���ַǵݹ��ʵ�ַ�ʽ
	void levelOrder(Node<T> *head);
	void getroad(Node<T> *head, T to);
	bool insert(Node<T> *head, T d, T f, int pos);
	int size;		//������
	int wide;		//���Ŀ�ȣ�����Ϊ���Ͻ��������һ���еĽ��������
	int height;		//���߶� 1�������Ϊ�߶�Ϊ0	����Ĭ�ϼ�һ��
	int leaves;		//Ҷ��
	Node<T> *root;
	list<Node<T>*> node_notfull;		//�洢���ܳ�Ϊ��������ĸ��׽���һ������
	vector<int> w;		//w[i]��ʾ�߶�Ϊi�Ľ�����
};
template <class T>
void BinaryTree<T>::clear(Node<T> *head) {
	if (head == nullptr) {
		return;
	}
	size = wide = height = 0;
	root = nullptr;
	node_notfull.clear();
	w.clear();
	destroy(head);
}
template <class T>
void BinaryTree<T>::destroy(Node<T> *head) {
	if (head == nullptr) {
		return;
	}
	destroy(head->left);
	destroy(head->right);
	delete head;
}
template<class T>
void BinaryTree<T>::preOrder(Node<T> *head)
{
	if (head != nullptr) {
		stack<Node<T>*> stack;
		stack.push(head);
		while (!stack.empty()) {
			head = stack.top();
			cout << head->value << "  ";
			stack.pop();
			if (head->right != nullptr) {
				stack.push(head->right);
			}
			if (head->left != nullptr) {
				stack.push(head->left);
			}
		}
	}
}
template<class T>
void BinaryTree<T>::inOrder(Node<T> *head)
{
	if (head != nullptr) {
		stack<Node<T>*> stack;
		while (!stack.empty() || head != nullptr) {
			if (head != nullptr) {
				stack.push(head);
				head = head->left;
			}
			else {
				Node<T> *s = stack.top();
				stack.pop();
				cout << s->value << "  ";
				head = s->right;
			}
		}
	}
	cout << endl;
}
template<class T>
void BinaryTree<T>::postOrder2(Node<T> *head)
{
	if (head != nullptr) {
		stack<Node<T>*> stack;
		stack.push(head);
		Node<T> *c = nullptr;
		while (!stack.empty()) {
			c = stack.top();
			if (c->left != head && c->left != nullptr && c->right != head) {
				stack.push(c->left);
			}
			else if (head != c->right&&c->right != nullptr) {
				stack.push(c->right);
			}
			else {
				cout << c->value << " ";
				head = stack.top();
				stack.pop();
			}
		}
	}
	cout << endl;
}
template<class T>
void BinaryTree<T>::postOrder(Node<T> *head) {
	if (head != nullptr) {
		stack<Node<T>*> s1;
		stack<Node<T>*> s2;
		s1.push(head);
		while (!s1.empty()) {
			head = s1.top();
			s1.pop();
			s2.push(head);
			if (head->left != nullptr)s1.push(head->left);
			if (head->right != nullptr)s1.push(head->right);
		}
		while (!s2.empty()) {
			cout << s2.top()->value << "  ";
			s2.pop();
		}
	}
	cout << endl;
}
template<class T>
void BinaryTree<T>::levelOrder(Node<T> *head) {
	if (head == nullptr) {
		return;
	}
	//bfsʵ��
	queue<Node<T>*> q;
	q.push(head);
	while (!q.empty()) {
		Node<T> *cur = q.front();
		cout << cur->value << " ";
		q.pop();
		if (cur->left) {
			q.push(cur->left);
		}
		if (cur->right) {
			q.push(cur->right);
		}
	}
	cout << endl;
}
template<class T>
void BinaryTree<T>::getroad(Node<T> *head, T to) {
	if (head == nullptr) {
		cout << "Please Build The TREE!" << endl;
		return;
	}
	//�����Թ���Ϸ
	unordered_map<Node<T>*, Node<T>*> mark;   //��¼·��
	queue<Node<T>*> q;
	q.push(head);
	Node<T> *now = nullptr;
	while (!q.empty()) {
		now = q.front();
		if (now->value == to) {
			break;
		}
		q.pop();
		if (now->left) {
			q.push(now->left);
			mark[now->left] = now;
		}
		if (now->right) {
			q.push(now->right);
			mark[now->right] = now;
		}
	}
	if (!q.empty()) {
		stack<Node<T>*> s;
		Node<T>* tmp = now;
		while (tmp != root) {
			s.push(tmp);		//Ϊ��������� ����ʹ��ջ
			tmp = mark[tmp];
		}
		s.push(root);
		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			cout << tmp->value << " ";
			if (s.empty()) {
				break;
			}
			if (tmp->left == s.top()) {
				cout << "go left" << endl;
			}
			else {
				cout << "go right" << endl;
			}
		}
		cout << "  Arrived!" << endl;
	}
	else {
		cout << "No Such Node!" << endl;
	}
}
template<class T>
bool BinaryTree<T>::insert(Node<T> *head, T d, T f, int pos) {
	if (head == nullptr) {
		root = new Node<T>(d, 0);
		node_notfull.push_back(root);
		size++;
		height++;
		w.push_back(0);
		w[height]++;
		wide = max(wide, w[height]);
		leaves++;
		return true;
	}
	for (Node<T>* z : node_notfull) {
		if (z->value == f) {
			if (pos == 0) {
				z->left = new Node<T>(d, z->level + 1);
				node_notfull.push_back(z->left);
			}
			else {
				z->right = new Node<T>(d, z->level + 1);
				node_notfull.push_back(z->right);
			}
			if (z->left&&z->right) {
				node_notfull.remove(z);
			}
			else {
				leaves++;
			}
			size++;
			if (z->level == height) {
				height++;
				w.push_back(0);
			}
			w[height]++;
			wide = max(wide, w[height]);
			return true;
		}
	}
	return false;
}
//�ݹ鷽���ı���
/*
void preOrder(Node* head)
{
	if (head == nullptr)return;
	cout << head->value << " ";
	preOrder(head->left);
	preOrder(head->right);
}
Node* prenode=nullptr;
void inOrder(Node *head)
{
	if (head == nullptr)return;
	preOrder(head->left);
	cout << head->value << " ";
	preOrder(head->right);
}
void postOrder(Node *head)
{
	if (head == nullptr)return;
	preOrder(head->left);
	preOrder(head->right);
	cout << head->value << " ";
}
*/
BinaryTree<int> lzz;
void showmenu() {
	cout << "1.�����������洢�ṹ" << endl
		<< "2.�������������������У��ݹ顢�ǵݹ飩" << endl
		<< "3.�������������������У��ݹ顢�ǵݹ飩" << endl
		<< "4.��������ĺ����������" << endl
		<< "5.��������Ĳ����������" << endl
		<< "6.��������Ŀ�ȡ���Ϊ1�Ľ��ĸ���" << endl
		<< "7.�����㵽ָ������·��" << endl
		<< "0.�˳�" << endl << "9.����" << endl;
}
void read() {
	cout << "��������,��ʽ���£������֮ǰ�����룩��" << endl <<
		"d f 0	����dΪ����f�ĺ��� 0��ʾ�� 1��ʾ��(��һ������Ĭ��Ϊ����� ֻ������d)" << endl
		<< "����0 0 0��ʾ�������" << endl;
	lzz.clear();
	int d, f, pos;
	cin >> d;
	lzz.insert(d);
	while (cin >> d >> f >> pos) {
		if (d == 0 && f == 0) {
			break;
		}
		if (!lzz.insert(d, f, pos)) {
			cout << "�������� ���������" << endl;
		}
	}
	cout << "������ϣ�" << endl;
}
void printTraverse(int k) {
	cout << "�������£�" << endl;
	switch (k) {
	case 2:lzz.preOrder(); break;
	case 3:lzz.inOrder(); break;
	case 4:lzz.postOrder(); break;
	case 5:lzz.levelOrder(); break;
	}
}
void getWideAndLeaves() {
	cout << "���Ϊ��" << lzz.getwide() << "     " << "��Ϊ1�Ľ��ĸ���Ϊ:" << lzz.getLeaves() << endl;
}
void getThePath() {
	int to;
	cout << "����Ŀ�����ֵ" << endl;
	cin >> to;
	lzz.getroad(to);
}
int main()
{
	showmenu();
	int n;
	while (cin >> n) {
		bool exit = false;
		switch (n) {
		case 1:read(); break;
		case 5:printTraverse(5); break;
		case 6:getWideAndLeaves(); break;
		case 7:getThePath(); break;
		case 0:exit = true; break;
		case 9:system("CLS"), showmenu(); break;
		default: {
			if (n >= 2 && n <= 5) {
				printTraverse(n);
			}
			else {
				cout << "����������ָ�" << endl;
			}
		}
		}
		if (exit)break;
		cout << endl;
		system("pause");
	}
	cout << "�ټ���" << endl;
	system("pause");
	return 0;
}
