class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string>current, next;//当前层，下一层，主要是为了去重
	    unordered_set<string>visited;//判断是否重复
	    unordered_map<string, vector<string> >father; //

	    int level = 0;
	    bool found = false;
	    current.push(beginWord);

	    while(!current.empty() && !found)
	   {
		    level++;
		    while(!current.empty() && !found)
		    {
			    const string str = current.front();
				current.pop();
				vector<string>new_states;
				new_states = state_extend(new_states, str, visited, wordDict);
				for(const auto &state : new_states )
				{
					next.push(state);
					if(state_is_target(state, endWord))
					{
						found = true;
						break;
					}
				}
			}
			swap(next, current);
		}
		if(found)return level+1;
		else return 0;
}

bool state_is_target(const string&s, const string&end)
{
	return s == end;
}

vector<string> state_extend(vector<string>&result, const string&s, unordered_set<string>&visited, unordered_set<string>&wordDict)
{
	

	for(size_t i  = 0; i < s.size(); i++)
	{
		string new_word(s);
		for(char c = 'a'; c <= 'z'; c++)
		{
			if(c == new_word[i])continue;
			swap(c, new_word[i]);

			if(wordDict.count(new_word) > 0 && !visited.count(new_word))
			{
				result.push_back(new_word);
				visited.insert(new_word);
			}
			swap(c, new_word[i]);
		}
	}
	return result;
}
    
};

/*****************word ladderII*********************/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string>current, next;
        unordered_set<string>visited;
        unordered_map<string, vector<string> > trace_pre; //map<current, pre>
        
        bool found = false;
        
        current.insert(start);
        while(!current.empty() && !found)
        {
            
            for( auto& vis_word : current)
                visited.insert(vis_word);
             
                
            for(unordered_set<string>::iterator iter = current.begin(); iter != current.end(); iter++)
            {
                string word = *iter;
                auto extend_words = word_is_extend(word, dict, end, visited);
                for(const auto& ex_wo : extend_words)
                {
                    if(ex_wo == end)found = true;
                    next.insert(ex_wo);
                    trace_pre[ex_wo].push_back(word);
                    
                }
            }
            
            current.clear();
            swap(current, next);
        }
        vector<vector<string> > result;
        if(found)
        {
            vector<string> path;
            path_find(result, path, trace_pre, start, end);
        }
        
        return  result;
        
    }
    unordered_set<string> word_is_extend( string &word,  unordered_set<string> &dict, const string& end, unordered_set<string>&visited)
    {
        unordered_set<string>extend_words;
        string word_copy(word);
        for(size_t i = 0; i < word_copy.size(); i++)
        {
            
            for(char c = 'a'; c <= 'z'; c++)
            {
                char temp = word_copy[i];
                if(c != word_copy[i])
                {
                    word_copy[i] = c;
                    if((dict.find(word_copy) != dict.end() ||(end == word_copy))&& !visited.count(word_copy))
                        extend_words.insert(word_copy);
                }
                word_copy[i] = temp;
            }
        }
        
        return extend_words;
    }
    void path_find(vector<vector<string> >&result, vector<string>&path, unordered_map<string, vector<string> >&trace_pre, const string &start, const string&end)
    {
        path.push_back(end);
        if(start == end)
        {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        }
        else
        {
            for(const auto& pre_word : trace_pre[end])
                path_find(result, path, trace_pre, start, pre_word);
        }
        
        path.pop_back();
    }
    
