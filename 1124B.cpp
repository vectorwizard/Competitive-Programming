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
    map<ll,vector<ll>> mpp;
    for(ll j=0;j<n;j++){
        if(mpp.count(a[j])) continue;
        ll x = a[j];
        vector<ll> temp;
        temp.push_back(x);
        for(ll i=0;i<=20;i++){
            ll sum = 0;
            while(x>0){
                ll digit = x%10;
                sum+=(digit*digit);
                x/=10; 
            }
            temp.push_back(sum);
            x = sum;
        }
        mpp[a[j]] = temp;
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            bool fl = false;
            for(ll k=0;k<=20;k++){
                if(mpp[a[i]][k]==mpp[a[j]][k]){
                    fl = true;
                    break;
                }
            }
            if(fl){
                ans++;
            }
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