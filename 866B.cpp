#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    ll maxi = 0;
    ll cnt = 0;
    string s1 = s+s;
    for(ll i=0;i<2*n;i++){
        if(s1[i]=='1') cnt++;
        else{
            maxi = max(maxi,cnt);
            cnt = 0;
        }
        if(i==n-1 && cnt>=n){
            break;
        }
    }
    maxi = max(maxi,cnt);
    if(maxi==n){
        cout<<(n*n)<<endl;
        return;
    }
    ll x = (maxi/2)+1;
    ll ans = x*(maxi-x+1);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
