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
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    set<int> st;
    sort(vec.begin(),vec.end());
    int ans =0;
    for(int i=0;i<n;i++){
        st.insert(vec[i]);
    }
    while(!st.empty()){
        int num = *st.begin();
        st.erase(num);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vec[i]==num) cnt++;
        }
        if(cnt>num) ans+=(cnt-num);
        else if(cnt<num) ans+=cnt;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
