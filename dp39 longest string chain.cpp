class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //sort based on the length
        sort(words.begin(),words.end(),[](const string &a, const string &b){return a.length() < b.length();});
        return helper(words);
    }
    
    //watch striver's dp 42 lecture video to understand this dp method
    int helper(vector<string> &words){
        int n = words.size();
        
        vector<int> longest(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && longest[i] < longest[j] + 1){
                    longest[i] = longest[j] + 1;
                    maxi = max(maxi, longest[i]);
                }
            }
        }
        
        return maxi;
    }
    
    //here s2 is the smaller string and s1 is the larger string
    int compare(string &s1, string &s2){
        if(s1.length() - 1 != s2.length())
            return 0;
        
        int i = 0, j = 0;
        
        while(i < s1.length()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
            
        }
        
        //if the longer string ends but the shorter string doesn't, means shorter string is not a predecessor or the 
        //longer string
        if(i == s1.length() && j == s2.length()){
            return 1;
        }
        else
            return 0;
        
    }
};
