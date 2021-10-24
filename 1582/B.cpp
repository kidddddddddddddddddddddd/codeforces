#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 1e3 + 7;
const int maxm = 2e6 + 7;

int T;
int n;
int a[maxn];

long long poww(long long a, long long b)
{
	long long res = 1, base = a;
	while (b) {
		if (b & 1) {
			res *= base;
		}
		base *= base;
		b >>= 1;
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt += !a[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				ans += poww(2, cnt);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
