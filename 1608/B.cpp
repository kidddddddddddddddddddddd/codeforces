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

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
int n, a, b;

bool check(vector<int>& res)
{
	if (res.size() != n) {
		return false;
	}
	int tmp_a = 0, tmp_b = 0;
	for (int i = 1; i < n - 1; i++) {
		if (res[i] > res[i - 1] && res[i] > res[i + 1]) {
			tmp_a++;
		}
		if (res[i] < res[i - 1] && res[i] < res[i + 1]) {
			tmp_b++;
		}
	}
	return tmp_a == a && tmp_b == b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &a, &b);
		if (abs(a - b) > 1) {
			printf("-1\n");
			continue;
		}
		vector<int> low, high, res;
		vector<int> ans;
		int p_low = 0, p_high = 0, p_res = 0;

		if (a == b) {
			for (int i = 1; i <= b + 1; i++) {
				low.push_back(i);
			}
			for (int i = b + 2; i <= b + a + 1; i++) {
				high.push_back(i);
			}
			for (int i = b + a + 2; i <= n; i++) {
				res.push_back(i);
			}
			for (int i = 1; i <= a + b + 1; i++) {
				if (i & 1) {
					ans.push_back(low[p_low++]);
				} else {
					ans.push_back(high[p_high++]);
				}
			}
			for (int x : res) {
				ans.push_back(x);
			}
		} else if (a == b + 1) {
			for (int i = 1; i <= b + 1; i++) {
				low.push_back(i);
			}
			for (int i = b + 2; i <= a + b; i++) {
				high.push_back(i);
			}
			for (int i = a + b + 1; i <= n; i++) {
				res.push_back(i);
			}
			for (int i = 1; i <= a + b; i++) {
				if (i & 1) {
					ans.push_back(low[p_low++]);
				} else {
					ans.push_back(high[p_high++]);
				}
			}
			reverse(res.begin(), res.end());
			for (int x : res) {
				ans.push_back(x);
			}
		} else if (b == a + 1) {
			for (int i = 1; i <= b; i++) {
				low.push_back(i);
			}
			for (int i = b + 1; i <= b + a + 1; i++) {
				high.push_back(i);
			}
			for (int i = b + a + 2; i <= n; i++) {
				res.push_back(i);
			}
			for (int i = 1; i <= b + a + 1; i++) {
				if (i & 1) {
					ans.push_back(high[p_high++]);
				} else {
					ans.push_back(low[p_low++]);
				}
			}
			for (int x : res) {
				ans.push_back(x);
			}
		}

		if (check(ans)) {
			for (int x : ans) {
				printf("%d ", x);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
