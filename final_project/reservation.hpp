#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>
#include <iomanip>
#include <bits/stdc++.h>
#include <utility>
#include <cstring>
#include <regex>
#include <stdlib.h>
#include <stdio.h>
#include "user.hpp"


using namespace std;
class User;
class Reservation {
    vector<User> users;
    bool isFree;
    string reservationType;

    public:
        Reservation(User u, bool isFree, string reservationType);
        Reservation(vector<User> u, bool isFree, string reservationType);
        void modify(User u);
        void modify(User u, string reservationType); 
        vector<User> getUsers();
        User getUserInfo();
        bool getIsFree();
        string getReservationType();
        void addUser(User u);
        string getReservationInfo();
        void setIsFree(bool b);
        friend ostream & operator <<(ostream &out, Reservation &r);





                            // Destructor
    ~Reservation() {}

    // Copy constructor
    Reservation(const Reservation& other) {
            this->users = other.users;
            this->isFree = other.isFree;
            this->reservationType = other.reservationType;
        }

    // Copy assignment operator
    Reservation& operator=(const Reservation& other) {
        if (this != &other) {
            users = other.users;
           isFree = other.isFree;
            reservationType = other.reservationType;
        }
        return *this;
    }

    // Move constructor
    Reservation(Reservation&& other) :
        users(move(other.users)), isFree(move(other.isFree)),
        reservationType(move(other.reservationType)) {}

    // Move assignment operator
    Reservation& operator=(Reservation&& other) {
        if (this != &other) {
            users = move(other.users);
            isFree = move(other.isFree);
            reservationType = move(other.reservationType);
        }
        return *this;
    }
};