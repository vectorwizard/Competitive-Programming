#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<0<<endl;
        return;
    }
    else if(n==1){
        cout<<m<<endl;
    }
    else if(m==1){
        cout<<n<<endl;
    }
    else if(n<=m){  
        ll ans = n+m-2;
        ans+=n;
        cout<<ans<<endl;
    }       
    else{
        ll ans = n+m-2;
        ans+=m;
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}