#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k>n){
        string ans = s;
        char ch=s[0];
        for(ll i=1;i<n;i++) ch = min(ch,s[i]);
        for(ll i=0;i<(k-n);i++) ans+=ch;
        cout<<ans<<endl;
        return;
    }
    string ans = "";
    set<char> st;
    for(ll i=0;i<n;i++) st.insert(s[i]);
    char smallest = *st.begin();
    char largest = *st.rbegin();
    ll i = k-1;
    while(i>=0){
        if(largest>s[i]){
            break;
        }
        ans+=smallest;
        i--;
    }
    for(char ch = 'a';ch<='z';ch++){
        if(ch>s[i] && st.count(ch)>0){
            ans+=ch;
            break;
        }
    }
    i--;
    while(i>=0){
        ans+=s[i];
        i--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
