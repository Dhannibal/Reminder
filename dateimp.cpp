#include "dateimp.h"

Dateimp::Dateimp()
{

}

bool Dateimp::isnap(int year) {
    return(((year%4 == 0)&&(year%100!=0)) || (year%400 == 0));
}
