#include <iostream>

// Author - Given Lepita
/*

we have a WebApplication base class that defines the template method handleRequest(),
which encapsulates the common steps for handling a request and generating a response.
The processRequest() method is declared as a pure virtual method, which means it must be implemented by subclasses.

In the CustomWebApplication subclass, we override the processRequest() method to provide the specific implementation
for handling a request in a custom web application. Additional logic specific to this type of web application can be added in that method.

In the main() function, we create an instance of CustomWebApplication and invoke the handleRequest() method.
The template method takes care of executing the common steps defined in the base class, as well as the specific step implemented in the subclass.

This allows for flexibility and customization, as different types of web applications can inherit from the WebApplication base class
and provide their own implementation for the processRequest() method while reusing the common steps defined in the template method.

*/


// Base class defining the template method
class WebApplication {
public:
    void handleRequest() {
        // Common steps for handling a request
        parseRequest();
        authenticateUser();
        // Specific step for handling the request
        processRequest();
        // Common step for generating response
        generateResponse();
    }

    virtual void processRequest() = 0; // Abstract method to be implemented by subclasses

    // Common steps implemented by the base class
    void parseRequest() {
        std::cout << "Parsing request...\n";
    }

    void authenticateUser() {
        std::cout << "Authenticating user...\n";
    }

    void generateResponse() {
        std::cout << "Generating response...\n";
    }
};

// Subclass implementing the specific step for handling a request
class CustomWebApplication : public WebApplication {
public:
    void processRequest() override {
        std::cout << "Performing custom request processing...\n";
        // Additional logic specific to this type of web application
    }
};

int main() {
    // Client code using the template method
    WebApplication* application = new CustomWebApplication();
    application->handleRequest();

    delete application;
    return 0;
}
