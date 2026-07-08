#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> func(ll n){
    vector<ll> vec;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if((n/i)==i) vec.push_back(i);
            else{
                vec.push_back(i);
                vec.push_back(n/i);
            }
        }
    }
    return vec;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    vector<ll> divisors_a = func(a[0]);
    vector<ll> divisors_b = func(b[0]);
    ll ans = 0;
    for(auto it1: divisors_a){
        for(auto it2: divisors_b){
            bool poss = true;
            for(ll i=1;i<n;i++){
                bool fl1 = false,fl2 = false;
                if(a[i]%it1==0 && b[i]%it2==0){
                    fl1 = true;
                }
                if(b[i]%it1==0 && a[i]%it2==0){
                    fl2 = true;
                }
                if(!fl1 && !fl2){
                    poss = false;
                    break;
                }
            }
            if(poss){
                ll x = (it1/__gcd(it1,it2))*it2;
                ans = max(ans,x);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
