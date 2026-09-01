// Problem: D - LCS
// Contest: Virtual Judge - #Sheet 3 : Dynamic Programming (Recursive)
// URL: https://vjudge.net/contest/694272#problem/D
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


///state : i,j
		//i is pointer for string s, j is pointer for string t


//transition 
//if(s[i]==t[j])  (return  this : ) dp[i][j]=dp[i+1][j+1]+1;
							//because a match was found
//after checking validity:
	//ch1 = dp[i][j]=dp[i+1][j]
	//ch2 = dp[i][j]=dp[i][j+1]

//base case: if i==n (or n+1 if 1-indexed) return 0 because it exceeded the limit
					//so don't add any new thing to the cur value in the recursion stack

string s,t;
int n,m;//sizes of them (limits of indices)

int dp[3000][3000];//+1 if 1-indexed

int go (int i, int j){
	
	
	if(i>=n||j>=m)return 0;//to be neglected when taking the max
			// and to avoid adding value to the current recusion stack
	if(~dp[i][j])return dp[i][j];
	
	
	///////fix:: don't forget to write here go not dp for going to next
	//////fix::: don't forget to save in the dp before return in all transitions
	/////fixx<<<<<<<t[j] not i <<<<<<<<<<<<<*****
	if(s[i]==t[j]) return dp[i][j]=1+go(i+1,j+1);
	
	
	int ch1=go(i,j+1);
	int ch2=go(i+1,j);
	
	int ans=max(ch1,ch2);
	
	return dp[i][j]=ans;
	
}

string built;

void build(int i,int j){
	
	if(i>=n||j>=m)return ;
	
	if(s[i]==t[j]){
		//////would this add the same charachter many times at different recursion states??
		//answer:
		//it is going in this branch only in each time (it sees which best and goes in it)
		
		built.push_back(s[i]);
		build(i+1,j+1);
		return;
	}
	
	if(go(i+1,j)>go(i,j+1)){///comparing which direction is better
		return build(i+1,j);
	} else {
		return build(i,j+1);
	}
	
	
}


//if two solutions exist (if both ch1 and ch2 is correct):
	//then it takes based on your code:
					//so it take ch2 
		//here i said : if ch1>ch2 take ch1 otherwise (including case of ==):
											//then take ch2 which is(i,j+1) which means:
													//skip charahcter from t
														//because you shifted j by 1

/*
example that apply to the current code logic if there are two answers

if there are 2 right answers for example
let s = ahmedmossshssen
 and t = ahmedmohsensss

then both are correct: ahmedmossss , ahmedmohsen
ahmedmossss appears if ahmedmossshssen comes first
ahmedmohsen apears if ahmedmohsensss comes first


*/

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	//////fix:::::::::::::forgeting memset
	memset(dp,-1,sizeof(dp));
	
	
	cin>>s>>t;
	n=s.size(),m=t.size();
	
	// cout<<go(0,0);
	
	//fix:::::::::::::::::call the build function:
	build(0,0);
	
	cout<<built;
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
