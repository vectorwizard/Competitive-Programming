#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &queries,vector<pair<ll,ll>> &vec,ll n){
    ll q = queries.size();
    ll m = vec.size();
    unordered_map<ll,ll> pref;
    for(ll i=0;i<=mid;i++){
        pref[queries[i]] = 1;
    }
    for(ll i=0;i<n;i++){
        pref[i] = pref[i-1] + pref[i];
    }
    for(ll i=0;i<m;i++){
        ll l = pref[vec[i].first-1];
        ll r = pref[vec[i].second];
        ll len = (vec[i].second-vec[i].first+1);
        if(((r-l)*2)>len) return true;
    }
    return false;
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vec(m);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        vec[i] = {x,y};
    }
    ll q;
    cin>>q;
    vector<ll> queries(q);
    for(ll i=0;i<q;i++){
        int x;
        cin>>x;
        x--;
        queries[i] = x;
    } 
    ll low = 0;
    ll high = q-1;
    ll ans = -1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,queries,vec,n)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    if(ans==-1) cout<<-1<<endl;
    else cout<<ans+1<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
