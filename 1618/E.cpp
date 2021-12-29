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
long long b[maxn];
long long a[maxn];
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
			scanf("%lld", &b[i]);
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += b[i];
		}
		bool flag = true;

		if (sum % ((n * n + n) / 2)) {
			printf("NO\n");
			continue;
		}
		sum /= (n * n + n) / 2;
		b[0] = b[n];
		for (int i = 1; i <= n; i++) {
			if ((b[i - 1] - b[i] + sum) % n || (b[i - 1] - b[i] + sum) <= 0) {
				flag = false;
			}
			a[i] = (b[i - 1] - b[i] + sum) / n;
		}
		if (!flag) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for (int i = 1; i <= n; i++) {
				printf("%lld ", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
