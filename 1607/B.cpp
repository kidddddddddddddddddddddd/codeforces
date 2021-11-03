#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 3e5 + 7;
const int maxm = 2e6 + 7;

int T;
long long x, n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &x, &n);
		long long diff = 0;
		long long y = (n / 4) * 4;
		if (x & 1) {
			if (y + 1 <= n) {
				diff += y + 1;
			}
			if (y + 2 <= n) {
				diff -= y + 2;
			}
			if (y + 3 <= n) {
				diff -= y + 3;
			}
			if (y + 4 <= n) {
				diff += y + 4;
			}
		} else {
			if (y + 1 <= n) {
				diff -= y + 1;
			}
			if (y + 2 <= n) {
				diff += y + 2;
			}
			if (y + 3 <= n) {
				diff += y + 3;
			}
			if (y + 4 <= n) {
				diff -= y + 4;
			}
		}

		printf("%lld\n", x + diff);
	}
	return 0;
}
