#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> pref(n);
    pref[0] = 0;
    ll bad = 0;
    for(ll i=1;i<n;i++){
        if(s[i]==s[i-1]) bad++;
        pref[i] = bad;
    }
    for(ll i=0;i<q;i++){
        ll l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        ll bads = pref[r] - pref[l];
        if(bads>(2*k)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
