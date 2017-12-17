#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct Date
{
    int d, m, y;
};


const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31};

Date parse_date(const string &s) 
{ 
   Date d; 
   d.d = atoi(s.substr(0, 2).c_str()); 
   d.m = atoi(s.substr(3, 2).c_str()); 
   d.y = atoi(s.substr(6, 4).c_str()); 
   return d; 
} 

int count_leap_years(Date d)
{
    int years = d.y;

    if (d.m <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}


int get_diff(Date dt1, Date dt2)
{
    long int n1 = dt1.y*365 + dt1.d;

    for (int i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];

    n1 += count_leap_years(dt1);


    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += count_leap_years(dt2);


    return (n2 - n1);
}

int main()
{
    string inp_date1;
    string inp_date2;
    
    cin>>inp_date1;
    cin>>inp_date2;

    Date date_1 = parse_date(inp_date1);
    Date date_2 = parse_date(inp_date2);

    Date dt1 = {date_1.d,date_1.m,date_1.y};
    Date dt2 = {date_2.d,date_2.m,date_2.y};
    
    cout<<get_diff(dt1,dt2);



    return 0;
}