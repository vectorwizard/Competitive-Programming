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
    set<int> st;
    for(int i=0;i<=n+1;i++) st.insert(i);
    map<int,int> mpp;
    int l = 0;
    int r = 0;
    while(r<k){
        mpp[a[r]]++;
        st.erase(a[r]);
        r++;
    }
    cout<<*st.begin()<<" ";
    while(r<n){
        mpp[a[r]]++;
        st.erase(a[r]);
        mpp[a[l]]--;
        if(mpp[a[l]]==0) st.insert(a[l]);
        cout<<*st.begin()<<" ";
        r++;
        l++;
    }
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}