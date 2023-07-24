#include <iostream>
#include <fstream>

class LoggingService {
private:
    static LoggingService* instance;
    std::ofstream logFile;

    // Private constructor to prevent direct instantiation from outside the class.
    LoggingService() {
        logFile.open("application.log", std::ofstream::app);
    }

public:
    // Static method to get the instance of LoggingService.
    static LoggingService* getInstance() {
        if (instance == nullptr) {
            // If the instance is not created yet, create a new one.
            instance = new LoggingService();
        }
        return instance;
    }

    // Method to log a message to the file.
    void logMessage(const std::string& message) {
        logFile << message << std::endl;
        logFile.flush();
    }

    // Method to close the log file before the application exits.
    void closeLogFile() {
        logFile.close();
    }
};

LoggingService* LoggingService::instance = nullptr;

int main() {
    // Using the LoggingService singleton in the application.
    LoggingService* logger = LoggingService::getInstance();

    // Logging some example messages.
    logger->logMessage("Application started.");
    logger->logMessage("User logged in.");
    logger->logMessage("Data processing started.");

    // Close the log file when the application is about to exit.
    logger->closeLogFile();

    return 0;
}
