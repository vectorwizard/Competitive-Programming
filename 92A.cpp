#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll l,r;
    cin>>l>>r;
    if((l*2)<=r){
        cout<<l<<" "<<2*l<<endl;
        return;
    }
    cout<<-1<<" "<<-1<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
