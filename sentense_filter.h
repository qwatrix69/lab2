#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype> 

using namespace std;

class SentenceFilter {
public:
    SentenceFilter();
    SentenceFilter(const char* filename, int wordCount);
    SentenceFilter(const char* text, int wordCount, bool isText);
    ~SentenceFilter();
    void result() const;

private:
    char* source;
    int count;
    bool isTextSource; 

    void split_into_sent(const char* text, char**& sentences, int& sentenceCount) const;
    int count_words(const char* sentence) const;
};
