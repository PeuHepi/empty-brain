#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double ASSIGNMENT = 0.6;
const double EXAM = 0.2;

void displayMenu();
int checkInt(string prompt);
double checkDouble(string prompt);

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    displayMenu();

}

void displayMenu() {
    cout << "Please enter the following information and I will calculate your" << endl;
    cout << "Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4.\n" << endl;
}

void goodbye() {
    cout << "\nThank you for using my Grade Calculator!" << endl;
}

int readAssignment()
{

    int numAssignments = checkInt(">>");

    while (numAssignments < 0 || numAssignments > 10)
    {
        cout << "Invalid Value! Please enter a number between 0 and 10." << endl;
        numAssignments = readAssignment();
    }
    return numAssignments;
}

int checkInt(string prompt)
{
    int tempVar = 0;
    cout << prompt;
    cin >> tempVar;
    while (!cin)
    {
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> tempVar;
    }
    cin.ignore(50, '\n');
    return tempVar;
}

void readScore(string prompt, double& num)// changes applied
{

    num = checkDouble(prompt);

    while (num < 0.0 || num > 4.0)
    {
        cout << "Illegal Score! Please try again!" << endl;
        num = checkDouble(prompt);
    }
    
}

double checkDouble(string prompt)
{
    double tempVar = 0.0;
    cout << prompt;
    cin >> tempVar;
    while (!cin)
    {
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> tempVar;
    }
    cin.ignore(50, '\n');
    return tempVar;
}

void getInput(double& midtermScore, double& finalExamScore) { // changes applied
    cout << "\nEnter your midterm exam score: " << endl;

    readScore(">>", midtermScore);

    cout << "Enter your final exam score: " << endl;

    readScore(">>", finalExamScore);
}

double assignAverege(int numAsigns) {
    double avScore = 0;
    double temp = 0; // changes applied
    for (int i = 1; i <= numAsigns; i++) {
        cout << "Enter score " << i << " \n";
        readScore(">>", temp); // changes applied
        avScore += temp; // changes applied
    }
    avScore = avScore / numAsigns;
    return avScore;

}

double calcFinalScore(double assignAvg, double midterm, double final) {
    return (assignAvg * ASSIGNMENT) + ((midterm + final) * EXAM);
}

void calcLetterGrade(double finalScore, char& letter) {
    if (finalScore < 1.2) {
        letter = 'F';
    }
    else if (finalScore < 2.0) {
        letter = 'D';
    }
    else if (finalScore < 2.8) {
        letter = 'C';
    }
    else if (finalScore < 3.3) {
        letter = 'B';
    }
    else if (finalScore <= 4.0) {
        letter = 'A';
    }
    else {
        cout << "Error in Letter Grade!" << endl;
        letter = 'N';
    }
}

//===============================================================================================

int main() {

    int numAssignmentsInput;
    double scoreAsign, midterm, final;
    char letter;

    welcome();

    cout << "Enter the number of assignments (0 to 10): \n";
    numAssignmentsInput = readAssignment();


    scoreAsign = assignAverege(numAssignmentsInput);
    getInput(midterm, final);

    double finalScore = calcFinalScore(scoreAsign, midterm, final);

    cout << setprecision(2) << "\nYour Final Numeric score is " << finalScore << endl;
    calcLetterGrade(finalScore, letter);
    cout << "Your Final Grade is " << letter << endl;

    goodbye();
}

