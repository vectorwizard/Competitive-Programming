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
    map<int,int> mpp;
    for(int i=0;i<n;i++) mpp[a[i]]++;
    int t=0;
    while(mpp[t]>=2) t++;
    if(mpp[0]==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string ans = "";
    for(int i=0;i<n;i++) ans+='Z';
    vector<int> cnt(t,0);
    for(int i=0;i<n;i++){
        if(a[i]>=t) continue;
        if(cnt[a[i]]==0){
            ans[i] = 'A';
            cnt[a[i]]++;
        }
        else if(cnt[a[i]]==1){
            ans[i] = 'B';
            cnt[a[i]]++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0 && ans[i]=='Z') ans[i] = 'A';
    }
    for(int i=0;i<n;i++){
        if(ans[i]=='Z') ans[i] = 'C';
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
