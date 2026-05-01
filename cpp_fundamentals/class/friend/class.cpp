#include <iostream>

using namespace std;

class Engine {
    private:
        int horsepower = 500;
    
        friend class Car; // Car can access Engine's private members
    public:
        string manufacturer;
    };
    
class Car {
public:
    void showHP(Engine e) {
        cout << e.horsepower << endl; // ✅ Allowed due to friendship
    }

};

class Airplane : public Engine{
    friend void getDetails(Airplane &air);
    private:
        string owner = "NULL";
    public:
        int length = 10;


};
void getDetails(Airplane &air){
    cout << "the owner is: ";
    cout << air.owner << endl;
}
int main() {
    // here car is a friend class of engine. and this means that any private and procted members will always be accessed by car.

    Engine e;
    Car c;
    c.showHP(e); // Output: 500

    Airplane a;
    getDetails(a); // access the private of airplane. 
    // by default airplane class cannot, inherit member of engine.



}