// https://leetcode.com/problems/valid-parenthesis-string/description/

// SOLUTION - 

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(open.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }
                else open.pop();
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else star.push(i);
        }
        while(!open.empty()){
            if(star.empty() || open.top()>star.top()) return false;
            else {
                star.pop();
                open.pop();
            }
        }
        return true;
    }
};