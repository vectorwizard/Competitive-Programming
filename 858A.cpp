#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d<b){
        cout<<-1<<endl;
        return;
    }
    else if(c>a && (d-b)<(c-a)){
        cout<<-1<<endl;
        return;
    }
    ll y = d-b;
    ll x = (a+y)-c;
    cout<<(x+y)<<endl;
}
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
