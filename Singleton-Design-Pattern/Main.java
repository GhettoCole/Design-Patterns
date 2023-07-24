import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

// Author - Given Lepita
/*
 * Imagine you are working on a complex software application, and you need to implement a logging service to track important events, errors, and other information.
 * You want to ensure that there is only one instance of the logging service throughout the application to avoid unnecessary resource consumption
 * and potential conflicts caused by multiple instances logging simultaneously.
 * In this case, you would use the Singleton design pattern to guarantee that there is only one instance of the logging service across the entire application.
 
 * The Singleton design pattern is one of the creational design patterns, which ensures that a class has only one instance
 * and provides a global point of access to that instance. The main idea behind the Singleton pattern is to control the instantiation
 * of a class so that there is only one unique instance throughout the application's lifetime.

                            ********* Key characteristics of the Singleton pattern *********

 * Private Constructor -> The Singleton class has a private constructor to prevent direct instantiation from outside the class.
 * This means that the class cannot be instantiated using the new keyword by other parts of the application.
 * Static Instance -> The Singleton class maintains a static member variable that holds the single instance of the class.
 * This static instance is usually created and initialized when the class is first accessed.
 * Global Access -> The Singleton provides a static method (often named getInstance()) that allows other classes to access the single instance.
 * This method is responsible for creating the instance if it doesn't exist or returning the existing instance.

                            ********* Use cases for the Singleton design pattern *********
 * Resource Management -> When there is a need for managing a shared resource, like a database connection, thread pool,
 * or configuration settings, the Singleton pattern ensures that only one instance of the resource is created and shared across the application.
 * Logger Classes -> Singleton can be used for logging in a way that multiple parts of the application can write logs to the same file or output stream without creating multiple loggers.
 * Caching -> Singletons can be used to manage caching mechanisms to store and retrieve frequently used data efficiently.
 * GUI Components -> In graphical user interface (GUI) applications, Singleton can be used to manage a unique user interface component, like a dialog box or main window.
*/

class LoggingService {
    private static LoggingService instance;
    private PrintWriter logFile;

    // Private constructor to prevent direct instantiation from outside the class.
    private LoggingService() {
        try {
            // Open the log file for writing.
            logFile = new PrintWriter(new FileWriter("application.log", true));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Static method to get the instance of LoggingService.
    public static LoggingService getInstance() {
        if (instance == null) {
            // If the instance is not created yet, create a new one.
            instance = new LoggingService();
        }
        return instance;
    }

    // Method to log a message to the file.
    public void logMessage(String message) {
        logFile.println(message);
        logFile.flush();
    }

    // Method to close the log file before the application exits.
    public void closeLogFile() {
        logFile.close();
    }
}

public class Main {
    public static void main(String[] args) {
        // Using the LoggingService singleton in the application.
        LoggingService logger = LoggingService.getInstance();

        // Logging some example messages.
        logger.logMessage("Application started.");
        logger.logMessage("User logged in.");
        logger.logMessage("Data processing started.");

        // Close the log file when the application is about to exit.
        logger.closeLogFile();
    }
}
