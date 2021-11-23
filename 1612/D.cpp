#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;
long long a, b, x;

bool judge(long long a, long long b, long long x)
{
	if (a == x || b == x) {
		return true;
	}
	if (a < b) {
		swap(a, b);
	}
	if (b > a - b) {
		b = a - b;
	}
	if (x > max(a, b) || a == 0 || b == 0) {
		return false;
	}
	return judge(a - b * max(1ll, (a - max(x, b)) / (2 * b)), b, x);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld", &a, &b, &x);
		printf("%s\n", judge(a, b, x) ? "YES" : "NO");
	}
	return 0;
}
