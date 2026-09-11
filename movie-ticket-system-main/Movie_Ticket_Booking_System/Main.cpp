#include <bits/stdc++.h>

#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_ShowSeat.cpp"
#include "06_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

using namespace std;

int main()
{
    Movie movie1("Avengers", "English", 180);
    Movie movie2("Dangal", "Hindi", 160);

    Seat seat1("A1", "SILVER");
    Seat seat2("A2", "GOLD");
    Seat seat3("A3", "GOLD");
    Seat seat4("A4", "PLATINUM");
    Seat seat5("B1", "SILVER");
    Seat seat6("B2", "PLATINUM");

    Screen screen1(1);

    screen1.AddSeat(&seat1);
    screen1.AddSeat(&seat2);
    screen1.AddSeat(&seat3);
    screen1.AddSeat(&seat4);
    screen1.AddSeat(&seat5);
    screen1.AddSeat(&seat6);

    Cinema cinema("PVR Cinemas");

    cinema.AddScreen(&screen1);

    vector<Seat*> seats = screen1.GetSeats();

    ShowSeat showSeat1(seats[0]);
    ShowSeat showSeat2(seats[1]);
    ShowSeat showSeat3(seats[2]);
    ShowSeat showSeat4(seats[3]);
    ShowSeat showSeat5(seats[4]);
    ShowSeat showSeat6(seats[5]);

    Show show1(&movie1, &screen1, "06:00 PM");

    show1.AddShowSeat(&showSeat1);
    show1.AddShowSeat(&showSeat2);
    show1.AddShowSeat(&showSeat3);
    show1.AddShowSeat(&showSeat4);
    show1.AddShowSeat(&showSeat5);
    show1.AddShowSeat(&showSeat6);

    Customer customer(
        "Manthan",
        "9876543210",
        "manthan@gmail.com"
    );

    BookingService bookingService;
    TicketPrinter ticketPrinter;

    Booking* currentBooking = nullptr;

    int choice;

    do
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << "     MOVIE TICKET BOOKING SYSTEM" << endl;
        cout << "====================================" << endl;
        cout << "1. List Movies" << endl;
        cout << "2. List Shows" << endl;
        cout << "3. Display Seat Layout" << endl;
        cout << "4. Book Ticket" << endl;
        cout << "5. Cancel Booking" << endl;
        cout << "6. Print Ticket" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl;
            cout << "Available Movies:" << endl;
            cout << "1. " << movie1.GetTitle()
                 << " - " << movie1.GetLanguage()
                 << " - " << movie1.GetDuration()
                 << " minutes" << endl;

            cout << "2. " << movie2.GetTitle()
                 << " - " << movie2.GetLanguage()
                 << " - " << movie2.GetDuration()
                 << " minutes" << endl;
            break;

        case 2:
            cout << endl;
            cout << "Available Shows:" << endl;
            cout << "1. " << show1.GetMovie()->GetTitle()
                 << " - " << show1.GetStartTime()
                 << " - Screen "
                 << show1.GetScreen()->GetScreenNumber()
                 << endl;
            break;

        case 3:
            cout << endl;
            show1.DisplaySeatLayout();
            break;

        case 4:
        {
            int numberOfSeats;

            cout << endl;
            cout << "Enter number of seats: ";
            cin >> numberOfSeats;

            if (numberOfSeats <= 0)
            {
                cout << "Invalid number of seats." << endl;
                break;
            }

            Booking* booking = new Booking(&customer, &show1);

            bool validBooking = true;

            for (int i = 0; i < numberOfSeats; i++)
            {
                string seatNumber;
                bool found = false;

                cout << "Enter seat number: ";
                cin >> seatNumber;

                for (ShowSeat* showSeat : show1.GetShowSeats())
                {
                    if (showSeat->GetSeat()->GetSeatNumber() == seatNumber)
                    {
                        if (showSeat->IsAvailable())
                        {
                            booking->AddSeat(showSeat);
                            found = true;
                        }
                        else
                        {
                            cout << "Seat is already booked." << endl;
                            validBooking = false;
                        }

                        break;
                    }
                }

            
                if (!found)
                {
                    cout << "Invalid seat number." << endl;
                    i--;
                }
            }

            if (!validBooking)
            {
                delete booking;
                break;
            }

            int paymentChoice;

            cout << endl;
            cout << "Select Payment Method:" << endl;
            cout << "1. UPI" << endl;
            cout << "2. Card" << endl;
            cout << "3. Cash" << endl;
            cout << "Enter choice: ";
            cin >> paymentChoice;

            Payment* payment = nullptr;

            if (paymentChoice == 1)
            {
                payment = new UpiPayment();
            }
            else if (paymentChoice == 2)
            {
                payment = new CardPayment();
            }
            else if (paymentChoice == 3)
            {
                payment = new CashPayment();
            }
            else
            {
                cout << "Invalid payment method." << endl;
                delete booking;
                break;
            }

            if (bookingService.BookTicket(booking, payment))
            {
                currentBooking = booking;
            }
            else
            {
                delete booking;
            }

            delete payment;

            break;
        }

        case 5:
            if (currentBooking == nullptr)
            {
                cout << "No active booking found." << endl;
            }
            else
            {
                bookingService.CancelBooking(currentBooking);
                delete currentBooking;
                currentBooking = nullptr;
            }
            break;

        case 6:
            if (currentBooking == nullptr)
            {
                cout << "No booking available." << endl;
            }
            else
            {
                ticketPrinter.PrintTicket(currentBooking);
            }
            break;

        case 7:
            cout << endl;
            cout << "Thank you for using the Movie Ticket Booking System."
                 << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    delete currentBooking;

    return 0;
}