
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(vector<ll> &a,ll k){
    ll n = a.size();
    ll l = 0;
    ll r = n-1;
    ll ans = 0;
    while(l<r){
        ll sum = a[l] + a[r];
        ll div = sum/k;
        if(div==1){
            ans++;
            l++;
            r--;
        }
        else{
            l++;
        }
    }
    return ans;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll base = 0;
    vector<ll> rem;
    for(ll i=0;i<n;i++){
        base+=(a[i]/k);
        ll temp = a[i]%k;
        if(temp>0) rem.push_back(temp);
    }
    sort(rem.begin(),rem.end());
    ll extra = func(rem,k);
    cout<<extra + base<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}