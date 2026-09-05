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
    ll ans = 1;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i+=3){
        ll x = a[i];
        ll y = a[i+1];
        ll z = a[i+2];
        ll mini = min(x,min(y,z));
        ll cnt = 0;
        if(x==mini) cnt++;
        if(y==mini) cnt++;
        if(z==mini) cnt++;
        if(cnt==1) continue;
        else if(cnt==2) ans = (ans*2)%mod;
        else ans = (ans*3)%mod;
    }
    ll y = ncr(n/3,n/6)%mod;
    ans = (ans*y)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
