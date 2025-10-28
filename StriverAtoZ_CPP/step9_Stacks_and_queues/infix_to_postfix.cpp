#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int priority(char a){
    if(a=='^'){
        return 3;
    }else if(a=='*' || a=='/'){
        return 2;
    }else if(a=='+' || a=='-'){
        return 1;
    }else{
        return -1;
    }
}
int main(){
    string a = " ((A+B)*(C-D))";
    string ans = "";
    int l=a.length();
    int i=0;
    stack<int> st;
    while(i<l){
        if((a[i]<='A' && a[i]>='Z') || (a[i]<='a' && a[i]>='z')){
            ans+=a[i];
        }else if(a[i]=='('){
            st.push(a[i]);
        }else if(a[i]==')'){
            while(st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(st.empty() && priority(a[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(a[i]);
        }
    }
    cout<<ans;
}