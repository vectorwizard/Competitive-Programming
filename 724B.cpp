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
    set<string> st;
    for(int i=0;i<n;i++){
        string temp= "";
        for(int j=i;j<min(n,i+3);j++){
            temp+=s[j];
            st.insert(temp);
        }
    }
    for(int i=0;i<26;i++){
        string temp="";
        temp += (char)('a'+i);
        if(st.count(temp)==0){
            cout<<temp<<endl;
            return;
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            string temp="";
            temp += (char)('a'+i);
            temp += (char)('a'+j);
            if(st.count(temp)==0){
                cout<<temp<<endl;
                return;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                string temp="";
                temp += (char)('a'+i);
                temp += (char)('a'+j);
                temp += (char)('a'+k);
                if(st.count(temp)==0){
                    cout<<temp<<endl;
                    return;
                }
            }
        }
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
