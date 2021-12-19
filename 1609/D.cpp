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
const int mod = 1e9 + 7;

int n, d;
int cnt;
int f[maxn], sum[maxn];

void init()
{
	for (int i = 0; i < maxn; i++) {
		f[i] = i;
		sum[i] = 1;
	}
}

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(int x, int y)
{
	sum[find(y)] += sum[find(x)];
	f[find(x)] = find(y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	init();
	scanf("%d%d", &n, &d);
	for (int i = 1, x, y; i <= d; i++) {
		scanf("%d%d", &x, &y);
		if (find(x) == find(y)) {
			cnt++;
		} else {
			merge(x, y);
		}
		vector<int> v;
		for (int j = 1; j <= n; j++) {
			if (j == find(j)) {
				v.push_back(sum[j]);
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for (int j = 0; j < v.size() && j <= cnt; j++) {
			ans += v[j];
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
