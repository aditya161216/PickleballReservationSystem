# A Pickleball Reservation System

A C++ console application to manage pickleball court reservations for a community club. The system supports multiple user types (members, coaches, officers), booking and cancelling reservations, user messaging, and day-by-day schedule management. Designed with OOP principles (composition & inheritance), this project is a full-featured simulation of a real-world reservation platform.

---

## Features

- **User Registration & Login**  
  Register or log in as a member, coach, or officer. Different user types have different privileges.
- **Day-by-Day Schedule**  
  View, book, and cancel reservations for any of 14 days (2 weeks), across 3 courts, with 36 time slots per day (from 6:00 am to 12:00 am).
- **User Types & Permissions**  
  - **Member:** Book regular games, send messages to officers.
  - **Coach:** Book special coaching sessions (with restrictions), send messages to officers.
  - **Officer:** Book “Open Play” slots, manage all reservations, and receive/cancel requests.
- **Messaging**  
  Members/Coaches can message officers; officers can view all messages.
- **Data Persistence**  
  All users and reservations are saved to local text files for persistence between sessions.
- **Robust Input Handling**  
  Prevents invalid bookings (e.g., double-bookings, skill requirements, booking too late/early, etc).

---

## How to Use

### Build & Run

1. **Change into the project directory:**  
   ```bash
   cd final_project

2. **Compile the Code:**  
   ```bash
   make

3. **Or, if you want to compile it manually:**  
   ```bash
   g++ -std=c++11 main.cpp reservation.cpp reservationSystem.cpp user.cpp -o pickleball

4. **Run the Program:**  
   ```bash
   ./pickleball

---

### User Flow
1. **Startup:** When you run the program, you'll be prompted to **register** (`r`) or **login** (`l`).

2. **Register:**
  - Select your user type:
    - `'m'` for Member
    - `'c'` for Coach
    - `'o'` for Officer
  - Enter a username and password.
  - (For members and officers) Choose your skill level:
    - `'A'` (high), `'B'` (medium), `'C'` (low)

3. **Login:**
  - Enter your username from the list of existing users.

4. **Main Menu Options:** After logging in or registering, you'll see the reservation schedule for the current day. Use the following commands to interact:
  - `n`: Next day
  - `b`: Previous day
  - `q`: Quit
  - `a`: Add a reservation
  - `c`: Cancel reservation (**officers only**)
  - `m`: View messages (**officers only**)
  - `t`: Send message to officer (**members/coaches only**)

5. **Booking a Reservation:**
  - Enter the day (1–14; 1 = today, 14 = two weeks from now)
  - Enter the time slot (0–35; each number is a half-hour increment starting from 6:00 am)
  - Enter the court (1–3)

6. **Role-Based Restrictions:**
  - **Coaches:** Must book at least 2 days in advance, can't book on Saturdays, and can only book select hours (9am–12pm & 3pm–6pm).
  - **Officers:** Can only book evening "Open Play" hours (6pm–9pm).
  - **Members:** Regular bookings, subject to slot availability.

---

## Code Structure
- `main.cpp`: Handles user interaction, persistence, and overall control flow.
- `reservationSystem.cpp/hpp`: The core logic for managing reservations for all courts.
- `reservation.cpp/hpp`: The `Reservation` class for each slot.
- `user.cpp/hpp`: Base `User` class + subclasses (`Member`, `Coach`, `Officer`).

---

## Object-Oriented Design
- **ReservationSystem**: Manages all courts and slots for a given day.
- **Reservation**: Tracks users, type, and status for each reservation slot.
- **User**: Base class; extended by `Member`, `Coach`, and `Officer` for custom behavior and permissions.

---

## File Persistence
- **Court reservations:** `data/Court[1-3]Day[0-13].txt`
- **Users:** `data/users.txt`

---

## Requirements
- Standard C++ (C++11 or newer)
- Linux, Mac, or Windows with g++ and make

---

## Credits
Developed by Aditya Vikrant and Aaryan Sinha 




