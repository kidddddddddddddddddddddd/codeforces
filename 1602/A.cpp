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

const int maxn = 2e5 + 7;
const int maxm = 1e6 + 7;

int T;
char s[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		set<char> ss;
		for (int i = 0; i < n; i++) {
			ss.insert(s[i]);
		}
		char c = *ss.begin();
		bool taken = false;
		printf("%c ", c);
		for (int i = 0; i < n; i++) {
			if (s[i] == c && taken == false) {
				taken = true;
				continue;
			} else {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
