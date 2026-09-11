#pragma once
#include <bits/stdc++.h>
using namespace std;

class Movie
{
    private:
       string Title;
       string Language;
       int Duration;
    
    public:
       Movie(string Title,string Language,int Duration)
       {
          this->Title = Title;
          this->Language = Language;
          this->Duration = Duration;
       }

       string GetTitle()
       {
          return Title;
       }

       string GetLanguage()
       {
          return Language;
       }

       int GetDuration()
       {
          return Duration;
       }
};