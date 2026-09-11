class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<long long> st;
        long long number = 0;
        long long result = 0;
        int sign = 1;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                number = number*10 + (s[i]-'0');
            } else if(s[i]=='+'){
                result += number*sign;
                number = 0;
                sign = 1;
            } else if(s[i]=='-'){
                result += number*sign;
                number = 0;
                sign = -1;
            } else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i]==')'){
                result += number*sign;   // (also fixed from earlier)
                number = 0;

                long long stack_sign = st.top(); st.pop();
                long long last_result = st.top(); st.pop();

                result *= stack_sign;
                result += last_result;
            }
        }
        result += number*sign;
        return (int)result;   // cast back since the function returns int
    }
};