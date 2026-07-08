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
        cout<<1<<endl;
        return;
    }
    ll mini = n;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ll x = n/i;
            if(x<=k) mini = min(mini,(n/x));
            if(i<=k) mini = min(mini,(n/i));
        }
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
