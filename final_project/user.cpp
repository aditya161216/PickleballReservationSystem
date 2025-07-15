#include "user.hpp"

using namespace std;

User::User(string username, string password) {
    this->username = username;
    this->password = password;
    this->playerSkill = 'A';
}

User::User(string username, string password, char playerSkill, char playerType) {
     this->username = username;
    this->password = password;
    this->playerSkill = playerSkill;
    this->playerType = playerType;
}

User::User(string username, string password, char playerSkill) {
    this->username = username;
    this->password = password;
    this->playerSkill = playerSkill;
    
}

string User::getUsername() {
    return username;
}

char User::getSkill() {
    return playerSkill;
}


void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setSkill(char skill) {
    this->playerSkill = skill;
}

char User::getType() {
    return playerType;
}


Member::Member(string username, string password, char playerSkill) : User::User(username, password, playerSkill, 'm') {}

Coach::Coach(string username, string password) : User::User(username, password, 'P', 'c') {}

Officer::Officer(string username, string password, char playerSkill) : User::User(username, password, playerSkill, 'o') {}

