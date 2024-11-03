#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "train.h"

using namespace std;

struct Node
{
    Node* next;
    Train* data;
};

class Container
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    Container();
    Container(Node* h, Node* t, const int c);
    Container(const Container& other);
    ~Container();

    Node* get_head();
    Node* get_tail();

    void add_train(Train* Tr, int index);
    Container& delete_train(int index);
    Container& edit_train(int index);
    void display_trains();
    void sort_trains_by_number();
    void search_train(const int number);

    Container& operator[](int index);
};

