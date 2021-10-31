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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if (n % 2 == 0) {
			printf("YES\n");
			continue;
		}
		bool ok = false;
		for (int i = 1; i < n; i++) {
			if (a[i] >= a[i + 1]) {
				ok = true;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
