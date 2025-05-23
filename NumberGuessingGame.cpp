#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void playGame();

int main() {
    srand(time(0));
    char choice;
    do {
        playGame();
        cout << "\nWant to Play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}

void playGame() {
    int lowerBound, upperBound;
    int secretNumber, guess, attempts = 0;
    time_t startTime, currentTime;

    cout << "\nWELCOME TO THE NUMBER GUESSING GAME\n***********************************\n";
    cout << "Choose difficulty level:\n";
    cout << "1. Easy (1-100)\n2. Medium (1-250)\n3. Hard (1-500)\n4. Extreme Hard (1-1500)\n5. Impossible (1-3000)\n";

    int choice;

    while (true) {
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        } else {
            break;
        }
    }

    switch (choice) {
        case 1: lowerBound = 1; upperBound = 100; break;
        case 2: lowerBound = 1; upperBound = 250; break;
        case 3: lowerBound = 1; upperBound = 500; break;
        case 4: lowerBound = 1; upperBound = 1500; break;
        case 5: lowerBound = 1; upperBound = 3000; break;
    }

    secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
    startTime = time(0); // Start timer

    cout << "\nGuess the number between " << lowerBound << " and " << upperBound << " within 60 seconds!\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }

        attempts++;
        currentTime = time(0);
        int remainingTime = 60 - static_cast<int>(difftime(currentTime, startTime));

        if (remainingTime <= 0) {
            cout << "Time's up! You lost.\n";
            cout << "The correct number was: " << secretNumber << "\n";
            return;
        }


        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
            cout << "Time left: " << remainingTime << " seconds\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
            cout << "Time left: " << remainingTime << " seconds\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            return;
        }

    } while (true);
}