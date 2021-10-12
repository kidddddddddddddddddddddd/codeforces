#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 20;
const int maxm = 1 << maxn;

struct BS {
	int balance;
	int lowest_balance;
	vector<int> queryAns;

	pair<int, int> go(int x, bool f)
	{
		if (f) {
			return make_pair(0, true);
		} else {
			return make_pair(x < queryAns.size() ? queryAns[x] : 0,
				x + lowest_balance < 0);
		}
	}

	BS() {};

	BS(string s)
	{
		vector<int> bal;
		int cur = 0;
		int n = s.size();
		for (char c : s) {
			if (c == '(') {
				cur++;
			} else {
				cur--;
			}
			bal.push_back(cur);
		}
		balance = bal.back();
		lowest_balance = min(0, *min_element(bal.begin(), bal.end()));
		vector<vector<int>> neg_pos(-lowest_balance + 1);
		for (int i = 0; i < n; i++) {
			if (bal[i] > 0) {
				continue;
			}
			neg_pos[-bal[i]].push_back(i);
		}
		queryAns.resize(-lowest_balance + 1);
		for (int i = 0; i < queryAns.size(); i++) {
			int last_pos = 1e9;
			if (i != -lowest_balance) {
				last_pos = neg_pos[i + 1][0];
			}
			queryAns[i] = lower_bound(neg_pos[i].begin(), neg_pos[i].end(), last_pos) - neg_pos[i].begin();
		}
	}
};

int n;
int dp[maxm][2];
char buf[maxm];
int total_val[maxm];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &n);
	vector<BS> bs;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		bs.push_back(BS(string(buf)));
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				total_val[i] += bs[j].balance;
			}
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int f = 0; f < 2; f++) {
			dp[i][f] = -1e9;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int f = 0; f < 2; f++) {
			if (dp[i][f] < 0) {
				continue;
			}
			for (int k = 0; k < n; k++) {
				if (i & (1 << k)) {
					continue;
				}
				pair<int, bool> res = bs[k].go(total_val[i], f);
				dp[i ^ (1 << k)][res.second] = max(dp[i ^ (1 << k)][res.second], dp[i][f] + res.first);
			}
		}
	}
	printf("%d\n", max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]));
	return 0;
}
