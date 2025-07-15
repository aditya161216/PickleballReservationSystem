
#include "reservation.hpp"
#include <vector>

using namespace std;



Reservation::Reservation(vector<User> u, bool isFree, string reservationType) {
    for (auto m : u) {
        users.push_back(m);
    }
    this->isFree = isFree;
    this->reservationType = reservationType;
}

Reservation::Reservation(User u, bool isFree, string reservationType) {
    users.push_back(u);
    this->isFree = isFree;
    this->reservationType = reservationType;
}

vector<User> Reservation::getUsers() {
    return users;
}


void Reservation::addUser(User u) {
    users.push_back(u);
}

string Reservation::getReservationType() {
    return reservationType;
}

string Reservation::getReservationInfo() {
    string output = "";
    
    // add usernames
    for (int i = 0; i < users.size(); i++) {
        output += users[i].getUsername();

        if (i != users.size() - 1) {
            output += " ";
        }
        
    }

    if (users.size() == 0) {
        output += "nouser";
    }



    output+= ";";

    if (users.size() != 0) {
        output += users[0].getSkill();
        output += ";";
    }

    else {
        output += "noskill";
        output += ";";
    }



    if (isFree) {
        output += "1";
    }
    else {
        output += "0";
    }
    output += ";";
    output += reservationType;

    return output;

}

ostream & operator <<(ostream &out, Reservation &r) {
    if (r.getReservationType() == "Free") {
        out << "Free Reservation";
        return out;
    }

    // else {
        string usersS = "";

        // cout << "Test Size: " << r.getUsers().size() << endl;

        // out << "Test type: " << r.getReservationType() << endl;

        // out << "Test Username" << r.getUsers()[0].getUsername() << endl;
        // out << r.getUsers()[1].getUsername() << endl;

        int usersSize = r.getUsers().size();

        for (int i = 0; i < usersSize; i++) {
            if (i == usersSize - 1) {
                usersS = usersS + r.getUsers()[i].getUsername();
            }
            else {
                usersS = usersS + r.getUsers()[i].getUsername() + ", ";
            }
            
           
        }


            // Add isFree condition or not
        out << r.getReservationType() << ": "  << usersS;
        


        
    // }

    return out;
}

bool Reservation::getIsFree() {
    return this->isFree;
}

void Reservation::setIsFree(bool b) {
    this->isFree = b;
}

void Reservation::modify(User u, string reservationType) {
    addUser(u);
    this->reservationType = reservationType;
    if (users.size() == 2) {
        this->isFree = false;
    }
}

void Reservation::modify(User u) {
     addUser(u);
    if (users.size() == 2) {
        this->isFree = false;
    }
}





