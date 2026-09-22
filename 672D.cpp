#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
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
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> vec;
    for(ll i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        vec.push_back({l,-1});
        vec.push_back({r,1});
    }
    sort(vec.begin(),vec.end());
    ll ans = 0;
    ll cnt = 0;
    for(ll i=0;i<vec.size();i++){
        ll ind = vec[i].first;
        ll op = vec[i].second;
        if(op==-1) op = 1;
        else op = -1;
        if(op==-1){
            cnt--;
        }
        else{
            cnt++;
            if(cnt>=k){
                ans = (ans+ncr(cnt-1,k-1))%mod;
            }
        }
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
