public class Solution {
    public int DayOfYear(string date) {
        var sum = 0;
        var d = DateTime.Parse(date);
        switch(d.Month)
        {
            case 12:
                sum += DateTime.DaysInMonth(d.Year, 11);
                goto case 11;
            case 11:
                sum += DateTime.DaysInMonth(d.Year, 10);
                goto case 10;
            case 10:
                sum += DateTime.DaysInMonth(d.Year, 9);
                goto case 9;
            case 9:
                sum += DateTime.DaysInMonth(d.Year, 8);
                goto case 8;
            case 8:
                sum += DateTime.DaysInMonth(d.Year, 7);
                goto case 7;
            case 7:
                sum += DateTime.DaysInMonth(d.Year, 6);
                goto case 6;
            case 6:
                sum += DateTime.DaysInMonth(d.Year, 5);
                goto case 5;
            case 5:
                sum += DateTime.DaysInMonth(d.Year, 4);
                goto case 4;
            case 4:
                sum += DateTime.DaysInMonth(d.Year, 3);
                goto case 3;
            case 3:
                sum += DateTime.DaysInMonth(d.Year, 2);
                goto case 2;
            case 2:
                sum += DateTime.DaysInMonth(d.Year, 1);
                goto case 1;
            case 1:
                break;
        }
        sum += d.Day;
        return sum;
    }
}
