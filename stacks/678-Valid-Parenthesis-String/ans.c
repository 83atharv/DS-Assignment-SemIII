// https://leetcode.com/problems/valid-parenthesis-string/description/

// SOLUTION - 

#define MAX_SIZE 1000

bool checkValidString(char *s) {
    int st[MAX_SIZE];
    int sr[MAX_SIZE];
    int st_top = -1;
    int sr_top = -1;

    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            st[++st_top] = i;
        } else if (s[i] == '*') {
            sr[++sr_top] = i;
        } else { 
            if (st_top >= 0) {
                st_top--;  
            } else if (sr_top >= 0) {
                sr_top--; 
            } else {
                return false;  
            }
        }
    }

    while (st_top >= 0) {
        if (sr_top < 0) {
            return false; 
        } else if (st[st_top] < sr[sr_top]) {
            st_top--;
            sr_top--;
        } else {
            return false; 
        }
    }

    return true;
}