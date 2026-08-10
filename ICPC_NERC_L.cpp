#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,ll a,ll b,ll c){
    if((a+b+c)>(3*mid)) return false;
    if(a<=mid && c<=(2*mid)) return true;
    else if(c<=mid && a<=(2*mid)) return true;
    return false;
}

void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll high = max(a,max(b,c));
    ll low = 1;
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,b,c)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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
