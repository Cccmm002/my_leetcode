// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
//
//
// Example :
// Input: 
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
//
//
// Note:
//
//
// 	All words in words and S will only consists of lowercase letters.
// 	The length of S will be in the range of [1, 50000].
// 	The length of words will be in the range of [1, 5000].
// 	The length of words[i] will be in the range of [1, 50].
//


public class TrieNode {
    public TrieNode[] children;
    public char current;
    public int word_count;
    
    public TrieNode(int c) {
        children=new TrieNode[26];
        for (int i=0;i<26;i++)
            children[i] = null;
        word_count=0;
        current=(char)(c+(int)'a');
    }
}

public class Solution {
    private int get_count(TrieNode root, string s, int start) {
        int n=s.Length;
        int p;
        for (p=start;p<n;p++) {
            if (s[p] == root.current)
                break;
        }
        if (p>=n) return 0;
        int res = root.word_count;
        for (int i=0;i<26;i++) {
            if (root.children[i]!=null)
                res += get_count(root.children[i], s, p+1);
        }
        return res;
    }
    
    public int NumMatchingSubseq(string S, string[] words) {
        TrieNode root=new TrieNode(-1);
        for (int ii=0;ii<words.Length;ii++) {
            string word=words[ii];
            int n = word.Length;
            TrieNode cur=root;
            for (int i=0;i<n;i++) {
                int c=word[i]-'a';
                if (cur.children[c] == null)
                    cur.children[c] = new TrieNode(c);
                cur = cur.children[c];
                if (i==n-1)
                    cur.word_count += 1;
            }
        }
        int ns = S.Length;
        int res = 0;
        for (int i=0;i<26;i++) {
            if (root.children[i]!=null)
                res += get_count(root.children[i], S, 0);
        }
        return res;
    }
}
