// https://leetcode.com/problems/implement-strstr/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strStr(string& haystack, string& needle)
{
    size_t haystack_len = haystack.length();
    size_t needle_len = needle.length();

    if (needle_len == 0) return 0;
    if (needle_len > haystack_len) return -1;

    // Compute prefix function
    vector<int> pi;
    pi.reserve(needle_len + 1);

    pi[0], pi[1] = 0;
    int k = 0;

    for(int q = 2; q < needle_len+1; q++) {
        // cout << needle[k] << ", " << needle[q-1] << endl;
        while(k > 0 && needle[k] != needle[q-1]) k = pi[k];
        if (needle[k] == needle[q-1]) k++;
        pi[q] = k;
    }

    // Search for `needle` in the `haystack` :P
    int q = 0;
    for (int i = 0; i < haystack_len; i++) {
        cout << haystack[i] << ", " << needle[q] << endl;
        while(q > 0 && haystack[i] != needle[q]) q = pi[q];
        if (haystack[i] == needle[q]) q++;
        if (q == needle_len) return i - needle_len + 1;
    }

    return -1;
}

int main(int argc, const char** argv) {
    
    string str = "ababcabcabababd";
    string pattern = "ababd";
    
    cout << strStr(str, pattern) << endl;

    return 0;
}