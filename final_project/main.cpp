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
#include <typeinfo>
#include "reservation.hpp"


using namespace std;

int grid_size = 26;
enum State{INIT, BEGIN, QUIT};

template<typename BClass, typename T>
inline bool typeCheck(const T *p) {
   return dynamic_cast<const BClass*>(p) != nullptr;
}


int main() {
    int day = 1;
    string month = "April";
    int year = 2023;
    bool quit = false;
    enum State state = INIT;
    vector<ReservationSystem> days;
    vector<User> currentUser;
    vector<User> loggedUsers;
    int index = 0;
    vector<string> messagesVector;

    while (state != QUIT) {
        switch(state) {
            case INIT:
            {
                index = 0;
                char c;

                for (int i = 0; i < 14; i++) {
                    ReservationSystem r1;
                    days.push_back(r1);
                }


                // i represents the court
                // j represents the day

                string fileName;

                for (int i = 1; i < 4; i++) {
                    fileName = "data/Court" + to_string(i);
                    
                    for (int j = 0; j < 14; j++) {

                        fileName = fileName + "Day" + to_string(j) + ".txt";

                        fstream infile(fileName);

                        



                    if (infile) {

                    



                        // cout << "Test: i = " << i << "j = " << j <<  endl;
                        // cout << "Test filename: " << filename << endl;

                        string line;
                        string t;
                        vector<string> temp;


                    while (getline(infile, line, '\n')) {
                        stringstream tempstream(line);
                        while(getline(tempstream, t, ';')) {
                            temp.push_back(t);
                            t = "";
                        }
                    }

                    // Processing information for one court one day
                    vector<string> info;
                    int indexSlot = 0;
                    char skill[5];

                    for (int k = 0; k < 144; k = k + 4) {
                        info.clear();
                        info.push_back(temp[k]);
                        info.push_back(temp[k + 1]);
                        info.push_back(temp[k + 2]);
                        info.push_back(temp[k + 3]);

                        string users = info[0];
                        vector<User> userVector;
                        int isFree = stoi(info[2]);
                        if (users != "nouser") {

                            string user;

                            stringstream ss(users);

                            
                            strcpy(skill, info[1].c_str()); 
                        
                            while (getline(ss, user, ' ')) {
                                User u1(user, "blank", skill[0]);
                                userVector.push_back(u1);
                            }

                        }

                        Reservation reservation(userVector, isFree, info[3]);

                        days[j].addReservation(reservation, i, indexSlot);

                        indexSlot++;
                
                    }

                }


                    fileName = "data/Court" + to_string(i);

                    }


                }

                

                

                fstream infile2("data/users.txt");
                string userStream;
                string line2;


                if (infile2) {

                    vector<string> temp2;
                    while (getline(infile2, line2, '\n')) {
                    stringstream tempstream(line2);
                    while(getline(tempstream, userStream)) {
                            temp2.push_back(userStream);
                            userStream = "";
                    }
                    }

                    for (int i = 0; i < temp2.size(); i++) {
                        User u1(temp2[i], "bruh", 'b', 'b');
                        loggedUsers.push_back(u1);
                    }

                }


                cout<<"Welcome to the Court Reservation System of Newton!"<<endl;
                cout<<"Please click r to register and l to login: ";
                cin >> c;
                // cout<<"What week would you like to see your schedule"

                    

                if (c == 'r') {

                    string username;
                    string password;
                    char playerType = 'p';
                    char playerSkillInput;

                    while (playerType != 'm' && playerType != 'c' && playerType != 'o') {
                        cout << "Please enter your player type, options: 'm' for member, 'c' for coach, 'o' for officer: ";
                        cin >> playerType;

                        if (playerType != 'm' && playerType != 'c' && playerType != 'o') {
                            cout<<"Invalid input!"<<endl;
                        }

                    }
                    

                    while ( ! (playerType == 'm' || playerType == 'c' || playerType == 'o') ) {
                        cout << "Please enter a valid option, options: 'm' for member, 'c' for coach, 'o' for officer" << endl;
                        cin >> playerType;
                    }

                    if (playerType == 'm') {

                        cout << "Please enter a username: ";
                        cin >> username;
                        cout << "Please enter a password: ";
                        cin >> password;

                        playerSkillInput = 'D';

                        while ( ! (playerSkillInput == 'A' || playerSkillInput == 'B' || playerSkillInput == 'C') ) {
                            cout << "Please enter your player skill, options: 'A' for high skill, 'B' for medium skill, 'C' for low skill" << endl;
                            cin >> playerSkillInput;

                            if (! (playerSkillInput == 'A' || playerSkillInput == 'B' || playerSkillInput == 'C') ) {
                                cout<<"Invalid input!"<<endl;
                            }
                        }

                        // Multiple reservation system, have to add member to system

                        Member m1(username, password, playerSkillInput);
                        // Sets current user of the system to m1
                        currentUser.push_back(m1);
                        loggedUsers.push_back(m1);


                    }

                    else if (playerType == 'c') {

                        cout << "Please enter a username: ";
                        cin >> username;
                        cout << "Please enter a password: ";
                        cin >> password;

                        Coach c1(username, password);
                        
                        // have to add to reservation system

                        currentUser.push_back(c1);
                        loggedUsers.push_back(c1);



                    }

                    else if (playerType == 'o') {
                        cout << "Please enter a username: ";
                        cin >> username;
                        cout << "Please enter a password: ";
                        cin >> password;

                        playerSkillInput = 'D';

                        while ( ! (playerSkillInput == 'A' || playerSkillInput == 'B' || playerSkillInput == 'C') ) {
                            cout << "Please enter your player skill, options: 'A' for high skill, 'B' for medium skill, 'C' for low skill: ";
                            cin >> playerSkillInput;

                            if (! (playerSkillInput == 'A' || playerSkillInput == 'B' || playerSkillInput == 'C') ) {
                                cout<<"Invalid input!"<<endl;
                            }
                        }

                        Officer o1(username, password, playerSkillInput);
                        currentUser.push_back(o1);
                        loggedUsers.push_back(o1);

                    }

                    // Need to deal with adding user to each reservation system after setting currentUser

                }

                // if user wants to login
                if (c == 'l') {
                    string userInput;
                    bool correct_username = false;


                    cout<<"Choose from the following users: "<<endl;
                    for (auto m : loggedUsers) {
                        cout<<m.getUsername()<<endl;
                    }

                    while (!correct_username) {
                        cout<<"Type in their full name to login: "<<endl;
                        cin>>userInput;

                        for (auto m : loggedUsers) {
                            if (m.getUsername() == userInput) {
                                correct_username = true;
                                currentUser.push_back(m);
                            }
                        }

                        if (!correct_username) {
                            cout<<"Incorrect username, please try again."<<endl;
                        }

                    }

                }

                state = BEGIN;
                break;
            }

            case(BEGIN):
            {

                 days[index].printGrid();
                 cout << "Current Day: "<< to_string(day) << " " << "April 2023" << endl;
                
                cout << endl;

                //cout<<currentUser[0].getType()<<endl;

                cout << "Showing reservations for date: " << day << " " << month << " " << year << endl; 
                cout<<"Click n to view the next day's schedule, b to show previous day's schedule, q to quit, and a to add a reservation"<<endl;

                if (currentUser[0].getType() == 'o' || currentUser[0].getUsername() == "officer1" || currentUser[0].getUsername() == "officer2") {
                    cout<<"Click c to cancel a reservation, click m to see any messages from coaches and members"<<endl;
                }

                else {
                    cout << "Click t to text a message to an officer" << endl;
                }

                // check for input
                char c1;
                cin >> c1;


                if (c1 == 'n') {
                    // If index larger than 13, then add a new page, or cycle back to one
                    day++;
                    index++;

                    if (index > 13) {
                        index = 0;
                        day = 1;
                    }
                    
                }

                else if (c1 == 'm') {
                    cout << "One message from John: Hello Officer, thank you for cancelling the reservation earlier!" << endl;
                    if (messagesVector.size() == 0) {
cout << "No other messages received." << endl;
                    }
                    else {
                        for (int i = 0; i < messagesVector.size(); i++) {
                            cout << "Message received: " << messagesVector[i] << endl;
                        }
                    }
                    
                }

                else if (c1 == 't') {
                    string message;
                    cout << "Please input your message here: ";
                    cin >> message;
                    messagesVector.push_back(message);
                    cout << "Message has been sent" << endl;

                }

                else if (c1 == 'c') {
                    int d1 = -1;
                    int time1 = -1;
                    int court1 = -1;
                    
                    while (d1 < 1 || d1 > 14) {
                        cout<<"Enter the day you would like to cancel a reservation in April on (Enter a number from 1 - 14): ";
                        cin>>d1;

                        if (d1 < 1 || d1 > 14) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }

                    while (time1 < 0 || time1 > 35) {
                        cout<<"Enter the time you would like to cancel your reservation for."<<endl;
                        cout<<"(Enter a number from 0 - 35, where 0 is 6 - 6:30 am, 1 is 6:30 - 7 am, and so on): ";
                        cin>>time1;

                        if (time1 < 0 || time1 > 35) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }

                    while (court1 < 1 || court1 > 3) {
                        cout<<"Enter the court number you would like to cancel the reservation at (1, 2, or 3): ";
                        cin>>court1;

                        if (court1 < 1 || court1 > 3) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }

                    days[index].cancelReservation(court1, time1);
                }

                else if (c1 == 'b') {
                    if (index > 0) {
                        day--;
                        index--;
                    }
                }

                else if (c1 == 'q') {
                    state = QUIT;
                    break;
                }

                else if (c1 == 'a') {
                    int d = -1;
                    int time = -1;
                    int court = -1;
                    
                    while (d < 1 || d > 14) {
                        cout<<"Enter the day you would like to book a reservation in April on (Enter a number from 1 - 14): ";
                        cin>>d;

                        if (d < 1 || d > 14) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }

                    while (time < 0 || time > 35) {
                        cout<<"Enter the time you would like to book your reservation for."<<endl;
                        cout<<"(Enter a number from 0 - 35, where 0 is 6 - 6:30 am, 1 is 6:30 - 7 am, and so on): ";
                        cin>>time;

                        if (time < 0 || time > 35) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }

                    while (court < 1 || court > 3) {
                        cout<<"Enter the court number you would like to book the reservation at (1, 2, or 3): ";
                        cin>>court;

                        if (court < 1 || court > 3) {
                            cout<<"Invalid value!"<<endl;
                        }

                    }


                    vector<User> addedUser;
                    Reservation oldR = days[d - 1].getCourt1()[time];

                    if (court == 2) {
                        oldR = days[d - 1].getCourt2()[time];
                    }

                    else if (court == 3) {
                        oldR = days[d - 1].getCourt3()[time];
                    }


                    // if member, check if the reservation can be added
                    if (currentUser[0].getType() == 'm') {
                    
                            if (oldR.getUsers().size() == 1) {
                                addedUser.push_back(oldR.getUsers()[0]);
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, false, "Game ");
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 0) {
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, true, "Game ");
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 2) {
                                cout<<"Reservation is full!"<<endl;
                            }
                    }


                    else if (currentUser[0].getType() == 'o') {

                            if (time < 18 || time > 24) {
                                while (time < 18 || time > 24) {
                                    cout<<"Officers can only book from 6 pm - 9 pm, please re-enter the time: "<<endl;
                                    cin>>time;
                                }

                            }

                            if (oldR.getUsers().size() == 1) {
                                addedUser.push_back(oldR.getUsers()[0]);
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, false, "Open Play with ");
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 0) {
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, true, "Open Play with");
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 2) {
                                cout<<"Reservation is full!"<<endl;
                            }

                    }


                    else if (currentUser[0].getType() == 'c') {

                        if (d < 3) {
                            while (d < 3) {
                                cout << "Coaches must reserve court at least 2 days in advanced, please re-enter the day: ";
                                cin >> d;
                            }

                        }

                        if (d % 6 == 0) {
                            while (d % 6 == 0) {
                                cout<<"Coaches cannot reserve time slots on Saturdays, please re-enter the day: "<<endl;
                                cin >> d;
                            }
                        }

                        if (time < 5 || (time > 11 && time < 18) || time > 24) {
                            while (time < 5 || (time > 11 && time < 18) || time > 24) {
                                cout<<"Coaches can only book from 9 am - 12 pm and 3 pm - 6 pm, please re-enter the time: "<<endl;
                                cin>>time;
                            }

                        }

                             
                        if (oldR.getUsers().size() == 1) {
                            addedUser.push_back(oldR.getUsers()[0]);
                            addedUser.push_back(currentUser[0]);
                            Reservation r6(addedUser, false, "Reserved for coaching by ");
                            days[d - 1].addReservation(r6, court, time);
                        }

                        else if (oldR.getUsers().size() == 0) {
                            addedUser.push_back(currentUser[0]);
                            Reservation r6(addedUser, true, "Reserved for coaching by ");
                            days[d - 1].addReservation(r6, court, time);
                        }

                        else if (oldR.getUsers().size() == 2) {
                            cout<<"Reservation is full!"<<endl;
                        }

                    }

                    else {
                            string message;

                            if (currentUser[0].getUsername() == "coach1" || currentUser[0].getUsername() == "coach2") {
                                message = "Reserved for coaching by ";
                            }

                            else if (currentUser[0].getUsername() == "officer1" || currentUser[0].getUsername() == "officer2") {
                                message = "Open Play with ";
                            }

                            else {
                                message = "Game ";
                            }

                            if (oldR.getUsers().size() == 1) {
                                addedUser.push_back(oldR.getUsers()[0]);
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, false, message);
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 0) {
                                addedUser.push_back(currentUser[0]);
                                Reservation r6(addedUser, true, message);
                                days[d - 1].addReservation(r6, court, time);
                            }

                            else if (oldR.getUsers().size() == 2) {
                                cout<<"Reservation is full!"<<endl;
                            }

                    }



                    
                }
               
            }
        }    
    }


    string infoAdd;
    string infoAddUser;

    // Printing court 1 for multiple days
    for (int i = 0; i < 14; i++) {
        infoAdd = days[i].getCourt1Info();
        ofstream outfile("data/Court1Day" + to_string(i) + ".txt");
        outfile << infoAdd;
        outfile.close();
    }

    // Printing court 2 for multiple days


       for (int i = 0; i < 14; i++) {
        infoAdd = days[i].getCourt2Info();
        ofstream outfile("data/Court2Day" + to_string(i) + ".txt");
        outfile << infoAdd;
        outfile.close();
    }



       for (int i = 0; i < 14; i++) {
        infoAdd = days[i].getCourt3Info();
        ofstream outfile("data/Court3Day" + to_string(i) + ".txt");
        outfile << infoAdd;
        outfile.close();
    }


    ofstream outfile2("data/users.txt");

    for (int i = 0; i < loggedUsers.size(); i++) {
        infoAddUser = loggedUsers[i].getUsername();
        outfile2 << infoAddUser;
        outfile2 << "\n";
        
    }
    outfile2.close();



    

    return 0;
}