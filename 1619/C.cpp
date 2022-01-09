#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e5 + 7;
const int maxm = 2e6 + 7;
const int mod = 998244353;

int T;
long long a, s;

vector<int> part(long long x)
{
	vector<int> res;
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

long long get(long long l, long long r, vector<int>& v)
{
	long long res = 0;
	for (int i = l; i <= r; i++) {
		res = res * 10 + v[i];
	}
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	//  freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &a, &s);
		vector<int> res;

		vector<int> v_a = part(a);
		vector<int> v_s = part(s);

		bool flag = true;
		int p_vs = v_s.size() - 1;

		for (int i = v_a.size() - 1; i >= 0; i--) {
			int cur = v_a[i];
			int dig = v_s[p_vs];
			int r = p_vs;
			while (cur > dig && p_vs >= 1) {
				dig = get(p_vs - 1, r, v_s);
				p_vs--;
			}
			p_vs--;
			if (cur > dig || dig - cur > 9) {
				flag = false;
				break;
			}
			res.push_back(dig - cur);
		}
		while (p_vs >= 0) {
			res.push_back(v_s[p_vs--]);
		}

		reverse(res.begin(), res.end());
		while (res.size() > 1 && res[0] == 0) {
			res.erase(res.begin());
		}
		if (!flag) {
			printf("-1\n");
		} else {
			for (int x : res) {
				printf("%d", x);
			}
			printf("\n");
		}
	}
	return 0;
}
