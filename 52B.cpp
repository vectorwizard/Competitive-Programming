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
    ll mini = max(0LL,n - 2*m);
    ll maxi;
    if(m==0) maxi = n;
    else{
        for(ll i=1;i<=n;i++){
            ll x = (i*(i-1))/2;
            if(x>=m){
                maxi = (n-i);
                break;
            }
        }
    }
    cout<<mini<<" "<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
