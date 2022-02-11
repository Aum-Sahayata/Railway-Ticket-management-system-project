#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice;

    printf(" 1. Booking Ticket.\n 2. Display Ticket Information using PNR number.\n 3. Cancellation of Booking Ticket\n 4. Edit/Update of booking ticket.\n 5. Exit.\n Enter your choice: ");

    FILE *o1;
    char id[5], Cname[20], Nname[20], pincode[6], Sstaion[10], Dstation[10], proof[10], fname[10], ch, save,x;

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("-------------Booking Ticket-------------\n");
        // Creating a Custom file and opening it
        printf("Enter PNR no:");
        scanf("%s", &fname);
        o1 = fopen(fname, "w");
        // Taking input for all the fields
        printf("\nEnter customer id: ");
        scanf("%s", id);
        printf("\nEnter your name: ");
        scanf("%s", Cname);
        printf("\nEnter your pincode: ");
        scanf("%s", pincode);
        printf("\nEnter your Source station: ");
        scanf("%s", Sstaion);
        printf("\nEnter your Destination station: ");
        scanf("%s", Dstation);
        printf("\nEnter your ID proof name: ");
        scanf("%s", &proof);
        printf("\nYour other information will be taken from provied ID proof.");

        // Here everything gets stored in file.
            fprintf(o1, "Customer name: %s\n", Cname);
            fprintf(o1, "ID: %s\n", id);
            fprintf(o1, "Customer pincode: %s\n", pincode);
            fprintf(o1, "Source station: %s\n", Sstaion);
            fprintf(o1, "Destination station: %s\n", Dstation);
            fprintf(o1, "ID proof: %s\n", proof);
            fprintf(o1,"Ticket status: Confirmed");
        fclose(o1);

        break;

    case 2:
        printf("------------Customer Ticket Info------------\n");
        printf("Enter PNR no:");
        scanf("%s", &fname);
        o1 = fopen(fname, "r");
        if (NULL == o1)
        {
            printf("Booking does not exist!! \n");
        }
        do
        {
            ch = fgetc(o1);
            printf("%c", ch);
            // Checking if character is not EOF.
            // If it is EOF stop reading.
        } while (ch != EOF);
        fclose(o1);
        break;

    case 3:
        printf("------------Cancellation of Ticket------------");
        printf("\nEnter PNR no:");
        scanf("%s", &fname);
        // This deletes the ticket file.
        if(remove(fname)==0){
            printf("\nCancellation successful.");
        }
        else{
            printf("Error in cancellation.");
        }
        break;

    case 4:
        printf("---------------Edit Name---------------");
        printf("\nEnter PNR no:");
        scanf("%s",&fname);
        o1 = fopen(fname,"r+");
        // Here we change the name of the person.
        fseek(o1,0,SEEK_SET);
        printf("\nEnter NEW name: ");
        scanf("%s", Nname);
        fprintf(o1, "Customer name: %s\n", Nname);
        printf("Name updated successfully.");
        break;

    case 5:
        exit(1);

    default:
        printf("Invalid choice!!");
        break;
    }
}
