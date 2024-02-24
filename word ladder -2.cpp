class Solution {
public:
    vector<vector<string>> findLadders(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({startWord});
        vector<vector<string>> result;
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(startWord);

        while (!q.empty()) {
            vector<string> current_list = q.front();
            string currentWord = current_list[current_list.size() - 1];
            q.pop();
            // if the current list size is greater than level
            // that means we are on another level
            if (current_list.size() > level) {
                level++;
                // erase all the element from previos level
                for (int i = usedOnLevel.size() - 1; i >= 0; i--) {
                    dictionary.erase(usedOnLevel[i]);
                    usedOnLevel.pop_back();
                }

            }
            if (currentWord == targetWord) {
                // check if it's the first list
                if (result.size() == 0) {
                    result.push_back(current_list);
                }
                // check if the current list length is same as result's element array lentgh
                else if (result[0].size() == current_list.size()) {
                    result.push_back(current_list);
                }
            }
            
            for (int i = 0; i < startWord.size(); i++) {
                char originalChar = currentWord[i];
                // change each character at index i and check if the modified word exists in the dicionary
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    currentWord[i] = ch;
                    if (dictionary.find(currentWord) != dictionary.end()) {
                        current_list.push_back(currentWord);
                        q.push(current_list);
                        usedOnLevel.push_back(currentWord);
                        current_list.pop_back();
                        
                    }
                }
                currentWord[i] = originalChar;
            }
            
        }
        return result;

    }
};
