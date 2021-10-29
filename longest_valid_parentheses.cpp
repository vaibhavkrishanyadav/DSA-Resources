// 32. Longest Valid Parentheses
int longestValidParentheses(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int dp[s.length()];
        dp[0]=0;
        st.push(0);
        
        for (int i=1;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
                dp[i]=dp[i-1];
            }
            else
            {
                if(st.top()==-1)
                {
                    dp[i]=dp[i-1];
                    st.push(i);
                }
                else if(s[st.top()]=='(')
                {
                    st.pop();
                    dp[i]=max(i-st.top(),dp[i-1]);
                }
                else
                {
                    st.push(i);
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[s.length()-1];
    }
