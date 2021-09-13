#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> triplets(vector<int> v, int S) {

	sort(v.begin(), v.end());

	vector<vector<int>> res;


	for (int i = 0; i < v.size(); i++) {
		int a = v[i];

		int start = i + 1;
		int end = v.size() - 1;
		int rem = S - a;

		while (start < end) {
			int b = v[start];
			int c = v[end];

			if (b + c == rem) {
				res.push_back({a, b, c});
				start++;
				end--;
			} else if (b + c > rem) {
				end--;
			} else {
				start++;
			}
		}

	}

	return res;

}

int main() {
	// vector is not having any duplicate
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

	auto res = triplets(v, S);
	cout << "[";
	for (vector<int> curr : res) {
		cout << "[";
		for (int num : curr) {
			cout << num << ",";
		}
		cout << "]" << endl;
	}
	cout << "]";
}