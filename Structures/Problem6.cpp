#include <iostream>
using namespace std;

struct Planet
{
    char name[32];
    double distanceFromSun;
    double diameter;
    double mass;
};

double seconds(Planet p)
{
    return p.distanceFromSun / 299792;
}

void enterElements(Planet p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name;
        cin >> p[i].distanceFromSun;
        cin >> p[i].diameter;
        cin >> p[i].mass;
    }
}

void print(Planet p)
{
    cout << "Name: " << p.name << endl;
    cout << "Distance from sun: " << p.distanceFromSun << endl;
    cout << "Diameter: " << p.diameter << endl;
    cout << "Mass: " << p.mass << endl;
}

void printStructure(Planet p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        print(p[i]);
    }
}

double printMaxDiameter(Planet p[], int n)
{
    double max = INT32_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < p[i].diameter)
        {
            max = p[i].diameter;
        }
    }

    return max;
}

int main()
{
    Planet p[5];
    int n;
    cout << "Enter n: ";
    cin >> n;

    enterElements(p, n);
    printStructure(p, n);

    for (int i = 0; i < n; i++)
    {
        cout << "Seconds: " << seconds(p[i]) << endl;
    }

    cout << "Max diameter: " << printMaxDiameter(p, n);

    return 0;
}