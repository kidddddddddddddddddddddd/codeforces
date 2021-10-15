#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n, Q;
int l, r;
char s[maxm];
int pre[2][maxm];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++) {
			pre[0][i] = pre[0][i - 1];
			pre[1][i] = pre[1][i - 1];
			if (s[i] == '[' || s[i] == ']') {
				pre[i & 1][i]++;
			}
		}
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d%d", &l, &r);
			int cnt_0 = pre[0][r] - pre[0][l - 1];
			int cnt_1 = pre[1][r] - pre[1][l - 1];
			printf("%d\n", abs(cnt_0 - cnt_1));
		}
	}
	return 0;
}
