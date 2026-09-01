// Problem: B - Frog 1
// Contest: Virtual Judge - #Sheet 3 : Dynamic Programming (Recursive)
// URL: https://vjudge.net/contest/694272#problem/B
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

//transitions: ////// if allwed : 	
					// dp[i][c]=dp[i-1]
					// dp[i][c]=dp[i-2]

//base case : if i  ==  1(or 0 if 0-indexed) return 0 
			//, if i == 2 (or 1 if 0-indexed)return abs(c[2]-c1)((assuming 1-indexed))


long long OO = 99999999999999;//to avoid overflow if was added

int dp[100000];//////using 0-index
int n;
vector<int>cost;
int go (int i){
	if(i<0)return OO;//to be ignored when taken min
	if(i==0)return 0;//why zero? because it can reach 1 in 0 cost as it starts there
	if(i==1)return abs(cost[1]-cost[0]);
	if(~dp[i]) return dp[i];
	
	
	int ch1=OO,ch2=OO;//OO to be ignored when taken min
	
	//checking validity (don't forget)
	
	if(i-1>=0)ch1=abs(cost[i-1]-cost[i])+go(i-1);
	if(i-2>=0)ch2=abs(cost[i-2]-cost[i])+go(i-2);
	
	int ans=min(ch1,ch2);
	
	
	return dp[i]=ans;
}


void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	cin>>n;
	cost.resize(n);
	memset(dp,-1,sizeof(dp));
	
	for(auto&c:cost) cin>>c;
	
	cout<<go(n-1);//0-index
	
	
	
	
	//previous thinking :
	//i thought in forward going but it would cost 2d dp 
	//you can use 1d dp only with backward recursion
	
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
