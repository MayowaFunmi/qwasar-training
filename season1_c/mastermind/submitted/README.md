# Welcome to My Mastermind

---

## Task

to create a program called mastermind, an implementation of the mastermind game

## Description

create 3 files:
headers.h file where the header files are saved
my_mastermind.c file where the main logic for the game resides
Makefile where the commands to compile the code reside

in the my_mastermind.c file, create
start_info() function to display information to user
commandInput() function to get code from users without breaking the running of the code
my_strlen() function to get the length of a string
equality() function to check if two strings are equal or not
my_isdigit() function to check if input string characters are all digits or not
endfile() function to exit the code
countUserChar() to count the number of well_placed characters and number of misplaced characters
checkCode() function to run maximum number of 10 times for the game to be played

    create the main() function with two parameters int argc and char* argv[] to get command line arguments
    declare a string variable secret to store user input code from the command line
    call the start_info() function
    call the checkCode() function and pass the variable secret as parameter
        in the checkCode() function, declare a variable get_code to get user code from the command line.
        if the user enters ctrd + d, the end the game
        check if all characters in the get_code are digits and also if both get_code and secret code are equal
            if all characters are digits and both get_code and secret code are equal
                then the user correctly get the code and wins the game
            if all characters are digits and get_code is not equal to secret code
                call the countUserChar() function and pass the secret and get_code as parameters
                declare two integer variables: misplaced and well_placed, and initialize both to 0
                then, compare all the digits of both the get_code and secret code
                    if a digit of get_code is in secret code but in the wrong position, increase the misplaced variable by 1
                    if a digit of get_code is in secret code and in the right position, increase the well_placed variable by 1
            repeat this process above for 10 rounds, at the tenth round if the user doesn't get the correct code, the game comes to end

## Installation

There is no installation of any package for this project

## Usage

Since there is no installation required, no usage is available

### The Core Team

<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
