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
    string s;
    cin>>s;
    stack<int> st;
    vector<int> vis(n+1,0);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') st.push(i);
        else if(s[i]=='2'){
            if(!st.empty()){
                cnt++;
                vis[st.top()] = 1;
                st.pop();
            }
            else{
                vis[i] = 1;
                cnt++;
            }
        }
        else{
            vis[i] = 1;
            cnt++;
        }
    }
    cout<<(n-cnt)<<endl;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}