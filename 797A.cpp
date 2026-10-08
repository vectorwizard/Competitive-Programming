
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
    ll x=3;
    ll y=2;
    ll z=1;    
    ll rem = n-6;
    while(rem>0){
        if(rem>0){
            x++;
            rem--;
        }
        if(rem>0){
            y++;
            rem--;
        }
        if(rem>0){
            z++;
            rem--;
        }
    }
    cout<<y<<" "<<x<<" "<<z<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}