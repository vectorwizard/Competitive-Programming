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
    stack<pair<char,int>> st;
    string temp = "";
    vector<int> col(n,1);
    int x = 0;
    bool fl = true;
    for(int i=0;i<n;i++){
        if(s[i]=='(') x++;
        else x--;
        if(x<0){
            fl = false;
            break;
        }
    }
    if(fl && x==0){
        cout<<1<<endl;
        for(int i=0;i<n;i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    x = 0;
    fl = true;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='(') x++;
        else x--;
        if(x<0){
            fl = false;
            break;
        }
    }
    if(fl && x==0){
        cout<<1<<endl;
        for(int i=0;i<n;i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch=='(') st.push({'(',i});
        else{
            if(!st.empty() && st.top().first=='('){
                col[i] = 1;
                st.pop();
            }
            else{
                col[i] = 2;
                st.push({')',i});
            }
        }
    }
    if(st.empty()){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    int siz = st.size();
    int y = 2;
    if(siz==n) y = 1;
    stack<pair<char,int>> st1;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.first=='('){
            st1.push({'(',it.second});
            col[it.second] = y;
        }
        else{
            if(!st1.empty() && st1.top().first=='('){
                col[it.second] = y;
                st1.pop();
            }
            else{
                st1.push({')',it.second});
            }
        }
    }
    if(!st1.empty()){
        cout<<-1<<endl;
        return;
    }
    if(siz==n){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<2<<endl;
    for(int i=0;i<n;i++){
        cout<<col[i]<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
