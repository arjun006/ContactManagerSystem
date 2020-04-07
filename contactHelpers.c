//==============================================
// Name:           Arjun Devakumar	
// Student Number: 159076199
// Email:          adevakumar1@myseneca.ca
// Section:        NQQ
// Date:           March 28, 2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5
//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n');
}

// pause:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt:
int getInt(void)
{
    char nl = 'x';
    int value;
    while (nl != '\n')
    {
        scanf("%d%c", &value, &nl);
        if (nl != '\n')
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;

}

// getIntInRange:
int getIntInRange(int min, int max)
{
    int integer;
    do {
        integer = getInt();
        if (integer > max || integer < min) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (integer > max || integer < min);
    return integer;
}

// yes:
int yes(void)
{
    char answer;
    char nl = '\n';
    scanf("%c%c", &answer, &nl);
    if (nl != '\n')
    {
        clearKeyboard();
    }
    while ((answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') || (nl != '\n'))
    {
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &answer, &nl);
        if (nl != '\n') {
            clearKeyboard();
        }
    }
    if (answer == 'y' || answer == 'Y') {
        return 1;

    }
    else return 0;


}

// menu:
int menu(void)
{
    int selection;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    do {
        selection = getInt();
        if (selection > 6 || selection < 0)
        {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
        }
    } while (selection > 6 || selection < 0);

    return selection;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
    int selection;
    int answer = 0;

    struct Contact contact[MAXCONTACTS] = 
    { { { "Rick", {'\0'}, "Grimes" },
{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
{ "4161112222", "4162223333", "4163334444" } },
{
{ "Maggie", "R.", "Greene" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
{ "7051112222", "7052223333", "7053334444" } },
{
{ "Sasha", {'\0'}, "Williams" },
{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
{ "9052223333", "9052223333", "9054445555" } },
    };
    while (answer == 0)
    {
        selection = menu();
        switch (selection)
        {
        case 1:
            printf("\n");
            displayContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 2:
            printf("\n");
            addContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 3:
            printf("\n");
            updateContact(contact, MAXCONTACTS);
            printf("\n");
            pause();
            printf("\n");
            break;
        case 4:
            printf("\n");
            deleteContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 5:
            printf("\n");
            searchContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 6:
            printf("\n<<< Feature to sort is unavailable >>>\n\n");
            pause();
            printf("\n");
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            answer = yes();
            printf("\n");
            if (answer) {
                printf("Contact Management System: terminated");
                printf("\n");
            }
            break;

        default: break;

        }
    }
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int i;
    while (needInput == 1) {
        scanf("%10s", phoneNum);
        clearKeyboard();
        if (strlen(phoneNum) == 10)
        {
            for (i = 0; i < 10; i++)
            {
                // (String Length Function: validate entry of 10 characters)
                if (phoneNum[i] < '0' || phoneNum[i] > '9')
                {
                    needInput = 1;
                    printf("Enter a 10-digit phone number: ");
                    break;
                }
                else 
                {
                    needInput = 0;
                }
            }
        } else
          printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int index = -1;
    int i;
    for (i = 0; i < MAXCONTACTS; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            index = i;
        }
    }
    return index;
}


// displayContactHeader
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
    //name
    char name[84] = {"\0"};

    strcat(name,contact->name.firstName);
    if (strlen(contact->name.middleInitial) != 0) {
        strcat(name, " ");
        strcat(name, contact->name.middleInitial);
        strcat(name, " ");
    }
    else {
        strcat(name, " ");
    }
    strcat(name, contact->name.lastName);

    printf(" %s\n", name);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
    return; 
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
    displayContactHeader();
    int i;
    int numValid = 0;
    for (i = 0; i < MAXCONTACTS; i++) {
        if (strlen(contacts[i].numbers.cell) > 0) {
            displayContact(&contacts[i]);
            numValid++;
        }
    }
    displayContactFooter(numValid);
    return;
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
    char cellSearch[11];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellSearch);
    int index;
    index = findContactIndex(contacts, MAXCONTACTS, cellSearch);
    if (index != -1) {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
    else 
    {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
    int emptyIndex;
    emptyIndex = findContactIndex(contacts, size, "");
    if (emptyIndex != -1) {
        getContact(&contacts[emptyIndex]);
        printf("--- New contact added! ---\n\n"); 
    }
    else {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
    char cellSearch[11];
    int a;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellSearch);
    a = findContactIndex(contacts, size, cellSearch);
    if (a != -1) {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[a]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes()) {
            getName(&contacts[a].name);
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes()) {
            getAddress(&contacts[a].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes()) {
            getNumbers(&contacts[a].numbers);
        }
        printf("--- Contact Updated! ---\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
}
// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    char cell[11];
    int a;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cell);
    a = findContactIndex(contacts,size,cell);
    if (a != -1) 
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[a]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes()) 
        {
            strcpy(&contacts[a].numbers.cell[0], "\0");
            printf("--- Contact deleted! ---\n");
        } printf("\n");
    } else 
        printf("*** Contact NOT FOUND***\n");

}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{

}