#pragma once
#include <bits/stdc++.h>
#include "09_Payment.cpp"
using namespace std;

class UpiPayment : public Payment
{
    public:
      bool Pay(double amount)override
      {
        cout<<"Processing UPI payment of Rs. "<< amount <<endl;
        return true;
      }
};

class CardPayment : public Payment
{
    public:
      bool Pay(double amount)override
      {
        cout<<"Processing Card payment of Rs. "<< amount <<endl;
        return true;
      }
};

class CashPayment : public Payment
{
    public:
      bool Pay(double amount)override
      {
        cout<<"Processing Cash payment of Rs. "<< amount <<endl;
        return true;
      }
};