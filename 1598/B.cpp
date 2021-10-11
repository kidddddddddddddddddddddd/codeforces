#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

const int maxn = 1e5 + 7;

int T;
int n;
int ok[maxn][7];

int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				scanf("%d",&ok[i][j]);
			}
		}
		bool flag = false;
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=5;j++){
				unordered_map<int,bool> f_map,s_map;
				for(int idx=1;idx<=n;idx++){
					if(ok[idx][i] && (!ok[idx][j])){
						f_map[idx] = 1;
					}
				}
				for(int idx=1;idx<=n;idx++){
					if(ok[idx][i] && f_map.size()<n/2){
						f_map[idx] = 1;
					}
				}
				for(int idx=1;idx<=n;idx++){
					if(ok[idx][j] && (!f_map.count(idx))){
						s_map[idx] = 1;
					}
				}
				if(f_map.size()>=n/2 && s_map.size()>=n/2){
					flag = true;
				}
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}


