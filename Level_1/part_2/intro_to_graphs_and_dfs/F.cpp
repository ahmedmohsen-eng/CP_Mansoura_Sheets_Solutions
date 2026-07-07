//problem link : https://vjudge.net/contest/690295#problem/F

#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<int>>adj;
vector<int>vis;

int n,m;
vector<string>maze;


////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int cnt;

void dfs(int x){
    vis[x]=1;
    
    for(int v:adj[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}


void solve(const int&tt){
    //dbg:
    // cerr<<"reached";
    
    cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    int u,v;
    for(int i = 0 ; i < m ;i ++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>ans;
    
    for(int i = 1 ; i <= n ;i++){
        if(!vis[i]){
            dfs(i);
            
            ans.push_back(i);//storing one point at each component
            
        }
    }
    
    cout<<ans.size()-1<<'\n';//exclusing one point because if you have y points then min. road to connect them linear is y-1
    for(int i = 1 /*starting from 1*/ ; i < (int)ans.size() ;i++){
        cout<<ans[i-1]<<' '<<ans[i]<<'\n';
    }
    
}


signed main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve(tt);
    }
    
    
}
