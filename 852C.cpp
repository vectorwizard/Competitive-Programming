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
    set<int> st;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        st.insert(i);
    }
    int l = 1;
    int r = n;
    while(l<r){
        if(a[l]==*st.begin()){
            st.erase(a[l]);
            l++;
        }
        else if(a[r]==*st.begin()){
            st.erase(a[r]);
            r--;
        }
        else if(a[l]==*st.rbegin()){
            st.erase(a[l]);
            l++;
        }
        else if(a[r]==*st.rbegin()){
            st.erase(a[r]);
            r--;
        }
        else break;
    }
    if(l<r){
        cout<<l<<" "<<r<<endl;
        return;
    }
    cout<<-1<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
