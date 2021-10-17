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

int n, m;
int Q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<string> pic(n);
	for (int i = 0; i < n; i++) {
		cin >> pic[i];
	}

	set<int> s;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (pic[i - 1][j] == 'X' && pic[i][j - 1] == 'X') {
				s.insert(j);
			}
		}
	}

	cin >> Q;
	int l, r;
	while (Q--) {
		cin >> l >> r;
		l--;
		r--;
		auto it = s.upper_bound(l);
		if (it != s.end() && (*it) <= r) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
