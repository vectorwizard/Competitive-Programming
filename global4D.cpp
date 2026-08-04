#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> sieve;
void cal(ll n){
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i=2;i*i<=n;i++){
        if(sieve[i]==0) continue;
        for(ll j = i*i;j<=n;j+=i){
            sieve[j] = 0;
        }
    }
}

void solve() {
    ll n;
    cin>>n;
    ll x;
    for(ll i=n;i<100001;i++){
        if(sieve[i]==1){
            x = i;
            break;
        }
    }
    ll three = (x-n)*2;
    ll two = (n-three);
    cout<<x<<endl;
    for(ll i=1;i<n;i++){
        cout<<i<<" "<<i+1<<endl;
    }
    cout<<n<<" "<<1<<endl;
    ll ind = 1;
    while(three>0){
        cout<<ind<<" "<<ind + (n/2)<<endl;
        ind++;
        three-=2;
    }
}

int main() {
    sieve.assign(100001,1);
    cal(100000);
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
