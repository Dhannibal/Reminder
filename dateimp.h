#ifndef DATEIMP_H
#define DATEIMP_H


class Dateimp
{
private:
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Dateimp();
    bool isnap(int year);
    int getmonth(int i) {
        if(i >= 1 && i <= 12) {
            return month[i];
        }
        else return -1;
    }
};

#endif // DATEIMP_H
