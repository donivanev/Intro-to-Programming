#include <iostream>
using namespace std;

struct Product
{
    char description[32];
    int partNum;
    double cost;
};

void enterElements(Product p[])
{
    for (int i = 0; i < 5; i++)
    {
        cin >> p[i].description;
        cin >> p[i].partNum;
        cin >> p[i].cost;
    }
}

void initialize(Product p[])
{
    strcpy_s(p[0].description, "screw driver");
    p[0].partNum = 456;
    p[0].cost = 5.50;

    strcpy_s(p[1].description, "hammer");
    p[1].partNum = 324;
    p[1].cost = 8.20;

    strcpy_s(p[2].description, "socket");
    p[2].partNum = 777;
    p[2].cost = 6.80;

    strcpy_s(p[3].description, "plier");
    p[3].partNum = 123;
    p[3].cost = 10.80;

    strcpy_s(p[4].description, "hand-saw");
    p[4].partNum = 555;
    p[4].cost = 12.80;
}

void initialValues(Product p[])
{
    for (int i = 0; i < 5; i++)
    {
        strcpy_s(p[i].description, "");
        p[i].partNum = 0;
        p[i].cost = 0.0;
    }
}

void print(Product p)
{
    cout << "Description: " << p.description << endl;
    cout << "PartNum: " << p.partNum << endl;
    cout << "Cost: " << p.cost << endl;
}

void printStructure(Product p[])
{
    for (int i = 0; i < 5; i++)
    {
        print(p[i]);
    }
}

int main()
{
    Product p1;
    Product p2;

    strcpy_s(p1.description, "screw driver");
    p1.partNum = 456;
    p1.cost = 5.50;

    strcpy_s(p2.description, "hammer");
    p2.partNum = 324;
    p2.cost = 8.20;

    print(p1);
    print(p2);

    Product p[5];

    enterElements(p);
    printStructure(p);

    initialValues(p);
    printStructure(p);

    initialize(p);
    printStructure(p);

    return 0;
}