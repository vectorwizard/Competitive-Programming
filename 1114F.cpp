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
    multiset<ll> st;
    for(ll i=0;i<n;i++) st.insert(a[i]);
    auto it = st.lower_bound(1LL);
    if(it==st.end()){
        cout<<-1<<endl;
        return;
    }
    ll x = *it;
    st.erase(it);
    vector<ll> ans(n);
    ans[0] = x;
    ll total = x;
    for(ll i=1;i<n;i++){
        ll target = 1-total;
        auto it = st.lower_bound(target);
        if(it==st.end()){
            cout<<-1<<endl;
            return;
        }
        ll x = *it;
        total += x;
        ans[i] = total;
        st.erase(it);
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
