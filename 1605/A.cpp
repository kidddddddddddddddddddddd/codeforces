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
const int maxm = 1e6 + 7;
const int mod = 998244353;

int T;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a[1], &a[2], &a[3]);
		int sum = a[1] + a[3] - 2 * a[2];
		int res = (sum % 3 + 3) % 3;
		printf("%d\n", res ? 1 : 0);
	}
	return 0;
}
