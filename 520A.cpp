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
    ll ans = 0;
    if(a[0]==1){
        ll cnt = 1;
        ll i = 1;
        ll t = 2;
        while(i<n && a[i]==t){
            cnt++;
            t++;
            i++;
        } 
        ans = max(ans,cnt-1);
    }
    if(a[n-1]==1000){
        ll cnt = 1;
        ll i = n-2;
        ll t = 999;
        while(i<n && a[i]==t){
            cnt++;
            t--;
            i--;
        } 
        ans = max(ans,cnt-1);
    }
    ll prev = a[0];
    ll cnt = 1;
    for(ll i=1;i<n;i++){
        if(a[i]==(prev+1)){
            cnt++;
        }
        else{
            if(cnt>2) ans = max(ans,cnt-2);
            cnt = 1;
        }
        prev = a[i];
    }
    if(cnt>2) ans = max(ans,cnt-2);
    cout<<ans<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
