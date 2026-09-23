#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;

vector<ll> divisors;

void cal(){
    for(ll i=1;i<=1e6;i++){
        for(ll j=i;j<=1e6;j+=i){
            divisors[j]++;
        }
    }
}


void solve() {
    ll n;
    cin>>n;
    vector<ll> dp(2*n+1);
    for(ll i=2;i<=2*n;i++) dp[i] = divisors[i/2];
    ll pref = dp[2];
    for(ll i=4;i<=2*n;i+=2){
        dp[i]+=pref;
        pref=(pref+dp[i])%mod;
    }
    ll ans = dp[2*n];
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    divisors.assign(1e6+1,0);
    cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
