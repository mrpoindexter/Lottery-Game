#include <iostream>
#include<iomanip>
using namespace std;

double matrix[100][100];
double result[100];


bool checkIllconditioned()
{
    if (matrix[1][1] == 0)
    {
        return false;
    }
    return true;
}

void matrixInput(int size)
{
    cout << "Enter the elements of Coefficients: " << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size + 1; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Solutions(double array1[], int size)
{
    cout << "The solution of linear equations is: " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << "x[" << i << "]= " << fixed << array1[i] << endl;
    }
}

void matrixReduction(int size)
{
    double pivot;

    for (int j = 1; j <= size - 1; j++)
    {
        for (int i = 1; i <= size; i++)
        {
            if (i > j)
            {
                pivot = matrix[i][j] / matrix[j][j];

                for (int k = 1; k <= size + 1; k++)
                {
                    matrix[i][k] = matrix[i][k] - (pivot * matrix[j][k]);
                }
            }
        }
    }
}

void findingSolution(int size)
{
    double sum = 0.0;

    result[size] = matrix[size][size + 1] / matrix[size][size];

    for (int i = size - 1; i >= 1; i--)
    {
        sum = 0.0;

        for (int j = i + 1; j <= size; j++)
        {
            sum += matrix[i][j] * result[j];
        }

        result[i] = (matrix[i][size + 1] - sum) / matrix[i][i];
    }
}

void gaussElimination(int size)
{

    matrixInput(size);

    if (checkIllconditioned())
    {
        cout << "The system is well conditioned and can be solved by direct methods." << endl;

        matrixReduction(size);

        findingSolution(size);

        Solutions(result, size);
    }
}



int main()
{
    int size;
    cout << "Enter the size of the equation: ";
    cin >> size;

    gaussElimination(size);

    system("pause>0");
    return 0;
}