//Preyansi Patel

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//declaring constants
const int INPUT = 1;
const int REPLACE_SINGLE_ELEMENT = 2;
const int REPLACE_MULTIPLE_ELEMENTS = 3;
const int CHANGE_CASE = 4;
const int INSERT_SINGLE_ELEMENT = 5;
const int REMOVE_SINGLE_ELEMENT = 6;
const int REVERSE = 7;
const int RESET = 8;
const int EXIT_PROGRAM = 9;

const int SIZE = 80; // constant for string size

//function prototypes
void inputString(char (&str)[SIZE], char (&original)[SIZE]);
void replaceChar(char (&str)[SIZE]);
void replaceMultipleChar(char (&str)[SIZE]);
void changeCase(char (&str)[SIZE]);
void insertChar(char (&str)[SIZE]);
void removeChar(char (&str)[SIZE]);
void reverseString(char (&str)[SIZE]);
void resetString(char (&str)[SIZE], char (&original)[SIZE]);
bool exitProgram();

int main()
{
    //declare variables
    int userChoice;
    bool mainMenu = true;
    char str[SIZE] = {0}; // used to store the string data
    char original[SIZE] = {0}; // used to store the original string to reset
    bool exit = false;
    
    do {
        
        if (mainMenu) {
            
            cout << "String Editor Menu" << endl;
            cout << "\t" << INPUT << " - Input a String" << endl;
            cout << "\t" << REPLACE_SINGLE_ELEMENT << " - Replace Single Element in String" << endl;
            cout << "\t" << REPLACE_MULTIPLE_ELEMENTS << " - Replace Multiple Elements in String" << endl;
            cout << "\t" << CHANGE_CASE << " - Change Case of Elements in String" << endl;
            cout << "\t" << INSERT_SINGLE_ELEMENT << " - Insert Single Element in String" << endl;
            cout << "\t" << REMOVE_SINGLE_ELEMENT << " - Remove Single Element in String" << endl;
            cout << "\t" << REVERSE << " - Reverse String" << endl;
            cout << "\t" << RESET << " - Reset to Original String" << endl;
            cout << "\t" << EXIT_PROGRAM << " - Exit Program" << endl;
        }
        
        cout << "\nPlease enter menu choice: ";
        cin >> userChoice;
        
        if (userChoice > INPUT && userChoice < EXIT_PROGRAM && strlen(str) == 0) {
            
            cout << "ERROR - YOU MUST ENTER IN A STRING FIRST. PLEASE SELECT OPTION 1!!\n" << endl;
            mainMenu = true;
            continue;
        }
        
        //using the switch case to manage the main menu options
        switch(userChoice) {
            
            case INPUT:
                inputString(str, original); // calling inputString function
                mainMenu = true;
                break;
            case REPLACE_SINGLE_ELEMENT:
                replaceChar(str); // calling replaceChar function
                mainMenu = true;
                break;
            case REPLACE_MULTIPLE_ELEMENTS:
                replaceMultipleChar(str); // calling replaceMultipleChar function
                mainMenu = true;
                break;
            case CHANGE_CASE:
                changeCase(str); // calling changeCase function
                mainMenu = true;
                break;
            case INSERT_SINGLE_ELEMENT:
                insertChar(str); // calling insertChar function
                mainMenu = true;
                break;
            case REMOVE_SINGLE_ELEMENT:
                removeChar(str); // calling removeChar function
                mainMenu = true;
                break;
            case REVERSE:
                reverseString(str); // calling reverseString function
                mainMenu = true;
                break;
            case RESET:
                resetString(str, original); // calling resetString function
                mainMenu = true;
                break;
            case EXIT_PROGRAM:
                exit = exitProgram(); // calling exitProgram function
                break;
            default:
                cout << "ERROR: You must enter in a valid menu item. Please try again";
                mainMenu = false;
                break;
        }
        
    } while(!exit);

    return 0;
} //end of main


//creating function for the user to input string
void inputString(char (&str)[SIZE], char (&original)[SIZE]){
    
    cin.ignore();
    cout << "Please enter in the string you want to edit: "; //getting string data from the user
    cin.get(str, SIZE);
    
    strcpy(original, str); // string for reset purpose
    cout << "The current contents of the string is: " << str << endl;
    cout << "The length of the string is: " << strlen(str) << endl << endl;
   
}
//creating function that allows the user to replace any single character in the string with a different character
void replaceChar(char (&str)[SIZE]) {
    
    char singleChar;
    int position;
    bool failed = false;
    
    cout << "Enter in a single character: ";
    cin >> singleChar;
    
    do {
        
        if (failed) {
            cout << "\nError, character number past end of line; Please re-enter: ";
        }
        else {
            cout << "Enter in the character number in the string holding the to replace: ";
        }
        
        cin >> position;
        
        if (position <= 0 || position > strlen(str)) {
            failed = true;
        }
        
    } while(position <= 0 || position > strlen(str));
    
    str[position-1] = singleChar;
    
    cout << "Character succesfully replaced." << endl;
    cout << "The current contents of the string is: " << str << endl;
    cout << "The length of the string is: " << strlen(str) << endl << endl;
    
}
//creating function that replaces all instances of a character in a string with a different character
void replaceMultipleChar(char (&str)[SIZE]) {
    
    char oldChar;
    char newChar; 
    int count = 0; // used to count how many characters are replaced

    cout << "Enter in a character from the current string: ";
    cin >> oldChar;
    
    cout << "Enter in the replacement character: ";
    cin >> newChar;
    
    // replacing and counting the characters
    for (int i = 0; i <= strlen(str); i++) {
        
        if (str[i] == oldChar) {
            
            str[i] = newChar;
            count++;
            
        }
    }
    
    cout << count << " characters succesfully replaced in the string." << endl;
    cout << "The current contents of the string is: " << str << endl;
    cout << "The length of the string is: " << strlen(str) << endl << endl;
    
}
//creating function that changes the case of all of the letters in the string
void changeCase(char (&str)[SIZE]) {
    
    char choice; // variable for case choice
    
    bool failed = false; // variable to handle failed case text
    
    do {
        
        if (failed) {
            cout << "Please enter U or L: ";
        }
        else {
            cout << "Do you want to change all letters to upper or lower case? (U or L): ";;
        }
        
        cin >> choice;
        
        choice = toupper(choice); // converting choice value to uppercase
        
        if (choice != 'U' && choice != 'L') {
            failed = true;
        }
        
    } while(choice != 'U' && choice != 'L');
    
    
    if (choice == 'U') {
        
        for (int i = 0; i <= strlen(str); i++) {
            str[i] = toupper(str[i]);
        }
        cout << "All letters set to upper case successfully!" << endl;
    }
    else {
    
        for (int i = 0; i <= strlen(str); i++) {
            str[i] = tolower(str[i]);
        }
        cout << "All letters set to lower case successfully!" << endl;
    }
    cout << "The current contents of the string is: " << str << endl;
    cout << "The length of the string is: " << strlen(str) << endl << endl;
    
}
//creating function that allows the user to insert a single element into a sting
void insertChar(char (&str)[SIZE]) {
    
    char singleChar; // used for character to insert
    int position; // used for position
    bool failed = false; // used to handle text in failed case
    char nextChar; // used to store next element
    char tempChar; // used to store next character temporarily
    
    if (strlen(str) == SIZE) { // check if string already reached to maximum size
        
        cout << "Insertion is not allowed because string has reached to the maximum size " << SIZE << endl;
    }
    else {
        
        cout << "Enter in a single character: ";
        cin >> singleChar;
        
        // checking validity of position
        do {
            
            if (failed) {
                cout << "\nError, character number past end of line; Please re-enter: ";
            }
            else {
                cout << "Enter in the character number the new character will be inserted after: ";
            }
            
            cin >> position;
            
            if (position <= 0 || position > strlen(str)) {
                failed = true;
            }
        } while(position <= 0 || position > strlen(str));
        
        nextChar = singleChar;
        
        for (int i = position; i <= strlen(str); i++) {
            
            tempChar = nextChar;
            nextChar = str[i];
            str[i] = tempChar;
        }
        cout << "Character succesfully inserted." << endl;
        cout << "The current contents of the string is: " << str << endl;
        cout << "The length of the string is: " << strlen(str) << endl << endl;
    }
   
}
//creating function that allows the user to remove a single element from a sting
void removeChar(char (&str)[SIZE]) {
    
    int remove; // character to remove
    bool failed = false;
    
    if (strlen(str) == 1) { // check if string has only 1 element
        
        cout << "You can not remove the element because string has only 1 element" << endl;
    }
    else {
        do {
        
            if (failed) {
                cout << "\nError, character number past end of line; Please re-enter: ";
            }
            else {
                cout << "Enter in the character number to be removed: ";
            }
            
            cin >> remove;
            
            if (remove <= 0 || remove > strlen(str)) {
                failed = true;
            }
            
        } while(remove <= 0 || remove > strlen(str));
        
        // removing element from string
        for (int i = remove-1; i <= strlen(str); i++) {
            
            str[i] = str[i+1];
        }
        cout << "Character succesfully removed." << endl;
        cout << "The current contents of the string is: " << str << endl;
        cout << "The length of the string is: " << strlen(str) << endl << endl;
        
    }
    
}
//creating function to reverse the string
void reverseString(char (&str)[SIZE]) { // function body for reversing string

    char swap; // used for swaping in revering the string
    int length = strlen(str); // storing the length of string
    int n = length - 1; // used for getting last value in string
    
    // reversing the string
    for(int i = 0; i < (length / 2); i++) {
        
        swap = str[i];
        str[i] = str[n];
        str[n] = swap;
        n--;
    }
    
    cout << "String reversal successful." << endl;
    cout << "The current contents of the string is: " << str << endl;
    cout << "The length of the string is: " << strlen(str) << endl << endl;
}

void resetString(char (&str)[SIZE], char (&original)[SIZE]) {
    
    char choice;
    bool failed = false;
    
    do {
        
        if (failed) {
            cout << "Please enter Y or N: ";
        }
        else {
            cout << "Are you sure you want to reset the string? (Y or N): ";
        }
        
        cin >> choice;
        
        choice = toupper(choice);
        
        if (choice != 'Y' && choice != 'N') {
            failed = true;
        }
        
    } while(choice != 'Y' && choice != 'N');
    
    if (choice == 'Y') {
        
        strcpy(str, original); // resetting to original string
        
        cout << "Reset successful." << endl;
        cout << "The current contents of the string is: " << str << endl;
        cout << "The length of the string is: " << strlen(str) << endl << endl;
        
    }
}
// function prototype for exit program
bool exitProgram() {
    
    char choice;
    bool failed = false;
    
    do {
        
        if (failed) {
            cout << "Please enter Y or N: ";
        }
        else {
            cout << "Do you wish to exit the program? (Y or N): ";
        }
        cin >> choice;
        
        choice = toupper(choice);
        
        if (choice != 'Y' && choice != 'N') {
            failed = true;
        }
        
    } while(choice != 'Y' && choice != 'N');
    
    if (choice == 'Y') {
        
        return true;
    }
    else {
        return false;
    }
    
}
