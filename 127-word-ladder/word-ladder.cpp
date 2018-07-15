// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time.
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return 0 if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if(beginWord==endWord) return 1;
    int wl=beginWord.length();
    map<string,int> list_a;
    auto it=wordList.begin();
    while(it!=wordList.end()){
        list_a[*it]=0;
        it++;
    }
    list_a[beginWord]=0;
    list_a[endWord]=0;
    map<string,int> list_b(list_a);
    list_a[beginWord]=1;
    list_b[endWord]=1;
    queue<string> qa,qb;
    qa.push(beginWord);
    qb.push(endWord);
    while(!qa.empty() && !qb.empty()){
        string sa=qa.front();
        qa.pop();
        for(int i=0;i<wl;i++)
            for(int j=0;j<26;j++){
                char c='a'+j;
                if(sa[i]==c) continue;
                string ns=sa;
                ns[i]=c;
                auto ait=list_a.find(ns);
                if(ait!=list_a.end()){
                    if(ait->second>0) continue;
                    if(list_b[ns]>0)
                        return list_b[ns]+list_a[sa];
                    qa.push(ait->first);
                    ait->second=list_a[sa]+1;
                }
            }

        string sb=qb.front();
        qb.pop();
        for(int i=0;i<wl;i++)
            for(int j=0;j<26;j++){
                char c='a'+j;
                if(sb[i]==c) continue;
                string ns=sb;
                ns[i]=c;
                auto ait=list_b.find(ns);
                if(ait!=list_b.end()){
                    if(ait->second>0) continue;
                    if(list_a[ns]>0)
                        return list_a[ns]+list_b[sb];
                    qb.push(ait->first);
                    ait->second=list_b[sb]+1;
                }
            }
    }
    return 0;
}
};
