// A factory design pattern is one of the most widely used design pattern.
 
// In this pattern,

//     We have a primary base class. 
//     There are two or more classes derived from the base class. 
//     We have a factory method, which returns the base object created on the heap.
//     This factory method takes one or more parameters, of which the first parameter is used to ascertain the derived class to be instantiated.
//     The other parameters of the factory method is passed to the constructor of the derived class.
//     Inside a factory method, we create and return a derived class object by using a switch-case suite or if-else ladder.




#include <iostream>
#include <memory>

class Beverage
{
public:
    Beverage() = default;
    virtual void prepareDrink() = 0;
    virtual ~Beverage() = default;
};

class Coffee : public Beverage
{
    int beanQuant_;

public:
    Coffee(int beanQuant) : beanQuant_(beanQuant) {};

    void prepareDrink() override
    {
        std::cout << "Crushing " << beanQuant_ << " number of beans.\n";
        std::cout << "Stirring. The drink is now prepared.\n";
    }
};

class Tea : public Beverage
{
    TeaFlavor flav_;  // assume that we have a TeaFlavor class that we have included
    int milkAmnt_;

public:
    Tea(TeaFlavor flav, int milkAmnt) : flav_(flav), milkAmnt_(milkAmnt) {};

    void prepareDrink() override
    {
        std::cout << "Adding the tea bag of " << flav_ << " flavor.\n";
        std::cout << "Adding " << milkAmnt_ << " ml of milk.\n";
        std::cout << "Stirring. The drink is now prepared.\n";
    }
};

enum class TypeOfDrink { Coffee, Tea };

template<typename... Ts>
std::unique_ptr<Beverage> make_drink(TypeOfDrink selection, Ts&&... ts)   // function named according to the std::make_unique. std::make_shared etc convention.
{
    // using switch-case ladder is preferable especially when we have more than two derived classes.
    if (selection == TypeOfDrink::Coffee)
    {
        return std::unique_ptr<Coffee>(new Coffee(std::forward<Ts>(ts)...));
    }

    else
    {
        return std::unique_ptr<Tea>(new Tea(std::forward<Ts>(ts)...));
    }
}