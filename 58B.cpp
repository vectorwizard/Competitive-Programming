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
    ll i = 0;
    while(i<n && s[i]!='['){
        i++;
    }
    ll ans = 1;
    while(i<n && s[i]!=':'){
        i++;
    }
    ans++;
    i++;
    ll j = n-1;
    while(j>=0 && s[j]!=']') j--;
    ans++;
    while(j>=0 && s[j]!=':') j--;
    ans++;
    j--;
    if((i-j)>1){
        cout<<-1<<endl;
        return;
    }
    while(i<=j){
        if(s[i]=='|') ans++;
        i++;
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
