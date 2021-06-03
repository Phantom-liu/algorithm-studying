#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
vector<int> marr;
class bfprt {
public:
	int BFPRT(vector<int> arr, int begin, int end, int k) {
		if (begin == end)return arr[begin];
		int pivot = medianofmedians(arr, begin, end);
		vector<int> range = partition(arr, begin, end, pivot);
		if (range[1] <= k) {
			return BFPRT(arr, range[1], end, k);
		}
		if (range[0] >= k) {
			return BFPRT(arr, begin, range[0], k);
		}
		else return arr[k];
	}
	int medianofmedians(vector<int>&arr, int begin, int end) {
		vector<int> marr;
		int num = end - begin + 1;
		int offset = num % 5 == 0 ? 0 : 1;
		int len = num / 5 + offset;
		for (int i = 0; i < len; i++) {
			int beginI = begin + 5 * i;
			int endI = beginI + 4;
			sort(arr.begin() + beginI, arr.begin() + min(end, endI)+1);
			marr.push_back(arr[(beginI + min(end, endI)) / 2]);
		}
		return BFPRT(marr, 0, len - 1, len / 2);
	}
	vector<int> partition(vector<int> &arr, int begin, int end, int pivot) {
		int less = begin - 1;
		int more = end + 1;
		int cur = begin;
		while (cur <more) {
			if (arr[cur] > pivot) {
				swap(arr[cur], arr[--more]);
			}
			else if (arr[cur] < pivot) {
				swap(arr[cur++], arr[++less]);
			}
			else {
				cur++;
			}
		}
		vector<int> range = { less,more };
		return range;
	}
};
class BFPRT {
public:
	// 时间复杂度 T(N) = T(N/2) + O(N) = O(N)
	int getMinKthByBFPRT(vector<int> arr, int k, int left, int right) {
		if (arr.empty() || k >= arr.size() || left > right || k < left || k > right) {
			return -1;
		}
		if (left == right) {
			return arr.at(left);
		}
		// 获取每组的中位数组成的数组的中位数(这是BFPTR算法与荷兰国旗问题最大的不同点)
		// 时间复杂度 O(N)
		int pivot = medianOfMedians(arr, left, right);
		// partition过程 <在左，=在中，>在右
		// 时间复杂度 O(N)
		vector<int> range = partition(arr, left, right, pivot);
		// k恰好在 相等的区域内，直接返回
		if (k > range.at(0) && k < range.at(1)) {
			return arr.at(k);
		}
		// 根据k所在的范围继续递归
		return k <= range.at(0) ? getMinKthByBFPRT(arr, k, left, range.at(0)) :
			getMinKthByBFPRT(arr, k, range.at(1), right);
	}

	// partition过程 <在左，=在中，>在右，时间复杂度 O(N)
	vector<int> partition(vector<int>& arr, int left, int right, int pivot) {
		int tmpL = left - 1;
		int tmpR = right + 1;
		int index = left;
		while (index < tmpR) {
			if (arr.at(index) < pivot) {
				swap(arr, index++, ++tmpL);
			}
			else if (arr.at(index) > pivot) {
				swap(arr, index, --tmpR);
			}
			else {
				index++;
			}
		}
		vector<int> res{ tmpL, tmpR };
		return res;
	}
	int medianOfMedians(vector<int>& arr, int left, int right) {
		vector<int> medians;
		int offset = ((right - left + 1) % 5 == 0) ? 0 : 1;
		int groupNums = (right - left + 1) / 5 + offset;
		// 此过程 (N/5) * O(1) = O(N)，(N/5)次5个数(或少于5个)排序O(1)
		for (int i = 0; i < groupNums; i++) {
			int tmpL = left + i * 5;
			int tmpR = tmpL + 5;
			sort(arr.begin() + tmpL, arr.begin() + min(tmpR, right));
			medians.push_back(arr.at(tmpL + ((min(tmpR, right) - tmpL) >> 1)));
		}
		return getMinKthByBFPRT(medians, medians.size() / 2, 0, medians.size() - 1);
	}

	void swap(vector<int>& arr, int n1, int n2) {
		int tmp = arr.at(n1);
		arr.at(n1) = arr.at(n2);
		arr.at(n2) = tmp;
	}
};
int main() {
	int k = 0;
	vector<int> arr;
	for (int i = 0; i < 1e5; i++) {
		arr.push_back(rand() % 100);
	}
	cout << arr[1];
	clock_t start = clock();
	cout << bfprt().BFPRT(arr,0, 1e5-1,3334)<<endl;
	cout << arr[1]<<endl;
	clock_t end = clock();
	cout << end - start <<"ms" <<endl;
	start = clock();
	sort(arr.begin(), arr.end());
	cout << arr[3334] << endl;
	end = clock();
	cout << end - start << "ms"<<endl;

}