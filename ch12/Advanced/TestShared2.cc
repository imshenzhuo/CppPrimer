#include <iostream>
#include <memory>
#include <chrono>
#include <string>
using chrono_clock = std::chrono::high_resolution_clock;

void compareSizes()
{
    std::shared_ptr<int> sPtr = std::make_shared<int>(23);
    std::unique_ptr<int> uPtr = std::make_unique<int>(23);

    std::cout << "Shared ptr content = " << *sPtr << ". Size = " << sizeof(sPtr) << '\n';
    std::cout << "Unique ptr content = " << *uPtr << ". Size = " << sizeof(uPtr) << '\n';

    // Setting - MSVC 14.12 , x64 platform
    // Results
    // Shared ptr content = 23. Size = 16
    // Unique ptr content = 23. Size = 8

    // Setting - MSVC 14.12 , x86 platform
    // Results
    // Shared ptr content = 23. Size = 8
    // Unique ptr content = 23. Size = 4

}

const int noOfPointers = 10000;

void displayStat(std::string message, std::chrono::steady_clock::time_point start , std::chrono::steady_clock::time_point finish)
{
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << message << " : " << elapsed.count() << '\n';
}

void comparePerformanceConvenienceFunc()
{
    std::cout << "\nUsing convenience functions" << '\n';
    std::cout << "Time for creation and destruction of " << noOfPointers << " of each type\n";

    auto start = chrono_clock::now();
    for (int i = 0; i < noOfPointers; ++i)
    {
        std::unique_ptr<int> uPtrVec2 = std::make_unique<int>(i);
    }
    
    auto finish = chrono_clock::now();
    displayStat("Unique Ptr", start, finish);

    start = chrono_clock::now();
    for (int i = 0; i < noOfPointers; ++i)
    {
        std::shared_ptr<int> sPtrVec = std::make_shared<int>(i);
    } 
    finish = chrono_clock::now();
    displayStat("Shared Ptr", start, finish);
}

void comparePerformanceUsingNew()
{
    std::cout << "\nWithout using convenience functions" << '\n';
    std::cout << "Time for creation and destruction of " << noOfPointers << " of each type\n";

    auto start = chrono_clock::now();
    for (int i = 0; i < noOfPointers; ++i)
    {
        std::unique_ptr<int> uPtrVec (new int(i));
    }
    auto finish = chrono_clock::now();
    displayStat("Unique Ptr", start, finish);

    start = chrono_clock::now();
    for (int i = 0; i < noOfPointers; ++i)
    {
        std::shared_ptr<int> sPtrVec(new int(i));
    }
    finish = chrono_clock::now();
    displayStat("Shared Ptr", start, finish);
}


int main()
{
    compareSizes();
    comparePerformanceUsingNew();
    comparePerformanceConvenienceFunc();

    // Setting - MSVC 14.12 , x64 platform
    // Output 
    /*
    Without using convenience functions
    Time for creation and destruction of 10000 of each type
    Unique Ptr : 0.00486729
    Shared Ptr : 0.00962007
    Using convenience functions
    Time for creation and destruction of 10000 of each type
    Unique Ptr : 0.00569801
    Shared Ptr : 0.00827406
    */
    
    // Obervations
    // Unique ptr creation and destruction is almost 100% faster than shared ptr
    // Using std::make_shared is considerably faster than using new when creating shared_ptr 
    // make_unique is very slightly slower compared to using new.  
}