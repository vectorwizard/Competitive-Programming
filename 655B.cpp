#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll spf(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return i;
    }
    return n;
}
void solve() {
    ll n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    else{
        ll a = n/spf(n);
        if(a==1){
            cout<<1<<" "<<n-1<<endl;
            return;
        }
        ll b = n-a;
        cout<<a<<" "<<b<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
