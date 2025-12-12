class Solution {
public:
    int romanToInt(string s) {
        int en = s.size() - 1;
        int res = get_val(s[en]);
        en--;
        while (en >= 0) {
            if (get_val(s[en]) >= get_val(s[en + 1])) res += get_val(s[en]);
            else res -= get_val(s[en]);
            en--;
        }
        return res;
    }
    
    int get_val(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return -1;
    }
};
