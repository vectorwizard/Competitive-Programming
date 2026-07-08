#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        if(s[i]=='*') a[i] = 1;
        else a[i] = 0;
    }
    vector<pair<ll,ll>> prefix(n);
    if(a[0]==1) prefix[0] = {0,1};
    else prefix[0] = {0,0};
    for(ll i=1;i<n;i++){
        if(a[i]==1){
            prefix[i] = {prefix[i-1].first+i,prefix[i-1].second+1};
        }
        else prefix[i] = prefix[i-1];
    }
    vector<pair<ll,ll>> suffix(n);
    if(a[n-1]==1) suffix[n-1] = {n-1,1};
    else suffix[n-1] = {0,0};
    for(ll i=n-2;i>=0;i--){
        if(a[i]==1){
            suffix[i] = {suffix[i+1].first+i,suffix[i+1].second+1};
        }
        else suffix[i] = suffix[i+1];
    }
    ll mini = 1e18;
    for(ll i=0;i<n;i++){
        auto l = prefix[i];
        auto r = (i<n-1) ? suffix[i+1] : make_pair(0LL,0LL);
        ll A = (i-l.second+1);
        ll B = i;
        ll left = (B - A + 1) * (A + B) / 2;
        A = i+1;
        B = (i+r.second);
        ll right = (B - A + 1) * (A + B) / 2;
        ll x = ((left)-l.first);
        ll y = (r.first-(right));
        mini = min(mini,(x+y));
    }
    if(mini == 1e18) mini = 0;
    cout<<mini<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
