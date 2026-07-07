//problem link : https://vjudge.net/contest/690295#problem/D

#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<int>>adj;
vector<int>vis;

vector<int>deg;


void dfs(int u){
    vis[u]=1;
    deg[u]=adj[u].size();     //degree means connected vertices to it // fix 1 : no -1
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

/*
tutorial translated from russian :
This problem required calculating the degrees of each vertex and finding the answer.
    Note that since n > 4, m > 3, and the graph is connected, the answer is unambiguous.
1) all degrees are 2, and two vertices have degree 1—a bus.
2) all degrees are 2—a ring.
3) all degrees are 1, and one vertex has degree > 2—a star.
4) otherwise unknown.
*/

void solve(const int&tt){
    // to be a tree, it must m=n-1 (edges=nodes-1)  
    int n,m;cin>>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    deg.assign(n+1,0);
    
    for(int i= 1 ; i<=m ; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);//it is a connected graph
    
    
    vector<int>freq(  3+1  ,  0  );  //first value is not important because of 1-index counting
    for(int i = 1 ;i <=n ;i++){
        if(deg[i]==1) freq[1]++;
        else if(deg[i]==2) freq[2]++;
        else freq[3]++;
    }
    
    
    if(freq[1]==2&&freq[3]==0) cout<< "bus"; //any number of 1 is accepted x-x-x-x-x-x-x           x
    else if(freq[1]==0&&freq[3]==0) cout<<"ring"; // any number of 2 is accepted        :        x   x
    else if(freq[2]==0&&freq[3]==1) cout<<"star"; // any number of 1 is accepted                     x
    /////////////////////////////////fix 2 : checking freq not deg
    // star representation: x     x
    //                         x
    //                      x     x
    
    else cout<<"unknown";
    
    
    cout<<" topology\n";
    
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
