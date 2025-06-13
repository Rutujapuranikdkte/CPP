//Implementing polymorphism and inheritance
#include<iostream>
using namespace std;

class Vehicle
{
	private:
		string vehicleID;
		string maker;
		string model;
		int year;
		bool isrented;//vehicle is on rent or not
		double dailyrentalrate;
		
		protected:
		    double getdailyrentalrate()
		    {
		        return dailyrentalrate;
		    }
		public:
			Vehicle(string id,string make,string mdl,int yr,bool rnt,double rate)
			{
				vehicleID=id;
				maker=make;
				model=mdl;
				year=yr;
				isrented=rnt;
				dailyrentalrate=rate;
			}
			 void rent() 
			 {
        		if (!isrented) 
        		{
				
            		isrented = true;
            		cout << "Vehicle rented successfully.\n";
        		} 		
				else 
					{
            		cout << "Vehicle is already rented.\n";
        			}
    		}
    		void returnVehicle()
		{
			if (isrented) 
			{
				isrented = false;
				cout << "Vehicle returned successfully.\n";
			} 
			else 
			{
				cout << "Vehicle is not currently rented.\n";
			}
		}
		virtual void calculateDailyRentalCost(int days)
		{
			double total = dailyrentalrate * days;
			cout << "Total rental cost for " << days << " days is: " << total << "\n";
		}
		virtual	void display()
			{
				cout<<"\nvehicle id is: "<<vehicleID<<"\nThe maker of the vehicle is: "<<maker<<"\nYears for vehicle: "
				<<year<<"\nThe vehicle is rented or not: "<<(isrented ? "Yes" : "No")<<"\nThe rate for vehicle: "<<dailyrentalrate;
			}
		
};
class Car:public Vehicle
{
	private:
		int numberofdoors;
		string fueltype;
	public:
		Car(string id, string make, string mdl, int yr, bool rnt, double rate,
        int d, string f): Vehicle(id, make, mdl, yr, rnt, rate)
		{
			numberofdoors=d;
			fueltype=f;
		}
	void display() override
	{
		Vehicle::display();
		cout<<"\nThe number of doors are: "<<numberofdoors<<"\nThe fuel type is: "<<fueltype;	
	}	
};
class Motorcycle:public Vehicle
{
	private:
		string enginetype;
		bool hassidecar;
	public:
		Motorcycle(string id, string make, string mdl, int yr, bool rnt, double rate,string e,bool s):
			Vehicle(id, make, mdl, yr, rnt, rate)
			{
				enginetype=e;
				hassidecar=s;
			}
			void display() override
			{
				Vehicle::display();
				cout<<"\nEngine type of motorcycle is: "<<enginetype<<"\nThe sidecar: "<<(hassidecar?"yes":"no")<<"\n";
			}
};
class Truck:public Vehicle
{
	private:
		double cargocapacity;
		int numberofaxles;
	public:
		Truck(string id, string make, string mdl, int yr, bool rnt, double rate,double c,int n):
			Vehicle(id, make, mdl, yr, rnt, rate)
			{
				cargocapacity=c;
				numberofaxles=n;				
			}
			void calculaterentalcost(int days)
{
    double total = getdailyrentalrate() * days + (cargocapacity * 10 * days);
    cout << "\nTotal truck rental cost for " << days << " days is: " << total << "\n";
}


			void display() override
			{
				Vehicle::display();
				cout<<"\nThe capacity of truck: "<<cargocapacity<<"\nThe no. of axles is: "<<numberofaxles;
			}
};
int main()
{
	Vehicle v("v1234","toyato","bear",2022,false,1500.00);
	v.rent();
	v.returnVehicle();
	v.calculateDailyRentalCost(5);
	v.display();
	cout<<"\nCar function:";
	Car c("c5678", "Honda", "Civic", 2023, false, 2000.00, 4, "CNG");
	c.display();
	cout<<"\nMotorcycle function:";
	Motorcycle m("m9999", "Yamaha", "YZF-R3", 2021, false, 1200.00, "Inline-4", true);
	m.display();
	cout<<"\nTruck function:";
	Truck t("t0211","ford","Ford F-150",2026,true,15000.00,123.00,5);
	t.calculaterentalcost(6);
	t.display();
	return 0;
}

