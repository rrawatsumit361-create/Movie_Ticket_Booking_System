#pragma once
#include <bits/stdc++.h>
#include "03_Screen.cpp"

using namespace std;

class Cinema
{
private:
    string CinemaName;
    vector<Screen*> screens;

public:
    Cinema(string CinemaName)
    {
        this->CinemaName = CinemaName;
    }

    void AddScreen(Screen* screen)
    {
        screens.push_back(screen);
    }

    vector<Screen*> GetScreens()
    {
        return screens;
    }

    void DisplayScreens()
    {
        cout << "Cinema Name: " << CinemaName << endl;

        for (Screen* screen : screens)
        {
            cout << "Screen "
                 << screen->GetScreenNumber()
                 << endl;
        }
    }
};