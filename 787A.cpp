#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll cnt = 0;
    cnt+=min(a,x);
    cnt+=min(b,y);
    ll rem = (x+y) - cnt;
    if(c>=rem){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
