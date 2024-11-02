#include "sentense_filter.h"

SentenceFilter::SentenceFilter() : source(""), count(0), isTextSource(false) {cout << "Вызван конструктор без параметров для класса SentenceFilter\n";}

SentenceFilter::SentenceFilter(const char* filename, int count)
    : count(count), isTextSource(false) {
    source = new char[strlen(filename) + 1];
    strcpy(source, filename);
    cout << "Вызван конструктор c параметрами для класса SentenceFilter\n";
}

SentenceFilter::SentenceFilter(const char* text, int count, bool isText)
    : count(count), isTextSource(isText) {
    source = new char[strlen(text) + 1];
    strcpy(source, text);
    cout << "Вызван конструктор копирования для класса SentenceFilter\n";
}

SentenceFilter::~SentenceFilter() {
    delete[] source;
    cout << "Вызван деструктор для класса SentenceFilter\n";
}

void SentenceFilter::result() const {
    char* text = new char[8192];
    if (isTextSource) {
        strncpy(text, source, 8192 - 1);
        text[8191] = '\0';
    } else {
        ifstream file(source);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл: " << source << endl;
            delete[] text;
            return;
        }
        file.read(text, 8191);
        text[file.gcount()] = '\0';
        file.close();
    }
    cout << "Считанный текст:\n" << text << "\n\n";
    char** sentences = nullptr;
    int sentenceCount = 0;
    split_into_sent(text, sentences, sentenceCount);
    delete[] text;
    cout << "Всего найдено предложений: " << sentenceCount << endl;
    for (int i = 0; i < sentenceCount; ++i) {
        int words = count_words(sentences[i]);
        if (words == count) {
            cout << sentences[i] << endl;
        }
        delete[] sentences[i];
    }
    delete[] sentences;
}

void SentenceFilter::split_into_sent(const char* text, char**& sentences, int& sentenceCount) const {
    sentenceCount = 0;
    const int maxSentences = 100;
    const int maxLength = 100;
    sentences = new char*[maxSentences]; 
    int charIndex = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            if (sentenceCount < maxSentences) {
                sentences[sentenceCount] = new char[charIndex + 2];
                strncpy(sentences[sentenceCount], text + i - charIndex, charIndex);
                sentences[sentenceCount][charIndex] = '\0';
                sentenceCount++;
                charIndex = 0;
            }
        } else {
            charIndex++;
        }
    }
    if (charIndex > 0 && sentenceCount < maxSentences) {
        sentences[sentenceCount] = new char[charIndex + 1];
        strncpy(sentences[sentenceCount], text + strlen(text) - charIndex, charIndex);
        sentences[sentenceCount][charIndex] = '\0';
        sentenceCount++;
    }
    if (sentenceCount == 0) {
        delete[] sentences;
        sentences = nullptr;
    }
}


int SentenceFilter::count_words(const char* sentence) const {
    int count = 0;
    bool inWord = false;
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (isspace(sentence[i])) {
            if (inWord) {
                count++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }
    if (inWord)
        count++;
    return count;
}
