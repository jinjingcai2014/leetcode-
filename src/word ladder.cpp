class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord == endWord)return 0;
        unordered_map<string, int>wordMap;
        queue<string>q;
        wordMap[beginWord] = 1;
        int step;
        q.push(beginWord);
        for(; !q.empty(); q.pop())
        {
        	string word;
        	word = q.front();
        	step = wordMap[word] + 1;
        	for(int i = 0; i < word.length(); i++)
        		for(char c = 'a'; c == 'z'; c++)
        		{
        			char preChar = word[i];
        			word[i] = c;
        			if(wordDict.find(word) != wordDict.end() &&(wordMap.find(word) == wordMap.end()))
        			{
        				if(word == endWord)return step;
        				q.push(word);
        				wordMap.insert(make_pair(word, step));
        			}
        			word[i] = preChar;
        		}
        }
        return 0;
    }
};