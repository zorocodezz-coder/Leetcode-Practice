class Solution {
public:
    struct trie{
        trie* children[26];
        trie(){
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };

    void build_trie(string & s,trie* root){
        trie* curr=root;

        for(char &c:s){
            int idx = c-'a';
            if(!curr->children[idx]){
                curr->children[idx]=new trie();
            }
            curr = curr->children[idx];
        }
    }
    int fun(string s, trie* root){
        trie* curr = root;
        for(char c:s){
            int idx = c-'a';
            if(curr->children[idx]==nullptr)return 0;
            curr=curr->children[idx];
        }
        return 1;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        trie* root=new trie();
      for(int i=0;i<word.size();i++){
        string temp="";
        for(int j=i;j<word.size();j++){
            temp+=word[j];
        }
        build_trie(temp,root);
      }
      int count=0;
      for(auto str:patterns){
       count+= fun(str,root);
      }
      return count;
    }
};