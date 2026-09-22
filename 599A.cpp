#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<ll> fact(1e6+2,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1e6;i++){
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
    vector<ll> div;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);
            if((n/i)!=i) div.push_back(n/i);
        }
    }
    if(div.size()==0){
        cout<<n<<endl;
        return;
    }
    ll ans = div[0];
    for(ll i=1;i<div.size();i++){
        ans = __gcd(ans,div[i]);
    }
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
