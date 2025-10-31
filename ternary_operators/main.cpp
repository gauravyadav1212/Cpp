#include <iostream>

static int s_Level = 1;
static int s_Speed = 1;


int main(){
    
    s_Speed = s_Level > 5 ? 10 : 5;
}