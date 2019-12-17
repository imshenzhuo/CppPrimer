/**
 *  The deleter lambda function can increase the size of std::unique_ptr depending on the number of variables captured and used.  
 * 
 *  
 * 
 * 
 * 
 */


#include <iostream>
#include <memory>
#include <string>

int main()
{
    {
        std::unique_ptr<int> someInt(new int(10));

        int xInt = 19;
        int *rawPtr = &xInt;
        double mDoub = 9.8;
        std::string sStr = "random chars - VJKLVJk AJSDKFJAKSFJ";

        std::cout << "For reference" << '\n';
        std::cout << "======================" << '\n';
        std::cout << "sizeof(int)" << sizeof(int) << '\n';
        std::cout << "sizeof(double)" << sizeof(double) << '\n';
        std::cout << "sizeof(float)" << sizeof(float) << '\n';
        std::cout << "sizeof(sStr)" << sizeof(sStr) << '\n';
        std::cout << "======================" << "\n\n";


        std::unique_ptr<int> uPtrInt = std::make_unique<int>(20);
        auto deleterFunc1 = [](int* xp)
        {
            std::cout << "Empty capture";
            delete xp;
        };

        auto deleterFunc2 = [&](int* xp)
        {

            // By printing the variables, we are simply using the captured variables
            // Try commenting  out the different cout statements and notice the change in the corresponding output

            std::cout << xInt << '\n';   
            std::cout << mDoub << '\n';
            std::cout << sStr << '\n';
            std::cout << "Reference capture\n";
            delete xp;
        };

        auto deleterFunc3 = [=](int* xp)
        {
            // By printing the variables, we are simply using the captured variables
            // Try commenting  out the different cout statements and notice the change in the corresponding output
            std::cout << xInt << '\n';
            std::cout << mDoub << '\n';
            std::cout << sStr << '\n';
            std::cout << "Value capture\n";
            delete xp;
        };
    
        std::unique_ptr<int, decltype(deleterFunc1)> uPtrInt1(nullptr, deleterFunc1);
        uPtrInt1.reset(new int{ 21 });

        std::unique_ptr<int, decltype(deleterFunc2)> uPtrInt2(nullptr, deleterFunc2);
        uPtrInt2.reset(new int{ 22 });

        std::unique_ptr<int, decltype(deleterFunc3)> uPtrInt3(nullptr, deleterFunc3);
        uPtrInt3.reset(new int{ 23 });
        
        std::cout << "Raw pointer : " << *rawPtr << " .Size = " << sizeof(rawPtr) << '\n';
        std::cout << "unique_ptr ( no custom deleter ) : " << *uPtrInt << " .Size = " << sizeof(uPtrInt) << '\n';
        std::cout << "unique_ptr ( custom deleter. No capture ) : " << *uPtrInt1 << " .Size = " << sizeof(uPtrInt1) << '\n';
        std::cout << "unique_ptr ( custom deleter. Capture by reference ) : " << *uPtrInt2 << " .Size = " << sizeof(uPtrInt2) << '\n';
        std::cout << "unique_ptr ( custom deleter. Capture by value ) : " << *uPtrInt3 << " .Size = " << sizeof(uPtrInt3) << "\n\n";
    }
  
    char ch;
    std::cin >> ch;

}