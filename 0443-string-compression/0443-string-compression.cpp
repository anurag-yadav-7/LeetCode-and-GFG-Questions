class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int ind = 0;
            char curr;
            bool flag = false;
            int count = 0;
            for (int i = 0; i < chars.size(); i++)
            {
                // cout<<"currently at: "<<chars[i]<<": "<<endl;
                if (flag == false)
                {
                    curr = chars[i];
                    flag = true;
                    count++;
                    ind++;
                }
                else if (chars[i] != curr)
                {
                    // cout<<"final freq of: "<<curr<<" --> "<<count<<endl;
                    if (count == 1)
                    {
                        curr = chars[i];
                        chars[ind] = curr;
                        ind++;
                        continue;
                    }
                    if (count > 9)
                    {
                        string temp = "";
                        while (count)
                        {
                            temp += (count % 10)+48;
                            count = count / 10;
                        }
                        // cout<<"temp count: "<<temp<<endl;
                        for (int j = temp.length() - 1; j >= 0; j--)
                        {
                            chars[ind] = temp[j];
                            ind++;
                        }
                        curr=chars[i];
                        chars[ind]=curr;
                        ind++;
                        count=1;
                        continue;
                    }
                    chars[ind] = count + 48;
                    ind++;
                    curr = chars[i];
                    chars[ind] = curr;
                    count = 1;
                    ind++;
                }
                else if (chars[i] == curr)
                {
                    count++;
                }
            }

            if (count > 9)
            {
                // cout<<"final freq of: "<<curr<<"-->"<<count<<endl;
                string temp = "";
                while (count)
                {
                    temp += (count % 10)+48;
                    count = count / 10;
                }
                for (int j = temp.length() - 1; j >= 0; j--)
                {
                    chars[ind] = temp[j];
                    ind++;
                }
            }
            else if (count > 1)
                chars[ind++] = count + 48;
            
            return ind;
        }
};