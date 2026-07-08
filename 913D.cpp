#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<pair<ll,ll>> &vec){
    ll n = vec.size();
    ll curr_l = 0,curr_r=0;
    for(ll i=0;i<n;i++){
        ll l = curr_l - mid;
        ll r = curr_r + mid;
        if(l>vec[i].second || r<vec[i].first) return false;
        curr_r = min(vec[i].second,curr_r+mid);
        curr_l = max(vec[i].first,curr_l-mid);
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    ll maxi = 0;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        vec[i] = {l,r};
        maxi = max(maxi,r);
    }
    ll low = 0,high = maxi;
    ll ans = 0;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,vec)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
