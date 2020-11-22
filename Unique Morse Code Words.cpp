class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>ar={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
        unordered_set<string> gen_codes;
    
        for(auto word : words) {
            string code = "";
            for(auto ch : word)
                code += ar[ch - 'a'];
            gen_codes.insert(code);
        }
    
        return gen_codes.size();
    }
};
