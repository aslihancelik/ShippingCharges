// ShippingCharges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
// This program calculates the shipping costs of a package to be shipped provided its weight and the 
// distance that it will be shipped.
//
// Programmer: Aslihan Celik
// Date: 10/26/2024



#include <iostream>
#include <iomanip>
using namespace std;

double calculateCharges(double weight, double distance) {

    double ratePerMiles;

    // Determine the rate based on the weight
    if (weight <= 2) {
        ratePerMiles = 1.1;
    }
    else if (weight <= 6) {
        ratePerMiles = 2.2;
    }
    else if (weight <= 10) {
        ratePerMiles = 3.7;
    }
    else if (weight <= 20) {
        ratePerMiles = 4.8;
    }

    // Calculate total charges based on distance
    return distance * ratePerMiles / 500;
}

int main()
{
    double weight, distance, charges;
    char choice;

    do {
        cout << "Please enter the weight of the package to be shipped in kilograms." << endl;
        cin >> weight;

        while (weight <= 0 || weight > 20) {
            cout << "Please enter again. The weight must be more than zero and less than or equal to 20kgs." << endl;
            cin >> weight;
        }

        cout << "Please enter the distance for the package to be shipped in miles." << endl;
        cin >> distance;


        while (distance <= 10 || distance > 3000) {
            cout << "Please enter again. The distance must be more than 10 and less than or equal to 3000." << endl;
            cin >> distance;
        }

        cout << "You entered " << weight << " kgs for weight and " << distance << " miles for the distance." << endl;

        charges = calculateCharges(weight, distance);
        cout << fixed << setprecision(2); // Format output to 2 decimal places
        cout << "The charges for this package is $" << charges << "." << endl;


        // Ask user if they want to enter another package
        cout << "Do you want to enter another package? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

