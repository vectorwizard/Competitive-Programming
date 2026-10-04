#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<ll> fact;

ll power(ll a,ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1) ans = (ans*a)%mod;
    return ans;
}

ll ncr(ll n,ll r){
    ll num = fact[n];
    ll dem1 = fact[r];
    ll dem2 = fact[n-r];
    ll dem = (dem1 * dem2)%mod;
    dem = (power(dem,mod-2))%mod;
    num = (num * dem)%mod;
    return num;
}

bool isplain(string &s){
    int n = s.size();
    int l = 0;
    int r = n-1;
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve() {  
    string s;
    cin>>s;
    int n = s.size();
    set<char> st;
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    string vowel = "";
    string cons = "";
    for(int i=0;i<n;i++){
        if(st.count(s[i])) vowel+=s[i];
        else cons+=s[i];
    }
    if(vowel.size()%2==1 && cons.size()%2==1){
        cout<<"NO"<<endl;
        return;
    }
    if(isplain(vowel) && isplain(cons)){
        cout<<"YES"<<endl;
        return;
    }
    else cout<<"NO"<<endl;
} 
 
int main() {
    fastio();
    // fact.assign(100001,0);
    // fact[0] = 1;
    // fact[1] = 1;
    // for(ll i=2;i<=1e5;i++){
    //     fact[i] = (fact[i-1]*i)%mod;
    // }
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
