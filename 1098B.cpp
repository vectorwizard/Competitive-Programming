#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x1,x2,k;
    cin>>n>>x1>>x2>>k;
    if(n<=3){
        cout<<1<<endl;
        return;
    }
    ll mini = min(x1,x2);
    ll maxi = max(x1,x2);
    ll ans = maxi-mini;
    ll x = (n-maxi);
    ans = min(ans,(x+mini)); 
    cout<<(k+ans)<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
