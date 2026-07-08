#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        if(a[i]>c) break;
        else if(a[i]==c) c+=a[i];
        else{
            if(k>=(c-a[i])){
                k-=(c-a[i]);
                c+=c;;
            }
            else{
                c+=(a[i]+k);
                k=0;
            }
        }
    }
    cout<<c<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}