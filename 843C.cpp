#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll n,ll mid){
    ll ans = 0;
    for(ll i=62;i>=0;i--){
        ll x = n & (1LL<<i);
        ll y = mid & (1LL<<i);
        if(x!=y){
            break;
        }
        else{
            ans = ans|x;
        }
    }
    return ans;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    ll low = n;
    ll high = 1e18 * 5;
    ll ans = -1;
    if(x>n){
        cout<<-1<<endl;
        return;
    }
    while(low<=high){
        ll mid = low+(high-low)/2;
        ll y = func(n,mid);
        if(y==x){
            ans = mid;
            high = mid-1;
        }
        else if(y>x){
            low = mid+1;
        }
        else high = mid-1;
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