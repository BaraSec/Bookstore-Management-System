//Including the required library(ies)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


#if 0
   Full Name: Bara ***
   Student ID Number: 1161357
   Lecture Section Number: 2

   Partner's info: No partner.
#endif


//Global variables declaration
int *ptr = NULL;
int globalCounter = 0;

COORD coord = {0, 0}; // sets coordinates to 0,0 (global variable)
COORD max_res, cursor_size;


// Functions' prototypes
void gotoxy(int, int);   // a function used to print text anywhere on the console (the program's screen)
void displayMainMenu();  // displays the main menu
void addBook();   	     // adds information for a new book
void removeBook();  	 // removes information of old book
void searchForBook(); 	 // searches for a book in the store
void uploadDataFile();   // uploads book data from file
void updateDataFile();   // saves book data updates to file


int main(int argc, char **argv)
{
    // Coloring the CMD (the console) to make it more user-friendly
    // by executing the "color" command in the command line (the cmd.exe process)
    // using the system(const char *command) function from the stdio (<stdio.h>) library
    system("color F9");

    gotoxy(7,4);
    printf("********************");

    gotoxy(26,4);
    printf(" Welcome To The Bookstore Management System ");

    gotoxy(70,4);
    printf("********************");

    uploadDataFile();

    system("COLOR 74");

    // Using the Beep(int (frequency), int ((duration)) function from the windows (<windows.h>) library
    // to initiate a user-friendly sound (a beep) in certain situations
    Beep(1500, 500);

    gotoxy(7,20);
    printf("Press any key to continue...");

    getch(); // Using the getch(void) function from the conio (<conio.h>) library to get a character from the console without echoing to the screen

    displayMainMenu();

    return 0;
}

// The definition of the gotoxy(int, int) function
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// The definition of the displayMainMenu() function
void displayMainMenu()
{
    system("COLOR F9");

    // Clearing the console by executing the "cls" command
    // in the command line (the cmd.exe process)
    // using the system(const char *command) function from the stdlib (<stdlib.h>) library
    system("cls");

    gotoxy(10,0);

    // Obfuscated code to display a nice simple shape
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Please Select an Operation (1-4): ");

    gotoxy(10,5);
    printf("1- Add a Book");

    gotoxy(10,7);
    printf("2- Remove a Book");

    gotoxy(10,9);
    printf("3- Search for a Book");

    gotoxy(10,11);
    printf("4- Exit System");

    gotoxy(10,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    switch (getch())
    {
        case '1':
            addBook();
            break;

        case '2':
            removeBook();
            break;

        case '3':
            searchForBook();
            break;

        case '4':
            system("cls");

            updateDataFile();

            gotoxy(10,10);
            printf("Thank you for using my BookStore Management System. GoodBye.");

            gotoxy(10,12);
            printf("By: Bara Adnan.");

            system("COLOR 74");
            Beep(1500, 500);

            gotoxy(10,16);
            printf("××Exiting system in");

            system("color f9");
            gotoxy(30,16);

            // Using a loop to simulate the exiting process
            // making the program more user-friendly
            for(globalCounter=3; globalCounter>0; globalCounter--)
            {
                /*
                    Using the Sleep(int) function from the windows (<windows.h>) library to make the calling thread sleep
                    until the specified time (the function's argument) in milliseconds is reached.
                    Using it to simulate the real processing time of this event.
                 */
                Sleep(800);
                printf("%d ", globalCounter);
            }

            system("COLOR 74");

            gotoxy(10, 18);
            printf("--> System has been exited.\a");
            printf("\n\n\n\n\n\n\n");

            // Using the exit(int status) function from the stdlib (<stdlib.h>) library
            // to end the execution of the program
            exit(0);
            break;

        default:
            system("cls");
            system("color 0c");

            gotoxy(10,6);
            printf("ERROR: No such operation! Please try again, Sir/Madam.");
            Beep(1500, 1500);

            displayMainMenu();
    }
}

// The definition of the uploadDataFile() function
void uploadDataFile()
{
    Sleep(1000);

    gotoxy(15,9);
    printf("Uploading data file.");

    // Using a loop to simulate the real processing time of this function
    // by printing a few contiguous '.' (dots)
    for(globalCounter=35; globalCounter<38; globalCounter++)
    {
        Sleep(800); // Using the Sleep(int) function to simulate the real processing time of this function
        gotoxy(globalCounter,9);
        printf(".");
    }

    Sleep(500);
    gotoxy(15,11);
    printf("--> Data file has been uploaded successfully.");
}

// The definition of the addBook() function
void addBook()
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Adding book info.");

    // Using a loop to simulate the real processing time of this function
    // by printing a few contiguous '.' (dots)
    for(globalCounter=27; globalCounter<31; globalCounter++)
    {
        Sleep(800); // Using the Sleep(int) function to simulate the real processing time of this function
        gotoxy(globalCounter,2);
        printf(".");
    }

    gotoxy(10,4);
    printf("--> Book info has been added.");

    system("COLOR 74");
    Beep(1500, 500);

    gotoxy(10,12);
    printf("Press Any Key To Go Back To The Main Menu...");
    getch();

    displayMainMenu();
}

// The definition of the removeBook() function
void removeBook()
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Removing book info.");

    // Using a loop to simulate the real processing time of this function
    // by printing a few contiguous '.' (dots)
    for(globalCounter=29; globalCounter<32; globalCounter++)
    {
        Sleep(800); // Using the Sleep(int) function to simulate the real processing time of this function
        gotoxy(globalCounter,2);
        printf(".");
    }

    gotoxy(10,4);
    printf("--> Book info has been removed.");

    system("COLOR 74");
    Beep(1500, 500);

    gotoxy(10,12);
    printf("Press Any Key To Go Back To The Main Menu...");
    getch();

    displayMainMenu();
}

// The definition of the searchForBook() function
void searchForBook()
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Searching for book.");

    // Using a loop to simulate the real processing time of this function
    // by printing a few contiguous '.' (dots)
    for(globalCounter=29; globalCounter<32; globalCounter++)
    {
        Sleep(800); // Using the Sleep(int) function to simulate the real processing time of this function
        gotoxy(globalCounter,2);
        printf(".");
    }

    gotoxy(10,4);
    printf("--> Book has been searched for.");

    system("COLOR 74");
    Beep(1500, 500);

    gotoxy(10,12);
    printf("Press Any Key To Go Back To The Main Menu...");
    getch();

    displayMainMenu();
}

// The definition of the updateDataFile() function
void updateDataFile()
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,20);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Updating data file.");

    // Using a loop to simulate the real processing time of this function
    // by printing a few contiguous '.' (dots)
    for(globalCounter=29; globalCounter<32; globalCounter++)
    {
        Sleep(800); // Using the Sleep(int) function to simulate the real processing time of this function
        gotoxy(globalCounter,2);
        printf(".");
    }

    gotoxy(10,4);
    printf("--> Data file has been updated successfully.");
}
