// virtual_comparison.cpp
// Shows the EXACT same setup with and without 'virtual'
// Compile: g++ -std=c++17 -o virtual_comparison virtual_comparison.cpp

#include <iostream>
using namespace std;

// ============================================================
//  EXAMPLE 1: WITHOUT virtual  (broken polymorphism)
// ============================================================

class AnimalNoVirtual {
public:
    // NO virtual keyword!
    string speak() const {
        return "...";
    }
};

class DogNoVirtual : public AnimalNoVirtual {
public:
    string speak() const {   // hides base version, but NOT polymorphic
        return "Woof!";
    }
};

class CatNoVirtual : public AnimalNoVirtual {
public:
    string speak() const {   // hides base version, but NOT polymorphic
        return "Meow!";
    }
};


// ============================================================
//  EXAMPLE 2: WITH virtual  (correct polymorphism)
// ============================================================

class AnimalVirtual {
public:
    virtual ~AnimalVirtual() {}   // always make destructor virtual too

    // HAS virtual keyword!
    virtual string speak() const {
        return "...";
    }
};

class DogVirtual : public AnimalVirtual {
public:
    string speak() const override {
        return "Woof!";
    }
};

class CatVirtual : public AnimalVirtual {
public:
    string speak() const override {
        return "Meow!";
    }
};


// ============================================================
//  MAIN — see the difference
// ============================================================

int main() {
    // --- WITHOUT virtual ---
    cout << "========== WITHOUT virtual ==========\n\n";

    AnimalNoVirtual* dog1 = new DogNoVirtual();
    AnimalNoVirtual* cat1 = new CatNoVirtual();

    // We WANT "Woof!" and "Meow!", but we get "..." for both!
    cout << "  dog1->speak() = " << dog1->speak() << endl;   // prints "..."  
    cout << "  cat1->speak() = " << cat1->speak() << endl;   // prints "..."  
    cout << endl;
    cout << "  Both say \"...\" because C++ only looks at the\n";
    cout << "  POINTER TYPE (AnimalNoVirtual*), not the actual object.\n";

    delete dog1;
    delete cat1;


    // --- WITH virtual ---
    cout << "\n========== WITH virtual ==========\n\n";

    AnimalVirtual* dog2 = new DogVirtual();
    AnimalVirtual* cat2 = new CatVirtual();

    // NOW we get the correct behavior!
    cout << "  dog2->speak() = " << dog2->speak() << endl;   // prints "Woof!"  
    cout << "  cat2->speak() = " << cat2->speak() << endl;   // prints "Meow!"  
    cout << endl;
    cout << "  Now C++ looks at the ACTUAL OBJECT and calls\n";
    cout << "  the correct derived version.\n";

    delete dog2;
    delete cat2;


    // --- Summary ---
    cout << "\n========== TAKEAWAY ==========\n\n";
    cout << "  Without 'virtual': pointer type decides which function runs.\n";
    cout << "  With    'virtual': actual object decides which function runs.\n";
    cout << "  That's it. That's the whole difference.\n\n";

    return 0;
}
