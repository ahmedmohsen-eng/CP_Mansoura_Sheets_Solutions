// Problem: C - Frog 2
// Contest: Virtual Judge - #Sheet 3 : Dynamic Programming (Recursive)
// URL: https://vjudge.net/contest/694272#problem/C
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

//state : i

//transitions: for loop on j=1 to j=k  (dp[i]=dp[i-j] + abs(cost[i]-cost[j]) )
		///////////////////////////////////////////////// removing j from allowed addtional backward moves

//basecase: if i==1 return 0

//there can be a validity check as the remaining of the base case

long long OO = 999999999999;//to be ignored when min is taken

int dp[100000];//+1 if 1-indexed

vector<int>cost;

int n,k;

//we don't need : 
//k as additional state
//other base cases

//error i made also:
//sometimes i forget using go and instead i use dp directly in both the functino of go and calling the function in main
									//and both are wrong in recursive


int go (int i){
	if(i==0)return 0;
	if(i<0)return OO;
	
	if(~dp[i])return dp[i];
	
	int ans=OO;
	
	for(int cur_k = 1; cur_k <= k; cur_k++){
		
		int choice=OO;
		if(i-cur_k>=0)choice=go(i-cur_k)+abs(cost[i]-cost[i-cur_k]);
		
		ans=min(ans,choice);
		
	}
	
	return dp[i]=ans;
	
}






void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	memset(dp,-1,sizeof(dp));
	
	cin>>n>>k;
	
	cost.resize(n);
	
	for(auto&c:cost)cin>>c;
	
	cout<<go(n-1);//0-indexed
	
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
