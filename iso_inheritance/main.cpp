#include <iostream>
#include <memory>

class Vehicle{
public:
    virtual void run() = 0;
};

class Car : public Vehicle{
public:
    void run() override{
        std::cout<<"Running on the road"<<std::endl;
    }
};

class Boat : public Vehicle{
public:
    void run() override{
        std::cout<<"Running on water"<<std::endl;
    }
};

class Plane : public Vehicle{
public:
    void run() override{
        std::cout<<"Running in the air"<<std::endl;
    }
};

void run(Vehicle* v){
    v->run();
}

int main(){
    Plane a;
    run(&a);

    return 0;
}