#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<ll> factorials(15);
vector<ll> factors;
void factorial(){
    factorials[0] = 1;
    factorials[1] = 1;
    for(ll i=2;i<15;i++){
        factorials[i] = factorials[i-1] * i;
    }
}
map<ll,ll> mpp;
void func1(ll n){
    ll ans = 0;
    for(ll i=0; i<12; i++){
        if((n >> i) & 1){ 
            ans += factors[i];
        }
    }
    ll sets = __builtin_popcountll(n);
    mpp[ans] = sets;
}
void func(ll ind,ll ch){
    if(ind==12){
        func1(ch);
        return;
    }
    ch = (ch<<1);
    func(ind+1,(ch|1));
    func(ind+1,ch);
}
void solve() {
    ll n;
    cin>>n;
    ll mini = 1e9;
    for(auto it:mpp){
        ll a = it.first;
        if(a>n) break;
        ll cnt = it.second;
        ll rem = n-a;
        ll sets = __builtin_popcountll(rem);
        mini = min(mini,cnt+sets);
    }
    cout<<mini<<endl;
}   

int main() {
    fastio();
    factorial();
    for(ll i=3;i<15;i++){
        factors.push_back(factorials[i]);
    }
    func(0,0);
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
