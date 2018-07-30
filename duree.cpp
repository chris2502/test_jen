#include "duree.h"

Duree::Duree(int hour, int min, int sec)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

void Duree::setHour(int hour)
{
	this->hour = hour;
}
int Duree::getHour() const
{
	return hour;
}

void Duree::setMin(int min)
{
	this->min = min;
}
int Duree::getMin() const
{
	return min;
}
		
void Duree::setSec(int sec)
{
	this->sec = sec;
}
int Duree::getSec() const
{
	return sec;
}

string Duree::displayTime() const
{
	return  to_string(hour) + "h:" + to_string(min) + "min:" + to_string(sec) + "\n";
}

bool Duree::isCopyDuree(Duree const &duree)
{
  //  return *this == duree;
    return true;
}

ostream& operator<<(ostream &os, Duree const &duree)
{
        os << to_string(duree.hour) + "h:" + to_string(duree.min) + "min:" + to_string(duree.sec) + "\n";;
        return os;
}
istream& operator>>(istream &is, Duree &duree)
{
        is >> duree.hour;
        is >> duree.min;
        is >> duree.sec;

        return is;
}

bool operator==(Duree const &duree1, Duree const &duree2)
{
        if(duree1.hour==duree2.hour &&
                duree1.min==duree2.min &&
                duree1.sec==duree2.sec
		 )
		return true;
	
	return false;
}
bool operator!=(const Duree &duree1, const Duree &duree2)
{
    return !(duree1 == duree2);
}

Duree operator+(Duree &duree1, Duree &duree2)
{
    int resultSec = duree1.sec + duree2.sec;
    int extraMin = 0;

    if(resultSec >= 60)
    {
        extraMin = resultSec / 60;
        resultSec = resultSec % 60;
    }

    int resultMin = duree1.min + duree2.min + extraMin;
    int extraHour = 0;
    if(resultMin >= 60)
    {
        extraHour = resultMin /60;
        resultMin = resultMin % 60;
    }
    int resultHour = duree1.getHour() + duree2.getHour() + extraHour;

    return Duree(resultHour, resultMin, resultSec);
}

Duree operator-(Duree &duree1, Duree &duree2)
{
    int resultSec = duree1.sec - duree2.sec;
    int extraMin = 0;

    if(resultSec < 0)
    {
        extraMin = 1;
        resultSec = 60 + resultSec;
    }

    int resultMin = duree1.min - duree2.min - extraMin;
    int extraHour = 0;
    if(resultMin < 0)
    {
        extraHour = 1;
        resultMin = 60 + resultMin;
    }
    int resultHour = duree1.getHour() - duree2.getHour() - extraHour;

    return Duree(resultHour, resultMin, resultSec);
}
