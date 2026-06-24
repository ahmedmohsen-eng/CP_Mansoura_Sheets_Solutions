#include<bits/stdc++.h>
using namespace std;
#define int long long

//try to write two times : one with void, and one with int

void solve(int n,vector<int>&v) {
    if(n==1) return void(v.push_back(1));
    
    v.push_back(n);
    
    if(n&1) {
        solve(n*3+1,v);
    } else {
        solve(n/2,v);
    }
    
}


signed main(){
    int n; cin>>n;
    vector<int>v;
    solve(n,v);
    for(auto&x:v)cout<<x<<' ';
}
