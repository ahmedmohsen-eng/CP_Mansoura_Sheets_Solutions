#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n) {
    cout << n << ' ';

    if (n == 1) return 0;//here it is zero because it is (number of steps)
    //, if you want the number of elements make it return 1; not return 0; to count the last element

    if (n & 1)
        return 1 + solve(3 * n + 1);
    else
        return 1 + solve(n / 2);
}

signed main() {
    int n;
    cin >> n;

    int steps = solve(n);
    // you can use steps if required, for example: if it is required to be printed
}
