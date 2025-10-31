#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    int m_Score;
public:
    Entity() : m_Name("Unknown"), m_Score(0) // Same order as declaration
    {}
    const std::string& getName() const { return m_Name; }

};