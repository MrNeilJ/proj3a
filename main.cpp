/**************************************************************
** Author: Neil Johnson
**
** Date: 1.20.2017
**
** Description: This program will ask the user for an amount
** of integers they would like to enter.  The application then
** will allow the user to enter that many numbers.  Once
** completed it will display the largest and smallest numbers
** that the user typed in.
**************************************************************/


#include <iostream>
#include <fstream>  // Needed to read and write to files


int main() {
    // Open a file for writing the future integers to
    std::ofstream outputFile("userIntegers.txt");

    // Before doing anything make sure the file opens properly
    if (!outputFile)
    {
        std::cout << "Error opening this file, try running the program again!" << std::endl;
        return 1;
    }

    // Variables required for the program
    int maxVal,
        minVal,
        counter,
        userNum;
    // Ask the user for the number of integers that they would like
    std::cout << "How many integers would you like to enter?" << std::endl;

    // Take in user input and set it for the loop counter
    std::cin >> counter;

    if (counter < 1)
    {
        std::cout << "That is too small, re-run the program and type in a larger number. Thank you." << std::endl;
        return 1;
    }

    // Print to the screen asking for X amount of integers
    std::cout << "Please enter " << counter << " integers." << std::endl;

    // Allow user to type in X amount of integers
    for (int i = 0; i < counter; i++)
    {
        std::cin >> userNum;

        // Write each value the user inputs into the file previously opened
        outputFile << userNum << std::endl;
    }

    // Close file so no more reading is done
    outputFile.close();

    // Open file and prepare it for reading from it
    std::ifstream inputFile("userIntegers.txt");

    // Make sure inputFile opened properly
    if (!inputFile)
    {
        std::cout << "Error opening this file, try running the program again!" << std::endl;
    }

    // Set initial values of maxVal and minVal to the first value the user inputted
    inputFile >> userNum;
    maxVal = userNum;
    minVal = userNum;

    // Read through the open file (using a loop)
    for (int i = 1; i < counter; i++) {
        inputFile >> userNum;
        // Compare current number against the value in maxVal and minVal
        // If the number is BIGGER than the maxVal set current number to maxVal
        if (userNum > maxVal)
        {
            maxVal = userNum;
        }
        // If the number is SMALLER than the minVal set the current number to minVal
        else if (userNum < minVal)
        {
            minVal = userNum;
        }
    }
    // Close the input file
    inputFile.close();

    // Once loop is complete return the values saved in maxVal and minVal to the console
    std::cout << "min: " << minVal << std::endl;
    std::cout << "max: " << maxVal << std::endl;

    return 0;
}