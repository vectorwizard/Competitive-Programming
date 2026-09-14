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
    ll ans = 0;
    for(ll i=0;i<=30;i++){
        ans+=(1<<i);
        if(ans>=n){
            cout<<i+1<<endl;
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
