//problem link: https://vjudge.net/contest/690295#problem/C

#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<int>>adj;
vector<int>vis;

int ans=1;
int cur=1;//1 not zero because minimum is that one person only exists in the group

void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            cur++;
            dfs(v);
        }
    }
}


void solve(const int&tt){
    // to be a tree, it must m=n-1 (edges=nodes-1)  
    int n,m;cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    for(int i= 1 ; i<=m ; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            dfs(i);
            ans=max(ans,cur);
            cur=1;//fix 2 : return to the same value inialized with
        }
    }
    
    cout<<ans<<'\n';
    //fix3: ans is not reset for each test case , so reset it after printed
    ans=1;
}


signed main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int tt=1;
    cin>>tt;
    while(tt--){
        solve(tt);
    }
    
    
}
