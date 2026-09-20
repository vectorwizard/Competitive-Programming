#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,vector<ll> &b){
    ll n = a.size() - 1;
    ll taken = 0;
    for(ll i=1;i<=n;i++){
        if((b[i]>=taken) && (a[i]>=(mid-taken-1))){
            taken++;
        }
    }
    if(taken>=mid) return true;
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans = 0;
    ll low = 0;
    ll high = n;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,b)){
            ans = mid;
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