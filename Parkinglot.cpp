#include<iostream>
#include<vector>
using namespace std;

class Vehicle{
protected:
    string number;

    public:
    Vehicle(string number)
    {
        this->number = number;
    }

    string getNumber()
    {
        return number;
    }

    virtual string getType()=0; //abstraction
    virtual ~Vehicle()=default; // virtual destructor for cleanup



};

class Car: public Vehicle
{
    public:
    Car(string number) : Vehicle(number){}
    string getType() override{
        return "CAR";
    }
};

class Bike: public Vehicle
{
    public:
    Bike(string number) : Vehicle(number){}
    string getType() override{
        return "BIKE";
    }
};

class ParkingSpot{
private:
    int id;
    Vehicle* vehicle;
public:
    ParkingSpot(int id)
    {
        this->id=id;
        this->vehicle=NULL;
    }

    bool isOccupied()
    {
        if(vehicle!=NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void park(Vehicle* vehicle)
    {
        this->vehicle=vehicle;
    }

    void removeVehicle(){
        this->vehicle=NULL;

    }
    

};

class ParkingLot{
private:
    vector<ParkingSpot> spots;
public:
    ParkingLot(int numberOfSpots)
    {
        for(int i=0;i<numberOfSpots;i++)
        {
            spots.emplace_back(i);
        }
    }

    void parkVehicle(Vehicle* vehicle)
    {
        for(auto&spot: spots)
        {
            if(!spot.isOccupied())
            {
                spot.park(vehicle);
                cout<<"Vehicle parked \n";
                return;
            }
        }

        cout<<"Parking Lot is Full \n";

    }

};


int main()
{
    // Vehicle* car=new Car("KA-01-HH-2876");
    // Vehicle* bike=new Bike("KA-01-HH-1234");

    Car car("HP-151-7177");
    Bike bike("HR-07-0739");

    ParkingLot lot(2);

    lot.parkVehicle(&car);
    lot.parkVehicle(&bike);

}