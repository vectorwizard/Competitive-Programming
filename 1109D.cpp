#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll m,n;
    cin>>m>>n;
    vector<ll> a(m);
    vector<ll> b(n);
    for(ll i=0;i<m;i++) cin>>a[i];
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        x--;
        b[i] = x;
    }
    sort(b.begin(),b.end());
    ll total = 0;
    ll curr = 0;
    ll ind = 0;
    for(ll i=0;i<m;i++){
        curr+=a[i];
        if(ind<n && b[ind]==i){
            total+=abs(curr);
            curr = 0;
            ind++;
        }
    }
    cout<<(total+curr)<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
