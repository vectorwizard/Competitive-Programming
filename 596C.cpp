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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> vis(n,0);
    vector<ll> vec;
    for(ll i=0;i<32;i++){
        vec.push_back(1<<i);
    }
    multiset<ll> ms;
    for(ll i=0;i<n;i++) ms.insert(a[i]);
    for(ll i=0;i<n;i++){
        ms.erase(ms.find(a[i]));
        for(ll j=0;j<vec.size();j++){
            ll t = vec[j] - a[i];
            if(ms.count(t)>0){
                vis[i] = 1;
            }
        }
        ms.insert(a[i]);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(vis[i]==0) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
