#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,w;
    cin>>n>>w;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll ans = 0;
    ll cnt = 1;
    ll curr = 0;
    multiset<ll> st;
    for(ll i=0;i<n;i++){
        if(st.lower_bound(a[i])!=st.end()){
            ll x = *st.lower_bound(a[i]);
            st.erase(st.find(x));
            st.insert(x-a[i]);
        }
        else if(curr+a[i]<=w){
            curr+=a[i];
        }
        else{
            st.insert(w-curr);
            cnt++;  
            curr = a[i];
        }
    }
    cout<<cnt<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
