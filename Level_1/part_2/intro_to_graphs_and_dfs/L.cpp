// i didn't undertand the logic of problem well because of T cells


//read the problems well

//the biggest mistake before implementation is not understanding logic of T that if you are current on a danger cell then not visit neighbours 


#include<bits/stdc++.h>
using namespace std;


#define int long long






////if 8 directions:
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;
vector<string>maze;
vector<vector<int>>vis;

int gold=0;

void dfs(int x, int y=0){
    
    bool danger=false;
    
    
    if( x>=n|| y>=m || x<0 || y<0 ) return;//fix : you should check bounds validit before checking content and even before vis
    
    //fix : forgetting to see if it was visited
    if(vis[x][y])return;
    
    
    
    if(maze[x][y]=='#') return;
    
    vis[x][y]=1; // put it in that order to avoid marking unnecessary cells as visited when they are '#'
    
    
    
    if(maze[x][y]=='G')gold++;
    
    
    for(int i = 0 ; i < 4 ; i++){
        // we don't need to check validity of bounds because the outer cells are always walls ('#')
        if(maze[x+dx[i]][y+dy[i]]=='T') danger = true;//error , i was writing [y]+dy[i] insated of [y+dy[i]] 
                                                        //,, this can be solved by writing a variable before which is equal to it
    }
    if(!danger){
        for(int i = 0 ; i < 4 ; i++){
            dfs(x+dx[i],y+dy[i]);// fix : don't check if not visited, it is handled by dfs because bounds errors
        }
    }
    
    
    
}


void solve(const int& tt){
    
    
    
    while(cin>>m>>n){//common mistake and its fix : don't write cin>>n>>m; before and now only one time
        
        maze.assign(n,{});
        vis.assign(n,{});
        gold=0;//forgetting resetting gold
        int startx=-1;
        int starty=-1;
        for(int i = 0 ; i < n ;i++){
            cin>>maze[i];
            for(int j = 0 ; j < (int)maze[i].size() ; j++ ){//fix : oop till size of maze[i] not size of maze
                vis[i].push_back(0);
                if(maze[i][j]=='P'){
                    startx=i;
                    starty=j;
                }
            }
        }
        
        
        
        dfs(startx,starty);
        
        cout<<gold<<'\n';
        
        
        
        
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
