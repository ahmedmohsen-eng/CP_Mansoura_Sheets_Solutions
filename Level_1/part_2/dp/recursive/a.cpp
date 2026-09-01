// Problem: A - Knapsack 1
// Contest: Virtual Judge - #Sheet 3 : Dynamic Programming (Recursive)
// URL: https://vjudge.net/contest/694272#problem/A
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

//state : i,cur_w      x not cur_v <<<<<<<<<<<<<<<<<<<<<<<<<<<<

//firstly it is at the first index and with cur_w=0

//choices:
///////////take : dp[i]=dp[i+1]+w[i]    if only it doesn't make total larger than W
											//other wise leave it zero
											///////////^ this is a base case but merged here


///////////leave: dp[i]=dp[i+1]

//then take max of choice 1 and choice 2

//base case : if index is larger than n return 0

int ans=0;//min is not to take anything

struct coin{
	int w,v;
};

int n,w;
vector<coin>vec;

int dp[100][100'000];//if needed +1 for each or +5 or whatever +x as safety

int go(int i,int cur_w){//idx
	if(i>=n)return 0;
	if(~dp[i][cur_w])return dp[i][cur_w];
	
	int ch1=0,ch2=0;
	
	//check is <= not <                               <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	if(cur_w+vec[i].w <= w)ch1=vec[i].v+go(i+1,cur_w+vec[i].w);//increase weight when taken
															//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	ch2=go(i+1,cur_w);
	
	int mx=max(ch1,ch2);
	
	return dp[i][cur_w]=mx;
	
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	memset(dp,-1,sizeof(dp));//not sz,-1 it was reversed    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	
	
	cin>>n>>w;
	
	vec.assign(n,{0,0});
	
	
	for(auto&c:vec){
		cin>>c.w>>c.v;
	}
	
	ans = go(0,0);    ///////////////////store the ans <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	
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
