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
    set<ll> st;
    unordered_map<int,int> mpp;
    for(int i=0;i<=n;i++) st.insert(i);
    for(int i=0;i<k;i++){
        mpp[a[i]]++;
        if(mpp[a[i]]==1) st.erase(a[i]);
    }
    cout<<*st.begin()<<" ";
    ll l = 0;
    for(int r=k;r<n;r++){
        mpp[a[r]]++;
        if(mpp[a[r]]==1) st.erase(a[r]);
        mpp[a[l]]--;
        if(mpp[a[l]]==0) st.insert(a[l]);
        cout<<*st.begin()<<" ";
        l++;
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
