#include<bits/stdc++.h>
using namespace std;
#define int long long

//try to write two times : one with void, and one with int

int solve(int n) {
    if(n==1) {cout<<1;return 0;}
    
    cout<<n<<' ';
    
    if(n&1) {
        return solve(n*3+1);
    } else {
        return solve(n/2);
    }
    
}


signed main(){
    int n; cin>>n;
    solve(n);
}
