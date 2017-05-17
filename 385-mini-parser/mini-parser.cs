// Given a nested list of integers represented as a string, implement a parser to deserialize it.
//
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
// Note:
// You may assume that the string is well-formed:
//
// String is non-empty.
// String does not contain white spaces.
// String contains only digits 0-9, [, - ,, ].
//
//
//
// Example 1:
//
// Given s = "324",
//
// You should return a NestedInteger object which contains a single integer 324.
//
//
//
// Example 2:
//
// Given s = "[123,[456,[789]]]",
//
// Return a NestedInteger object containing a nested list with 2 elements:
//
// 1. An integer containing value 123.
// 2. A nested list containing two elements:
//     i.  An integer containing value 456.
//     ii. A nested list with one element:
//          a. An integer containing value 789.


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * interface NestedInteger {
 *
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool IsInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     int GetInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void SetInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void Add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     IList<NestedInteger> GetList();
 * }
 */
public class Solution
{
    public NestedInteger Deserialize(string s)
    {
        //Console.WriteLine(s);
        if(s.Length<=0) return null;
        if(s[0]!='[') 
        {
            int i=0;
            if(s[0]=='-') i++;
            int num=0;
            for(;i<s.Length;i++)
            {
                num*=10;
                num+=s[i]-'0';
            }
            if(s[0]=='-') num=0-num;
            return new NestedInteger(num);
        }
        else
        {
            NestedInteger res=new NestedInteger();
            int b=1, p=1;
            while(p<s.Length)
            {
                if(s[p]=='[')
                {
                    int pp=p;
                    int counter=1;
                    while(counter>0)
                    {
                        pp++;
                        if(s[pp]=='[') counter++;
                        if(s[pp]==']') counter--;
                    }
                    NestedInteger ni=Deserialize(s.Substring(p,pp-p+1));
                    if(ni!=null) res.Add(ni);
                    p=pp+1;
                }
                else
                {
                    int pp=p;
                    while(pp<s.Length-1 && s[pp]!=',') pp++;
                    NestedInteger ni=Deserialize(s.Substring(p,pp-p));
                    if(ni!=null) res.Add(ni);
                    p=pp+1;
                }
            }
            return res;
        }
    }
}
