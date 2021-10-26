#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n;
int a[maxn];
vector<int> pos[32];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i <= 30; i++) {
			pos[i].clear();
		}
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 30; j++) {
				if ((a[i] >> j) & 1) {
					pos[j].push_back(i);
				}
			}
		}
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			bool ok = true;
			for (int j = 0; j <= 30; j++) {
				if (pos[j].size() % i) {
					ok = false;
				}
			}
			if (ok) {
				ans.push_back(i);
			}
		}
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
