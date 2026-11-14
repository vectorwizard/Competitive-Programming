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
    vector<ll> vec(26,0);
    ll i = 0;
    ll j = n-1;
    while(i<j){
        if(s[i]!=s[j]){
            char ch1 = s[i];
            char ch2 = s[j];
            if(ch1>ch2) swap(ch1,ch2);
            for(char ch = ch2;ch>ch1;ch--){
                vec[ch-'a'] = 1;
            }
        }
        i++;
        j--;
    }
    ll ans = 0;
    for(ll i=0;i<26;i++){
        if(vec[i]) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}