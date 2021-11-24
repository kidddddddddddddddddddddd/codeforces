#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 1e9 + 7;

int n;
int m[maxn], k[maxn];
vector<int> idx[maxn];
vector<int> ans_idx;

bool frac_greater(pair<int, int> a, pair<int, int> b)
{
	return a.first * b.second > a.second * b.first;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &m[i], &k[i]);
		idx[m[i]].push_back(i);
	}
	pair<int, int> ans = { 0, 1 };
	for (int i = 1; i <= 20; i++) {
		vector<int> score(maxn);
		for (int j = 1; j <= n; j++) {
			score[m[j]] += min(i, k[j]);
		}
		vector<pair<int, int>> aux;
		for (int j = 0; j < maxn; j++) {
			aux.push_back(make_pair(score[j], j));
		}
		sort(aux.rbegin(), aux.rend());
		pair<int, int> cur_ans = { 0, i };
		vector<int> tmp_ans;
		for (int j = 0; j < i; j++) {
			cur_ans.first += aux[j].first;
			tmp_ans.push_back(aux[j].second);
		}
		if (frac_greater(cur_ans, ans)) {
			ans = cur_ans;
			ans_idx = tmp_ans;
		}
	}
	printf("%d\n", ans_idx.size());
	for (int x : ans_idx) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
