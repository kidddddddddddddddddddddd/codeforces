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
char s[maxm];
int pre[3][maxm];

int count(int l, int r, int idx) { return pre[idx][r] - pre[idx][l - 1]; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				pre[j][i] = pre[j][i - 1];
			}
			pre[s[i] - 'a'][i]++;
		}
		int ans = -1;
		for (int len = 2; len <= 10; len++) {
			for (int l = 1; l + len - 1 <= n; l++) {
				int r = l + len - 1;
				if (count(l, r, 0) > count(l, r, 1) && count(l, r, 0) > count(l, r, 2)) {
					ans = len;
					len = 11;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
