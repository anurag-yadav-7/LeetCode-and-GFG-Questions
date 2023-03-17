class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res = "" ;
        unordered_set < string > st ;
        
        int len= sentence.length() ;
        
        for( auto it : dictionary )
        {
            // cout<<"inserted into st: "<< it << endl;
            st.insert( it ) ;
        }
        
        string currword="";
        for( int i = 0 ; i < len ; i++ )
        {
            // cout << " curr i : " << i <<" currletter "<< sentence[i]<<endl;
            // cout << " currword: " << currword <<endl;
            // cout << " curres: "<< res << endl;
            
            
            if(currword!="" && sentence[i] == ' ' && st.find( currword)==st.end() )
            {
                res = res + currword + " ";
                currword = "" ;
                continue;
            }
            
            if(sentence[i]!=' '){
                // cout<<"appending "<<sentence[i]<<" at the end o word: "<<currword<<endl;   
                currword=currword+sentence[i];
                // cout<<" new currword: "<< currword<<endl;
            }
            
            if( st.find( currword) != st.end() )
            {
                res = res+ currword + " " ;
                // cout<<" now skipping characters: i = ";
                while(i< len && sentence[i]!=' ')
                {
                    i++;
                    // cout<<i<<" ";
                }
                
                i--;
                // cout<<" finally i: "<<i<< endl;
                currword = "";
            }
        }
        if(currword!="")
            res+=currword+" ";
        if(res.length()>0)
        res.pop_back();
        return res;
        
    }
};