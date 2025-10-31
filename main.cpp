#include <iostream>

int s_variable = 5; // This var is only linked inside this translation unit

int main(){
    std::cout<< s_variable << std::endl;
    std::cin.get();
}