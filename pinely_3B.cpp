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
    for(ll i=1;i<60;i++){
        ll x = (1LL<<i);
        unordered_set<ll> st;
        for(ll j=0;j<n;j++){
            st.insert(a[j]%x);
        }
        if(st.size()==2){
            cout<<x<<endl;
            return;
        }
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
