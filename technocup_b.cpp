#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll n){
    ll x = n;
    while(x>0){
        ll digit = x%10;
        if(digit==0){
            x/=10;
            continue;
        }
        if(n%digit!=0) return false;
        x/=10;
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    while(1){
        if(func(n)){
            cout<<n<<endl;
            return;
        }
        n++;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
