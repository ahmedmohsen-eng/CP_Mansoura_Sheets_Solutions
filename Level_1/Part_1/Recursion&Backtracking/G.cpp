// Problem: G - The maximum path-sum
// Contest: Virtual Judge - Sheet #5 | Recursion and Backtracking
// URL: https://vjudge.net/contest/761024#problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

bool multicases_=false;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template<class  T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
#define int long long//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<??
typedef unsigned long long u64;//this or the one  below
#define ull unsigned long long

void pre_compute(){
	
}

struct point{
	int x,y;
};

//initalizing ans with longmin not zero because of negative values
int sm=0,ans=LLONG_MIN,n,m;
vector<vector<int>>grid;

void backtrack(point p){
	
	if(p.x==n-1&&p.y==m-1){
		ans=max(ans,sm);
		return;
	}
	
	//the base case written here in the condition instead of another parameter sum
	if(p.x<n-1){
		sm+=grid[p.x+1][p.y];
		backtrack({p.x+1,p.y});
		sm-=grid[p.x+1][p.y];
	}
	if(p.y<m-1){
		sm+=grid[p.x][p.y+1];
		backtrack({p.x,p.y+1});
		sm-=grid[p.x][p.y+1];
	}
	
	
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	cin>>n>>m;
	grid.assign(n,vector<int>(m,0));
	
	for(auto&v:grid){
		for(auto&x:v){
			cin>>x;
			
			// //dbg
			// cout<<x<<' ';
		}
		
		// //dbg
		// cout<<endl;
	}
	
	sm=grid[0][0];
	backtrack({0,0});
	
	cout<<ans;
	
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	pre_compute();
	
	int tc=1;
	if(multicases_)cin>>tc;
	int total_tcs=tc;
	while(tc--){
		solve(total_tcs-tc);
	}
	return 0;
}
