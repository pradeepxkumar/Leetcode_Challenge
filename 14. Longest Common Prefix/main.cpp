class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i =0;
        string first = strs[0], last = strs.back();
        while(i<first.size() && i<last.size() && first[i]==last[i]){
            i++;
        }
    return first.substr(0,i);
    }
};