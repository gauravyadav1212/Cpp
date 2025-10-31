#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;
public:
    const std::string& GetName() const{ // 1st const: Do not change stuff in here. 
        // 2nd const: The function does not modify function's state
        m_DebugCount++;
        return m_Name;
    }
};

int main(){
    const Entity e;
    e.GetName();
}