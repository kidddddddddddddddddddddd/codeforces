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

int n;
int p[maxn], a[maxn];
int nxt[maxn];

int ask()
{
	printf("? ");
	for (int i = 1; i <= n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

void gen(int pos, int type)
{
	if (type == 1) {
		for (int i = 1; i <= n; i++) {
			if (i == pos) {
				a[i] = 1;
			} else {
				a[i] = 2;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (i == pos) {
				a[i] = 2;
			} else {
				a[i] = 1;
			}
		}
	}
}

void calc(int i)
{
	int ans;
	gen(i, 1);
	ans = ask();
	if (ans != 0 && ans != i) {
		nxt[ans] = i;
	}
	gen(i, 2);
	ans = ask();
	if (ans != 0 && ans != i) {
		nxt[i] = ans;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		calc(i);
	}
	int cur_pos = 0, cur_n = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (nxt[j] == cur_pos) {
				cur_pos = j;
				p[j] = cur_n--;
				break;
			}
		}
	}
	printf("! ");
	for (int i = 1; i <= n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
