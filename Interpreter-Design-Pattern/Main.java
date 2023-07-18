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

public class Main {
    public static void main(String[] args) {
        String input = "5 + 3 - 2 + 10 - 4";
        Parser parser = new Parser(input);
        Expression expression = parser.parse();
        int result = expression.interpret();
        System.out.println(input + " = " + result);
    }
}

// Expression interface
interface Expression {
    int interpret();
}

// Terminal expression for numbers
class NumberExpression implements Expression {
    private int number;

    public NumberExpression(int number) {
        this.number = number;
    }

    @Override
    public int interpret() {
        return number;
    }
}

// Non-terminal expression for addition
class AddExpression implements Expression {
    private Expression left;
    private Expression right;

    public AddExpression(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int interpret() {
        return left.interpret() + right.interpret();
    }
}

// Non-terminal expression for subtraction
class SubtractExpression implements Expression {
    private Expression left;
    private Expression right;

    public SubtractExpression(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int interpret() {
        return left.interpret() - right.interpret();
    }
}

// Parser
class Parser {
    private String[] tokens;
    private int currentTokenIndex;
    
    public Parser(String input) {
        tokens = input.split("\\s+");
        currentTokenIndex = 0;
    }

    public Expression parse() {
        Expression left = parseTerm();
        while (currentTokenIndex < tokens.length) {
            String operator = tokens[currentTokenIndex++];
            Expression right = parseTerm();

            if (operator.equals("+")) {
                left = new AddExpression(left, right);
            } else if (operator.equals("-")) {
                left = new SubtractExpression(left, right);
            } else {
                throw new IllegalArgumentException("Invalid operator: " + operator);
            }
        }
        return left;
    }

    private Expression parseTerm() {
        String token = tokens[currentTokenIndex++];
        try {
            int value = Integer.parseInt(token);
            return new NumberExpression(value);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid number: " + token);
        }
    }
}
