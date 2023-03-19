class TrieNode{
    public:
        bool isComplete;
        TrieNode* children[26];

        TrieNode(){
            isComplete=false;
            memset(children,0,sizeof(children));
        }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto it:word){
            int ind = it - 'a';
            if(node->children[ind]==NULL)
                node->children[ind] = new TrieNode();
            node=node->children[ind];
        }
        node->isComplete=true;
    }
    bool checkPresence(TrieNode* node,string word,int ind){
        if(ind==word.size())
            return node->isComplete;
        bool left=false,right=false;
        if(word[ind]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL)
                    left = left || checkPresence(node->children[i],word,ind+1);
            } 
        }
        else{
            int x = word[ind] - 'a';
            if(node->children[x]==NULL)
                return false;
            right = checkPresence(node->children[x],word,ind+1);
        }
        return left || right;
    }
    bool search(string word) {
        TrieNode* node = root;
        if(checkPresence(root,word,0))
            return true;
        return false;
    }
};