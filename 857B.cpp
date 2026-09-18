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
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vec[i] = {x,y};
    }
    sort(vec.begin(),vec.end());
    vector<ll> suf(n);
    suf[n-1] = vec[n-1].second;
    for(ll i=n-2;i>=0;i--){
        suf[i] = max(suf[i+1],vec[i].second);
    }
    ll ans = 1e18;
    set<ll> st;
    for(ll i=0;i<n;i++){
        ll maxi = 0;
        ll taken = vec[i].first;
        if(i<n-1){
            maxi = suf[i+1];
            ans = min(ans,abs(maxi-taken));
        }
        auto it = st.lower_bound(taken);
        if(it!=st.end()){
            ll temp = max(maxi,*it);
            ans = min(ans,abs(temp-taken));
        }
        if(it!=st.begin()){
            it = prev(it);
            ll temp = max(maxi,*it);
            ans = min(ans,abs(temp-taken));
        }
        st.insert(vec[i].second);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cal();
    cin>>t;
    while (t--) solve();
    return 0;
}