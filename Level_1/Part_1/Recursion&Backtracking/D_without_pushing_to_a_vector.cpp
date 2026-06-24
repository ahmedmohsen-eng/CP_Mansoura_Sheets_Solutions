#include<bits/stdc++.h>
using namespace std;
#define int long long

//try to write two times : one with void, and one with int

void solve(int n) {
    if(n==1) return void(cout<<1);
    
    cout<<n<<' ';
    
    if(n&1) {
        solve(n*3+1);
    } else {
        solve(n/2);
    }
    
}


signed main(){
    int n; cin>>n;
    solve(n);
}
