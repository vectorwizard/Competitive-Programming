#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
int dp[1000002][2];
void func(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2;i<=1000000;i++){
        dp[i][0] = (dp[i-1][1]+4LL*dp[i-1][0])%mod;
        dp[i][1] = (2LL*dp[i-1][1]+dp[i-1][0])%mod;
    }
}
void solve() {
    func();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans = (dp[n][0]+dp[n][1])%mod;
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
