#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    sort(d.begin(),d.end());
    int a = d[n-1];
    unordered_set<int> st;
    for(int i=1;i<=1e4 + 2;i++){
        if(a%i==0) st.insert(i);
    }
    for(int i=0;i<n;i++){
        if(st.count(d[i])>0){
            st.erase(d[i]);
            d[i] = 1;
        }
    }
    sort(d.begin(),d.end());
    cout<<a<<" "<<d[n-1]<<endl;
} 
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}