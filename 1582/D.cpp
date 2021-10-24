
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;

int T;
int n;
int a[maxn];
int b[maxn];

void solve(int l, int r)
{
	while (l <= r) {
		b[l] = a[r];
		b[r] = -a[l];
		l++;
		r--;
	}
}

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
			scanf("%d", &a[i]);
		}
		int l = 1, r = n;
		if (n & 1) {
			if (a[1] + a[2] != 0) {
				b[1] = a[3];
				b[2] = a[3];
				b[3] = -(a[1] + a[2]);
			} else if (a[2] + a[3] != 0) {
				b[1] = -(a[2] + a[3]);
				b[2] = a[1];
				b[3] = a[1];
			} else if (a[1] + a[3] != 0) {
				b[2] = -(a[1] + a[3]);
				b[1] = a[2];
				b[3] = a[2];
			}
			l = 4;
		}
		solve(l, r);
		for (int i = 1; i <= n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}
