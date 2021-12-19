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
const int maxm = 2e7 + 7;
const int mod = 1e9 + 7;

int T;
int n;
long long a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				cnt++;
			}
		}
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= cnt; i++) {
			a[n] <<= 1;
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
