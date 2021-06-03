#include<iostream>
#include<deque>
#include<vector>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
//生成窗口最大值数组
vector<int> getmaxWindow(vector<int> arr, int w) {
	vector<int> res;
	deque<int> qmax;
	if (arr.size() == 0 || arr.size() < w || w < 1) {
		return res;
	}
	for (int i = 0; i < arr.size(); i++) {
		while (!qmax.empty() && arr[i] >= arr[qmax.back()]) {
			qmax.pop_back();
		}
		qmax.push_back(i);
		if (qmax.front() == i - w) {
			qmax.pop_front();
		} 
		if (i > w - 1) {
			res.push_back(arr[qmax.front()]);
		}
	}
	return res;
}
//给定数组arr和num，返回有多少子数组满足其中最大值减最小值小于等于num
int getsum(vector<int> arr, int num)
{
	deque<int> qmax;
	deque<int> qmin;
	int L = 0, R = 0, res = 0;
	while (L < arr.size()) {
		while (R < arr.size()) {
			while (!qmax.empty() && arr[R] >= arr[qmax.back()]) {
				qmax.pop_back();
			}
			qmax.push_back(R);
			while (!qmin.empty() && arr[R] <= arr[qmin.back()]) {
				qmin.pop_back();
			}
			qmin.push_back(R);
			if (arr[qmax.front()] - arr[qmin.front()] > num) {
				break;
			}
			R++;
		}
		if (qmin.front() == L) {
			qmin.pop_front();
		}
		if (qmax.front() == L) {
			qmax.pop_front();
		}
		res += R - L;
		L++;
	}
	return res;
}

int main()
{
	vector<int> a = { 1,5,7,1,5,6,9,72,0,4,6,15 };
	vector<int> res(getmaxWindow(a, 3));
	for (auto z : res)cout << z;
	puts("");
	cout << getsum(a,10);
}