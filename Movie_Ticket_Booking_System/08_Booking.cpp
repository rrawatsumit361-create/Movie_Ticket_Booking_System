#pragma once
#include <bits/stdc++.h>
#include "06_Show.cpp"
#include "07_Customer.cpp"

using namespace std;

class Booking
{
    private:
      int BookingId;
      Customer *customer;
      Show *show;
      vector<ShowSeat*> SelectedSeats;
      double TotalAmount;
      string Status;

      static int NextBookingId;

    public:
      Booking(Customer *customer,Show *show)
      {
        this->BookingId = NextBookingId++;
        this->customer = customer;
        this->show = show;
        this->TotalAmount = 0;
        this->Status = "PENDING";
      }

      void AddSeat(ShowSeat* seat)
      {
        SelectedSeats.push_back(seat);
      }

      int GetBookingId()
      {
        return BookingId;
      }

      double GetTotalAmount()
      {
        return TotalAmount;
      }

      void SetTotalAmount(double amount)
      {
        TotalAmount = amount;
      }

      string GetStatus()
      {
        return Status;
      }

      void Confirm()
      {
        Status = "CONFIRMED";
      }

      void Cancel()
      {
        Status = "CANCELLED";
      }

      vector<ShowSeat*> GetSelectedSeats()
      {
        return SelectedSeats;
      }
};

int Booking::NextBookingId = 1;