#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int T;

long long get(int x) { return 1ll * x * (x + 1) / 2; }

int k;
long long x;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &k, &x);
		long long l = 1, r = 2 * k - 1;
		long long res = 2 * k - 1;
		bool over = false;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (mid >= k) {
				over = (get(k) + get(k - 1) - get(2 * k - 1 - mid)) >= x;
			} else {
				over = get(mid) >= x;
			}
			if (over) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
