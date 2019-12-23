// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Project goals: Produce price, produce money tendered. Require user to input correct change. Stores time taken, outputs .txt file with time and can recall shortest times.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

unsigned int tendered;
unsigned int dolPrice;
float cenPrice;
float price;
float difference;
unsigned randomOut;
unsigned randomIn;
bool helpYes;
string input;

class RandomGen {
public:;
      void initRandom() {
          srand(time(NULL));
          cout << "Random init \n";
      }
      void getRandom() {
          randomOut = rand() % 10;
      }
      void randomHelp() {
          cout << "This program generates it's pseudo-random values based on the current time. While not truly random, for the purposes \n"
              "Of this excercise, it will more than suffice. The program will generate values based on another set of random information every time \n"
              "The program is run, so you should never run into the same number twice in a row!\n";
      }
};

class PriceGen {
public:;
      short dolCount = 0;
      short cenCount = 0;
    void getPrice() {
        while (dolCount < 8) {
            RandomGen().getRandom();
            dolPrice = dolPrice + randomOut;
            dolCount = dolCount + 1;
        }

        while (cenCount < 16) {
            RandomGen().getRandom();
            cenPrice = cenPrice + randomOut;
            cenCount = cenCount + 1;
        }
        cenPrice = cenPrice * 0.01;
        price = dolPrice + cenPrice;
    }

    void getTender() {
        float tempVar;
        unsigned int tempPrice;
        tempVar = 1 - cenPrice;
        tempPrice = price + tempVar;

        while (tempPrice >= tendered) {
            tendered = tendered + 5;

        }
    }

    void getDifference() {
        difference = tendered - price;
        difference = roundf(difference * 100) / 100;
    }

    void reset() {
        price = 0;
        tendered = 0;
        difference = 0;
        dolCount = 0;
        cenCount = 0;
        cenPrice = 0;
        cenCount = 0;
        dolPrice = 0;
    }

    void priceHelp() {
        cout << "This program generates it's money using the random function. It tries to calculate reasonable prices by adding together single \n"
            "digit integers eight times for the dollar value. From there, it uses the same process to generate a change amount, and then multiplies \n"
            "that number by '0.01' to turn it into a decimal value. Those two numbers are then added together, producing the price. To get the amount \n"
            "tendered, a function adds 5 to a variable until the amount tendered is above the price. Given that the most important aspect of calculating \n"
            "change is dealing with cents, the lack of large discrepencies between tender and price is not a big deal. A hidden difference is then calculated \n"
            "by subtracting the amount tendered from the price. These three activities (Price calculation, tender calculation, difference calculation) are \n"
            "each handled by three distinct functions, all called in sequence when the computer generates a new problem for you to solve.\n";
    }
};

class HelpGen {
public:;
    void getHelp() {
        cout << "Hello! Welcome to the help page. Below will be the different commands you can use in this program. If you'd \n"
            "like to learn about a specific command in more detail, please format it like this: 'help--command.' If you don't\n"
            "Want anymore help, use the command 'nohelp', please. Thank you and have fun!\n"
            "1. About\n"
            "2. Start \n"
            "3. Stop \n"
            "4. Exit \n"
            "5. Hiscores \n";
        input = " ";

    }
    void aboutHelp() {
        cout << "Generating random numbers: \n";
        RandomGen().randomHelp();
        cout << "\n\n";
        cout << "Calculating price: \n";
        PriceGen().priceHelp();
        input = " ";

    }
    void startHelp() {
        cout << "Using the command 'start' will begin the change training challenge! Your goal is \n"
            "to calculate the amount of change owed in your head and enter the answer. Good luck!\n";
        input = " ";
    }
    void stopHelp() {
        cout << "Done with calculating change and want to check out your scores or close the app? \n"
            "entering the command 'stop' will bring you back to the menu!\n";
        input = " ";

    }
    void exitHelp() {
        cout << "Done with the program and want to exit safely? Use the command 'exit' to do so!\n";
        input = " ";

    }
    void hiscoreHelp() {
        cout << "Want to see your fastest change solution? Use the command 'hiscores' to see your\n"
            "fastest times!\n";
        input = " ";

    }

    void helpActive(){
        getHelp();
        while (helpYes == 1) {
            if (input == "help--about") {
                aboutHelp();
            }
            if (input == "help--start") {
                startHelp();
            }
            if (input == "help--stop") {
                stopHelp();
            }
            if (input == "help--exit") {
                exitHelp();
            }
            if (input == "help--hiscores") {
                hiscoreHelp();
            }
            if (input == "nohelp") {
                helpYes = 0;
                cout << "Exiting the help menu!\n";
                input = " ";
            }
            if (input == "help") {
                getHelp();
            }
            if (input == " ") {
                cin >> input;

            }
                else {
                    cout << "Sorry, that command is not valid! Exiting help mode!\n";
                    helpYes = 0;
                    input = " ";

                }
        }

    }


};

class RuntimeLoop {
public:;
    void gametime() {
        bool y = 1;
        bool active = 1;
        bool response = 1;
        float changeInput;
        while (y == 1) {
            if (active == 1) {
                PriceGen().getPrice();
                PriceGen().getTender();
                PriceGen().getDifference();
                cout << "The price of the item is:  " << price << "\n";
                cout << "The customer has handed you:  " << tendered << "\n";
                cout << "Enter the change." << "\n";
                cout << difference << " Debug ";
                active = 0;
                response = 1;
            }
            while (response == 1) {
                cin >> changeInput;
                changeInput = roundf(changeInput * 100) / 100;
                if (changeInput == difference) {
                    cout << "Congratulations! That was correct." << "\n";
                    active = 1;
                    response = 0;
                }
                if(changeInput != difference){
                    cout << "That was incorrect. Try again." << "\n";
                    cout << "Your answer was: " << changeInput << ", but the correct answer was: " << difference << "\n";
                    active = 1;
                    response = 0;
                    }
                if (changeInput == 0) {
                    cout << "Please only enter numbers in the xx.xx format! \n";
                    response = 0;
                    active = 0;
                    y = 0;
                    cout << "Exiting changetrainer. \n";
                }
                if (changeInput < 0) {
                    cout << "Please only enter positive numbers in the xx.xx format! \n";
                    response = 0;
                    active = 0;
                    y = 0;
                    cout << "Exiting changetrainer. \n";
                }
                PriceGen().reset();
            }

        }
    }

    void runtime() {
        short x = 1;
        short y = 1;
        cout << "Runtime start\n";
        cout << "Hi! Welcome to this change trainer. For help, please type in 'help' below. Otherwise, have fun! \n \n";

        while (y == 1){
            cin >> input;
            x = 1;
            while (x == 1) {
                if (input == "help") {
                    input = " ";
                    helpYes = 1;
                    HelpGen().helpActive();
                }
                if (input == "exit") {
                    cout << "So long! Thanks for practicing!";
                    x = 0;
                }
                if (input == "start") {
                    gametime();
                }
                if (input == "hiscores") {
                }
                input = "";
                x = 0;
            }
        }
    }
};

int main()
{
    RandomGen().initRandom(); 
    RuntimeLoop().runtime();

    return 0;
}

