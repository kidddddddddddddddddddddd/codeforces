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

int n, d;
struct node {
	int s, a;
} climbers[maxm];

bool operator<(node& x, node& y)
{
	return max(x.s, x.a) == max(y.s, y.a) ? x.s < y.s
																				: max(x.s, x.a) < max(y.s, y.a);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &climbers[i].s, &climbers[i].a);
	}
	sort(climbers + 1, climbers + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (climbers[i].s >= d) {
			d = max(d, climbers[i].a);
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
