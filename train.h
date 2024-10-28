#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Train {
    private:
        string destination;
        int number;
        string time_of_departure;
    public:
        Train();
        Train(const string& d, const int& n, const string& t);
        Train(const Train& other);
        ~Train();

        string get_destination();
        void set_destination(const string& d);
        int get_number();
        void set_number(const int& n);
        string get_time();
        void set_time(const string& t);

        void display_train();
        void edit_train();
};