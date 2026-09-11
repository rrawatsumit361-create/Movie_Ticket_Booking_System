#pragma once
#include <bits/stdc++.h>
using namespace std;

class Customer
{
    private:
      string CustomerName;
      string CustomerPhone;
      string CustomerEmail;

    public:
      Customer(string CustomerName,string CustomerPhone,string CustomerEmail)
      {
        this->CustomerName = CustomerName;
        this->CustomerPhone = CustomerPhone;
        this->CustomerEmail = CustomerEmail;
      }

      string GetCustomerName()
      {
        return CustomerName;
      }

      string GetCustomerPhone()
      {
        return CustomerPhone;
      }

      string GetCustomerEmail()
      {
        return CustomerEmail;
      }
};