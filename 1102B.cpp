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
    ll rem = n%12;
    if(rem!=10){
        cout<<rem<<" "<<(n-rem)<<endl;
    } 
    else{
        if(22>n) cout<<-1<<endl;
        else cout<<22<<" "<<(n-22)<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
