#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e1;
//栈
struct Arraystack {
	int a[maxn];
	int index=0;
	void push(const int &x) {
		if (index < maxn)a[index++] = x;
		else cout << "当前栈已满！"<<endl;
	}
	void pop() {
		if (index)index--;
		else cout << "当前栈为空！" << endl;
	}
	int top() {
		if(index)return a[index - 1];
		else cout << "当前栈为空！" << endl;
		return -1;
	}
};
int main()
{
	Arraystack s;
	char cmd[4];
	int y;
	while (scanf_s("%s",cmd,5) == 1) {
		if (cmd[1] == 'u') {
			scanf_s("%d", &y);
			s.push(y);
		}
		if (cmd[1] == 'o' && cmd[0] == 'p')s.pop();
		if (cmd[1] == 'o' && cmd[0] == 't')if(s.top()!=-1)cout << s.top() << endl;
	}
	return 0;
}