#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    vector<ll> dp(x+1,0);
    for(int ind = n-1;ind>=0;ind--){
        vector<ll> curr(x+1,0);
        for(int wallet = 0;wallet<=x;wallet++){
            ll take = 0,nottake = 0;
            if(prices[ind]<=wallet) take = pages[ind] + dp[wallet-prices[ind]];
            nottake = dp[wallet];
            curr[wallet]=max(take,nottake);
        }
        dp = curr;
    }
    ll ans = dp[x];
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
