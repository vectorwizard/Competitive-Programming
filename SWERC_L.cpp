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
    ll q;
    cin>>q;
    ll c1 = 0;
    ll c2 = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='+') c1++;
        else c2++;
    }
    if(c2>c1) swap(c2,c1);
    while(q--){
        ll a,b;
        cin>>a>>b;
        if(c1==c2){
            cout<<"YES"<<endl;
            continue;
        }
        if(a<b){
            swap(a,b);
        }
        ll l = lcm(a,b);
        ll x = l/b;
        ll y = l/a;
        ll d = abs(c1-c2);
        if((x-y)==0){
            cout<<"NO"<<endl;
            continue;
        }
        if((d%abs(x-y))!=0) cout<<"NO"<<endl;
        else{
            ll k = (d/abs(x-y));
            if((k*(x+y))<=n) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
