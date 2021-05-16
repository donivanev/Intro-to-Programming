#pragma once
#include <iostream>
using namespace std;

int numberLength(unsigned number);
int reverseNumber(int number);
int* numberToArray(int number);
bool isNegative(int number);
bool hasRepeatingDigits(int number);
bool hasZeroDigit(int number);
bool isInputValid(int number);
int searchForBulls(int numberToGuess, int attemptingNumber);
int searchForCows(int numberToGuess, int attemptingNumber);
int* loadValidNumbers();
bool* loadPossibleNumbers();
int chooseAPossibleNumber(int* validNumbers, bool* isPossible);
void filterPossibleNumbers(int bulls, int cows, int guess, int* validNumbers, bool* isPossible);

const int* tryGuess(int number);
void play();