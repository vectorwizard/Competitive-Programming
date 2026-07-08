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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll mini = 0;
    ll curr = 0;
    ll maxi = LLONG_MIN;
    for(ll i=0;i<n;i++){
        curr = curr+a[i];
        maxi = max(maxi,(curr-mini));
        mini = min(mini,curr);
    }
    cout<<maxi<<endl;
}  

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
