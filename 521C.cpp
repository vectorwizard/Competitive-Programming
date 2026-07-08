#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;;
    cin>>n;
    vector<ll> a(n);
    multiset<ll> st;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    } 
    ll total = accumulate(a.begin(),a.end(),0LL);
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        st.erase(st.find(a[i]));
        ll x = *st.rbegin();
        if(x==(total-x-a[i])){
            ans.push_back(i+1);
        }
        st.insert(a[i]);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
