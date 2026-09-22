#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<string> t = {"abc","bac","cab","acb","bca","cba"};
    map<ll,vector<ll>> mpp; 
    for(ll i=0;i<6;i++){
        ll ind = 0;
        ll cnt = 0;
        string temp = t[i];
        for(ll j = 0;j<n;j++){
            if(s[j]!=temp[ind]) cnt++;
            mpp[i].push_back(cnt);
            ind=(ind+1)%3;
        }
    }
    while(m--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll mini = 1e9;
        for(ll i=0;i<6;i++){
            ll lcost = 0;
            if(l>0) lcost = mpp[i][l-1];
            ll rcost = mpp[i][r];
            mini = min(mini,rcost-lcost);
        }
        cout<<mini<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}