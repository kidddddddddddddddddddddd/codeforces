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

long long x, y;
string a, b;
set<string> s;

void dfs(string cur)
{
	if (cur.size() >= 100) {
		return;
	}
	while (cur.size() && cur[0] == '0') {
		cur.erase(cur.begin());
	}
	if (s.count(cur) || s.count(b)) {
		return;
	}
	s.insert(cur);
	string s0 = cur;
	reverse(s0.begin(), s0.end());
	dfs(s0);
	string s1 = cur + "1";
	reverse(s1.begin(), s1.end());
	dfs(s1);
}

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	cin >> x >> y;
	while (x) {
		a += '0' + (x & 1);
		x >>= 1;
	}
	while (y) {
		b += '0' + (y & 1);
		y >>= 1;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	dfs(a);
	printf("%s\n", s.count(b) ? "YES" : "NO");
	return 0;
}
