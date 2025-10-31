
Static Keyword: This keyword tells cpp that we are only gonna use that function in that file, not in other files.

Linking errors:

Error with linker, with a error code of LNK 
One Linking error happens when we have 2 functions in different files with same defination.

Static can also be used for internal mapping. e.g. if we have a log function defined in a .h file, we can use the static keyword so that we are able to import the same .h file at multiple locations.

Or, we can use inline instead, which just takes the body and paste it there.

**Data Structure**

In cpp, we have different data types, e.g. int (4 byte, -2 billion to + 2 billion), and unsigned int (can contain only +ve value 0 to 4 billion)

We have short  char (1 byte), (2 byte), int (4 byte), long (4 byte) {depending on the OS} and long long (8 byte). We can also add unsigned in any of them

float - 4 byte - need to append "f" at the end of the number
double - 8 byte
bool - 1 byte {cannot be 1 bit because we cannot address individual bits} - So, we can store 8 bools in 1 byte

sizeof(int) - tells the size of a particular data type

<> These symbols are not relative to the file, they just have to be in one of the include directories

<h2>Pointers</h2>
A pointer is an integer that stores a memory address. They are extremely useful tool and it is good to use them. Types (int, char, etc) are meaningless for pointers.

However, it is recommended to not use void pointer, because it will give error while dereferencing the pointer. As cpp would not know how many memory address to modify.

```
#include <iostream>

int main(){

    char* buffer = new char[8]; // 8 bytes of memory after the memory address of buffer

    memset(buffer, 0, 8) // At the memory location of buffer - add the value 0, of size 8 bytes

  

    delete[] buffer;

}
```

We can also have pointers to a pointer. Its like pointer themselves have to assign memory and a pointer to a pointer refers to that memory. Its like a never ending cycle. 


<h2>References</h2>
They are basically the same as pointers. The only difference is the syntax and that references do not consume new memory.

```
#include <iostream>

void increment_using_pointer(int* value){ //this uses pointer

    //*value++; // this increment_using_pointers first and then de-reference

    (*value)++; // this de-reference first and then increment_using_pointers

}

void increment_using_reference(int& value){

    value++; // Value do not need to be assigned memory

}

int main(){

    int a = 5; // assign memory

    int& ref = a; // memory is not assigned here, its just a thing pointing to 'a'. No memry is assigned here, its handled by the compiler

    increment_using_pointer(&a);

    std::cout<<a<<'\n';

    increment_using_reference(a);

    std::cout<<a;

}
```


We need to assign the reference, we cannot just keep it declared

```
#include <iostream>

int main(){

    int a = 5; // assign memory
    int b = 7;
    int& ref = a;
    ref = b; // this means a = b
    std::cout<<a; // prints 7

}
```


```
#include <iostream>

int main(){

    int a = 5; // assign memory

    int b = 7;

    int* ref = &a;

    *ref = 2;

    std::cout<<a; // prints 2

}
```


**Classes**

If any variable starts with small "m_", we say that it is a private attribute of that class.

e.g. 
private:
	int m_logLevel;


A simple log file:

```
#include <iostream>

  

class Log{

  

    public:

        const int LogLevelInfo = 0;

        const int LogLevelWarning = 1;

        const int LogLevelError = 2;

    private:

        int m_currentLogLevel = 0;

  

    public:

        void SetLevel(int level){

            m_currentLogLevel = level;

        }

  

        void Info(const char* message){

            if (m_currentLogLevel <= LogLevelInfo)

                std::cout<< " [Info] " << message <<std::endl;

        }

  

        void Warn(const char* message){

            if (m_currentLogLevel <= LogLevelWarning)

                std::cout<< " [Warning] " << message <<std::endl;

        }

  

        void Error(const char* message){

            if (m_currentLogLevel <= LogLevelError)

                std::cout<< " [Error] " << message <<std::endl;

        }

  

};

  

int main(){

    Log log;

    log.SetLevel(log.LogLevelInfo);

    log.Info("Hello");

    log.Warn("Warning");

    log.Error("Error here");

    std::cin.get();

}
```


<h2>Static Keyword</h2>

A static variable defined in a translation unit, means that it is only available in it. And linker is not gonna look at other places.

However, if we use it inside a class, it shares its memory with all of instances of class.
Same with Static method

Outside of a class:

Main.cpp:

```
#include <iostream>

int s_variable = 5; // This var is only linked inside this translation unit

int main(){

    std::cout<< s_variable << std::endl;

    std::cin.get();

}
```

static.cpp:

```
int s_variable = 5;
```

If we link them together, we will get a linker error, stating that we cannot have more than one def of variables, as it has already been defined in a different translation unit.

However, if inside static.cpp, we do this:

static.cpp:

```
static int s_variable = 5;
```


Then the code compiles because we have limited the scope of it to that file. And whenever the linker will look at the static.cpp file, it will ignore the static key.

	Make the variables static unless we really want to use them in other files.




<h1>Constructor and Destructor</h1>

Name of the constructor is the same as the name of the class. We have parameterized constructor and un-parameterized constructors.

Destructors are similar, they are called when the object's scope is destroyed. The destructor's name is the same as the class but with a ~ at the starting.


<h1>Inheritance</h1>

```
#include <iostream>

class Entity

{

public:

    float X, Y;

  

    void move(float xa, float ya){

        X += xa;

        Y += ya;

    }

  

};

class Player : public Entity

{

    const char* Name;

  

    void PrintName(){

        std::cout<< Name << std::endl;

    }

};

  

int main(){

    return 0;

}
```


<h1>Virtual Functions</h1>

This is how we do method overriding in c++. 
If we know that we are going to override a method in the child class, we add a virtual keyword in front of that method in the parent class.

E.g.

```
ParentClass:
	virtual GetName()
	{
	}
	
ChildClass:
	GetName() override
	{
	}
```

This virtual keyword creates a V-table which tells us that this particular method can be overridden. 

Also, the "override" keyword is not required but can be useful.

However, virtual functions can be costing. Because we have to create a V-table which costs memory and we would need to look through the V-table to check for the virtual function, which costs time.

So, if we are on an embedded platform with a very very major performance overhead, don't use virtual functions, otherwise, do use them.

<h1>Pure Virtual Function</h1>
It is same as abstract method in Java. It allows us to define a function in base class which does not have any implementation and then implement it in the child class.

<h1>Arrays</h1>

Arrays are basically pointers. E.g. if we write something like this:

```
		int example[5];
```

This would mean that we are referencing any address in memory which is pointing to the next 8 bytes.

And if we write example[2] then, we are adding an offset of 8 bytes to that offset.

We can also use the new keyword to create an array, however, while using that new keyword, we must delete it as well.
Here's why:

When we create an array with this:

```
	int example[5]
```

It just creates an array in stack, which means that it will get destroyed when we go out of scope.

However, if we use something like this:

```
	int* another = new int[5];
```

We would have stored this in the heap, so, it will not be destroyed out of scope, we would have to use delete keyword in order to destroy it. 

```
	delete[] another;
```


Using the new keyword to create an array is also a very big memory hit. It costs us memory and time.

cool code:

```
int count = sizeof(array) / sizeof(array_type) // array_type may be int, char, etc
```


<h1>Important thing to note about strings</h1>
In Strings, always use const keyword while passing a string in a function. Because if we do not use it, we risk copying the string which may cause performance delays.


<h1>Mutable</h1>
Basically if we have a const method, we cannot modify any of attributes in that method. However, with mutable we can. Here's a sample code:

```
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
```


<h1>Member Initializing list</h1>
This is a way of initializing the variables defined inside of a class.

This is used for 2 main purposes:
	1. Better Syntax
	2. So that the objects do not initialize 2 times {object of another class that is}.


```
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
```

