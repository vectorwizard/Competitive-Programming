#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll base = 0;
    for(ll i=0;i<n;i++){
        if(i==0 || a[i]!=a[i-1]){
            base+=((i+1)*(n-i));
        }
        else{
            base+=(n-i);
        }
    }
    while(q--){
        ll i,m;
        cin>>i>>m;
        i--;
        if(a[i]==m){
            cout<<base<<endl;
            continue;
        }
        if(i==0 || a[i]!=a[i-1]){
            base-=((i+1)*(n-i));
        }
        else{
            base-=(n-i);
        }
        if(i+1<n){
            if(a[i+1]!=a[i]){
                base-=((i+2)*(n-i-1));
            }
            else{
                base-=(n-i-1);
            }
        }
        a[i] = m;
        if(i==0 || a[i]!=a[i-1]){
            base+=((i+1)*(n-i));
        }
        else{
            base+=(n-i);
        }
        if(i+1<n){
            if(a[i+1]!=a[i]){
                base+=((i+2)*(n-i-1));
            }
            else{
                base+=(n-i-1);
            }
        }
        cout<<base<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}