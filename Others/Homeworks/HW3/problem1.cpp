#include <iostream>
using namespace std;

void deleteMatrix(int** matrix, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int** allocateMatrix(int** matrix, int size)
{
    matrix = new(nothrow) int* [size];

    if (!matrix) return matrix;

    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new(nothrow) int[3];
        if (!matrix[i])
        {
            deleteMatrix(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

void inputData(unsigned tasksCount, unsigned uniqueIndex, unsigned time, unsigned points, unsigned remainingDays,
    int** matrix, int& sum)
{
    int index = 0;

    for (size_t i = 0; i < tasksCount; i++)
    {
        cin >> uniqueIndex;
        cin >> time;
        cin >> points;

        matrix[i][index] = uniqueIndex;
        index++;
        matrix[i][index] = time;
        index++;
        matrix[i][index] = points;
        index = 0;
    }

    cin >> remainingDays;
    int inputMinutes = 0;

    for (size_t i = 0; i < remainingDays; i++)
    {
        cin >> inputMinutes;
        sum += inputMinutes;
    }
}

void getPriority(int** matrix, int size)
{
    double maxPointsForMinTime = INT_MAX;
    int minIndex = 0;

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            double minutes = matrix[j][1], points = matrix[j][2];

            double result = minutes / points;

            if (result < maxPointsForMinTime)
            {
                maxPointsForMinTime = result;
                minIndex = j;
            }
        }

        if (i != minIndex)
        {
            int* helper = matrix[i];
            matrix[i] = matrix[minIndex];
            matrix[minIndex] = helper;
        }

        maxPointsForMinTime = INT_MAX;
    }
}

/*void traverseMatrix(int** matrix, int& sum, int size, int* indexesArr, int& sizeOfIndexes)
{
    int index = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (matrix[i][1] <= sum)
        {
            sum -= matrix[i][1];
            *(indexesArr + index) = matrix[i][0];
            index++;
            sizeOfIndexes++;
        }
    }
}*/

void pickBestOption(int** matrix, int& sum, int size)
{
    int index = 0, currSum = 0, currPoints = 0, arrSumsIndex = 0, arrPointsIndex = 0, matrixRows = 0,
        indexIndexes = 0, indexesRows = 0, indexesCols = 0;
    int** matrixOfNumbers = nullptr;
    matrixOfNumbers = allocateMatrix(matrixOfNumbers, size);

    //tasksCount
    int* indexes = new(nothrow) int[100];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if (currSum + matrix[j][1] <= sum)
            {
                currSum += matrix[j][1];
                currPoints += matrix[j][2];
                matrixOfNumbers[matrixRows][0] = currSum;
                matrixOfNumbers[matrixRows][1] = currPoints;

                indexes[indexesRows] = matrix[j][0];
                indexesRows++;
            }
        }
        currSum = 0;
        currPoints = 0;
        matrixRows++;
        indexes[indexesRows] = -1;
        indexesRows++;
    }

    int maxP = INT_MIN, maxT = 0, maxIndex = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (maxP < matrixOfNumbers[i][1])
        {
            maxP = matrixOfNumbers[i][1];
            maxT = matrixOfNumbers[i][0];
            maxIndex = i;
        }
    }

    int resultIndex = 0, levelIndex = 0;

    cout << "Tasks: ";
    for (size_t i = 0; i < 100; i++)
    {
        if (levelIndex == maxIndex)
        {
            if (indexes[i] != -1)
            {
                if (indexes[i + 1] == -1)
                {
                    cout << indexes[i] << " ";
                }
                else
                {
                    cout << indexes[i] << ", ";
                }
            }
        }
        if (indexes[i] == -1)
        {
            levelIndex++;
        }
    }

    cout << endl;
    int remainingTime = abs(sum - maxT);

    cout << "Time remaining: ";
    cout << remainingTime / 60 << ":" << remainingTime - (remainingTime / 60) * 60;

    deleteMatrix(matrixOfNumbers, size);
    delete[] indexes;
}

int main()
{
    unsigned tasksCount = 0, uniqueIndex = 0, time = 0, points = 0, remainingDays = 0, minutesSequence = 0;

    cin >> tasksCount;

    int** matrix = nullptr;
    matrix = allocateMatrix(matrix, tasksCount);
    if (!matrix) return 1;

    int sum = 0;

    inputData(tasksCount, uniqueIndex, time, points, remainingDays, matrix, sum);

    //sorting the matrix
    getPriority(matrix, tasksCount);

    //picking the best option
    pickBestOption(matrix, sum, tasksCount);

    deleteMatrix(matrix, tasksCount);

    return 0;
}