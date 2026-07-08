#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mpp;
    set<pair<ll,ll>> st;
    for(ll i=0;i<k;i++){
        if(mpp.find(a[i])==mpp.end()){
            mpp[a[i]]++;
            st.insert({1,a[i]});
        }
        else{
            mpp[a[i]]++;
            st.erase({mpp[a[i]]-1,a[i]});
            st.insert({mpp[a[i]],a[i]});
        }
    }
    ll highest_freq = st.rbegin()->first;
    auto it = st.lower_bound({highest_freq,0});
    cout<<it->second<<" ";
    ll l = 0;
    for(ll r = k;r<n;r++){
        if(mpp.find(a[r])==mpp.end()){
            mpp[a[r]]++;
            st.insert({1,a[r]});
        }
        else{
            mpp[a[r]]++;
            st.erase({mpp[a[r]]-1,a[r]});
            st.insert({mpp[a[r]],a[r]});
        }
        st.erase({mpp[a[l]],a[l]});
        mpp[a[l]]--;
        if(mpp[a[l]]==0) mpp.erase(a[l]);
        else st.insert({mpp[a[l]],a[l]});
        l++;
        ll highest_freq = st.rbegin()->first;
        auto it = st.lower_bound({highest_freq,0});
        cout<<it->second<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}