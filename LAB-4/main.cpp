#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Package{
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};

struct Courier{
    string courierName;
    string vehicleType;
};

Package* Stack = nullptr;
Courier courierQueue[5];
int front = 0, rear = -1, courierCount = 0;


void arrival(string id, string city, int length, int width, int height){
    Package* newPackage = new Package;
    newPackage->packageID = id;
    newPackage->destinationCity = city;
    newPackage->dimensions[0] = length;
    newPackage->dimensions[1] = width;
    newPackage->dimensions[2] = height;
    newPackage->next = Stack;
    Stack = newPackage;
}

void courierRegister(string name, string vehicle){
    rear = (rear+1)%5;
    courierQueue[rear].courierName = name;
    courierQueue[rear].vehicleType = vehicle;
    courierCount++;
}

void dispatch(){
    Package* temp = Stack;
    Stack = Stack->next;
    delete temp;

    front = (front+1)%5;
    courierCount--;
}

void display(){
    cout << "STATUS" << endl;
    cout << "Stock: ";
    Package* current = Stack;
    while (current != nullptr){
        cout << current->packageID << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Couriers waiting: ";
    for (int i=0; i<courierCount; i++){
        int index = (front+i)%5;
        cout << courierQueue[index].courierName << " ";
    }
    cout << endl;
}

int main(){
    arrival("P1", "city1", 10, 15, 20);
    arrival("P2", "city2", 20, 25, 50);
    arrival("P3", "city3", 35, 15, 40);
    courierRegister("C1", "truck");
    courierRegister("C2", "car");

    display();
    cout << "dispatching..." << endl;
    dispatch();
    display();

    return 0;
}
