#include<iostream>
#include<string>
using namespace std;
int process(int N,string from,string to,string help)
{
	if (N == 1) {
		return 1;
		//cout << "Move 1 from" << from << "to" << to << endl;
	}
	else {
		//process(N - 1, from, help,to);
		////cout << "Move "<<N<<" from" << from << "to" << to << endl;
		//process(N - 1, help,to, from);
		return process(N - 1, from, help, to) + 1 + process(N - 1, help, to, from);
	}
}
int main()
{
	cout << process("s", "×ó", "ÖÐ", "ÓÒ");
	return 0;
}