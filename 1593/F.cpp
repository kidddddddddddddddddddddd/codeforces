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

const int maxn = 4e5 + 7;
const int maxm = 1e6 + 7;

int T;
int n, A, B;
char s[maxn];
bool dp[41][2][41][41][41]; // i color cnt_a val_a%A val_b%B

struct node {
	int i, c, cnt, a, b;
};

node pre[41][2][41][41][41];

void init()
{
	for (int i = 0; i <= n; i++) {
		for (int c = 0; c < 2; c++) {
			for (int cnt = 0; cnt <= n; cnt++) {
				for (int a = 0; a <= A; a++) {
					for (int b = 0; b <= B; b++) {
						dp[i][c][cnt][a][b] = false;
						pre[i][c][cnt][a][b] = node { 0, 0, 0, 0, 0 };
					}
				}
			}
		}
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
		scanf("%d%d%d", &n, &A, &B);
		scanf("%s", s + 1);
		init();
		dp[1][0][1][(s[1] - '0') % A][0] = true;
		dp[1][1][0][0][(s[1] - '0') % B] = true;
		for (int i = 1; i <= n - 1; i++) {
			int dig = s[i + 1] - '0';
			for (int c = 0; c < 2; c++) {
				for (int cnt = 0; cnt <= i; cnt++) {
					for (int a = 0; a < A; a++) {
						for (int b = 0; b < B; b++) {
							if (!dp[i][c][cnt][a][b]) {
								continue;
							}
							// i+1 to 0
							dp[i + 1][0][cnt + 1][(a * 10 + dig) % A][b] = true;
							pre[i + 1][0][cnt + 1][(a * 10 + dig) % A][b] = node { i, c, cnt, a, b };
							// i+1 to 1
							dp[i + 1][1][cnt][a][(b * 10 + dig) % B] = true;
							pre[i + 1][1][cnt][a][(b * 10 + dig) % B] = node { i, c, cnt, a, b };
						}
					}
				}
			}
		}
		int ans = n;
		node cur;
		for (int c = 0; c < 2; c++) {
			for (int cnt = 1; cnt < n; cnt++) {
				if (dp[n][c][cnt][0][0]) {
					if (abs((n - cnt) - cnt) < ans) {
						cur = node { n, c, cnt, 0, 0 };
						ans = abs((n - cnt) - cnt);
					}
				}
			}
		}
		if (ans == n) {
			printf("-1\n");
			continue;
		}
		vector<int> colors;
		for (int i = n; i >= 1; i--) {
			colors.push_back(cur.c);
			cur = pre[cur.i][cur.c][cur.cnt][cur.a][cur.b];
		}
		reverse(colors.begin(), colors.end());
		for (int x : colors) {
			printf("%c", x == 0 ? 'R' : 'B');
		}
		printf("\n");
	}
	return 0;
}
