#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 998244353;
void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,ll> mpp;
    for(ll i=0;i<n;i++) mpp[s[i]]++;
    ll ans;
    if(s[0]==s[n-1]){
        char ch = s[0];
        ll i = 0;
        while(s[i]==ch) i++;
        ll j = n-1;
        while(s[j]==ch) j--;
        ll len = (j-i+1);
        ll start = i+1;
        ll end = (n-j);
        ans = (start*end)%mod;
        cout<<ans<<endl;
    }
    else{
        ll i = 0;
        map<char,ll> temp = mpp;
        while(mpp.size()>1){
            mpp[s[i]]--;
            if(mpp[s[i]]==0) mpp.erase(s[i]);
            i++;
        }
        ll ans = (n-i+1);
        i = n-1;
        while(temp.size()>1){
            temp[s[i]]--;
            if(temp[s[i]]==0) temp.erase(s[i]);
            i--;
        }
        ans = (ans + (i+1))%mod;
        cout<<ans<<endl;
    }
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
