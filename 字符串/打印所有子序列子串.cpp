#include<string>
#include<iostream>
using namespace std;
void printallsub(char str[], string res, int i)
{
	if (i == strlen(str)){
		printf("%s\n", res.c_str()); return;
	}
	printallsub(str, res, i + 1);
	printallsub(str, res + str[i], i + 1);
}
void swap(char str[],int p,int q) {
	char s;
	s = str[p];
	str[p] = str[q];
	str[q] = s;
}
void printallrange(char str[], int p, int q)
{
	if (p == q-1) {
		puts(str);
		return;
	}
	for (int i = p+1; i < q; i++) {
		swap(str, p,i);
		printallrange(str, p + 1, q);
		swap(str, p, i);
	}
	printallrange(str, p + 1, q);
}
int main() {
	char str[100];
	string res;
	cin >> str;
	//printallsub(str, res, 0);
	int k = strlen(str);
	printallrange(str, 0, k);
	return 0;
}