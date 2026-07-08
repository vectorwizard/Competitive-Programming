#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll dp[5002][5002];
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<n;i++) cin>>a[i];
    for(int ind1=n-1;ind1>=0;ind1--){
        for(int ind2 = ind1;ind2<n;ind2++){
            int turn = n-(ind2-ind1+1);
            if(turn%2==0) turn = 1;
            else turn = 2;
            if(turn==1){
                ll ch1 = a[ind1] + dp[ind1+1][ind2];
                ll ch2 = a[ind2] + dp[ind1][ind2-1];
                dp[ind1][ind2]=max(ch1,ch2);
            }
            else{
                ll ch1 = 0+ dp[ind1+1][ind2];
                ll ch2 = 0+ dp[ind1][ind2-1];
                dp[ind1][ind2]=min(ch1,ch2);
            }
        }
    }
    ll ans = dp[0][n-1];
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
