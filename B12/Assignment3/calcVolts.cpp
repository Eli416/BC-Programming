/**
 *    Description: Declares and manipulates 3 one dimensional arrays
 *    Name: Sean Halpin
 *    Class: COMP B12 8AM MW
 *    Instructor: Richard Miles
 *    Created On: 2016/10/23
 *    Assignment: Assignment 3
 */

#include <iostream>
using namespace std;
void calcVolts(double * current, double * resistance, double * voltage) {
    for (int i = 0; i < 10; ++i) {
        *voltage = *current * *resistance;
        voltage++;
        current++;
        resistance++;
    }
    /* Return pointers to beginning of array */
    for (int i = 0; i < 10; ++i) {
        voltage--;
        current--;
        resistance--;
    }
}

int main() {
    double current[] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 
        12.15, 3.98};
    double resistance[] = {4.0, 8.5, 6.0, 7.35, 9.0, 15.3, 3.0, 5.4, 2.9, 4.8};
    double voltage[10];
    for (int i = 0; i < 10; ++i) {
        cout << "Current:  " << current[i] 
            << "\t   Resistance: " << resistance[i] 
            << "\tVoltage: " << voltage[i] << endl;
    }
    calcVolts(current, resistance, voltage);
    cout << "calcVolts called." << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Current:  " << current[i] 
            << "\t   Resistance: " << resistance[i] 
            << "\tVoltage: " << voltage[i] << endl;
    }
    return 0;
}