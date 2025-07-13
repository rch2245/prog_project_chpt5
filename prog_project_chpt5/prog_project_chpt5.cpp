#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

// ==== POPULATION GROWTH PROGRAM ====

void handlePopulationGrowth() {
    int startingPopulation = 0, numberOfDays = 0;
    double dailyIncrease = 0.0, population = 0.0;

    std::cout << "\nPOPULATION GROWTH SIMULATOR\n\n";
    std::cout << "This program calculates population growth over a number of days.\n\n";

    std::cout << "Enter the starting number of organisms (minimum 2): ";
    while (!(std::cin >> startingPopulation) || startingPopulation < 2) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter a value of 2 or more: ";
    }

    std::cout << "Enter average daily population increase (percentage): ";
    while (!(std::cin >> dailyIncrease) || dailyIncrease < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter a non-negative value: ";
    }

    std::cout << "Enter number of days the organisms will multiply (minimum 1): ";
    while (!(std::cin >> numberOfDays) || numberOfDays < 1) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Enter a value of 1 or more: ";
    }

    std::cout << "\nDay    Population\n";
    std::cout << "-------------------\n";

    population = startingPopulation;
    std::cout << std::fixed << std::setprecision(2);
    for (int day = 1; day <= numberOfDays; day++) {
        std::cout << std::setw(3) << day << "    " << population << "\n";
        population += population * (dailyIncrease / 100.0);
    }
}

// ==== STUDENT LINEUP PROGRAM ====

void handleStudentLineup() {
    std::ifstream inputFile("LineUp.txt");
    std::string name, firstName, lastName;
    int studentCount = 0;

    std::cout << "\nSTUDENT LINEUP PROGRAM\n\n";
    std::cout << "This program reads names from a file and determines the front and end of the line alphabetically.\n\n";

    if (!inputFile) {
        std::cout << "Error: Could not open LineUp.txt\n";
        return;
    }

    if (inputFile >> name) {
        firstName = lastName = name;
        studentCount = 1;
    }
    else {
        std::cout << "The file is empty.\n";
        return;
    }

    while (inputFile >> name) {
        studentCount++;
        if (name < firstName) firstName = name;
        if (name > lastName) lastName = name;
    }

    inputFile.close();
    std::cout << "Number of students: " << studentCount << "\n";
    std::cout << "Student at the front of the line: " << firstName << "\n";
    std::cout << "Student at the end of the line: " << lastName << "\n";
}

// ==== POPULATION BAR CHART PROGRAM ====

void handlePopulationBarChart() {
    std::string filename, town;
    std::ifstream inputFile;
    int population, year = 1900;
    const int interval = 20;

    std::cout << "\nPOPULATION BAR CHART\n\n";
    std::cout << "This program displays a bar chart of a town's population growth.\n\n";

    std::cout << "Enter the name of the data file (e.g., People.txt): ";
    std::cin >> filename;

    std::cin.ignore();
    std::cout << "Enter the name of the town: ";
    std::getline(std::cin, town);

    inputFile.open(filename);
    if (!inputFile) {
        std::cout << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::cout << "\n" << town << " Population Growth\n";
    std::cout << "(each * represents 1,000 people)\n\n";

    while (inputFile >> population) {
        std::cout << year << " ";
        for (int i = 0; i < population / 1000; i++) {
            std::cout << "*";
        }
        std::cout << "\n";
        year += interval;
    }

    inputFile.close();
}

// ==== PATTERNS PROGRAM ====

void handlePatternsProgram() {
    std::cout << "\nPATTERNS PROGRAM\n\n";
    std::cout << "This program prints two triangle patterns using loops.\n\n";

    std::cout << "Pattern A\n\n";
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) std::cout << "+";
        std::cout << "\n";
    }

    std::cout << "\nPattern B\n\n";
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= i; j++) std::cout << "+";
        std::cout << "\n";
    }
}

// ==== RANDOM NUMBER GUESSING GAME ====

void handleRandomNumberGame() {
    int randomNumber, userGuess, guessCount = 0;

    std::cout << "\nRANDOM NUMBER GUESSING GAME\n\n";
    std::cout << "Guess a number between 1 and 100.\n";

    srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand() % 100 + 1;

    do {
        std::cout << "Enter your guess: ";
        while (!(std::cin >> userGuess)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter a number: ";
        }

        guessCount++;

        if (userGuess > randomNumber) {
            std::cout << "Too high, try again.\n";
        }
        else if (userGuess < randomNumber) {
            std::cout << "Too low, try again.\n";
        }
        else {
            std::cout << "Congratulations! You guessed the number in " << guessCount << " tries.\n";
        }
    } while (userGuess != randomNumber);
}

// ==== MAIN MENU ====

int main() {
    int choice = 0;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Population Growth\n";
        std::cout << "2. Student Lineup\n";
        std::cout << "3. Population Bar Chart\n";
        std::cout << "4. Patterns Program\n";
        std::cout << "5. Random Number Game\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: handlePopulationGrowth(); break;
        case 2: handleStudentLineup(); break;
        case 3: handlePopulationBarChart(); break;
        case 4: handlePatternsProgram(); break;
        case 5: handleRandomNumberGame(); break;
        case 6: std::cout << "Goodbye!\n"; break;
        default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
