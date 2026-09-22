#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e22;
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
    ll n;
    cin>>n;
    string s = "";
    ll x = n;
    while(x>0){
        ll rem = (x%3);
        s+=('0'+rem);
        x/=3;
    }
    reverse(s.begin(),s.end());
    ll two = -1;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='2'){
            two = i;
            break;
        }
    }
    if(two==-1){
        cout<<n<<endl;
        return;
    }
    ll j = two;
    ll ans = -1;
    while(j>=0){
        if(s[j]=='0'){
            ans = j;
            break;
        }
        j--;
    }
    if(ans==-1){
        cout<<power(3,s.size())<<endl;
        return;
    }   
    s[ans] = '1';
    for(ll i=ans+1;i<s.size();i++) s[i] = '0';
    reverse(s.begin(),s.end());
    ll p = 1;
    ll res = 0;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='1'){
            res+=p;
        }
        p= p*3;
    }
    cout<<res<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
