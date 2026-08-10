#include <iostream>
#include <iomanip> // Add this header for setw
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

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthsDays[Month - 1];
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

// proplem-5: Get day name and order from gaven date
const static string WeakDays[] = {
    "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};
short DayOrderInWeak(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
void PrintDayNameAndOrder(short Year, short Month, short Day)
{
    short DayIndex = DayOrderInWeak(Year, Month, Day);

    cout << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order: " << DayIndex << endl;
    cout << "Day Name: " << WeakDays[DayIndex] << endl;
}
//

// proplem-6: Print Month Calnder
const static string Months[12] = { 
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
};
void PrintMonthCalnderHeader(string MonthName)
{
    cout << "_______________" << MonthName << "_______________" << endl << endl;
    cout << "SUN  ";
    cout << "MON  ";
    cout << "TUE  ";
    cout << "WED  ";
    cout << "THU  ";
    cout << "FRI  ";
    cout << "SAT  ";
    cout << endl;
}
void PrintMonthCalnder(short Year, short Month)
{
    string MonthName = Months[Month - 1];
    short FirstDayIndex = DayOrderInWeak(Year, Month, 1);
    short NumberOfDays = MonthDays(Month, Year);
    string EmptyDayPlaceHolder = "     ";

    PrintMonthCalnderHeader(MonthName);

    int i = 0;
    for (i = 0; i < FirstDayIndex; i++)
    {
        cout << EmptyDayPlaceHolder;
    }

    for (int j = 1; j <= NumberOfDays; j++)
    {
        cout << setw(3) << j << "  ";
        
        if (++i == 7)
        {
            i = 0;
            cout << endl;
        }
    }

    cout << endl << "_________________________________" << endl;
}
//

// proplem-7: Print Year Calnder
void PrintYearCalnderHeader(short Year)
{
    cout << "_________________________________" << endl << endl;
    cout << "              " << Year << endl;
    cout << "_________________________________" << endl << endl;    
}
void PrintYearCalender(short Year)
{
    PrintYearCalnderHeader(Year);

    for (int i = 1; i < 13; i++)
    {
        PrintMonthCalnder(Year, i);
        cout << endl;
    }
}
//

// proplem-8: Calculate total days from the begining of the year
short TotalDaysFromYearStart(short Year, short Month, short Day)
{
    short Total = 0;
    
    for (int i = 1; i < Month; i++)
    {
        Total += MonthDays(i, Year);
    }

    Total += Day;

    return Total;
}
//

int main()
{
    cout << TotalDaysFromYearStart(2022, 9, 20);
}