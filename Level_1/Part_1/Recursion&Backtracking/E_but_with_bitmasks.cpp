#include<bits/stdc++.h>
using namespace std;
#define int long long

//try to solve this problem using:
//1-recursion
//2-bitmasks




signed main(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto&x:v)cin>>x;
    
    int total=accumulate(v.begin(),v.end(),0LL);//0LL to avoid 0 as the intial value which means overflow even after using long long
    
    int ans=LLONG_MAX;//#define int long long must be used 
    
    for(int mask = 0 ; mask < (1<<n) ; mask ++){
        int sm=0;
        for(int i = 0 ; i < n ; i++){
            if(mask&(1<<i)){
                sm+=v[i];
            }
            //now you have your first group : sm
            // second group : total-sm
            //difference = |g2-g1| = |total-sm-sm| 
        }
        ans=min(ans,llabs(total-2*sm));//update outside the nested loop
    }
    cout<<ans;
}
