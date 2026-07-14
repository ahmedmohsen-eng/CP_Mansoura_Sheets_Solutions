#include<bits/stdc++.h>
using namespace std;


#define int long long


int n,m;
vector<string>maze;


////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


// (use map to handle input here) ___________________________________________________________________________________________________________
map<int,int>vis;
set<int>nodes;//fix : set not vector to put only one copy of each node
map<int,vector<int>>adj;
map<int,int>in;
void dfs(int node){
    
    vis[node] = 1;

    for (int v : adj[node]) {
        if (!vis[v]) dfs(v);//fixed adj not map<int,.......
    }
    
    
}

//idea is to :
// handle input
// (use map to handle input here)
// check empty graph
// check if there is exactly one root by indegrees
// dfs from the root to mark all children and their children as vis ,, then if there is a node which is not visited so it is not a tree



void solve(const int& tt){
    // handle input ___________________________________________________________________________________________________________
    int tc=0;
    while(true){
        
        //fix: putting it outside the brackets in while ()
        ++tc;
        
        vis.clear();//fix ,, clearing at each test case
        nodes.clear();
        adj.clear();
        in.clear();
        
        //fix : declaring yes and no early
        string yes="Case "+to_string(tc)+" is a tree.\n";
        string no="Case "+to_string(tc)+" is not a tree.\n";
        
        int u,v;
        bool valid=true;
        
        while(cin>>u>>v) {
            if(u<0&&v<0){valid=false;break;}
            else if(u==0&&v==0) break;//breaking directly if invalid
            
            adj[u].emplace_back(v);
            in[v]++;
            nodes.insert(u); nodes.insert(v);
            
        }
        
        if(!valid) break;
        
        //fix : zero graph ___________________________________________________________________________________________________________
        if(adj.size()==0){
            cout<<yes;
            continue;
        }
        
        bool ok = true;
        // check if there is exactly one root by indegrees ___________________________________________________________________________________________________________
        int rote=-1;
        int roots_num=0;
        
        for(auto&x:nodes) {//fix iterate in nodes to iterate over all
            if(!in[x]) roots_num++,rote=x;
            else if(in[x]>1) {ok = false;break;}
        }
        
        if(roots_num!=1){
            cout<<no;
            continue;
        }
        // dfs from the root to mark all children and their children as vis ,, then if there is a node which is not visited so it is not a tree
        dfs(rote);
        
        for(auto&x:nodes){//iterate over nodes not vis, because vis contain only nodes which were vis
            if(!vis[x]){
                ok=false;
                break;
            }
        }
        
        
        
        if(ok){
            cout<<yes;
        } else {
            cout<<no;
        }
        
        
        
        
        
    }
    
    
    //dbg
    // cout<<--tc<<'\n';
    
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
