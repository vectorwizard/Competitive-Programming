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
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int l = 0;
    int r = 0;
    unordered_set<int> st;
    int cnt = 0;
    while(l<n && r<n){
        if(a[l]==b[r]){
            l++;
            r++;
        }
        else{
            if(st.count(a[l])){
                l++;
            }
            else{
                cnt++;
                st.insert(b[r]);
                r++;
            }
        }
    }
    cout<<cnt<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
