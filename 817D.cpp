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
    string s;
    cin>>s;
    vector<ll> diff;
    ll total = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='L'){
            total+=i;
            ll dist_right = (n-1-i);
            ll delta = dist_right - i;
            if(delta>0) diff.push_back(delta);
        }
        else{
            total+=(n-1-i);
            ll dist_left = i;
            ll delta = dist_left - (n-1-i);
            if(delta>0) diff.push_back(delta);
        }
    }
    sort(diff.rbegin(),diff.rend());
    for(ll i=1;i<diff.size();i++){
        diff[i] = diff[i-1] + diff[i]; 
    }
    ll m = diff.size();
    for(ll i=0;i<m;i++){
        cout<<total+diff[i]<<" ";
    }
    ll x = 0;
    if(m>0) x = diff[m-1];
    for(ll i=m;i<n;i++){
        cout<<total+x<<" ";
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
