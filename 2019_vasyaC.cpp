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
    string s = "";
    cin>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        a[i] = s[i]-'0';
    }
    ll total = accumulate(a.begin(),a.end(),0);
    if(total==0){
        cout<<"YES"<<endl;
        return;
    }
    for(ll i=1;i<=total-1;i++){
        ll sum = 0;
        for(ll j=0;j<n;j++){
            sum+=a[j];
            if(sum==i) sum=0;
        }
        if(sum==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
