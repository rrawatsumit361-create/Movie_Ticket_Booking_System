#pragma once
#include <bits/stdc++.h>
#include "08_Booking.cpp"
using namespace std;

class TicketPrinter
{
    public:
      void PrintTicket(Booking* booking)
      {
          cout<<endl;
          cout<<"--------MOVIE TICKET--------"<<endl;
          cout<<"Booking Id: "<< booking->GetBookingId()<<endl;
          cout<<"Status: "<<booking->GetStatus()<<endl;
          cout<<"Total Amount: Rs. "<<booking->GetTotalAmount()<<endl;

          cout<<"Seats: "<<endl;
          for(ShowSeat* showseat : booking->GetSelectedSeats())
          {
            cout<<showseat->GetSeat()->GetSeatNumber()
                <<" - "
                <<showseat->GetSeat()->GetSeatType()
                <<endl;
          }

      }
};