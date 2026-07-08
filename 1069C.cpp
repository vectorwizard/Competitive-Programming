#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s,t;
    cin>>s;
    cin>>t;
    string ans = "";
    vector<int> hasht(26,0);
    vector<int> hashs(26,0);
    for(int i=0;i<t.size();i++){
        hasht[t[i]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        hashs[s[i]-'a']++;
    }
    vector<int> excess(26,0);
    for(int i=0;i<26;i++){
        if(hashs[i]>hasht[i]){
            cout<<"Impossible"<<endl;
            return;
        }
        excess[i] = hasht[i]- hashs[i];
    }
    int excess_ptr = 0;
    for (char c : s) {
        int current_char_idx = c - 'a';

        while (excess_ptr < current_char_idx) {
            while (excess[excess_ptr] > 0) {
                ans += (char)('a' + excess_ptr);
                excess[excess_ptr]--;
            }
            excess_ptr++;
        }
        ans += c;
    }
    for(int i=0;i<26;i++){
        while(excess[i]>0){
            ans+=(char)('a'+i);
            excess[i]--;
        }
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