#include<cstdio>
#include<queue>
#include<map>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 1010;
int main()
{
	int t, kase=1;
	while (scanf_s("%d", &t) == 1 && t)
	{
		map<int, int> team;
		printf("Scenario #%d:", kase++);
		for (int i = 0; i < t; i++)
		{
			int n, x;
			scanf_s("%d", &n);
			for (int j = 0; j < n; j++)
			{
				scanf_s("%d", &x);
				team[x] = i;
			}
		}
		queue<int> q, q2[maxn];
		for (;;)
		{
			/*string cmd;
			cin >> cmd;*/
			char cmd[10];
			scanf_s("%s", cmd,10);
			if (cmd[0] == 'S')break;
			else if (cmd[0] == 'D')
			{
				int t = q.front();
				printf("%d", q2[t].front());
				q2[t].pop();
				if (q2[t].empty())q.pop();
			}
			else if (cmd[0] == 'E')
			{
				int ss; scanf_s("%d", &ss);
				int t = team[ss];
				if (q2[t].empty())q.push(t);
				q2[t].push(ss);
			}
		}
		printf("\n");
	}
	return 0;
}