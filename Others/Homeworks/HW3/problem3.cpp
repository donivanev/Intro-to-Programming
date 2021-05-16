#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned char pixel[3];

void deleteMatrix(pixel** image, size_t height)
{
    for (size_t i = 0; i < height; i++)
    {
        delete[] image[i];
    }

    delete[] image;
}

pixel** allocateMatrix(size_t height, size_t width)
{
    pixel** image = new(nothrow) pixel * [height];
    if (!image) return image;

    for (size_t i = 0; i < height; i++)
    {
        image[i] = new(nothrow) pixel[width];
        if (!image[i])
        {
            deleteMatrix(image, i);
            return nullptr;
        }
    }

    return image;
}

void loadMatrix(pixel** pixelMatrix, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cin >> pixelMatrix[i][j];
        }
    }
}

void showMatrix(pixel** pixelMatrix, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            cout << pixelMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int lengthOfPixel(const pixel p)
{
    int counter = 0;

    while (*p)
    {
        p++;
        counter++;
    }

    return counter;
}

bool isPixelBiggerByOneOrZero(const pixel firstPixel, const pixel secondPixel)
{
    int firstNumber = 0, secondNumber = 0, startingNumber = 0;
    int length1 = lengthOfPixel(firstPixel);
    int length2 = lengthOfPixel(secondPixel);

    switch (length1)
    {
    case 1: startingNumber = 1; break;
    case 2: startingNumber = 10; break;
    case 3: startingNumber = 100; break;
    }

    while (*firstPixel)
    {
        firstNumber += (*firstPixel - '0') * startingNumber;
        firstPixel++;
        startingNumber /= 10;
    }

    switch (length2)
    {
    case 1: startingNumber = 1; break;
    case 2: startingNumber = 10; break;
    case 3: startingNumber = 100; break;
    }

    while (*secondPixel)
    {
        secondNumber += (*secondPixel - '0') * startingNumber;
        secondPixel++;
        startingNumber /= 10;
    }

    if (abs(firstNumber - secondNumber) == 1 || firstNumber == secondNumber)
    {
        return true;
    }

    return false;
}

void transferPixel(pixel firstPixel, const pixel secondPixel)
{
    int index = 0;

    for (size_t i = 0; i < 3; i++)
    {
        firstPixel[index] = secondPixel[i];
        index++;
    }
}

/*
20 20 20 15 18 10
22 21 20 19 18 14
20 20 26 16 22 42
21 25 25 20 19 41
19 20 23 43 44 44

8 9 10 6 8 77
7 13 3 55 1 21
1 2 8 7 33 21
9 4 23 6 9 13
3 5 7 4 22 9

8 9 10 11 12 13
7 1 3 5 12 2
1 2 8 7 13 14
9 4 2 6 9 15
3 5 7 4 22 9
*/

pixel** fillArea(const pixel* const* const image, size_t width, size_t height, size_t row, size_t column)
{
    pixel** resultMatrix = allocateMatrix(height, width);
    resultMatrix[row][column][0] = ' ';
    resultMatrix[row][column][1] = '0';
    resultMatrix[row][column][2] = '\0';

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            //image[i][j - 1]  image[i - 1][j]  image[i][j + 1]  image[i + 1][j]
            //if the element is 0 => spread the black color
            if (resultMatrix[i][j][0] == ' ' && resultMatrix[i][j][1] == '0')
            {
                if (j != 0)
                {
                    if (isPixelBiggerByOneOrZero(image[i][j - 1], image[i][j]))
                    {
                        resultMatrix[i][j - 1][0] = ' ';
                        resultMatrix[i][j - 1][1] = '0';
                        resultMatrix[i][j - 1][2] = '\0';
                    }
                }

                if (i != 0)
                {
                    if (isPixelBiggerByOneOrZero(image[i - 1][j], image[i][j]))
                    {
                        resultMatrix[i - 1][j][0] = ' ';
                        resultMatrix[i - 1][j][1] = '0';
                        resultMatrix[i - 1][j][2] = '\0';
                    }
                }

                if (j + 1 < width)
                {
                    if (isPixelBiggerByOneOrZero(image[i][j + 1], image[i][j]))
                    {
                        resultMatrix[i][j + 1][0] = ' ';
                        resultMatrix[i][j + 1][1] = '0';
                        resultMatrix[i][j + 1][2] = '\0';
                    }
                }

                if (i + 1 < height)
                {
                    if (isPixelBiggerByOneOrZero(image[i + 1][j], image[i][j]))
                    {
                        resultMatrix[i + 1][j][0] = ' ';
                        resultMatrix[i + 1][j][1] = '0';
                        resultMatrix[i + 1][j][2] = '\0';
                    }
                }
            }
            else
            {
                bool flag = false;
                //if not => check if there are zeros around 

                if (j != 0)
                {
                    if (resultMatrix[i][j - 1][0] == ' ' && resultMatrix[i][j - 1][1] == '0')
                    {
                        if (isPixelBiggerByOneOrZero(image[i][j - 1], image[i][j]))
                        {
                            resultMatrix[i][j][0] = ' ';
                            resultMatrix[i][j][1] = '0';
                            resultMatrix[i][j][2] = '\0';

                            flag = true;
                        }
                    }
                }

                if (i != 0)
                {
                    if (resultMatrix[i - 1][j][0] == ' ' && resultMatrix[i - 1][j][1] == '0')
                    {
                        if (isPixelBiggerByOneOrZero(image[i - 1][j], image[i][j]))
                        {
                            resultMatrix[i][j][0] = ' ';
                            resultMatrix[i][j][1] = '0';
                            resultMatrix[i][j][2] = '\0';

                            flag = true;
                        }
                    }
                }

                if (j + 1 < width)
                {
                    if (resultMatrix[i][j + 1][0] == ' ' && resultMatrix[i][j + 1][1] == '0')
                    {
                        if (isPixelBiggerByOneOrZero(image[i][j + 1], image[i][j]))
                        {
                            resultMatrix[i][j][0] = ' ';
                            resultMatrix[i][j][1] = '0';
                            resultMatrix[i][j][2] = '\0';

                            flag = true;
                        }
                    }
                }

                if (i + 1 < height)
                {
                    if (resultMatrix[i + 1][j][0] == ' ' && resultMatrix[i][j + 1][1] == '0')
                    {
                        if (isPixelBiggerByOneOrZero(image[i + 1][j], image[i][j]))
                        {
                            resultMatrix[i][j][0] = ' ';
                            resultMatrix[i][j][1] = '0';
                            resultMatrix[i][j][2] = '\0';

                            flag = true;
                        }
                    }
                }

                //else => do nothing  
                if (!flag)
                {
                    transferPixel(resultMatrix[i][j], image[i][j]);
                }
            }
        }
    }

    return resultMatrix;
}

int main()
{
    //The user should input the height and the width of a matrix
    unsigned height, width, row, column;
    cin >> height >> width;

    pixel** pixelMatrix = allocateMatrix(height, width);

    //then he initializes it with values
    loadMatrix(pixelMatrix, height, width);

    //the user enters a row and a column where the black painting begins from
    cin >> row >> column;

    cout << endl;

    pixel** filledMatrix = fillArea(pixelMatrix, width, height, row, column);

    showMatrix(filledMatrix, height, width);

    deleteMatrix(filledMatrix, height);
    deleteMatrix(pixelMatrix, height);

    return 0;
}