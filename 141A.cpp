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
    unordered_set<ll> st;
    for(ll i=0;i<n;i++) st.insert(a[i]);
    if(st.size()==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    sort(a.rbegin(),a.rend());
    cout<<a[0]<<" "<<a[n-1]<<" ";
    for(int i=1;i<n-1;i++){
        cout<<a[i]<<" ";
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
