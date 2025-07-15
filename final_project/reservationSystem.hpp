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
#include "reservation.hpp"
#include <ctime>


using namespace std;

class ReservationSystem {

    // vector of all the users
    vector<User> users;
    // vector of all reservations within this system

    vector<Reservation> court1;
    vector<Reservation> court2;
    vector<Reservation> court3;

    

    public:
        ReservationSystem();
        void modifyReservation(int court, int slot, User u);
        void modifyReservation(int court, int slot, User u, string reservationType);
        void addMember(User u);
        bool login(string username, string password);
        string viewSchedule();
        void reserve();
        void cancelReservation(Reservation r);
        void cancelReservation(int court, int slot);
        void printGrid();
        void addReservation(Reservation r, int courtNumber);
        void addReservation(Reservation r, int courtNumber, int slot);
        string getCourt1Info();
        string getCourt2Info();
        string getCourt3Info();
        vector<Reservation> getCourt1();
        vector<Reservation> getCourt2();
        vector<Reservation> getCourt3();




                    // Destructor
    ~ReservationSystem() {}

    // Copy constructor
    ReservationSystem(const ReservationSystem& other) {
            this->users = other.users;
            this->court1 = other.court1;
            this->court2 = other.court2;
            this->court3 = other.court3;
        }

    // Copy assignment operator
    ReservationSystem& operator=(const ReservationSystem& other) {
        if (this != &other) {
            users = other.users;
           court1 = other.court1;
            court2 = other.court2;
            court3 = other.court3;
        }
        return *this;
    }

    // Move constructor
    ReservationSystem(ReservationSystem&& other) :
        users(move(other.users)), court1(move(other.court1)),
        court2(move(other.court2)), court3(other.court3) {}

    // Move assignment operator
    ReservationSystem& operator=(ReservationSystem&& other) {
        if (this != &other) {
            users = move(other.users);
            court1 = move(other.court1);
            court2 = move(other.court2);
            court3 = other.court3;
        }
        return *this;
    }


};