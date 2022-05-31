// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description: Gets a list of percentage marks and calculates the average.

#include <list>
#include <array>
#include <iomanip>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stof;
using std::array;
using std::list;

// This function caluculates the average of the entered marks
float CalcAverage(list<float> marks) {
    float sumNum = 0;
    // Checking to ensure the list had items in it
    if (marks.size() == 0) {
        return -1;
    } else {
        // Calculating the sum
        for (float aNum : marks) {
            sumNum += aNum;
        }
        // Calculating the average
        float avg = sumNum / marks.size();
        return avg;
    }
}


int main() {
    cout << "Enter your marks as a percentage. When you're ready to " <<
    " calculate the average, just enter '-1'. Calculated numbers must" <<
    " be between 0-100" << endl;

    list<float> uMarks;
    float newNum;
    int end = -1;

    do {
        string tempNum;
        cout << "Enter a mark: ";
        cin >> tempNum;

        try {
            newNum = stof(tempNum);
            // adding the input to the list
            if (newNum <= 100 && newNum >= end) {
                uMarks.push_back(newNum);
            } else {
                cout << "That number was not within the valid range" << endl;
            }
        } catch (...) {
            cout << "That was an invalid number" << endl;
        }
    // end is the assigned to the value that will be entered to start the calcs
    } while (newNum != end);

    // Getting rid of the -1
    uMarks.pop_back();
    float average = CalcAverage(uMarks);

    if (average == end) {
        cout << "No marks were entered :/";
    } else {
        cout << "Your average is " << std::fixed <<
        std::setprecision(2) << average << "%";
    }
}
