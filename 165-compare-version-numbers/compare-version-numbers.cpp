// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Example 1:
//
//
// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
//
// Example 2:
//
//
// Input: version1 = "1.0.1", version2 = "1"
// Output: 1
//
// Example 3:
//
//
// Input: version1 = "7.5.2.4", version2 = "7.5.3"
// Output: -1
//


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        string remain1 = "", remain2 = "";
        if (version1.size() == 0 && version2.size() == 0)
            return 0;
        if (version1.size() > 0) {
            int dot = version1.find('.');
            if (dot == string::npos) {
                v1 = stoi(version1);
            }
            else {
                v1 = stoi(version1.substr(0, dot));
                remain1 = version1.substr(dot + 1, version1.size() - dot - 1);
            }
        }
        if (version2.size() > 0) {
            int dot = version2.find('.');
            if (dot == string::npos) {
                v2 = stoi(version2);
            }
            else {
                v2 = stoi(version2.substr(0, dot));
                remain2 = version2.substr(dot + 1, version2.size() - dot - 1);
            }
        }
        if (v1 > v2)
            return 1;
        else if (v1 < v2)
            return -1;
        else
            return compareVersion(remain1, remain2);
    }
};
