#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    unordered_set<int> st;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        st.insert(a[i]);
    }
    int sp;
    cin>>sp;
    int x = a[sp];
    if(st.size()==1){
        cout<<0<<endl;
        return;
    }
    int left=0,right = 0;
    for(int i=sp-1;i>=1;i--){
        if(a[i]!=a[i+1]){
            left++;
        }
    }
    for(int i=sp+1;i<=n;i++){
        if(a[i]!=a[i-1]) right++;
    }
    int maxi = max(left,right);
    if(maxi%2==0){
        cout<<maxi<<endl;
        return;
    }
    else{
        cout<<maxi+1<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
