//problem link: https://vjudge.net/contest/690295#problem/B

#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<int>>adj;
vector<int>vis;

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


void solve(const int&tt){
    // to be a tree, it must m=n-1 (edges=nodes-1)  , and number of connected components = 1
    int n,m;cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    for(int i= 1 ; i<=m ; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int con_comps=0;
    for(int i = 1 ; i < n; i++){
        if(!vis[i]){
            con_comps++;
            dfs(i);
        }
    }
    cout<<(n-1==m && con_comps==1?"YES":"NO");
    
}


signed main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve(tt);
    }
    
    
}
