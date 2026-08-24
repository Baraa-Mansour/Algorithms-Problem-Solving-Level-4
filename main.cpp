#include <iostream>
#include <iomanip> // Add this header for setw
#include <ctime>
#include <vector>
#include <numeric>
#include <string>
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

// proplem-9: Take total days and convert them to date in year
struct stDate
{
    short Year = 1971;
    short Month = 1;
    short Day = 1;
};
stDate GetDateFromTotalDays(short Year, short Days)
{
    stDate Date;
    Date.Year = Year;

    while(true)
    {
        short MonthTotalDays = MonthDays(Date.Month, Year);

        if (Days >= MonthTotalDays)
        {
            Days -= MonthTotalDays;
            Date.Month++;
        }
        else
        {
            Date.Day = Days;
            break;
        }
    }

    return Date;
}
//

// proplem-10: Add days for Date
stDate AddDaysForDate(short Days, stDate Date)
{
    Days += Date.Day;
    while (true)
    {
        short MonthTotalDays = MonthDays(Date.Month, Date.Year);

        if (Days >= MonthTotalDays)
        {
            Days -= MonthTotalDays;
            if (Date.Month == 12)
            {
                Date.Year++;
                Date.Month = 1;
            }
            else
            {
                Date.Month++;
            }
        }
        else
        {
            Date.Day = Days;
            break;
        }
    }

    return Date;
}
//

// proplem-11: Date proplems
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : 
        ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
         (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) 
        : false);
}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month ==
            Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false)
            : false) : false;
}
bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == MonthDays(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}
stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}
//

// proplem-12: Get Diff Between Date in Days
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int DiffDays = 0;

    for (short i = Date1.Year; i < Date2.Year; i++)
    {
        DiffDays += YearDays(i);
    }

    DiffDays -= TotalDaysFromYearStart(Date1.Year, Date1.Month, Date1.Day);
    DiffDays += TotalDaysFromYearStart(Date2.Year, Date2.Month, Date2.Day);

    return IncludeEndDay ? ++DiffDays : DiffDays;
}
//

// proplem-13: Get Age
tm GetCurrentSystemDate()
{
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);

    return now;
}
stDate GetCurrentDate()
{
    tm tmObject = GetCurrentSystemDate();

    stDate Date;
    Date.Year = 1900 + tmObject.tm_year;
    Date.Month = tmObject.tm_mon + 1;
    Date.Day = tmObject.tm_mday;

    return Date;
}
short GetAge(stDate DateOfBirth)
{
    stDate CurrentDate = GetCurrentDate();

    return GetDifferenceInDays(DateOfBirth, CurrentDate, true);
}
//

// problem-14: Get diff even if negative
int GetDifferenceInDaysNegative(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return GetDifferenceInDays(Date1, Date2, IncludeEndDay);
    else
        return -GetDifferenceInDays(Date2, Date1, IncludeEndDay);
}
//

// problem-15: Increase Date Problems
stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    //last check day in date should not exceed max days in the current month
     // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
    // be 28/2/2022
    short NumberOfDaysInCurrentMonth = MonthDays(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
stDate IncreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}
stDate IncreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    // Note that need to check leap year with 2nd month
    return Date;
}
stDate IncreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year += Years;
    // Note that need to check leap year with 2nd month
    return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
    //Period of 10 years
    Date.Year += 10;
    // Note that need to check leap year with 2nd month
    return Date;
}
stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year += Decade * 10;
    // Note that need to check leap year with 2nd month
    return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{
    //Period of 100 years
    Date.Year += 100;
    // Note that need to check leap year with 2nd month
    return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date)
{
    //Period of 1000 years
    Date.Year += 1000;
    // Note that need to check leap year with 2nd month
    return Date;
}
//

// proplem-16: Decrease Date Problems
stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = MonthDays(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
        Date.Month--;
    //last check day in date should not exceed max days in the current month
    // example if date is 31/3/2022 decreasing one month should not be 31 / 2 / 2022, it should
    // be 28/2/2022
    short NumberOfDaysInCurrentMonth = MonthDays(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
stDate DecreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
stDate DecreaseDateByXMonths(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}
stDate DecreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year -= Years;
    return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
    //Period of 10 years
    Date.Year -= 10;
    return Date;
}
stDate DecreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year -= Decade * 10;
    return Date;
}
stDate DecreaseDateByOneCentury(stDate Date)
{
    //Period of 100 years
    Date.Year -= 100;
    return Date;
}
stDate DecreaseDateByOneMillennium(stDate Date)
{
    //Period of 1000 years
    Date.Year -= 1000;
    return Date;
}
//

// proplem-17: More Date Proplems
enum enWeekEnd
{
    FRI = 5,
    SAT = 6
};
short DayOrderInWeak(stDate Date)
{
    short a, y, m;
    a = (14 - Date.Month) / 12;
    y = Date.Year - a;
    m = Date.Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
bool IsEndOfWeak(stDate Date)
{
    short DayOrder = DayOrderInWeak(Date);

    return DayOrder == 6;
}
bool IsWeekEnd(stDate Date)
{
    short DayOrder = DayOrderInWeak(Date);

    return DayOrder == (short)enWeekEnd::FRI || DayOrder == (short)enWeekEnd::SAT;
}
bool IsBusinessDay(stDate Date)
{
    return !IsWeekEnd(Date);
}
short DaysUntilTheEndOfWeek(stDate Date)
{
    short DayOrder = DayOrderInWeak(Date);

    return 6 - DayOrder;
}
short DaysUntilTheEndOfMonth(stDate Date)
{
    short NumberOfDayInMonth = MonthDays(Date.Month, Date.Year);

    return NumberOfDayInMonth - Date.Day;
}
short DaysUntilTheEndOfYear(stDate Date)
{
    stDate EndOfYear;
    EndOfYear.Day = 31;
    EndOfYear.Month = 12;
    EndOfYear.Year = Date.Year;

    short DifferenceBeetweenDate = GetDifferenceInDays(Date, EndOfYear, true);

    return DifferenceBeetweenDate;
}
//

// problem-18: Calculate Actual Vacation Days (weekends are excluded)
short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}
//

// problem-19: Calculate Actual Vacation Days (weekends are excluded) and get return date 
stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    for (short i = 1; i <= VacationDays; i++)
    {
        if (IsWeekEnd(DateFrom))
        {
            VacationDays++;
        }

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}
void PrintDate(stDate Date)
{
    printf("%d/%d/%d\n", Date.Day, Date.Month, Date.Year);
}
//

// problem-20: Is date1 after date2
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
//

// problem-21: compare dates
enum enDateCompareResult
{
    BEFORE = -1,
    AFTER = 1,
    EQUAL = 0
};
enDateCompareResult CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return BEFORE;
    else if (IsDate1AfterDate2(Date1, Date2))
        return AFTER;
    else
        return EQUAL;
}
//

// problem-22: Overlap period
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    enDateCompareResult CompareStartWithEnd = CompareDates(Period1.StartDate, Period2.EndDate);
    enDateCompareResult CompareEndwithStart = CompareDates(Period1.EndDate, Period2.StartDate);

    return 
        (CompareStartWithEnd == BEFORE || CompareStartWithEnd == EQUAL) &&
        (CompareEndwithStart == AFTER || CompareEndwithStart == EQUAL);
}
//

// problem-23: Period Length
short PeriodLength(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}
//

// problem-24: Is Date in Period
bool IsDateInPeriod(stPeriod Period, stDate Date)
{
    return !(CompareDates(Period.StartDate, Date) == AFTER ||
             CompareDates(Period.EndDate, Date) == BEFORE );
}
//

// problem-25: Number of overlap days
short NumberOfOverlapDays(stPeriod Period1, stPeriod Period2)
{
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    bool Start1InPeriod2 = IsDateInPeriod(Period2, Period1.StartDate);
    bool End1InPeriod2 = IsDateInPeriod(Period2, Period1.EndDate);

    if (Start1InPeriod2 && End1InPeriod2)
        return PeriodLength(Period1, true);
    else if (Start1InPeriod2)
        return GetDifferenceInDays(Period1.StartDate, Period2.EndDate, true);
    else if (End1InPeriod2)
        return GetDifferenceInDays(Period2.StartDate, Period1.EndDate, true);
    else
        return PeriodLength(Period2, true);
}
//

// problem-26: Valid Date
bool IsValidDay(stDate Date)
{
    return (Date.Day <= 31) && (Date.Day > 0) && (Date.Day <= MonthDays(Date.Month, Date.Year));
}
bool IsValidMonth(short Month)
{
    return Month > 0 && Month <= 12;
}
bool IsDateValid(stDate Date)
{
    if (!IsValidMonth(Date.Month))
        return false;
    else if (!IsValidDay(Date))
        return false;
    else
        return Date.Year > 0;
}
//

// proplem-27: Convert String <-> Date
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
stDate ConvertStringToDate(string strDate)
{
    vector<string> vDateComponents = SplitString(strDate, "/");
    stDate Date;

    Date.Day = stoi(vDateComponents[0]);
    Date.Month = stoi(vDateComponents[1]);
    Date.Year = stoi(vDateComponents[2]);

    return Date;
}
string ConvertDateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
//

// problem-28: Print Date with format
string ReplaceStringWords(string str, string WordToReplace, string NewWord)
{
    short Pos = str.find(WordToReplace);
    while (Pos != std::string::npos)
    {
        str.replace(Pos, WordToReplace.length(), NewWord);

        Pos = str.find(WordToReplace);
    }
    return str;
}
string FormateDate(stDate Date, string Format = "dd/mm/yyyy")
{
    string FormatedDate = "";

    FormatedDate = ReplaceStringWords(Format, "dd", to_string(Date.Day));
    FormatedDate = ReplaceStringWords(FormatedDate, "mm", to_string(Date.Month));
    FormatedDate = ReplaceStringWords(FormatedDate, "yyyy", to_string(Date.Year));

    return FormatedDate;
}
//

int main()
{
    stDate Date;
    Date.Day = 25;
    Date.Month = 15;
    Date.Year = 2022;

    cout << "\n" << FormateDate(Date) << "\n";
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
}