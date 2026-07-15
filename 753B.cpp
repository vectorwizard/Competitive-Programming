#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll x,n;
    cin>>x>>n;
    if(x%2==0){
        if(n%4==0){
            cout<<x<<endl;
            return;
        }
        ll a = x-1;
        ll b = a+2;
        ll c = b+3;
        if(n%4==2){
            cout<<b<<endl;
            return;
        }
        if(n%4==1){
            ll cnt = n/4;
            cout<<(a-(cnt*4))<<endl;
            return;
        }
        if(n%4==3){
            ll cnt = n/4;
            cout<<(c+(cnt*4))<<endl;
            return;
        }
    }
    else{
        if(n%4==0){
            cout<<x<<endl;
            return;
        }
        ll a = x+1;
        ll b = a-2;
        ll c = b-3;
        if(n%4==2){
            cout<<b<<endl;
            return;
        }
        if(n%4==3){
            ll cnt = n/4;
            cout<<(c-(cnt*4))<<endl;
            return;
        }
        if(n%4==1){
            ll cnt = n/4;
            cout<<(a+(cnt*4))<<endl;
            return;
        }
    }
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
