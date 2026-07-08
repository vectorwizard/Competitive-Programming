#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<vector<ll>> &vec,vector<pair<ll,ll>> &maxis){
    ll n = vec.size();
    ll power = mid;
    for(ll i=0;i<n;i++){
        ll ind = maxis[i].second;
        for(ll j=0;j<vec[ind].size();j++){
            if(power<=vec[ind][j]){
                return false;
            }
            else{
                power++;
            }
        }
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        for(ll j=0;j<k;j++){
            ll x;
            cin>>x;
            vec[i].push_back(x);
        }
    }
    vector<pair<ll,ll>> maxis;
    ll maxi_all = 0;
    for(ll i=0;i<n;i++){
        ll maxi = 0;
        for(ll j=0;j<vec[i].size();j++){
            maxi = max(maxi,vec[i][j]-j+1);
        }
        maxis.push_back({maxi,i});
        maxi_all = max(maxi_all,maxi);
    }
    sort(maxis.begin(),maxis.end());
    ll low = 0;
    ll high = maxi_all+1;
    ll ans;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,vec,maxis)){
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
    cin >> t;
    while (t--) solve();
    return 0;
}
