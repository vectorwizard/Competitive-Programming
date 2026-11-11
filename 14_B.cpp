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
    if(n%2==0){
        ll x = n/2;
        ll y = sqrt(x);
        if((y*y)==x){
            cout<<"YES"<<endl;
            return;
        }
    }
    if(n%4==0){
        ll x = n/4;
        ll y = sqrt(x);
        if((y*y)==x){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}