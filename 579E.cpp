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
    set<ll> st;
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        if(a[i]>1 && (st.count(a[i]-1)==0)){
            st.insert(a[i]-1);
        }
        else if(st.count(a[i])==0){
            st.insert(a[i]);
        }
        else if(st.count(a[i]+1)==0){
            st.insert(a[i]+1);
        }
    }
    cout<<st.size()<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
