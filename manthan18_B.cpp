#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll mid = a[n/2];
    if(mid==s){
        cout<<0<<endl;
        return;
    }
    else if(mid<s){
        ll ans = 0;
        ll i = n/2;
        while(i<n){
            if(a[i]<s){
                ans+=(s-a[i]);
            }
            else break;
            i++;
        }
        cout<<ans<<endl;
        return;
    }
    else{
        ll ans = 0;
        ll i = n/2;
        while(i>=0){
            if(a[i]>s){
                ans+=(a[i]-s);
            }
            else break;
            i--;
        }
        cout<<ans<<endl;
        return;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}