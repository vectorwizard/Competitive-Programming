#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;
vector<ll> fact(1e6+2,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1e6;i++){
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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int first = n;
    int last = -1;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            first = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            last = i;
            break;
        }
    }
    for(int i=0;i<first;i++){
        if(a[i]==-1){
            a[i] = 1;
            break;
        }
    }
    for(int i=n-1;i>last;i--){
        if(a[i]==-1){
            a[i] = 1;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            a[i] = 0;
        }
    }
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
