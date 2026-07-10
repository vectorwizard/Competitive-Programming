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
    ll maxi = 0;
    ll cnt = 0;
    for(ll i=1;i<=1e2;i++){
        if(n%i==0){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else cnt = 0;
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
