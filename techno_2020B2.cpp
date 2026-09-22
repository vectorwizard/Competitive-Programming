#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k,d;
    cin>>n>>k>>d;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll maxi = 1;
    map<ll,ll> mpp;
    ll r = 0;
    set<ll> st;
    while(r<d){
        mpp[a[r]]++;
        st.insert(a[r]);
        r++;
    }
    maxi = st.size();
    ll l = 0;
    while(r<n){
        mpp[a[r]]++;
        st.insert(a[r]);
        mpp[a[l]]--;
        if(mpp[a[l]]==0) st.erase(a[l]);
        maxi = min(maxi,(ll)st.size());
        l++;
        r++;
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}