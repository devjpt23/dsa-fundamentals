#include <iostream>
using namespace std;

class Box {
    private:
        int width;
    
    public:
        Box(int w) : width(w) {}
    
        // Declaration inside the class — grants access
        friend void printWidth(Box b);
    };
    
    // Defined OUTSIDE the class — NOT a member function
    void printWidth(Box b) {
        cout << b.width << endl; //  Can access private 'width'
    }
    
    int main() {
        Box b(10);
        printWidth(b); // Output: 10
        // even though width is a private member we were able to access it via the friend function
        //in short, when we declare a friend function in class, we can create a function that can directly access the private and protected members of the class, as if the function is declared in the class.
        
    }