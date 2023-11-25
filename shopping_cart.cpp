
// NAME: RAJDEEP KUMAR SINGH
// USN: 1BY20IS124
// COLLEGE: BMS Institue of Technology and Management
// Year of passing: 2024
// phone no: 9798355985
// email: rajdeepdav4@gmail.com

#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string Name;
    double UnitPrice;
    double GstPer;
    int Quantity;

public:
    double gstAmt() const
    {
        auto gstamount = (UnitPrice * GstPer / 100) * Quantity;
        return gstamount;
    }

public:
    double totalCost() const
    {
        double discount = 0;
        if (UnitPrice >= 500)
        {
            discount = UnitPrice * 0.05;
        }
        auto cost = (UnitPrice - discount) * Quantity + gstAmt();
        return cost;
    }
};

int main()
{

    vector<Product> basket = {{"leather_wallet", 1100, 18, 1}, {"umbrella", 900, 12, 4}, {"cigarette", 200, 28, 3}, {"Honey", 100, 0, 2}};
    auto maxGstProduct = max_element(basket.begin(), basket.end(), [](const Product &a, const Product &b)
                                     {
                                         auto value=a.gstAmt()<b.gstAmt();
                                         return value; });

    cout << "Product max GST: " << maxGstProduct->Name << endl;

    double totalAmount = 0;
    for (auto &product : basket)
    {
        totalAmount += product.totalCost();
    }
    cout << "Total amount to paid is: Rs " << totalAmount << endl;
    return 0;
}