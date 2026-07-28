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
    sort(a.begin(),a.end());
    vector<ll> ans(n);
    ans[0] = a[n-1];
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[a[i]]++;
    }
    ll ind = 1;
    mpp[a[n-1]]--;
    for(auto &it:mpp){
        if(it.second==0) continue;
        ans[ind] = it.first;
        it.second--;
        ind++;
    }
    for(auto &it:mpp){
        ll nu = it.first;
        ll cnt = it.second;
        for(ll i=0;i<cnt;i++){
            ans[ind] = nu;
            ind++;
        }
    }
    ll final = 0;
    ll maxi = ans[0];
    set<ll> st;
    for(ll i=0;i<=n;i++){
        st.insert(i);
    }
    for(ll i=0;i<n;i++){
        st.erase(ans[i]);
        final+=(maxi+*st.begin());
    }
    cout<<final<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
