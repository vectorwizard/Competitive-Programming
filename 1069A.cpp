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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    int size = st.size();
    int i=0;
    while(true){
        if(st.find(size+i)!=st.end()){
            cout<<size+i<<endl;
            break;
        }
        i++;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}