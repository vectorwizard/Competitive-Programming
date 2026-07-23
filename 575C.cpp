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
    vector<vector<ll>> a(n,vector<ll>(6));
    for(ll i=0;i<n;i++){
        ll x,y,f1,f2,f3,f4;
        cin>>x>>y>>f1>>f2>>f3>>f4;
        a[i] = {x,y,f1,f2,f3,f4};  //{u,r,d,l}
    }
    ll u = 1e5;
    ll d = -1e5;
    ll r = 1e5;
    ll l = -1e5;
    for(ll i=0;i<n;i++){
        ll x = a[i][0];
        ll y = a[i][1];
        ll f1 = a[i][2];
        ll f2 = a[i][3];
        ll f3 = a[i][4];
        ll f4 = a[i][5];
        if(f1*f2*f3*f4==1) continue;
        if(f3==0){
            if(d>x){
                cout<<0<<endl;
                return;
            }
            u = min(x,u);
        }
        if(f1==0){
            if(u<x){
                cout<<0<<endl;
                return;
            }
            d = max(x,d);
        }
        if(f2==0){
            if(l>y){
                cout<<0<<endl;
                return;
            }
            r = min(r,y);
        }
        if(f4==0){
            if(r<y){
                cout<<0<<endl;
                return;
            }
            l = max(l,y);
        }
    }
    cout<<1<<" "<<u<<" "<<r<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
