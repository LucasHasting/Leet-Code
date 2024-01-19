class Solution {
public:
    bool isAnagram(string s, string t) {
        //if the two strings are not the same length, they can not be annograms
        if(s.length() != t.length())
            return false;
        
        //sort both strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        //check to see if the strings contain the same letters
        for (int i = 0; i < s.length(); i++){
            if (s[i] != t[i])
                return false;
        }

        return true;
    }
};
