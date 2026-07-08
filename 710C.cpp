#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string a,b;
    cin>>a>>b;
    ll n1 = a.size();
    ll n2 = b.size();
    unordered_set<string> st;
    for(ll i=0;i<n1;i++){
        string temp = "";
        for(ll j=i;j<n1;j++){
            temp+=a[j];
            st.insert(temp);
        }
    }
    ll maxi = 0;
    for(ll i=0;i<n2;i++){
        string temp = "";
        for(ll j=i;j<n2;j++){
            temp+=b[j];
            if(st.count(temp)>0){
                maxi = max(maxi,(ll)temp.size());
            }
        }
    }
    cout<<((n1-maxi)+(n2-maxi))<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
