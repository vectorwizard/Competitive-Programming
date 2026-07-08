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
    sort(a.begin(),a.end());
    if(a[0]!=1){
        cout<<"NO"<<endl;
        return;
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    if(n>1 && a[0]!=1 || a[1]!=1){
        cout<<"NO"<<endl;
        return;
    }
    ll total=2;
    for(ll i=2;i<n;i++){
        if(a[i]>total){
            cout<<"NO"<<endl;
            return;
        }
        total+=a[i];
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
