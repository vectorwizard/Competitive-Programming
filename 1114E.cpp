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
    vector<ll>b(n);
    for(ll i=0;i<n;i++) cin>>b[i];
    map<ll,ll> mpp;
    map<ll,ll> ans;
    for(ll i=0;i<n;i++) mpp[b[i]]++;
    auto it = mpp.begin();
    if(it->first!=0){
        cout<<-1<<endl;
        return;
    }
    ll prev_cnt = it->second;
    ll prev_val = it->first;
    ll total = 0;
    ll maxi = 0;
    mpp.erase(it);
    for(auto it:mpp){
        ll num = it.first;
        ll freq = it.second;
        ll req = num - total;
        if(req%prev_cnt!=0){
            cout<<-1<<endl;
            return;
        }
        ll x = req/prev_cnt;
        if(x<=maxi){
            cout<<-1<<endl;
            return;
        }
        maxi = x;
        ans[prev_val] = x;
        total=num;
        prev_val = num;
        prev_cnt = freq;
    }
    ans[prev_val] = maxi+1;
    for(ll i=0;i<n;i++){
        cout<<ans[b[i]]<<" ";
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
