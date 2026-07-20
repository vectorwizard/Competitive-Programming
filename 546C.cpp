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
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<ll>> b(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    map<ll,multiset<ll>> mpp1;
    map<ll,multiset<ll>> mpp2;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            mpp1[i+j].insert(a[i][j]);
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            mpp2[i+j].insert(b[i][j]);
        }
    }
    if(mpp1==mpp2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
