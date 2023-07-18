#include <iostream>
#include <sstream>
#include <vector>

// Author - Given Lepita
/*
 * Suppose you are developing a simple language interpreter for a new programming language.
 * This language has a small set of commands that perform specific operations.
 * To implement this interpreter efficiently and keep the code flexible, you decide to use the Interpreter Design Pattern.
 * The Interpreter pattern allows you to interpret and execute the language's commands and expressions by defining a grammar and representing them as classes.
 * we'll create an interpreter for a simple language that performs arithmetic operations on two numbers: addition and subtraction.
 * The language has the following syntax:

        Addition: <number> + <number>
        Subtraction: <number> - <number>
 */


class Expression {
public:
    virtual int interpret() = 0;
};

class NumberExpression : public Expression {
private:
    int number;

public:
    NumberExpression(int number) : number(number) {}

    int interpret() override {
        return number;
    }
};

class AddExpression : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    AddExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() override {
        return left->interpret() + right->interpret();
    }
};

class SubtractExpression : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    SubtractExpression(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() override {
        return left->interpret() - right->interpret();
    }
};

class Parser {
private:
    std::vector<std::string> tokens;
    int currentTokenIndex;

public:
    Parser(const std::string& input) {
        std::istringstream iss(input);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        currentTokenIndex = 0;
    }

    Expression* parse() {
        Expression* left = parseTerm();
        while (currentTokenIndex < tokens.size()) {
            std::string& op = tokens[currentTokenIndex++];
            Expression* right = parseTerm();

            if (op == "+") {
                left = new AddExpression(left, right);
            } else if (op == "-") {
                left = new SubtractExpression(left, right);
            } else {
                throw std::invalid_argument("Invalid operator: " + op);
            }
        }
        return left;
    }

private:
    Expression* parseTerm() {
        std::string& token = tokens[currentTokenIndex++];
        try {
            int value = std::stoi(token);
            return new NumberExpression(value);
        } catch (const std::invalid_argument&) {
            throw std::invalid_argument("Invalid number: " + token);
        }
    }
};

int main() {
    std::string input = "5 + 3 - 2 + 10 - 4";
    Parser parser(input);
    Expression* expression = parser.parse();
    int result = expression->interpret();
    std::cout << input << " = " << result << std::endl;

    // Cleanup: Delete the dynamically allocated expressions
    delete expression;
    return 0;
}
