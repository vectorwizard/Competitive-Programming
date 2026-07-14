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
    for(ll i=n-2;i>=0;i--){
        ll cnt = 0;
        while(a[i]>=a[i+1] && a[i]!=0){
            cnt++;
            a[i]=a[i]/2;
        }
        if(a[i]==0 && a[i+1]==0){
            cout<<-1<<endl;
            return;
        }
        ans+=cnt;
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
