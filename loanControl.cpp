#include "LoanControl.h"
#include <iostream>

using namespace std;


bool loancontrol::check(Users x, Equipments y)
{
    if (x.getStatus() && y.getStatus())
    {
        return true;
    }
    else
    {
        return false;
    }
}
