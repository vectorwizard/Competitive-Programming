#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll d;
    if(x%2==1) d= 1; 
    else d =0;
    for(ll i=0;i<n;i++){
        ll p1 = a[i]%2;
        ll p2 = d%2;
        if((p1^p2)==1){
            d = 1;
        }
        else d = 0;
    }
    ll p_y;
    if(y%2==0) p_y = 0;
    else p_y = 1;
    if(p_y==d) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
