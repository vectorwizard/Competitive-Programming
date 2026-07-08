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
    ll ones = 0;
    for(auto it:a){
        if(it==1) ones++;
    }
    if(ones>=1){
        cout<<(n-ones)<<endl;
        return;
    }
    ll mini = 1e9;
    for(ll i=0;i<n;i++){
        ll gcdd = a[i];
        for(ll j=i;j<n;j++){
            gcdd = __gcd(gcdd,a[j]);
            if(gcdd==1){
                mini = min(mini,j-i);
            }
        }
    }
    if(mini==1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<(mini+(n-1))<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
