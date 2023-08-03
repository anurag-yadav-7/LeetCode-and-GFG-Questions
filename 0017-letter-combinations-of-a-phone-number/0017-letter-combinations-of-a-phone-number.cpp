class Solution {

    void rec(int ind, string &digits, string &temp, vector<string> &ans, map<char,vector<char>> &mp)
    {
        // cout<<"temp: "<<temp<<endl;
        if(temp.length() == digits.length())
        {
            ans.push_back(temp);
            return;
        }
        // cout<<"digits[i]: "<<digits[ind]<<" size: "<<mp[digits[ind]].size()<<endl;
        for(int i = 0 ; i<mp[digits[ind]].size(); i++)
        {
            temp.push_back(mp[digits[ind]][i]);
            rec(ind+1 ,digits, temp, ans, mp);
            temp.pop_back();
        }
    }
        
public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mp;
        if(digits.length() == 0)
            return {};
        
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        string temp = "";
        int n = digits.length();
        vector<string> ans;
        // cout<<"digits[0]: "<<digits[0]<<endl;.
        for(int i = 0 ; i<mp[digits[0]].size() ; i++)
        {
            temp.push_back(mp[digits[0]][i]);
            // cout<<"temp: "<<temp<<endl;
            rec(1,digits, temp, ans, mp);
            temp.pop_back();
        }
        
        return ans;
    }
};