#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

bool func(ll mid,vector<ll> &a){
    ll n = a.size();
    ll cnt = n*mid;
    for(ll i=0;i<n;i++){
        if((a[i]-cnt)<=0) return true;
        cnt++;
    }
    return false;
}

void solve() {
    int a,b,x;
    cin>>a>>b>>x;
    string ans = "";
    x++;
    int y = 0;
    if(b>a) y = 1;
    for(int i=0;i<x-2;i++){
        if(y==0){
            ans+='0';
            a--;
        } 
        else{
            ans+='1';
            b--;
        }
        y = !y;
    }
    if(y==0){
        while(a){
            ans+='0';
            a--;
        }
        while(b){
            ans+='1';
            b--;
        }
    }
    else{
        while(b){
            ans+='1';
            b--;
        }
        while(a){
            ans+='0';
            a--;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
