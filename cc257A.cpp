#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> a){
    ll n = a.size();
    ll s = 0;
    for(ll i=0;i<n;i++){
        if(a[i]>=mid){
            a[i] = mid;
            s+=(a[i]-mid);
        }
        else{
            s-=min(s,mid-a[i]);
            a[i]+=min(s,mid-a[i]);
        }
    }
    bool fl = false;
    vector<ll> sorted = a;
    sort(sorted.begin(),sorted.end());
    if(sorted!=a) fl = false;
    if(fl) return true;
    return false;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> sorted = a;
    sort(sorted.begin(),sorted.end());
    if(sorted==a){
        cout<<-1<<endl;
        return;
    }
    ll low = 1;
    ll high = 1e9;
    ll ans = -1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}