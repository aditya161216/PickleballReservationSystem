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
#include "reservationSystem.hpp"


using namespace std;


ReservationSystem::ReservationSystem() {

    // Initalizing reservations
    for (int i = 0; i < 36; i++) {
        vector<User> u;
        Reservation r1(u, true, "Free");

        addReservation(r1, 1);
        
    }

    for (int i = 0; i < 36; i++) {
        vector<User> u;
        Reservation r2(u, true, "Free");

        addReservation(r2, 2);
        
    }

       for (int i = 0; i < 36; i++) {
        vector<User> u;
        Reservation r3(u, true, "Free");

        addReservation(r3, 3);
        
    }






}

// Adds a given member to the reservation system
void ReservationSystem::addMember(User u) {
    users.push_back(u);
}


void ReservationSystem::addReservation(Reservation r, int courtNumber) {



    if (courtNumber == 1) {
        court1.push_back(r);
    }
    else if (courtNumber == 2) {
        court2.push_back(r);
        
    }
    else {
        court3.push_back(r);
    }
}


void ReservationSystem::addReservation(Reservation r, int courtNumber, int slot) {



    if (courtNumber == 1) {
        court1[slot] = r;
    }
    else if (courtNumber == 2) {
        court2[slot] = r;
        
    }
    else {
        court3[slot] = r;
    }
}


void ReservationSystem::printGrid() {

vector<string> timeSlots = {"06:00 - 06:30", "06:30 - 07:00", "07:00 - 07:30", "07:30 - 08:00", "08:00 - 08:30", "08:30 - 09:00", "09:00 - 09:30", "09:30 - 10:00",
    "10:00 - 10:30", "10:30 - 11:00", "11:00 - 11:30", "11:30 - 12:00", "12:00 - 12:30", "12:30 - 13:00", "13:00 - 13:30", "13:30 - 14:00", 
    "14:00 - 14:30", "14:30 - 15:00", "15:00 - 15:30", "15:30 - 16:00", "16:00 - 16:30", "16:30 - 17:00", "17:00 - 17:30", "17:30 - 18:00",
    "18:00 - 18:30", "18:30 - 19:00", "19:00 - 19:30", "19:30 - 20:00", "20:00 - 20:30", "20:30 - 21:00", "21:00 - 21:30", "21:30 - 22:00",
    "22:00 - 22:30", "22:30 - 23:00", "23:00 - 23:30", "23:30 - 00:00"};

    // 30, (25, 30, 30)
 
      cout << right << "Time" << setw(40) << "Court #1" << setw(40) << "Court #2" << setw(40) << "Court #3" << endl;

    

      for (int i = 0; i < timeSlots.size(); i++) {
        cout << right << timeSlots[i] << setw(35) << court1[i] << setw(40) << court2[i] << setw(40) << court3[i] << endl;
      }

    //    cout << "06:00 - 06:30" << setw(25) << "Game: Aaryan, Aditya" << setw(30) << "Open Play: 69 seats open" << setw(30) << "Game: Arnav, Black" << endl;

    
}

string ReservationSystem::getCourt1Info() {
    string output = "";



    for (int i = 0; i < court1.size(); i++) {
        output = output + court1[i].getReservationInfo() + "\n";

    }

    return output;



}


string ReservationSystem::getCourt2Info() {
     string output = "";



    for (int i = 0; i < court2.size(); i++) {
        output = output + court2[i].getReservationInfo() + "\n";

    }

    return output;
}

string ReservationSystem::getCourt3Info() {
      string output = "";



    for (int i = 0; i < court3.size(); i++) {
        output = output + court3[i].getReservationInfo() + "\n";

    }

    return output;
}

vector<Reservation> ReservationSystem::getCourt1() {
    return this->court1;
}

vector<Reservation> ReservationSystem::getCourt2() {
    return this->court2;
}

vector<Reservation> ReservationSystem::getCourt3() {
    return this->court3;
}


void ReservationSystem::modifyReservation(int court, int slot, User u, string reservationType) {

    // May need to check if reservation is free in this method
    if (court == 1) {
        Reservation r = court1[slot];

        vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, reservationType);
        court1[slot] = newR;

    }

    if (court == 2) {
                Reservation r = court2[slot];
       vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, reservationType);
        court2[slot] = newR;
    }

    if (court == 3) {
        Reservation r = court3[slot];

        vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, reservationType);
        court3[slot] = newR;
    }
}



void ReservationSystem::modifyReservation(int court, int slot, User u) {

    // May need to check if reservation is free in this method
    if (court == 1) {
        Reservation r = court1[slot];

        vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, r.getReservationType());
        court1[slot] = newR;

    }

    if (court == 2) {
                Reservation r = court2[slot];

        vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, r.getReservationType());
        court2[slot] = newR;
    }

    if (court == 3) {
        Reservation r = court3[slot];

        vector<User> users = r.getUsers();
        users.push_back(u);
        bool isFree = r.getIsFree();

        Reservation newR(users, isFree, r.getReservationType());
        court3[slot] = newR;
    }


}


void ReservationSystem::cancelReservation(int court, int slot) {
    if (court == 1) {
        vector<User> users;
        Reservation r(users, true, "Free Reservation");
        court1[slot] = r;
        

      
    }

    if (court == 2) {
        vector<User> users;
        Reservation r(users, true, "Free Reservation");
        court1[slot] = r;
     
    }

    if (court == 3) {
        vector<User> users;
        Reservation r(users, true, "Free Reservation");
        court1[slot] = r;
    
    }
}