#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts < MAX_CONTACTS) {
        struct Contact newContact;
        printf("Enter name: ");
        scanf("%s", newContact.name);
        printf("Enter phone number: ");
        scanf("%s", newContact.phone);
        printf("Enter email address: ");
        scanf("%s", newContact.email);
        
        contacts[numContacts] = newContact;
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Contact list is full!\n");
    }
}

void displayContacts() {
	int i;
    printf("Contacts:\n");
    for ( i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i+1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

