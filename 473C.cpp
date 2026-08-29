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
    if(n<6){
        cout<<-1<<endl;
    }
    else{
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<1<<" "<<4<<endl;
        for(ll i=5;i<=n;i++){
            cout<<2<<" "<<i<<endl;
        }
    }
    for(ll i=2;i<=n;i++){
        cout<<i-1<<" "<<i<<endl;
    }
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
