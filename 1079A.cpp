#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll x,ll i){
    ll n = x+i;
    ll sum = 0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    if(sum==i){
        return true;
    }
    else return false;
}

void solve() {  
    ll x;
    cin>>x;
    ll ans = 0;
    for(ll i=0;i<=90;i++){
        if(func(x,i)){
            ans++;
        }
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
