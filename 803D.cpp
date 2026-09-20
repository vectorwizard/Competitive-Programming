#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll l,ll r){
    vector<ll> ans(r-l+1);
    cout<<'?'<<" "<<l<<" "<<r<<endl;
    unordered_set<ll> st;
    for(ll i=0;i<(r-l+1);i++){
        cin>>ans[i];
    }
    for(ll i=l;i<=r;i++){
        st.insert(i);
    }
    ll cnt = 0;
    for(ll i=0;i<(r-l+1);i++){
        if(st.count(ans[i])>0) cnt++;
    }
    if(cnt%2==0) return false;
    return true;
}

void solve() {
    ll n;
    cin>>n;
    ll l = 1;
    ll r = n;
    while(l<r){
        ll mid = l+(r-l)/2;
        if(func(l,mid)){
            r = mid;
        }
        else l = mid+1;
    }
    cout<<'!'<<" "<<l<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}