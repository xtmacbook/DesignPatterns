#include "Factory.h"

#include <iostream>
/**
 * Concrete Products provide various implementations of the Product interface.
 */

std::string ConcreteProduct1::Operation() const  
{
    return "{Result of the ConcreteProduct1}";
}

std::string ConcreteProduct2::Operation() const  
{
    return "{Result of the ConcreteProduct2}";
}

std::string Creator::SomeOperation() const {
    // Call the factory method to create a Product object.
    Product* product = this->FactoryMethod();
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
}

Product* ConcreteCreator1::FactoryMethod() const  {
    return new ConcreteProduct1();
}

Product* ConcreteCreator2::FactoryMethod() const  {
    return new ConcreteProduct2();
}
/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator& creator) {
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeOperation() << std::endl;
    // ...
}


