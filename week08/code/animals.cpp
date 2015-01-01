#include <iostream>
#include <string>

using namespace std;

class Animal
{
    public:
        Animal(string name) {
            this->name = name;
        }

        virtual void make_sound() {
            cout << "No sound :(" << endl;
        }

    private:
        string name;
};

class Dog : public Animal
{
    public:
        Dog(string name, string breed) : Animal(name){
            this->breed = breed;
        }

        void make_sound() {
            cout << "Woof!" << endl;
        }

    private:
        string breed;
};

class Cat : public Animal
{
    public:
        Cat(string name, int cuteness_factor) : Animal(name){
            this->cuteness_factor = cuteness_factor;
        }

        void make_sound() {
            cout << "Meooow!" << endl;
        }

    private:
        int cuteness_factor;
};

int main()
{
    Animal a("Amoeba");
    a.make_sound();

    Dog d("Snati", "Rex");
    d.make_sound();

    Cat c("Kisi", 1337);
    c.make_sound();

    a = c;
    a.make_sound();

    cout << "Pointers" << endl;

    Animal *ap = new Animal("Amoeba");
    ap->make_sound();

    Dog *dp = new Dog("Snati", "Rex");
    dp->make_sound();

    Cat *cp = new Cat("Kisi", 1337);
    cp->make_sound();

    ap = cp;
    ap->make_sound();
    return 0;
}
