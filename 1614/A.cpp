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
int n, l, r, k;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &l, &r, &k);
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] >= l && a[i] <= r) {
				v.push_back(a[i]);
			}
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for (int x : v) {
			if (k >= x) {
				k -= x;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
