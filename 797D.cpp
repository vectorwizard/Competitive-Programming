#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll l = 0,r=0;
    ll cnt = 0;
    ll mini = k;
    for(r = 0;r<k;r++){
        if(s[r]=='B') cnt++;
    }
    mini = min(k,(k-cnt));
    for(ll i = r;i<n;i++){
        if(s[i]=='B') cnt++;
        if(s[l]=='B') cnt--;
        l++;
        mini = min(mini,(k-cnt));
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
