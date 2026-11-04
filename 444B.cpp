#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll ind,vector<ll> &digits,vector<ll> &vis,vector<vector<ll>> &vec){
    ll n = digits.size();
    ll m = vec.size();
    if(ind==n) return true;
    for(ll i=0;i<m;i++){
        if(vis[i]) continue;
        for(ll j=0;j<6;j++){
            if(digits[ind]==vec[i][j]){
                vis[i] = true;
                if(func(ind+1,digits,vis,vec)) return true;
                vis[i] = false;
            } 
        }
    }
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> vec(n,vector<ll>(6));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<6;j++){
            cin>>vec[i][j];
        }
    }
    string s = "";
    for(ll i=0;i<n;i++) s+='9';
    ll maxi = stoi(s);
    for(ll i=1;i<=maxi;i++){
        ll x = i;
        vector<ll> digits;
        while(x>0){
            ll digit = x%10;
            digits.push_back(digit);
            x/=10;
        }
        vector<ll> vis(n,0);
        bool fl = func(0,digits,vis,vec);
        if(!fl){
            cout<<i-1<<endl;
            return;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}