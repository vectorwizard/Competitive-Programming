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
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll med1 = a[n/2];
    ll ans1 = 0,ans2=0;
    for(ll i=0;i<n;i++){
        ans1+=abs(med1-a[i]);
    }
    if(n>1){
        ll med2 = a[n/2-1];
    for(ll i=0;i<n;i++){
        ans2+=abs(med2-a[i]);
    }
    }
    
    cout<<min(ans1,ans2)<<endl;
}  

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
