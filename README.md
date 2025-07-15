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
