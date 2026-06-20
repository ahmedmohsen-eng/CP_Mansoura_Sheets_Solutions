// https://vjudge.net/contest/669349#problem/C

#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=1000000007;

int fast(int n,int m){
    if(m==0) return 1;
    
    
    int ans=fast(n,m/2)%mod;
    ans=(ans*ans)%mod;
    
    if(m&1) ans=(ans*n)%mod;//if power is odd , so when dividing by two you need to multiply in another n
    //for ex:
    // 2  pow  3
    // 2 pow (3/2) * 2 pow (3/2)   ===========>> here you it is rounded in both to 1 : because int x = 3/2; it is stored as int so it is 1
    // so we multiply in another 3
    // so the final answer is : 
    // 2 pow 1 * 2 pow 1 * 2

    // but if it is even it is perfectly divided 
    
    return ans;
    
}

signed main(){
    int n,m;cin>>n>>m;
    cout<<fast(n%mod,m);
}



/*
//tle and stack overflow:
#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=1000000007;

int solve(int n,int m,int step=0,int ans=1){
    if(step==m) return ans ;
    return  solve( n , m ,step+1 ,(ans*n)%mod  );
    
}

signed main(){
    int n,m;cin>>n>>m;
    cout<<solve(n,m);
}
*/




/*
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1000000007;

int power_linear(int a, int b){
    if(b == 0) return 1;

    return (a % mod) * power_linear(a, b - 1) % mod;
}

signed main(){
    long long a, b;
    cin >> a >> b;

    cout << power_linear(a, b);
}








#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1000000007;

int power_fast(int a, long long b){
    if(b == 0) return 1;

    long long half = power_fast(a, b / 2);
    long long res = (half * half) % mod;

    if(b % 2 == 1)
        res = (res * (a % mod)) % mod;

    return res;
}

signed main(){
    long long a, b;
    cin >> a >> b;

    cout << power_fast(a, b);
}


*/
