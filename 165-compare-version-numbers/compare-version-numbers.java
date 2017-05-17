// Compare two version numbers version1 and version2.
// If version1 &gt; version2 return 1, if version1 &lt; version2 return -1, otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Here is an example of version numbers ordering:
// 0.1 &lt; 1.1 &lt; 1.2 &lt; 13.37
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


public class Solution {
    public int compareVersion(String version1, String version2) {
        Scanner parser1=new Scanner(version1).useDelimiter("\\.");
        Scanner parser2=new Scanner(version2).useDelimiter("\\.");
        while(parser1.hasNextInt() && parser2.hasNextInt()) {
            int v1=parser1.nextInt();
            int v2=parser2.nextInt();
            if(v1>v2)
                return 1;
            else if(v1<v2)
                return -1;
        }
        while(parser1.hasNextInt()) {
            if(parser1.nextInt()!=0)
                return 1;
        }
        while(parser2.hasNextInt()) {
            if(parser2.nextInt()!=0)
                return -1;
        }
        return 0;
    }
}
