#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll a, ll b){
    ll cnt = 0;
    while(a>0){
        cnt++;
        a/=b;
    }
    return cnt;
}

void solve() {
    ll a,b;
    cin>>a>>b;
    if(a<b){
        cout<<1<<endl;
        return;
    }
    else if(a==b){
        cout<<2<<endl;
        return;
    }
    else{
        ll mini = 1e9;
        ll x = 0;
        if(b==1) {
            x = 1;
            b++;
        }
        for(ll i=0;i<=30;i++){
            ll cnt = func(a,b+i);
            mini = min(mini,cnt+x+i);
        }
        cout<<mini<<endl;
        return;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
