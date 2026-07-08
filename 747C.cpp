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
    char c;
    cin>>c;
    string s;
    cin>>s;
    s='a'+s;
    bool fl = true;
    for(ll i=1;i<=n;i++){
        if(s[i]!=c){
            fl =false;
            break;
        }
    }
    if(fl==true){
        cout<<0<<endl;
        return;
    }
    for(ll i=1;i<=n;i++){
        bool fl = true;
        for(ll j=1;j<=n;j++){
            ll x = i*j;
            if(x>n) break;
            if(s[x]!=c){
                fl = false;
                break;
            }
        }
        if(fl==true){
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n<<" "<<n-1<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
