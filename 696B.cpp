#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool prime(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve() {
    ll d;
    cin>>d;
    ll ans = 1e9;
    ll i = d+1;
    while(1){
        if(prime(i)) break;
        i++;
    }
    ans = i*i*i;
    ll j = d+i;
    while(1){
        if(prime(j)){
            break;
        }
        j++;
    }
    ans = min(ans,(i*j));
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
