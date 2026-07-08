#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll p,q;
    cin>>p>>q;
    ll x = 2*p + 4*q + 1;
    for(ll y = 1;y*y<=x;y+=2){
        if(x%y==0){
            ll temp = x/y;
            ll n = (y-1)/2;
            ll m = (temp-1)/2;
            if(n>0 && m>0){
                cout<<n<<" "<<m<<" "<<endl;
                return;
            } 
        }
    }
    cout<<-1<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
