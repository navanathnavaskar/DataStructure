struct Date
{
    int d,m,y;
};

const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int getLeapDays(Date date)
{
    int y = date.y;
    
    //if month is less than or equal 2 then dont count curr year.
    if(date.m <= 2)
        y = y-1;
    
    return(y/4 + y/400 - y/100);
}

int dateDiff(Date d1, Date d2)
{
    //calculate number of days for date 1
    int n1 = d1.y * 365 + d1.d;
    //add days for each month
    for(int i = 0;i<d1.m;i++)
    {
        n1 += days[i];
    }
    // now add leap year days
    n1 += getLeapDays(d1);
    
    //get for d2
    int n2 = d2.y * 365 + d2.d;
    //add days for each month
    for(int i = 0;i<d2.m;i++)
    {
        n2 += days[i];
    }
    // now add leap year days
    n2 += getLeapDays(d2);
    //return differnce
    if(n1>n2)
        return n1-n2;
    else
        return n2-n1;
}

int main()
{
    Date d1 = {31,3,2019};
    Date d2 = {13,5,2021};
    cout<<"\nDifference is : "<<dateDiff(d1,d2);
    return 0;
}