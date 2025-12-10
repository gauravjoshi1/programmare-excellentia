class Solution {
public:
    bool isAnagram(string s, string t) {
        // m1
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // for (int i = 0; i < min((int)s.size(), (int)t.size()); i++) {
        //     if (s[i] != t[i]) return false;
        // }
        // return s.size() == t.size();

        // m2
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) if (freq[i] != 0) return false;
        return true;
    }
};
