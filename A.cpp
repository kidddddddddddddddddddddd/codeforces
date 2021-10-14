#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 20;
const int maxm = 1 << maxn;

int T;
int a, b, c;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &a, &b, &c);
		printf("%d %d %d\n", max(0, max(b, c) + 1 - a), max(0, max(a, c) + 1 - b),
			max(0, max(a, b) + 1 - c));
	}
	return 0;
}
