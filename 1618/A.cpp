#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int b[maxn];

bool check(vector<int>& a)
{
	vector<int> v_a, v_b;
	for (int i = 1; i <= 7; i++) {
		v_b.push_back(b[i]);
	}
	for (int i = 1; i < (1 << 3); i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		v_a.push_back(sum);
	}
	sort(v_a.begin(), v_a.end());
	return v_a == v_b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		for (int i = 1; i <= 7; i++) {
			scanf("%d", &b[i]);
		}
		vector<int> ans;
		ans.push_back(b[1]);
		bool ok = false;
		for (int i = 2; i <= 7; i++) {
			for (int j = i + 1; j <= 7; j++) {
				if (ok) {
					break;
				}
				ans.push_back(b[i] - b[1]);
				ans.push_back(b[j] - b[1]);
				if (check(ans)) {
					ok = true;
					break;
				} else {
					ans.pop_back();
					ans.pop_back();
				}
			}
		}
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
