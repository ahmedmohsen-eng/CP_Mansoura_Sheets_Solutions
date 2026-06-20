// https://vjudge.net/contest/669349#problem/B

#include<bits/stdc++.h>
using namespace std;
#define int long long
int solve(int n,int step=0){
    if(n==1)return steps+1;
    
    if(n&1) return solve(3*n+1,steps+1);
    else return solve(n/2,steps+1);
    
}
signed main(){
    int n;cin>>n;
    cout<<solve(n);
}
