#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
int n, m;
int ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1) {
			ans = 0;
		} else if (min(n, m) == 1) {
			ans = 1;
		} else {
			ans = 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
