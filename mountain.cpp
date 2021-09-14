#include<bits/stdc++.h>
using namespace std;


vector<int> findMountainLength(int peak, vector<int> v) {


	int left = peak - 1;
	int right = peak + 1;

	while (left > 0 && v[left] < v[left + 1]) {

		left--;

	}

	while (right < v.size() - 1 && v[right] < v[right - 1]) {
		right++;
	}

	return {right - left - 1, right};

}

int getMaxLengthMountain(vector<int> v) {

	int res = 0;

	for (int i = 1; i < v.size(); i++) {

		if (i > 0 && i < v.size() - 2 && v[i - 1] < v[i] && v[i + 1] < v[i]) {

			int peak = i;
			vector<int> lenpair = findMountainLength(peak, v);

			int len = lenpair[0];
			res = len > res ? len : res;
			int nextIndex = lenpair[1];
			i = nextIndex - 1;
		}
	}
	return res;
}


int main() {

	vector<int> v{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	int result = getMaxLengthMountain(v);
	cout << result;


}