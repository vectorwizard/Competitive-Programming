#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> cost(n,0);
    for(ll i=0;i<n;i++){
        cost[i] = i + 1 + a[i];
    }
    sort(cost.begin(),cost.end());
    for(ll i=1;i<n;i++){
        cost[i] = cost[i-1] + cost[i];
    }
    ll ind = upper_bound(cost.begin(),cost.end(),c)-cost.begin();
    cout<<ind<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
