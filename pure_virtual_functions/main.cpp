#include <iostream>

class Entity
{
public:
    virtual std::string GetName() = 0; // Pure virtual function
};

class Player : public Entity
{
private:
    std::string m_Name;

public:
    Player(const std::string& name) : m_Name(name){

    }

    std::string GetName() {return m_Name; }
};

int main(){

    Player* p = new Player("Player");
    std::cout<< p->GetName()<<std::endl;

    Entity* entiry = p;
    std::cout<< entiry->GetName()<<std::endl;

    return 0;
}