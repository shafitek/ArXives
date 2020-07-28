// https: //leetcode.com/problems/encode-and-decode-tinyurl/

#include <chrono>
#include <random>

class Solution
{
public:
    unordered_map<long int, string> db;
    string idToShortURL(long int n)
    {
        // Map to store 62 possible characters
        char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                     "GHIJKLMNOPQRSTUVWXYZ0123456789";

        string shorturl;

        // Convert given integer id to a base 62 number
        while (n)
        {
            shorturl.push_back(map[n % 62]);
            n = n / 62;
        }

        // Reverse shortURL to complete base conversion
        reverse(shorturl.begin(), shorturl.end());

        return shorturl;
    }

    // Function to get integer ID back from a short url
    long int shortURLtoID(string shortURL)
    {
        long int id = 0; // initialize result

        // A simple base conversion logic
        for (int i = 0; i < shortURL.length(); i++)
        {
            if ('a' <= shortURL[i] && shortURL[i] <= 'z')
                id = id * 62 + shortURL[i] - 'a';
            if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
                id = id * 62 + shortURL[i] - 'A' + 26;
            if ('0' <= shortURL[i] && shortURL[i] <= '9')
                id = id * 62 + shortURL[i] - '0' + 52;
        }
        return id;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        minstd_rand0 generator(42);
        long int rand_val = generator();

        while (db.count(rand_val) > 0)
            rand_val = generator();

        db[rand_val] = longUrl;

        return idToShortURL(rand_val);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        long int id = shortURLtoID(shortUrl);
        return db[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));