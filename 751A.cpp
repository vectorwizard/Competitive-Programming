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
    map<ll,ll> mpp;
    for(ll i=30;i>=0;i--){
        for(ll j=0;j<n;j++){
            if(a[j]&(1<<i)){
                mpp[i]++;
            }
        }
    }
    ll gcdd = 0;
    for(auto it:mpp){
        gcdd = __gcd(gcdd,it.second);
    }
    if(gcdd==0){
        for(ll i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(ll i=1;i<=gcdd;i++){
        if(gcdd%i==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
