#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n;

char s[2][107];
bool vis[2][107];
queue<pair<int,int>> Q;

bool check(int i,int j){
	return i>=0 && i<2 && j>=0 && j<n && s[i][j]=='0' && (!vis[i][j]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<2;i++){
			scanf("%s",s[i]);
		}
		memset(vis,0,sizeof(vis));
		vis[0][0] = 1;
		Q.push(make_pair(0,0));
		while(!Q.empty()){
			pair<int,int> cur = Q.front();
			Q.pop();
			int x = cur.first, y = cur.second;
			for(int i=-1;i<=1;i++){
				for(int j=-1;j<=1;j++){
					if(check(x+i,y+j)){
						vis[x+i][y+j] = 1;
						Q.push(make_pair(x+i,y+j));
					}
				}
			}
		}
		printf("%s\n",vis[1][n-1]?"YES":"NO");
	}	
    return 0;
}
