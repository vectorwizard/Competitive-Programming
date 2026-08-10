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
    string s;
    cin>>s;
    ll ones = 0;
    ll zeros = 0;
    string s1 = "01";
    string s2 = "10";
    ll i = 0;
    ll j = 0;
    while(i<n){
        if(s[i]==s1[j]){
            i++;
            j++;
        }
        else{
            if(s[i]=='1') ones++;
            else zeros++;
            i++;
        }
        if(j==2) j = 0;
    }
    ll ans = 1e9;
    if(abs(zeros-ones)<=1) ans = (zeros+ones);
    ones = 0;
    zeros=0;
    i = 0;
    j=0;
    while(i<n){
        if(s[i]==s2[j]){
            i++;
            j++;
        }
        else{
            if(s[i]=='1') ones++;
            else zeros++;
            i++;
        }
        if(j==2) j = 0;
    }
    if(abs(zeros-ones)<=1) ans = min(ans,(zeros+ones));
    if(ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
