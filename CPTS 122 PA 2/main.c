#include "Header.h"

int main(void)
{

    Record* head = NULL;
    struct Record** pHead = &head;
    Record* cur = head;
    FILE* infile = NULL;
    infile = fopen("list.csv", "r+");

    if (infile != NULL)
    {
        main_menu();

        int choice = 0;
        do {
            printf("Enter your choice of action: ");
            scanf(" %d", &choice);
        } while ((choice < 1) && (choice > 10));

        switch (choice)
        {
        case 1:
            insert_at_front(*pHead, infile);
            system("clear");
            break;

        case 2:
            store(head, infile);
            system("clear");
            break;

        case 3:
            display(head);
            system("clear");
            break;

        case 4:


            system("clear");
            break;

        case 5:


            system("clear");
            break;

        case 6:
            edit(head);
            system("clear");
            break;

        case 7:


            system("clear");
            break;

        case 8:
            rate(head);
            system("clear");
            break;

        case 9:
            play(head);
            system("clear");
            break;

        case 10:
            shuffle(head);
            system("clear");
            break;

        case 11:


            break;
        }

    }
    else
    {
        printf("File can not be opened");
    }




    fclose(infile);

    return 0;
}