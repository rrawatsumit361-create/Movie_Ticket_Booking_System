#pragma once
#include <bits/stdc++.h>
#include "05_ShowSeat.cpp"
using namespace std;

class PriceCalculator
{
    public:
      double CalculatePrice(vector<ShowSeat*> seats)
      {
        double total = 0;
        for(ShowSeat* showseat : seats)
        {
            string SeatType = showseat->GetSeat()->GetSeatType();
            
            if(SeatType == "SILVER")
            {
                total+=150;
            }

            else if(SeatType == "GOLD")
            {
                total+=250;
            }

            else if(SeatType == "PLATINUM")
            {
                total += 400;
            }
        }

        return total;
      }
};
