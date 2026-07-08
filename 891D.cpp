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
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<pair<ll,ll>> vec;
    for(ll i=1;i<=n;i++){
        vec.push_back({a[i]-b[i],i});
    } 
    sort(vec.rbegin(),vec.rend());
    ll maxi = vec[0].first;
    vector<ll> ans;
    for(auto it:vec){
        if(it.first==maxi) ans.push_back(it.second);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
