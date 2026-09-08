class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        string result="";
        int n=s.size();

        for(int i=0;i<n;i++){
            if(st.empty()||st.top()!=s[i]){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;

    }
};