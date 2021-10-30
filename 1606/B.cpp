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

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;

int T;
long long n, k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &n, &k);
		long long cur_n = 1, ans = 0, cur_dif = 1;
		for (int i = 1; i; i++) {
			if (cur_n >= n) {
				break;
			}
			ans++;
			cur_n = min(n, cur_n + cur_dif);
			cur_dif = cur_n;
			if (cur_dif >= k) {
				break;
			}
		}
		ans += (n - cur_n) % k == 0 ? (n - cur_n) / k : (n - cur_n) / k + 1;
		printf("%lld\n", ans);
	}
	return 0;
}
