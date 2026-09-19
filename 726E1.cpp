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
    string ans = "";
    for(ll i=0;i<k;i++) ans+='z';
    for(ll i=0;i<n;i++){
        string temp = s.substr(0,i+1);
        string temp1 = "";
        while(temp1.size()<k){
            temp1+=temp;
        }
        string temp2 = temp1.substr(0,k);
        if(temp2<ans) ans = temp2;
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