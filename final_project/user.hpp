#pragma once
#include <string>
#include <vector>
#include "reservation.hpp"



using namespace std;

class Reservation;

class User {
    string username;
    string password;
    char playerSkill;  
    char playerType;
    
    public:
        User(string username, string password);
         User(string username, string password, char playerSkill);
        User(string username, string password, char playerSkill, char playerType);
        string getUsername();
        char getSkill();
        char getType();
        void setUsername(string username);
        void setPassword(string password);
        void setSkill(char skill);


            // Destructor
    ~User() {}

    // Copy constructor
    User(const User& other) {
            this->username = other.username;
            this->password = other.password;
            this->playerSkill = other.playerSkill;
            this->playerType = other.playerType;
        }

    // Copy assignment operator
    User& operator=(const User& other) {
        if (this != &other) {
            username = other.username;
           password = other.password;
            playerSkill = other.playerSkill;
            playerType = other.playerType;
        }
        return *this;
    }

    // Move constructor
    User(User&& other) :
        username(move(other.username)), password(move(other.password)),
        playerSkill(move(other.playerSkill)), playerType(other.playerType) {}

    // Move assignment operator
    User& operator=(User&& other) {
        if (this != &other) {
            username = move(other.username);
            password = move(other.password);
            playerSkill = move(other.playerSkill);
            playerType = other.playerType;
        }
        return *this;
    }



    };


class Member : public User {
        public:
            Member(string username, string password, char playerSkill);
            void requestCancellation(Reservation r);
    };

class Coach : public User {
            public:
                Coach(string username, string password);
                void requestCancellation(Reservation r);
    };

class Officer : public User {
        public:
            Officer(string username, string password, char playerSkill);
            void modifyReservation(Reservation r);
            void scheduleOpenPlay(string startTime, string endTime);
    };  


