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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll twos = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==2) twos++;
    }
    if(twos%2==1){
        cout<<-1<<endl;
        return;
    }
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==2) cnt++;
        if(cnt==(twos/2)){
            cout<<i+1<<endl;
            return;
        }
    }
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
