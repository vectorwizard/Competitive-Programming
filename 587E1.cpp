#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll i,ll t){
    string s = to_string(i);
    char ch = s[t-1];
    return (ch-'0');
}

void solve() {
    ll total = 0;
    ll past = 0;
    vector<ll> vec;
    for(ll i=1;i<=1e5;i++){
        string s = to_string(i);
        ll len = s.size();
        past+=len;
        total+=past;
        vec.push_back(total);
        if(total>1e9) break;
    }
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        ll ind = lower_bound(vec.begin(),vec.end(),k) - vec.begin();
        if(ind>=1) k -= vec[ind-1];
        ll cnt = 0;
        for(ll i=1;i<1e5;i++){
            string s = to_string(i);
            ll len = s.size();
            if((cnt+len)>=k){
               ll ans = func(i,k-cnt);
               cout<<ans<<endl;
               break;
            }
            cnt+=len;
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}