// https://vjudge.net/contest/669349#problem/A

#include<bits/stdc++.h>
using namespace std;
#define int long long
int solve(int n){
    if(n==0) return 1;
    return n*solve(n-1);
}
signed main(){
    int n;cin>>n;
    cout<<solve(n);
}
