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
    ll zeros = 0;
    ll pos = 0;
    ll neg = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==0) zeros++;
        else if(a[i]>0) pos++;
        else neg++;
    }
    int need = (n+1)/2;
    if(pos>=need){
        cout<<1<<endl;
        return;
    }
    else if(neg>=need){
        cout<<-1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}