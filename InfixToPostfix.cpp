#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string expr) {                     // function to return true or false if the expression's parentheses are balanced
    stack<char> s;                               // makes a stack of chars to see if the parentheses are balanced
    for (char c : expr) {                        // goes through all the characters in the expression
        if (c == '(' || c == '[' || c == '{') {  // if the current character is an open parenthesis then push it onto the stack
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {  // if the current character is a close parenthesis then continue
            if (s.empty()) {  // tests if the stack is empty and if it is, the parentheses are not balanced and the function returns false
                return false;
            } else if ((c == ')' && s.top() == '(') || (c == '}' && s.top() == '{') ||
                       (c == ']' &&
                        s.top() ==
                            '[')) {  // if the current character is the same as the top of the stack, then pop the value from the stack
                s.pop();
            } else {
                return false;  // if the current char is a close parenthesis, and the top of the stack is not the corresponding open one,
                               // return false
            }
        }
    }
    return s.empty();  // returns whether the stack is empty or not and if it is empty, the equation is balanced, otherwise not
}

int weight(char c) {  // This function sets values to each of the operands to determine their presidende in order of operations
    if (c == '*' || c == '/' || c == '%') {  // * / and % all have the same level of precedence and are above + and -
        return 2;
    } else if (c == '+' || c == '-') {  // + and - have the second level of precedence
        return 1;
    } else {  // if an operand is not passed through, it gets no weight
        return 0;
    }
}

string convert(string expr) {   // this function converts an infix expression to postfix
    stack<char> s;              // initalizes a stack of characters
    string postfixString = "";  // initalizes a string of the new postfix expression
    for (char c : expr) {       // loops through all the characters in the expression
        if (isdigit(c)) {       // checks if the character is a digit, if so add it to the stack
            postfixString += c;
        } else if (c == '(') {  // else if the character is (, push it to the stack
            s.push(c);
        } else if (c == ')') {  // if the character is a ), check if the stack is empty and if the top of the stack is not an (, if true
                                // then add the top of the stack to the infix string and pop the element from the stack
            while (!s.empty() && s.top() != '(') {
                postfixString += s.top();
                s.pop();
            }
            s.pop();  // pops the element from the stack
        } else {
            while (!s.empty() && s.top() != '(' &&
                   weight(c) <= weight(s.top())) {  // tests while the stack isnt empty, the top isnt an (, and the precedence of
                                                    // the current char is more than that of the top of the stack
                postfixString += s.top();           // if true, add the top of the stack to the expression and pop it
                s.pop();
            }
            s.push(c);  // push the current character to the top of the stack
        }
    }
    while (!s.empty()) {  // while the stack isnt empty, add the top of the stack to the postfix string and then pop that element
        postfixString += s.top();
        s.pop();
    }
    return postfixString;  // return the postfix string to the user
}

int main() {
    string expr;                            // variable to keep track of the input expression from the user
    cout << "Enter an infix expression: ";  // prompts the user
    cin >> expr;                            // takes in the expression
    if (!balanced(expr)) {                  // checks if the expression is balanced or not and tells the user if it isn't
        cout << "The Expression is not balanced." << endl;
    } else {  // if the expression is balanced, it will take the user input and convert it to the postfix string and output it to the user
        string postfix = convert(expr);
        cout << "Postfix expression: " << postfix << endl;
    }
    return 0;
}
