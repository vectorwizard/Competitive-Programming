#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    if(k>=n){
        cout<<n<<endl;
        return;
    }
    ll ans = 0;
    ll cost = 1;
    while(n>=cost){
        ll take = min(k,n/cost);
        ans+=take;
        n-=take*cost;
        cost*=2;
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
