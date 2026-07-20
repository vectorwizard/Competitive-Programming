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
    if(n%2==1){
        cout<<"NO"<<endl;
        return;
    }
    ll ones = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==1) ones++;
    }
    if(abs(n/2-ones)%2==1){
        cout<<"NO"<<endl;
        return;
    } 
    cout<<"YES"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
