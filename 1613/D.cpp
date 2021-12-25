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
int n;
long long f[maxn][2];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			f[i][0] = 0;
			f[i][1] = 0;
		}
		f[0][0] = 1;
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			f[x + 1][0] = f[x + 1][0] * 2 % mod;
			f[x + 1][1] = f[x + 1][1] * 2 % mod;
			f[x + 1][0] = (f[x + 1][0] + f[x][0]) % mod;
			if (x) {
				f[x - 1][1] = f[x - 1][1] * 2 % mod;
				f[x - 1][1] = (f[x - 1][1] + f[x - 1][0]) % mod;
			}
		}
		long long res = -1;
		for (int i = 0; i <= n; i++) {
			res = (res + f[i][0] + f[i][1]) % mod;
		}
		printf("%lld\n", res);
	}
	return 0;
}
