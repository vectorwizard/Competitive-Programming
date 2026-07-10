#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b;
    cin>>a>>b;
    string s = "";
    ll x = __builtin_clzll(a);
    ll y = __builtin_ctzll(a);
    for(ll i=63-x;i>=y;i--){
        if(a&(1LL<<i)){
            s+='1';
        }
        else s+='0';
    }
    string s1 = "";
    ll x1 = __builtin_clzll(b);
    ll y1 = __builtin_ctzll(b);
    for(ll i=63-x1;i>=y1;i--){
        if(b&(1LL<<i)){
            s1+='1';
        }
        else s1+='0';
    }
    if(s!=s1){
        cout<<-1<<endl;
        return;
    }
    cout<<(abs(x1-x)+2)/3<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
