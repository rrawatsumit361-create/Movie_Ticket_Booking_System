#pragma once
#include<bits/stdc++.h>
using namespace std;

class Seat
{
    private:
       string SeatNumber;
       string SeatType;
       
    public:
       Seat(string SeatNumber,string SeatType)
       {
            this->SeatNumber = SeatNumber;
            this->SeatType = SeatType;
       }

       string GetSeatNumber()
       {
            return SeatNumber;
       }

       string GetSeatType()
       {
            return SeatType;
       }
};