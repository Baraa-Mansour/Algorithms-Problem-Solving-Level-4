#include <iostream>

using namespace std;

// proplem-1: Print the text of number
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

// proplem-2: Is leap year
bool IsLeapYear(short Year)
{
    return  (Year % 400 == 0) || ((Year % 100 != 0) && (Year % 4 == 0));
}
//

// proplem-3: Get Year Days, Hours, Minutes and Seconds
short YearDays(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}
short YearHours(short Year)
{
    short Days = YearDays(Year);

    return Days * 24;
}
int YearMinutes(short Year)
{
    short Hours = YearHours(Year);

    return Hours * 60;
}
int YearSeconds(short Year)
{
    int Minutes = YearMinutes(Year);

    return Minutes * 60;
}

void PrintYearComponent(short Year)
{
    short Days = YearDays(Year);
    cout << Days << endl;
    short Hours = YearHours(Year);
    cout << Hours << endl;
    int Minutes = YearMinutes(Year);
    cout << Minutes << endl;
    int Seconds = YearSeconds(Year);
    cout << Seconds << endl;
}
//

// proplem-4: Get month days, hours, minutes and seconds
const static short MonthsDays[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};
short MonthDays(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }

    return MonthsDays[Month - 1];
}
short MonthHours(short Month, short Year)
{
    return MonthDays(Month, Year) * 24;
}
int MonthMinutes(short Month, short Year)
{
    return MonthHours(Month, Year) * 60;
}
int MonthSeconds(short Month, short Year)
{
    return MonthMinutes(Month, Year) * 60;
}

void PrintMonthComponent(short Month, short Year)
{
    short Days = MonthDays(Month, Year);
    cout << Days << endl;
    short Hours = MonthHours(Month, Year);
    cout << Hours << endl;
    int Minutes = MonthMinutes(Month, Year);
    cout << Minutes << endl;
    int Seconds = MonthSeconds(Month, Year);
    cout << Seconds << endl;
}
//

int main()
{
    PrintMonthComponent(2, 1971);
}