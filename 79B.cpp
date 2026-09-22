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
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll maxi = 0;
    ll ans = 0;
    vector<ll> pref(n);
    pref[0] = a[0];
    for(ll i=1;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    int ind = upper_bound(pref.begin(),pref.end(),s) - pref.begin();
    ind--;
    if(ind>=0){
        maxi = ind+1;
        ans = 0;
    }
    for(ll i=0;i<n;i++){
        ll sum = pref[i] - a[i];
        if(sum>s) break;
        ll target = s - sum +  pref[i];
        ll ind = upper_bound(pref.begin()+i+1,pref.end(),target) - pref.begin();
        ind--;
        ll take = i + (ind-i);
        if(take>=maxi){
            ans = i+1;
            maxi = take;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
