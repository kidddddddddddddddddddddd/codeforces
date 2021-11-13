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
const int maxm = 1e6 + 7;
const int mod = 998244353;

int T;
int n;
int a[maxn];
int suf[maxn];

void calc_suffix()
{
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + (a[i] == 0);
	}
}

vector<vector<int>> ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		ans.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			vector<int> idx_0, idx_1;
			calc_suffix();
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					continue;
				}
				if (idx_1.size() + 1 <= suf[i + 1]) {
					idx_1.push_back(i);
				}
			}
			for (int i = n; i >= 1; i--) {
				if (a[i] == 1) {
					continue;
				}
				if (idx_0.size() < idx_1.size() && i > idx_1.back()) {
					idx_0.push_back(i);
				}
			}
			vector<int> tmp;
			for (int i = 0; i < idx_1.size(); i++) {
				tmp.push_back(idx_0[i]);
				tmp.push_back(idx_1[i]);
			}
			sort(tmp.begin(), tmp.end());
			for (int i = 0; i < tmp.size() / 2; i++) {
				swap(a[tmp[i]], a[tmp[tmp.size() - i - 1]]);
			}
			if (tmp.size()) {
				ans.push_back(tmp);
			}
		}
		printf("%d\n", ans.size());
		for (auto it = ans.begin(); it != ans.end(); it++) {
			printf("%d", (*it).size());
			for (int x : (*it)) {
				printf(" %d", x);
			}
			printf("\n");
		}
	}
	return 0;
}
