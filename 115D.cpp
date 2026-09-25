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
    map<ll,ll> mppx;
    map<ll,ll> mppy;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        vec[i] = {a,b};
        mppx[a]++;
        mppy[b]++;
    }
    ll total = (n*(n-1)*(n-2))/6;
    for(ll i=0;i<n;i++){
        ll x = vec[i].first;
        ll y = vec[i].second;
        total-=((mppx[x]-1) * (mppy[y]-1));
    }
    cout<<total<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
