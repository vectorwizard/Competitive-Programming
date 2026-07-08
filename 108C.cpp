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
    vector<ll> u(n);
    vector<ll> s(n);
    for(ll i=0;i<n;i++) cin>>u[i];
    for(ll i=0;i<n;i++) cin>>s[i];
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        vec[i] = {s[i],u[i]};
    }
    vector<vector<ll>> hash(n+1);
    sort(vec.rbegin(),vec.rend());
    for(ll i=0;i<n;i++){
        hash[vec[i].second].push_back(vec[i].first);
    }
    for(ll i=1;i<=n;i++){
        vector<ll> temp = hash[i];
        if(temp.size()==0) continue;
        for(ll j=1;j<temp.size();j++){
            hash[i][j] = hash[i][j-1] + hash[i][j];
        }
    }
    vector<ll> ans(n+1,0);
    for(ll i=1;i<=n;i++){
        vector<ll> temp = hash[i];
        if(temp.size()==0) continue;
        for(ll k=1;k<=temp.size();k++){
            ll rem = temp.size()%k;
            ans[k] += temp[temp.size()-1-rem];
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
