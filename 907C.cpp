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
    ll l = 0;
    ll r = n-1;
    ll ans = 0; 
    ll x = 0;
    while(l<r){
        if(x==a[r]){
            ans++;
            r--;
            x=0;
        }
        else if(x+a[l]<=a[r]){
            x+=a[l];
            ans+=a[l];
            l++;
        }
        else{
            ans+=(a[r]-x)+1;
            a[l]-=(a[r]-x);
            x=0;
            r--;
        }
    }
    ll mini = a[l];
    ll cnt = 0;
    ll rem = a[l]-x;
    if(rem<=0) cnt = 1;
    else if(rem%2==0) cnt+=(rem/2)+1;
    else cnt+=(rem/2)+2;
    mini = min(mini,cnt);
    cout<<ans+mini<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
