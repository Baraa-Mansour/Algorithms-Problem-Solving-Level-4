#include <iostream>

using namespace std;

// proplem-1: print the text of number
const static string TextNumber[] = { 
    "",
    "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
    "Ten", "Eleven", "Twelve", 
    "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" 
};
const static string TextTens[] = {
    "","",
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty"
,   "Ninety" 
};
string NumberToText(int Number)
{
    int ActualNumber = 0;
    int Remainder = 0;

    if (Number <= 0)
        return " ";
    if (Number <= 19)
        return TextNumber[Number] + " ";

    if (Number <= 99)
    {
        ActualNumber = Number / 10;
        Remainder = Number % 10;

        return TextTens[ActualNumber] + " " + TextNumber[Remainder] + " ";
    }

    if (Number >= 100 && Number <= 199)
    {
        Remainder = Number % 100;

        return "One Hundred " + NumberToText(Remainder);
    }

    if (Number >= 200 && Number <= 999)
    {
        ActualNumber = Number / 100;
        Remainder = Number % 100;

        return NumberToText(ActualNumber) + "Hundreds " + NumberToText(Remainder);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        Remainder = Number % 1000;

        return "One Thousand " + NumberToText(Remainder);
    }
    
    if (Number >= 2000 && Number <= 999999)
    {
        ActualNumber = Number / 1000;
        Remainder = Number % 1000;

        return NumberToText(ActualNumber) + "Thousands " + NumberToText(Remainder);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        Remainder = Number % 1000000;

        return "One Million " + NumberToText(Remainder);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        ActualNumber = Number / 1000000;
        Remainder = Number % 1000000;

        return NumberToText(ActualNumber) + "Millions " + NumberToText(Remainder);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        Remainder = Number % 1000000000;

        return "One Billion " + NumberToText(Remainder);
    }
    
    if(Number >= 2000000000 && Number <= INT_MAX)
    {
        ActualNumber = Number / 1000000000;
        Remainder = Number % 1000000000;

        return NumberToText(ActualNumber) + "Billions " + NumberToText(Remainder);
    }
    else
    {
        return "Infinity";
    }
}
//

// proplem-2: is leap year
bool IsLeapYear(short Year)
{
    if (Year % 400 == 0)
        return true;

    if (Year % 100 == 0)
        return false;

    if (Year % 4 == 0)
        return true;

    return  false;
}
//

int main()
{
    cout << IsLeapYear(2000);
}