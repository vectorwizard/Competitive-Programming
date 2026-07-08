#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<ll>> hash(k,vector<ll>(26,0));
    for(ll i=0;i<n;i++){
        hash[i%k][s[i]-'a']++;
    }
    vector<vector<ll>> vec;
    ll l = 0;
    ll r = k-1;
    while(l<r){
        vector<ll> temp(26,0);
        for(ll i=0;i<26;i++){
            temp[i]+=hash[l][i];
            temp[i]+=hash[r][i];
        }   
        vec.push_back(temp);
        l++;
        r--;
    }
    if(l==r){
        vec.push_back(hash[l]);
    }
    ll ans = 0;
    for(ll i=0;i<vec.size();i++){
        ll cnt = 0;
        ll maxi = 0;
        for(ll j=0;j<26;j++){
            maxi = max(maxi,vec[i][j]);
            cnt+=vec[i][j];
        }
        ans+=(cnt-maxi);
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