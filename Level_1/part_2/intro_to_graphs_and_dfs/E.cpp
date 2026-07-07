//problem link : https://vjudge.net/contest/690295#problem/E

//learnt and written from ai
//first time to deal with 2d dfs

#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<bool>>vis;

int n,m;
vector<string>maze;


////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};



int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y){
    vis[x][y]=1;
    
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;

        if (maze[nx][ny] == '#')
            continue;

        if (vis[nx][ny])
            continue;

        dfs(nx, ny);
    }
    
}



void solve(const int&tt){
    //dbg:
    // cerr<<"reached";
    
    
    cin>>n>>m;
    maze.assign(n,{});
    vis.assign(n, vector<bool>(m, false));
    
    for(int i= 0 ;i <n ;i++){
        cin>>maze[i];
    }
    
    
    
    int cnt=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout<<cnt;
    
    
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







//also using ai but 1-indexed <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/*



#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<vector<bool>>vis;

int n,m;
vector<string>maze;


////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y){
    vis[x][y]=1;
    
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx <= 0 || nx > n || ny <= 0 || ny > m)
            continue;

        if (maze[nx][ny] == '#')
            continue;

        if (vis[nx][ny])
            continue;

        dfs(nx, ny);
    }
    
}



void solve(const int&tt){
    //dbg:
    // cerr<<"reached";
    
    
    cin>>n>>m;
    maze.assign(n+1,string{});
    vis.assign(n+1, vector<bool>(m+1, false));
    
    for(int i=1  ;i <=n ;i++){
        string s;cin>>s;
        maze[i]=" "+s; //for making the string internally 1-indexed
    }
    
    
    
    int cnt=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    
    cout<<cnt;
    
    
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

*/
