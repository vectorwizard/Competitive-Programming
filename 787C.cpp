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
    ll last_one = 0;
    ll first_zero = n-1;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') last_one = i;
    }
    for(ll i=n-1;i>=0;i--){
        if(s[i]=='0') first_zero = i;
    }
    cout<<(first_zero-last_one+1)<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
