#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
//try to solve this problem using:
//1-recursion
//2-bitmasks
ll ans=LLONG_MAX;
void solve(int n,vector<int>&v,int i=0 , int sm1=0 , int sm2=0){
    if(i==n){    
        ans=  min(ans,llabs(sm1-sm2));
        return;
    }
    solve(n,v,i+1,sm1+v[i],sm2);
    solve(n,v,i+1,sm1,sm2+v[i]);
    
    
    
}



signed main(){
    
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    int n;cin>>n;
    vector<int>v(n);
    for(auto&x:v)cin>>x;
    solve(n,v);
    cout<<ans;
    
}
