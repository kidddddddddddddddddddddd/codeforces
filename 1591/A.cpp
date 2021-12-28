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
int n;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (i > 1 && a[i] == 0 && a[i - 1] == 0) {
				ans = -1;
				break;
			}
			if (i > 1 && a[i] == 1 && a[i - 1] == 1) {
				ans += 5;
				continue;
			}
			ans += a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
