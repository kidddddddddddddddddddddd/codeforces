#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n, k;
int x[maxn];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", &x[i]);
		}
		sort(x + 1, x + 1 + k);
		reverse(x + 1, x + 1 + k);
		int ans = 0;
		int cur = 0;
		for (int i = 1; i <= k; i++) {
			if (x[i] <= cur) {
				break;
			}
			ans++;
			int len = n - x[i];
			cur += len;
		}
		printf("%d\n", ans);
	}
	return 0;
}
