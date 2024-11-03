#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

class SentenceFilter {
private:
    string source;
    int count;
    bool isTextSource;

    void split_into_sent(const string& text, string*& sentences, int& sentenceCount) const;
    int count_words(const string& sentence) const;

public:
    SentenceFilter();
    SentenceFilter(const string& filename, int wordCount);
    SentenceFilter(const string& text, int wordCount, bool isText);
    ~SentenceFilter();
    void result() const;
};