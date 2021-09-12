#include<bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> arr, int S) {

	unordered_set<int> numSet;
	vector<int> res;

	for (int num : arr) {
		if (numSet.find(S - num) != numSet.end()) {
			res.push_back(num);
			res.push_back(S - num);
			return res;
		}

		numSet.insert(num);
	}

	return res;
}

int main() {

	vector<int> arr{10, 5, 2 , 3, -6, 9, 11};

	int S = 4;

	auto p = pairSum(arr, S);

	if (p.size() != 0) {
		cout << p[0] << "," << p[1] << endl;
	} else {
		cout << "No such pair";
	}
}