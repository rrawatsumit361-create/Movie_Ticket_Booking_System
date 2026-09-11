#pragma once
#include <bits/stdc++.h>
#include "02_Seat.cpp"
using namespace std;

class ShowSeat
{
private:
    Seat *seat;
    string Status;

public:
    ShowSeat(Seat *seat)
    {
        this->seat = seat;
        this->Status = "AVAILABLE";
    }

    bool IsAvailable()
    {
        return Status == "AVAILABLE";
    }

    bool BookSeat()
    {
        if (!IsAvailable())
        {
            return false;
        }

        Status = "BOOKED";
        return true;
    }

    void CancelSeat()
    {
        Status = "AVAILABLE";
    }

    Seat *GetSeat()
    {
        return seat;
    }

    string GetStatus()
    {
        return Status;
    }
};