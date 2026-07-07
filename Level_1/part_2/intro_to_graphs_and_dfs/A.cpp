//problem link : https://vjudge.net/contest/690295#problem/A

#include<bits/stdc++.h>
using namespace std;


#define int long long


vector<vector<int>>adj;
vector<bool>vis; // int if 3 options


vector<int>freq;

void dfs(int u){
    vis[u]=1;
    
    //fix 2 : answer is number of roads so it is degree ,,, not tree length (and if i used tree length and there is edge between two visited before (cycle) so it is not considered)
    freq[u] = adj[u].size(); 
    
    for(auto v : adj[u]){
        if(!vis[v]){
            // freq[u]++; xxxxxxx as mentioned before tree length is not the solution
            // freq[v]++; xxxxxxx as mentioned before tree length is not the solution
            dfs(v);
        }
    }
}

void solve(const int&tt){
    
    int n,m; cin>>n>>m;
    adj.assign(n + 1, {});
    vis.assign(n+1,0);
    
    freq.assign(n+1,0);
    
    for(int i = 0 ; i < m; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//fix 1 : don't forget to add u to v after adding v to u because it is undirected
    }
    
    //fix3 : may be not connected componenets
    for(int i=1 ; i<=n ;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    for(int i = 1 ; i <= n ; i++) cout<<freq[i]<<endl;
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
