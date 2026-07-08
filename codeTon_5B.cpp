#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++) cin>>c[i];
    ll curr = 0;
    for(ll i=0;i<n;i++){
        bool take = true;
        for(ll j=0;j<31;j++){
            if(a[i]&(1<<j)!=0 && (x&(1<<j))!=0){
                continue;
            }
            else if((a[i]&(1<<j))!=0 && (x&(1<<j))==0){
                take = false;
                break;
            }
        }
        if(take){
            curr = curr|a[i];
        }
        else break;
    }
    for(ll i=0;i<n;i++){
        bool take = true;
        for(ll j=0;j<31;j++){
            if(b[i]&(1<<j)!=0 && (x&(1<<j))!=0){
                continue;
            }
            else if((b[i]&(1<<j))!=0 && (x&(1<<j))==0){
                take = false;
                break;
            }
        }
        if(take){
            curr = curr|b[i];
        }
        else break;
    }
    for(ll i=0;i<n;i++){
        bool take = true;
        for(ll j=0;j<31;j++){
            if(c[i]&(1<<j)!=0 && (x&(1<<j))!=0){
                continue;
            }
            else if((c[i]&(1<<j))!=0 && (x&(1<<j))==0){
                take = false;
                break;
            }
        }
        if(take){
            curr = curr|c[i];
        }
        else break;
    }
    if(curr==x){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
