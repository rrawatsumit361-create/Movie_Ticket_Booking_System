#pragma once
#include <bits/stdc++.h>
#include "08_Booking.cpp"
#include "11_PriceCalculator.cpp"
#include "09_Payment.cpp"

using namespace std;

class BookingService
{
    private:
     PriceCalculator pricecalculator;

    public:
     bool BookTicket(Booking* booking,Payment* payment)
     {
        vector<ShowSeat*> seats = booking->GetSelectedSeats();

        for (ShowSeat* seat : seats)
        {
            if(!seat->IsAvailable())
            {
                cout<<"Seat: "
                    <<seat->GetSeat()->GetSeatNumber()
                    <<" is already booked."<<endl;
                return false;
            }
        }

        double amount = pricecalculator.CalculatePrice(seats);
        booking->SetTotalAmount(amount);

        cout<<"Total Amount: Rs. "<<amount<<endl;

        if(!payment->Pay(amount))
        {
            cout<<"Payment Failed."<<endl;

            for(ShowSeat* seat : seats)
            {
                seat->CancelSeat();
            }
            return false;
        }

        for(ShowSeat* seat : seats)
        {
            seat->BookSeat();
        }

        booking->Confirm();
        cout<<"Booking confirmed successfully."<<endl;
        return true;
     }

     void CancelBooking(Booking* booking)
     {
        for(ShowSeat* seat : booking->GetSelectedSeats())
        {
            seat->CancelSeat();
        }

        booking->Cancel();

        cout<<"Booking cancelled successfully."<<endl;
     }
};