#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
map<ll,ll> ways;
void cal(){
    for(ll i=0;i<=9;i++){
        for(ll j=0;j<=9;j++){
            for(ll k=0;k<=9;k++){
                ll sum = i + j + k;
                if(sum<10) ways[sum]++;
            }
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    if(n==0){
        cout<<1<<endl;
        return;
    }
    string s = to_string(n);
    ll m = s.size();
    ll ans = 1;
    for(ll i=0;i<m;i++){
        ans = ans * ways[s[i]-'0'];
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    cal();
    while (t--) solve();
    return 0;
}
