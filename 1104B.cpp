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
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    set<ll> st;
    for(ll i=0;i<n;i++) st.insert(b[i]);
    vector<ll> c(n);
    bool fl = true;
    for(ll i=0;i<n;i++){
        auto it = lower_bound(st.begin(),st.end(),a[i]);
        if(it==st.end()){
            fl = false;
            break;
        }
        c[i] = *it;
        st.erase(c[i]);
    }
    if(!fl){
        cout<<-1<<endl;
        return;
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(c[j]<c[i]) ans++;
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
