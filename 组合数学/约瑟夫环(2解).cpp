#include<iostream>
using namespace std;
//������ O(nk)
int josephus_linkedlist(int n, int k) {
	struct list {
		int k;
		list *next;
		list(int k):k(k),next(nullptr){}
	};
	list *head = new list(1);
	list *tmp = head;
	for (int i = 2; i <= n; i++) {
		tmp->next = new list(i);
		tmp = tmp->next;
	}
	int cnt = n;
	tmp->next = head;
	tmp = head;
	while (cnt > 1) {
		for (int i = 1; i <= k - 2; i++) {
			tmp = tmp->next;
		}
		list *tmpnxt = tmp->next;
		tmp->next = tmp->next->next;
		delete tmpnxt;
		tmp = tmp->next;
		cnt--;
	}
	return tmp->k;
}
//��ѧ�Ƶ� O(n)
int josephus_mathsolution(int n, int k) {
	int pre, now = 0;	//����Ϊ�˱��ڼ��� ���ǽ�1-nӳ����0-(n-1);
	// ���ǿ�������һ����������µ�һ����Ϸ���������е����now ���������i��ʾ��ǰʣ������:
	//		1.��������һ���е���Ŵ�����һ�����ߵ���ţ�������һ��3�����ˣ�������Ϊ4�ţ�
	//		��ô�������µ�һ���е����Ϊ��һ�����pre-k  (����3��������ôk=4) (pre-k����0��i-k)
	//		2.��������һ���е����С����һ�����ߵ����
	//		��ô�������µ�һ���е����Ϊ��һ�����pre-k+i+1 (��pre-k����-k��-2��Χ�ڵĲ���ӳ����i-k+1��i-1 
	//															��1�еķ�Χ��ͬ����0��i-1��ӳ��)
	//		�ۺϷ����ɵ�now=(pre-k+i+1)%i   �����õ� pre=(now+k-i-1)%(i+1) ȡ��ֵ pre=(now+k)%(i+1);
	for (int i = 1; i <= n - 1; i++) {
		pre = (now + k) % (i + 1);
		now = pre;
	}
	return pre + 1;		//��0-(n-1)ӳ���1-n
}
int main() {
	cout << josephus_mathsolution(10, 3);
	return 0;
}
