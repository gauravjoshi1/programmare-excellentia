class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int rev = 0;
        int temp = x;
        while (x) {
            if (rev > (INT_MAX / 10)) return false;
            rev = (rev * 10) + (x % 10);
            x = (x / 10);
        }
        return temp == rev;
    }
};
