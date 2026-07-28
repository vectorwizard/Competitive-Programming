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
    ll sum = 0;
    for(ll i=n-1;i>=0;i--){
        if(a[i]<=0){
            if((sum+a[i])>0){
                ans++;
                sum+=a[i];
            }
            else{
                sum = 0;
            }
        }
        else{
            sum+=a[i];
            ans++;
        }
    }
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
