#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<ll> fact;

ll power(ll a,ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1) ans = (ans*a)%mod;
    return ans;
}

ll ncr(ll n,ll r){
    ll num = fact[n];
    ll dem1 = fact[r];
    ll dem2 = fact[n-r];
    ll dem = (dem1 * dem2)%mod;
    dem = (power(dem,mod-2))%mod;
    num = (num * dem)%mod;
    return num;
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll cnt = 0;
    ll prev = -1;
    for(ll i=0;i<k;i++){
        if(a[i]==prev) cnt++;
        else{
            cnt = 1;
            prev = a[i];
        }
    }
    ll total = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==prev) total++;
    }
    ll ans = ncr(total,cnt);
    cout<<ans<<endl;
} 
 
int main() {
    fastio();
    fact.assign(1002,0);
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1001;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
