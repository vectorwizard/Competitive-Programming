#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<ll> ans(n);
    ll xyxz = a[0][1] * a[0][2];
    ll yz = a[1][2];
    ll x = sqrt(xyxz/yz);
    ans[0] = x;
    xyxz = a[n-1][0] * a[n-1][1];
    yz = a[0][1];
    ans[n-1] = sqrt(xyxz/yz);
    for(ll i=1;i<n-1;i++){
        xyxz = a[i][i-1] * a[i][i+1];
        yz = a[i-1][i+1];
        ans[i] = sqrt(xyxz/yz);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
