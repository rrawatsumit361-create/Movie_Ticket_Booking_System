#pragma once
#include <bits/stdc++.h>
using namespace std;

class Payment
{
    public:
      virtual bool Pay(double amount) = 0;

      virtual ~Payment()
      {
      }
};
