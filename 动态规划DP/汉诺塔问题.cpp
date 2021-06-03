#include<iostream>
#include<string>
using namespace std;
void process(int N,string from,string to,string help)
{
	if (N == 1) {
		cout << "Move 1 from" << from << "to" << to << endl;
	}
	else {
		process(N - 1, from, help,to);
		cout << "Move "<<N<<" from" << from << "to" << to << endl;
		process(N - 1, help,to, from);
	}
}
int main()
{
	process(3, "×ó", "ÖÐ", "ÓÒ");
	return 0;
}