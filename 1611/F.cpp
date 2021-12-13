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
long long s;
long long a[maxn];

long long ans;
int ans_l, ans_r;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &s);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		ans = 0;
		ans_l = -1, ans_r = -1;

		int r = -1;
		long long sum = 0;

		for (int l = 1; l <= n; l++) {
			if (r < l) {
				r = l;
				sum = a[l];
			}
			while (r <= n && s + sum >= 0) {
				if (r - l + 1 > ans) {
					ans = r - l + 1;
					ans_l = l;
					ans_r = r;
				}
				r++;
				sum += a[r];
			}
			if (r >= n) {
				break;
			}
			sum -= a[r];
			r--;
			sum -= a[l];
		}
		if (ans == 0) {
			printf("-1\n");
		} else {
			printf("%d %d\n", ans_l, ans_r);
		}
	}
	return 0;
}
