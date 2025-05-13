
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
T datatype_checker(const string& prompt);

#ifndef MYFUNSHARE_H
#define MYFUNSHARE_H

int levenshtein_distance(const string& s1, const string& s2) {
    const int len1 = s1.length();
    const int len2 = s2.length();

    int** d = new int*[len1 + 1];
    for (int i = 0; i <= len1; i++) {
        d[i] = new int[len2 + 1];
    }

    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] != s2[j - 1]);

            int del = d[i - 1][j] + 1;
            int ins = d[i][j - 1] + 1;
            int sub = d[i - 1][j - 1] + cost;

            d[i][j] = del;
            if (ins < d[i][j]) d[i][j] = ins;
            if (sub < d[i][j]) d[i][j] = sub;
        }
    }

    int result = d[len1][len2];

    for (int i = 0; i <= len1; i++) {
        delete[] d[i];
    }
    delete[] d;

    return result;
}

string to_lower(const string& str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + ('a' - 'A');
        }
    }
    return result;
}

bool is_similar(const string& s1, const string& s2, int threshold = 2) {
    string lower_s1 = to_lower(s1);
    string lower_s2 = to_lower(s2);

    return levenshtein_distance(lower_s1, lower_s2) <= threshold;
}

#endif