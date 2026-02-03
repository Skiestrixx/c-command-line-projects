#include <stdio.h>
#include <stdlib.h>

void printInstruction()
{
    puts("Insert an operator and number eg:");
    puts("+ (number to be added)");
    puts("- (number to be subtracted)");
    puts("* (number to be multiplied)");
    puts("/ (number to be divided)");
    puts("c 0(To clear)");
    puts("o 0(to off)");
}

void startingPrompt(double *ptotal)
{
    printf("Enter a number: ");
    scanf("%lf", ptotal);
    printf("%lf ", *ptotal);
}

void addNumber(double *ptotal, double *pnumber)
{
    *ptotal += *pnumber;
    *pnumber = 0;
    printf("%lf ", *ptotal);
}

void subtractNumber(double *ptotal, double *pnumber)
{
    *ptotal -= *pnumber;
    *pnumber = 0;
    printf("%lf ", *ptotal);
}
void multiplyNumber(double *ptotal, double *pnumber)
{
    *ptotal *= *pnumber;
    *pnumber = 0;
    printf("%lf ", *ptotal);
}

void clearAll(double *ptotal, double *pnumber)
{
    *ptotal = 0;
    *pnumber = 0;
    system("clear");
    printInstruction();
    startingPrompt(ptotal);
}

void divideNumber(double *ptotal, double *pnumber)
{
    *ptotal /= *pnumber;
    *pnumber = 0;
    printf("%lf ", *ptotal);
}

int main()
{
    char operator;
    int turnOff = 0;
    double total = 0;
    double *ptotal = &total;
    double number;
    double *pnumber = &number;

    printInstruction();
    startingPrompt(ptotal);
    do
    {
        scanf(" %c %lf", &operator, &number);
        switch (operator)
        {
        case '+':
            addNumber(ptotal, pnumber);
            break;
        case '-':
            subtractNumber(ptotal, pnumber);
            break;
        case '*':
            multiplyNumber(ptotal, pnumber);
            break;
        case '/':
            divideNumber(ptotal, pnumber);
            break;
        case 'c':
            clearAll(ptotal, pnumber);
            break;
        case 'o':
            system("clear");
            turnOff = 1;
            break;
        default:
            puts("Invalid");
            clearAll(ptotal, pnumber);
            break;
        }
    } while (turnOff == 0);
    return 0;
}