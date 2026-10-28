#include<iostream>
using namespace std;

class Animal{
    public:
        string color;                                           
        int age;
        Animal(string c="not mentioned", int a=-1){
            color = c;
            age = a;
            
        }
        void virtual sleep(){
            cout << "Animal Sleeps!" << endl;
        }
};

class Dog : public Animal{
    private:
        string breed;
    public:
        Dog(string c="not mentioned", int a=-1, string b="not mentioned") : Animal(c,a),breed(b){
        }
        void sleep(){
            cout << "Dog Sleeps!" << endl;
        }

};

int main(){
    Dog d("brown", 5, "Labrador");
    d.sleep();
    cout<< d.age<<endl;
    cout<< d.color<<endl;
    
}

// runtime polymorphism is achieved through the use of virtual functions in C++. In this example, the `sleep` function in the `Animal` class is declared as a virtual function. This allows the derived class `Dog` to override the `sleep` function. When we call `d.sleep()`, it invokes the overridden method in the `Dog` class, demonstrating runtime polymorphism.