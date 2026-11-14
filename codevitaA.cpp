#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    set<ll> r;
    set<ll> c;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='R'){
                r.insert(i);
                c.insert(j);
            }
        }
    }
    string temp = "";
    if(r.size()==1){
        ll i = *r.begin();
        for(ll j=0;j<m;j++){
            if(a[i][j]=='C')  temp+=a[i][j];
            else if(i>0 && i<n-1 && a[i+1][j]=='C' && a[i-1][j]=='C')  temp+=a[i][j];
        }
    }
    else{
        ll j = *c.begin();
        for(ll i=0;i<n;i++){
            if(a[i][j]=='C')  temp+=a[i][j];
            else if(j>0 && j<m-1 && a[i][j-1]=='C' && a[i][j+1]=='C')  temp+=a[i][j];
        }
    }
    string ans = "";
    ll i = 0;
    ll t = temp.size();
    stack<char> st;
    while(i<t){
        if(st.empty()){
            st.push(temp[i]);
            i++;
        }
        else if(st.top()==temp[i]){
            st.pop();
            i++;
        }
        else{
            st.push(temp[i]);
            i++;
        }
    }
    cout<<(st.size()/2)<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}