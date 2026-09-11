# 🎬 Movie Ticket Booking System — C++

A **menu-driven Movie Ticket Booking System** developed in C++ for a single-cinema environment. This project demonstrates how **Object-Oriented Programming (OOP)** and **System Design principles** can be translated into a working application.

The system manages movies, screens, seats, shows, customers, bookings, payments, and ticket generation while following a modular and maintainable class-based architecture.

## 🚀 Features

* 🎥 **Movie Management** — Manage movies and their details.
* 🖥️ **Screen & Show Management** — Associate shows with cinema screens and movies.
* 💺 **Seat Management** — Handle seat categories, availability, booking, and cancellation.
* 🎟️ **Ticket Booking** — Book multiple seats and generate booking details.
* ❌ **Booking Cancellation** — Cancel bookings and automatically release seats.
* 💳 **Multiple Payment Methods** — Supports:

  * UPI
  * Card
  * Cash
* 💰 **Dynamic Pricing** — Different pricing for:

  * Silver
  * Gold
  * Platinum
* 🧾 **Ticket Generation** — Generates ticket details after successful booking.
* 📋 **Menu-Driven Interface** — Simple console-based interaction.

## 🏗️ Object-Oriented Concepts Used

The project is designed around multiple independent classes and demonstrates:

* **Classes & Objects**
* **Encapsulation**
* **Abstraction**
* **Inheritance**
* **Polymorphism**
* **Composition**
* **Aggregation**
* **Association**

### 💳 Runtime Polymorphism

The payment system uses an abstract `Payment` base class with different implementations:

```text
Payment
├── UPI
├── Card
└── Cash
```

This demonstrates **inheritance and runtime polymorphism** by allowing different payment methods to implement their own payment-processing behavior.

## 📐 System Design

The project also includes UML diagrams to represent the architecture and workflow.

### UML Class Diagram

The class diagram represents relationships between components such as:

```text
Cinema
   │
   └── Screen
          │
          └── Seat

Movie ─── Show ─── Screen
              │
              └── Booking ─── Customer
                     │
                     └── Payment
```

It demonstrates **association, aggregation, composition, and inheritance** between different classes.

### UML Sequence Diagram

The booking workflow is represented using a sequence diagram:

```text
Customer
   ↓
Select Movie & Show
   ↓
Check Seat Availability
   ↓
Select Seats
   ↓
Calculate Price
   ↓
Process Payment
   ↓
Confirm Booking
   ↓
Generate Ticket
```

## 📂 Project Structure

The project follows a **one-class-per-file** structure to keep the code modular and organized.

```text
Movie-Ticket-Booking-System/
│
├── Movie
├── Seat
├── Screen
├── Show
├── Customer
├── Booking
├── Payment
├── UPI
├── Card
├── Cash
├── Pricing
├── Ticket
│
├── UML/
│   ├── Class-Diagram
│   └── Sequence-Diagram
│
└── README.md
```

## 🛠️ Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Programming
* **Design:** UML & Object-Oriented System Design
* **Interface:** Console / Menu-Driven

## 🎯 Learning Objectives

This project was built to gain practical experience in:

* Designing real-world systems using classes and objects
* Understanding relationships between classes
* Applying OOP principles in a complete application
* Implementing inheritance and runtime polymorphism
* Converting UML diagrams into actual C++ code
* Designing modular and maintainable software

## 🔮 Future Improvements

Possible future enhancements include:

* Database integration using MySQL
* Graphical User Interface
* Online payment gateway integration
* User authentication
* Admin dashboard
* Movie search and filtering
* Multiple cinema support
* Persistent booking history

## 👨‍💻 Author

**Fayaj Ahmad**

This project was developed as a practical implementation of **C++ OOP and System Design concepts**.
