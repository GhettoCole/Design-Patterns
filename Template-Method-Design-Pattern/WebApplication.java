// Author - Given Lepita
/*

We have a WebApplication base class that defines the template method handleRequest(),
which encapsulates the common steps for handling a request and generating a response.
The processRequest() method is declared as an abstract method, which means it must be implemented by subclasses.

In the CustomWebApplication subclass, we override the processRequest() method to provide the specific implementation
for handling a request in a custom web application. Additional logic specific to this type of web application can be added in that method.

In the main() function, we create an instance of CustomWebApplication and invoke the handleRequest() method.
The template method takes care of executing the common steps defined in the base class, as well as the specific step implemented in the subclass.

This allows for flexibility and customization, as different types of web applications can inherit from the WebApplication base class
and provide their own implementation for the processRequest() method while reusing the common steps defined in the template method.

*/

// Base class defining the template method
abstract class WebApplication {
    public void handleRequest() {
        // Common steps for handling a request
        parseRequest();
        authenticateUser();
        // Specific step for handling the request
        processRequest();
        // Common step for generating response
        generateResponse();
    }

    protected abstract void processRequest(); // Abstract method to be implemented by subclasses

    // Common steps implemented by the base class
    void parseRequest() {
        System.out.println("Parsing request...");
    }

    void authenticateUser() {
        System.out.println("Authenticating user...");
    }

    void generateResponse() {
        System.out.println("Generating response...");
    }
}

// Subclass implementing the specific step for handling a request
class CustomWebApplication extends WebApplication {
    @Override
    protected void processRequest() {
        System.out.println("Performing custom request processing...");
        // Additional logic specific to this type of web application
    }
}

public class TemplateMethod {
    public static void main(String[] args) {
        // Client code using the template method
        WebApplication application = new CustomWebApplication();
        application.handleRequest();
    }
}
