#include<iostream>
#include<string>
using namespace std;
class Duree
{
	private:
		int hour;
		int min;
		int sec;
	public:
		Duree(int hour = 0, int min = 0, int sec = 0);

	public:
		void setHour(int hour);
		int getHour() const;

		void setMin(int min);
		int getMin() const;
		
		void setSec(int sec);
		int getSec() const;
		
                template<class Type> Type sumCal(Type num1, Type num2)
{
	return num1 + num2;
}

	public:
		string displayTime() const;
                bool isCopyDuree(Duree const &duree);
                friend ostream& operator<<(ostream &os, Duree const &duree);
                friend istream& operator>>(istream &is, Duree &duree);
                friend bool operator==(Duree const &duree1, Duree const &duree2);
                friend bool operator!=(Duree const &duree1, Duree const &duree2);
                friend Duree operator+(Duree &duree1, Duree &duree2);
                friend Duree operator-(Duree &duree1, Duree &duree2);
};

