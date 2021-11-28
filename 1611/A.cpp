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
char s[maxn];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		if ((s[n - 1] - '0') % 2 == 0) {
			printf("0\n");
			continue;
		}
		if ((s[0] - '0') % 2 == 0) {
			printf("1\n");
			continue;
		}
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if ((s[i] - '0') % 2 == 0) {
				ok = true;
			}
		}
		printf("%d\n", ok ? 2 : -1);
	}
	return 0;
}
