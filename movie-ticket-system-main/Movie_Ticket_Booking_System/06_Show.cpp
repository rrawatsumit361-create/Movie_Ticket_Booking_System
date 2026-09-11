#pragma once
#include <bits/stdc++.h>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "05_ShowSeat.cpp"
using namespace std;

class Show
{
   private:
     Movie* movie;
     Screen* screen;
     string StartTime;
     vector<ShowSeat*> showseats;
   
   public:
     Show(Movie* movie,Screen* screen,string StartTime)
     {
        this->movie = movie;
        this->screen = screen;
        this->StartTime = StartTime;
     }

     void AddShowSeat(ShowSeat *Showseat)
     {
        showseats.push_back(Showseat);
     }

     Movie *GetMovie()
     {
        return movie; 
     }

     Screen *GetScreen()
     {
        return screen;
     }

     string GetStartTime()
     {
        return StartTime;
     }

     vector<ShowSeat*> GetShowSeats()
     {
        return showseats;
     }

     void DisplaySeatLayout()
     {
        cout<<"Movie: "<<movie->GetTitle()<<endl;
        cout<<"Screen: "<<screen->GetScreenNumber()<<endl;
        cout<<"Show Time: "<<StartTime<<endl;
        cout<<endl;

        for(ShowSeat *showseat : showseats)
        {
                cout<<showseat->GetSeat()->GetSeatNumber()
                    <<" - "
                    <<showseat->GetSeat()->GetSeatType()
                    <<" - "
                    <<showseat->GetStatus()
                    <<endl;
        }
     }
};