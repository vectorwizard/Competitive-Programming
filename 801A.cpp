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
    ll sum = 0;
    bool zero = false;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        if(zero==true && a[i]!=0){
            cout<<"NO"<<endl;
            return;
        }
        if(sum<0){
            cout<<"NO"<<endl;
            return;
        }
        if(sum==0) zero = true;
    }
    if(sum != 0){
        cout << "NO" << endl;
    }
    else cout<<"YES"<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
