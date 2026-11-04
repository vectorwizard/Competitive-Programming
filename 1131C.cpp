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
    ll total = accumulate(a.begin(),a.end(),0);
    if(total==n){
        cout<<-1<<endl;
        return;
    }
    bool fl = false;
    for(int i=1;i<n-1;i++){
        if(a[i]>1){
            fl = true;
            break;
        }
    }
    if(!fl){
        cout<<(total-(n-1))<<endl;
    }
    else cout<<(total-1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}