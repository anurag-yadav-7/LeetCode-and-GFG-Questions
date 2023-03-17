class Trie {
    unordered_set<string> st;
    unordered_set<string> st2;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        st.insert(word);
        int len=word.length();
        for(int i=1;i<=len;i++)
        {
            string temp=word.substr(0,i);
            // cout<<"substring: "<<temp<<endl;
            st2.insert(temp);
        }
    }
    
    bool search(string word) {
        if(st.find(word)==st.end())
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        if(st2.find(prefix)==st2.end())
            return false;
        return true;
            
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */