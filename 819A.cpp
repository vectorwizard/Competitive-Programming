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
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll ans = 0;
    ll maxi = *max_element(a.begin()+1,a.end());
    ans = max(ans,(maxi-a[0]));
    ll mini = *min_element(a.begin(),a.end()-1);
    ans = max(ans,(a[n-1]-mini));
    for(ll i=0;i<n-1;i++){
        ans = max(ans,(a[i]-a[i+1]));
    }
    ans = max(ans,(a[n-1]-a[0]));
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
