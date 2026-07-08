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
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a[i] = x;
        b[i] = y;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2==1){
        cout<<1<<endl;
        return;
    }
    ll low_a = a[n/2-1];
    ll high_a = a[n/2];
    ll low_b = b[n/2-1];
    ll high_b = b[n/2];
    ll x = (high_a-low_a+1);
    ll y = (high_b-low_b+1);
    cout<<(x*y)<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
