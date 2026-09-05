#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll r,c;
    cin>>r>>c;
    if(r==1 && c==1){
        cout<<0<<endl;
        return;
    }
    if(r==1){
        for(ll i=2;i<=c+1;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(c==1){
        for(ll i=2;i<=r+1;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(ll i=1;i<=r;i++){
        for(ll j=1;j<=c;j++){
            cout<<i*(j+r)<<" ";
        }
        cout<<endl;
    }

}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
