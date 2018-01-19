//Including the required library(ies)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


#if 0
   Full Name: Bara ***
   Student ID Number: 1161357
   Lecture Section Number: 2

   Partner(s) info: no partner.
#endif


// Defining a global constant
#define MAXSIZE 100
#define NAMESIZE 50


// Global variables declaration
int *ptr = NULL;
int globalCounter = 0, tempBin = 0, i = 0, x = 0, y = 0, z = 0;
double tempPrice = 0.0;
char tempName[NAMESIZE];

COORD coord = {0, 0}; // sets coordinates to 0,0 (global variable)
COORD max_res, cursor_size;


// Functions' prototypes
void gotoxy(int, int);                              // a function used to print text anywhere on the console (the program's screen)
void displayMainMenu(char [][NAMESIZE], int [], double [], int *);     // displays the main menu
void uploadDataFile(char [][NAMESIZE], int [], double [], int *);      // uploads book data from file
void addBook(char [][NAMESIZE], int [], double [], int *);   	        // adds information for a new book
void removeBook(char [][NAMESIZE], int [], double [], int *);  	    // removes information of old book
void searchForBook(char [][NAMESIZE], int [], double [], int); 	    // searches for a book in the store
void printBooks(char [][NAMESIZE], int [], double [], int);            // prints (displays) the book list (bins + prices) on the screen
void updateDataFile(char [][NAMESIZE], int [], double [], int);        // saves book data updates to file


int main(int argc, char **argv)
{
    // Coloring the CMD (the console) to make it more user-friendly
    // by executing the "color" command in the command line (the cmd.exe process)
    // using the system(const char *command) function from the stdio (<stdio.h>) library
    system("color F9");

    int bins[MAXSIZE], size = 0;
    double prices[MAXSIZE];
    char names[MAXSIZE][NAMESIZE];

    gotoxy(7,4);
    printf("********************");

    gotoxy(26,4);
    printf(" Welcome To The Bookstore Management System ");

    gotoxy(70,4);
    printf("********************");

    uploadDataFile(names, bins, prices, &size);

    system("COLOR 74");

    // Using the Beep(int (frequency), int ((duration)) function from the windows (<windows.h>) library
    // to initiate a user-friendly sound (a beep) in certain situations
    Beep(1500, 500);

    gotoxy(7,20);
    printf("Press any key to continue...");

    getch(); // Using the getch(void) function from the conio (<conio.h>) library to get a character from the console without echoing to the screen
    displayMainMenu(names, bins, prices, &size);

    return 0;
}

// The definition of the gotoxy(int, int) function
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// The definition of the displayMainMenu(int [], double [], int *) function
void displayMainMenu(char names[][NAMESIZE], int bins[], double prices[], int *size)
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
    printf("Please Select an Operation (1-5): ");

    gotoxy(10,5);
    printf("1- Add a Book");

    gotoxy(10,7);
    printf("2- Remove a Book");

    gotoxy(10,9);
    printf("3- Search for a Book");

    gotoxy(10,11);
    printf("4- Print the book list");

    gotoxy(10,13);
    printf("5- Exit System");

    gotoxy(10,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    switch (getch())
    {
        case '1':
            addBook(names, bins, prices, size);
            break;

        case '2':
            removeBook(names, bins, prices, size);
            break;

        case '3':
            searchForBook(names, bins, prices, *size);
            break;

        case '4':
            printBooks(names, bins, prices, *size);
            break;

        case '5':
            system("cls");

            updateDataFile(names, bins, prices, *size);

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

            displayMainMenu(names, bins, prices, size);
    }
}

// The definition of the uploadDataFile(int [], double [], int *) function
void uploadDataFile(char names[][NAMESIZE], int bins[], double prices[], int *size)
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

    // The start of the actual code
    FILE *dataFile;

    dataFile = fopen("books.txt", "r");

    while(!feof(dataFile))
    {
        fscanf(dataFile, "%s\t%d\t%lf\n", names[*size], &bins[*size], &prices[*size]);
        (*size)++;
    }

    fclose(dataFile);
    // The end of the actual code

    Sleep(500);
    gotoxy(15,11);
    printf("--> Data file has been uploaded successfully.");
}

// The definition of the addBook(int [], double [], int *) function
void addBook(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,16);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Enter bin number for the book: ");
    scanf("%d", &tempBin);

    gotoxy(10,4);
    printf("Enter the price of the book: ");
    scanf("%lf", &tempPrice);

    gotoxy(10,6);
    printf("Enter the name of the book: ");
    scanf("%s", tempName);

    if((*size) == 0)
    {
        bins[0] = tempBin;
        prices[0] = tempPrice;
        strcpy(names[0], tempName);

        gotoxy(10,10);
        printf("--> A book with bin %d has been added.", bins[0]);
        (*size)++;

        system("COLOR 74");
        Beep(1500, 500);
    }

    else if((*size) == MAXSIZE)
    {
        gotoxy(10,10);
        printf("--> The Book list is full. Remove some books to insert others please.");

        system("COLOR 74");
        Beep(1500, 500);
    }

    else
    {
        for(x=0, z=0; x<(*size); x++)
        {
            if(tempBin == bins[x])
            {
                gotoxy(10,10);
                printf("--> A book with bin %d already exists, no change has been made.", tempBin);

                system("COLOR 74");
                Beep(1500, 500);

                z++; // To prevent executing the if(!z) statements below

                break;
            }

            else if(tempBin < bins[x])
            {
                for(y=*size; y>=x; y--)
                {
                    bins[y] = bins[y-1];
                    prices[y] = prices[y-1];
                    strcpy(names[y], names[y-1]);
                }

                bins[x] = tempBin;
                prices[x] = tempPrice;
                strcpy(names[x], tempName);

                gotoxy(10,10);
                printf("--> A book with bin %d has been added.", tempBin);

                system("COLOR 74");
                Beep(1500, 500);

                (*size)++;
                z++;

                break;
            }
        }

        if(!z)
        {
            bins[*size] = tempBin;
            prices[*size] = tempPrice;
            strcpy(names[*size], tempName);

            gotoxy(10,10);
            printf("--> A book with bin %d has been added.", tempBin);

            system("COLOR 74");
            Beep(1500, 500);

            (*size)++;
        }
    }

    gotoxy(10,14);
    printf("Press Any Key To Go Back To The Main Menu...");

    getch();
    displayMainMenu(names, bins, prices, size);
}

// The definition of the removeBook(int [], double [], int *) function
void removeBook(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    if((*size) > 0)
    {
        gotoxy(10,2);
        printf("Enter the bin number for the book to remove: ");
        scanf("%d", &tempBin);

        for(x=0, z=0; x<*size; x++)
        {
            if(tempBin == bins[x])
            {
                for(y=x+1; y<(*size); y++)
                {
                    bins[y-1] = bins[y];
                    prices[y-1] = prices[y];
                    strcpy(names[y-1], names[y]);
                }

                (*size)--;
                z++;

                gotoxy(10,6);
                printf("--> Book with bin %d has been removed.", tempBin);

                system("COLOR 74");
                Beep(1500, 500);

                break;
            }
        }

        if(!z)
        {
            gotoxy(10,6);
            printf("--> Book with bin %d does not exist, no change has been made.", tempBin);

            system("COLOR 74");
            Beep(1500, 500);
        }
    }

    else
    {
        gotoxy(10,4);
        printf("--> The book list is empty, no books are there to be removed.");
    }

    gotoxy(10,12);
    printf("Press Any Key To Go Back To The Main Menu...");

    getch();
    displayMainMenu(names, bins, prices, size);
}

// The definition of the searchForBook(int [], double [], int ) function
void searchForBook(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(10,2);
    printf("Enter the bin number for the book to search for: ");
    scanf("%d", &tempBin);

    if(size > 0)
    {
        for(x=0, z=0; x<size; x++)
        {
            if(tempBin == bins[x])
            {
                gotoxy(10,6);
                printf("--> Book with bin %d has been found: ", tempBin);

                gotoxy(10,8);
                printf("\t\tName: %-30s\tbin#: %-10d\tprice: %0.2f\n", names[x], bins[x], prices[x]);

                z++;

                system("COLOR 74");
                Beep(1500, 500);

                break;
            }
        }

        if(!z)
        {
            gotoxy(10,6);
            printf("--> No Book with bin %d has been found in the book list.", tempBin);

            system("COLOR 74");
            Beep(1500, 500);
        }
    }

    else
    {
        gotoxy(10,4);
        printf("--> The book list is empty, no books are there to be searched for.");
    }

    gotoxy(10,12);
    printf("Press Any Key To Go Back To The Main Menu...");

    getch();
    displayMainMenu(names, bins, prices, &size);
}

// The definition of the printBooks(int [], double [], int ) function
void printBooks(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    system("cls");

    gotoxy(10,0);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    gotoxy(10,2);
    printf("--> Books in the list are: \n\n");

    if(size > 0)
    {
        for(x=0; x<size; x++)
        {
            Sleep(300);
            printf("\t\tName: %-30s\tbin#: %-10d\tprice: %0.2f\n", names[x], bins[x], prices[x]);
        }
    }

    else
    {
        Sleep(500);

        gotoxy(10,4);
        printf("--> No books in the list. Add some please.\n\n");
    }

    system("COLOR 74");
    Beep(1500, 500);

    printf("\n\n\n\n\t  Press Any Key To Go Back To The Main Menu...\n");
    printf("\n\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    getch();
    displayMainMenu(names, bins, prices, &size);

}

// The definition of the updateDataFile(int [], double [], int ) function
void updateDataFile(char names[][NAMESIZE], int bins[], double prices[], int size)
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

    // The start of the actual code
    FILE *dataFile;

    dataFile = fopen("books.txt", "w");

    while(i<size)
    {
        fprintf(dataFile, "%s\t%d\t%0.2f\n", names[i], bins[i], prices[i]);
        i++;
    }

    fclose(dataFile);
    // The end of the actual code

    gotoxy(10,4);
    printf("--> Data file has been updated successfully.");
}
