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
    for(ll i=0;i<n;i++){
        ll cnt = 0;
        for(ll j=0;j<m;j++){
            if(b[i][j]!=a[i][j]) cnt++;
        }
        if(cnt%2==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(ll j=0;j<m;j++){
        ll cnt = 0;
        for(ll i=0;i<n;i++){
             if(b[i][j]!=a[i][j]) cnt++;
        }
        if(cnt%2==1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
