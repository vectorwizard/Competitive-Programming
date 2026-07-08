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
    ll total = 0;
    ll mini = 1e9;
    ll neg = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<0) neg++;
        mini = min(mini,abs(a[i]));
        total+=abs(a[i]);
    }
    if(neg%2==1){
        cout<<(total-2*mini)<<endl;
        return;
    }
    else{
        cout<<total<<endl;
        return;
    }
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
