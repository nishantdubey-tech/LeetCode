class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n=s.length();
      int hashlen=256;
      int hash[hashlen];
      for(int i=0;i<256;i++){
        hash[i]=-1;
      }
      int l=0; 
      int r=0;
      int maxlen=0;
      while(r<n){
      if(hash[s[r]]!= -1){
        l=max(hash[s[r]]+1,l);
        
      }
      hash[s[r]]=r;
      int len=r-l+1;
      maxlen=max(maxlen,len);
      r++;
      }
      return maxlen;
    }

};