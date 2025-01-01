// https://leetcode.com/problems/clear-digits/description/

// SOLUTION - 

char* clearDigits(char* s) {
    char* ans = malloc((strlen(s) + 1)*sizeof(char));
    int i = 0, k = 0;
    while (s[i] != '\0') {
        if (s[i]>=0 &&s[i] <= '9'){
            k--; 
        } else{
            ans[k++] = s[i]; 
        }
        i++;
    }
    ans[k] = '\0';
    return ans;
}