#pragma once
#include <bits/stdc++.h>
#include "02_Seat.cpp"
using namespace std;

class Screen
{
    private:
        int ScreenNumber;
        vector<Seat*> Seats;
    
    public:
        Screen(int ScreenNumber)
        {
            this->ScreenNumber = ScreenNumber; 
        }

        void AddSeat(Seat* seat)
        {
            Seats.push_back(seat);
        }

        vector<Seat*> GetSeats()
        {
            return Seats;
        }

        int GetScreenNumber()
        {
            return ScreenNumber;
        }

        void DisplaySeats()
        {
            cout<<"Screen "<<ScreenNumber<<endl;
            for(Seat* seat : Seats)
            {
                cout<< seat->GetSeatNumber()
                    << " - "
                    <<seat->GetSeatType()
                    <<endl;
            }
        }
};