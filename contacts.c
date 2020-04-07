//==============================================
// Name:           Arjun Devakumar
// Student Number: 159076199
// Email:          adevakumar1@myseneca.ca
// Section:        NQQ
// Date:           March 28,2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
    int answer;
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    answer = yes();

    if (answer != 0)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else 
    {
        (*name).middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}
// getAddress:
void getAddress(struct Address* address)
{
    int aprtNum = '\0';
    int num;
    int answer;
    printf("Please enter the contact's street number: ");
    num = getInt();
    while (num < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        num = getInt();
    }
    address->streetNumber = num;



    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();
    printf("Do you want to enter an apartment number? (y or n): ");
    answer = yes();
    if (answer)
    {
        if (answer != 0) {
            printf("Please enter the contact's apartment number: ");
            aprtNum = getInt();
            while (aprtNum < 0)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                aprtNum = getInt();
            }
        }
    }
    else {
        (*address).apartmentNumber = aprtNum;
    }
       
  
    address->apartmentNumber = aprtNum;
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int answer;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    answer = yes();
    if (answer == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else {
        (*numbers).home[0] = '\0';
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    answer = yes();
    if (answer == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {
        (*numbers).business[0] = '\0';
    }
}
// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}