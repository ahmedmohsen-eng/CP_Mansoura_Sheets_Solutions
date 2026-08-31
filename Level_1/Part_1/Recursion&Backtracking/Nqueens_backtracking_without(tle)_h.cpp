// Problem: H - N Queens
// Contest: Virtual Judge - Sheet #5 | Recursion and Backtracking
// URL: https://vjudge.net/contest/761024#problem/H
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

bool allowed (point one, point two){
	if(one.x==two.x||one.y==two.y)return false;
	
	//another way for checking the slope(multiplying instead of division)
	if(  abs(one.y-two.y)==abs(one.x-two.x)   )return false;
	
	return true;
}

int n;

vector<point>pos;//positions already put

vector<vector<vector<int>>>ans;


//the optimization is to check row by row not cell by cell
//because you can only keep one by row


//or you can do it by column (both implementations are right)





void backtrack(int row){
	
	//forming the vector if found
	if((int)pos.size()==n){
		vector<vector<int>>board(n,vector<int>(n,0));
		for(auto&p:pos)
			board[p.x][p.y]=1;
		ans.push_back(board);//typo fix board not baord
		return;
	}
	
	
	
	//fixxxxxxxxx
	//don't forget cur. before both x and y
	
	
	for(int col=0;col<n;col++){
		
		point cur={row,col};
		
		bool ok=true;
		for(auto&p:pos){
			if(!allowed(cur,p)){
				ok=false;
				break;
			}
		}
	
		if(ok){
			
			pos.push_back(cur);
			
			backtrack(row+1);//with putting at current
			
			pos.pop_back();
			
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

void solve(int tc){
	// //dbg:
	 // cerr<<"at the test case no."<<tc<<" : \n";
	
	//prohibted locations between two pieces:
	////if absolute slope between them is 1  
		//(don't forget to handle cases when slop is zero to avoid division on zero)
	////or if they are in the same row or column
	
	cin>>n;
	
	backtrack(0);
	
	
	for(auto&v2:ans){
		for(auto&v:v2){
			for(auto&x:v)cout<<(x?'Q':'.');
			cout<<'\n';
		}
		cout<<'\n';
	}
	
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
