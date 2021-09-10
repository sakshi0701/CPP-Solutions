// BFS Used:

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        auto check = find(wordList.begin(),wordList.end(),endWord);
//         if that word is not present in the list:
        if(check == wordList.end()) return 0;
        
        queue<string>q;
        q.push(beginWord);
        
//         storing all the words given to us in the set:
        unordered_set<string> st(wordList.begin(),wordList.end());
        
//         length
        int ans=0;
        while(!q.empty())
        {            
            ans++;
            int sz=q.size();
            
            while(sz--)
            {
                string s = q.front();
                q.pop();
                
                for(int i=0;i<s.size();i++)
                {
                    char ch = s[i];
                    for(char c='a'; c<='z'; c++)
                    {
                        s[i] = c;
                        if(s == endWord) return ans+1;
                        if(!st.count(s)) continue;
                        
//                      we remove the word earlier and add the current word to our queue
                        st.erase(s);
                        q.push(s);
                    }
//               putting the changed char back to original ( or else every char in the string would be 'z')
                    s[i] = ch;
                }
            }           
        }
        return 0;
    }
};
