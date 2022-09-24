#include "Header.h"


void main_menu()
{

    printf("Main Menu\n");
    printf("(1) Load songs\n");
    printf("(2) Store songs\n");
    printf("(3) Display songs\n");
    printf("(4) Insert songs\n");
    printf("(5) Delete songs\n");
    printf("(6) Edit songs\n");
    printf("(7) Sort songs\n");
    printf("(8) Rate songs\n");
    printf("(9) Play songs\n");
    printf("(10) Shuffle\n");
    printf("(11) Exit\n");

}

struct record* make_node(FILE* infile)
{
    //Memory allocated for node; parsing variables declared
    Record* node = malloc(sizeof(struct record));
    char* i = NULL;
    char temp[250];



    fgets(temp, 250, infile);

    i = strtok(temp, ",");
    if (i != '\0')
    {
        strcpy(node->Artist, i);
    }


    i = strtok(NULL, ",");
    if (i != '\0')
    {
        strcpy(node->Album, i);
    }


    i = strtok(NULL, ",");
    if (i != '\0')
    {
        strcpy(node->Song, i);
    }

    i = strtok(NULL, ",");
    if (i != '\0')
    {
        strcpy(node->Genre, i);
    }

    i = strtok(NULL, ",");
    char* length = i;


    i = strtok(NULL, ",");

    if (i != '\0')
    {
        node->times_played = atoi(i);
    }


    i = strtok(NULL, ",");

    if (i != '\0')
    {
        node->Rating = atoi(i);
    }

    char* min_or_sec = NULL;
    min_or_sec = strtok(length, ":");
    if (min_or_sec != '\0')
    {
        node->Length.minutes = atoi(min_or_sec);
        min_or_sec = strtok(NULL, ":");
        node->Length.seconds = atoi(min_or_sec);
    }


    node->pPrev = NULL;
    node->pNext = NULL;

    return node;
}
void insert_at_front(struct record** pHead, FILE* infile)
{

    if ((*pHead) == NULL)
    {
        Record* new_node = make_node(infile);
        *pHead = new_node;

        new_node->pPrev = NULL;
        new_node->pNext = NULL;
    }
    else
    {
        Record* new_node = make_node(infile);
        Record* holder = *pHead;
        *pHead = new_node;
        new_node->pNext = holder;
        new_node->pPrev = NULL;
        holder->pPrev = new_node;
    }
}

void display(struct record* list)
{
    int i = 0;

    do
    {
        printf("Enter 1 to see all songs");
        printf("Enter 2 to see songs by one artist");
        scanf("%d", &i);

    } while ((i != 1) && (i != 2));

    Record* current_song = list;

    if (i == 1)
    {
        while (current_song != NULL)
        {
            printf("Song: %s\n", current_song->Song);
            printf("Artist: %s\n", current_song->Artist);
            printf("Album: %s\n", current_song->Album);
            printf("Genre: %s\n", current_song->Genre);

            if (current_song->Length.seconds > 9)
            {
                printf("TIME: %d:%d\n", current_song->Length.minutes, current_song->Length.seconds);
            }
            else
            {
                printf("TIME: %d:0%d\n", current_song->Length.minutes, current_song->Length.seconds);
            }
            printf("NUM PLAYS: %d\n", current_song->times_played);
            printf("RATING: %d\n\n", current_song->Rating);

            current_song = current_song->pNext;

        }

    }
    else if (i == 2)
    {
        while (current_song != NULL)
        {
            printf("Song: %s\n", current_song->Song);
            printf("Artist: %s\n", current_song->Artist);
            printf("Album: %s\n", current_song->Album);
            printf("Genre: %s\n", current_song->Genre);

            if (current_song->Length.seconds > 9)
            {
                printf("TIME: %d:%d\n", current_song->Length.minutes, current_song->Length.seconds);
            }
            else
            {
                printf("TIME: %d:0%d\n", current_song->Length.minutes, current_song->Length.seconds);
            }
            printf("NUM PLAYS: %d\n", current_song->times_played);
            printf("RATING: %d\n\n", current_song->Rating);

            current_song = current_song->pNext;

        }
    }
}

void store(struct node** pHead, FILE* infile)
{
    struct record* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pNext != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Artist, current->Album, current->Song, current->Genre, current->Length.minutes, current->Length.seconds, current->times_played, current->Rating);

        current = current->pPrev;
    }
}

void edit(struct record* head)
{
    struct record* current = head;
    int choice = 0;
    char search[50];
    char edit[50];
    int temp = 0;
    printf("Enter the artist to search: ");

    fgets(search, 50, stdin);


    while (current != NULL & choice == 0)
    {

        if (strcmp(search, current->Artist) == 10)
        {

            printf("What do you want to edit?\n");
            printf("1) Artist\n2) Album\n3) Song\n4) Genre\n5) Length\n6) Number of plays\n7) Rating\n");
            scanf(" %d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter the new artist: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Artist, edit);

                printf("The new artist is %s\n", current->Artist);
                break;
            case 2:
                printf("Enter the new album: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Album, edit);
                printf("The new album is %s\n", current->Album);
                break;
            case 3:
                printf("Enter the new title: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Song, edit);
                printf("The new Song is %s\n", current->Song);
                break;
            case 4:
                printf("Enter the new genre: ");
                getchar();
                fgets(edit, 50, stdin);
                strcpy(current->Genre, edit);
                printf("The new genre is %s\n", current->Genre);
                break;
            case 5:
                printf("Enter the new number of minutes: ");
                scanf(" %d", &temp);
                current->Length.minutes = temp;
                printf("Enter the new number of seconds: ");
                scanf(" %d", &temp);
                current->Length.seconds = temp;
                break;
            case 6:
                printf("Enter the new number of plays: ");
                scanf(" %d", &temp);
                current->times_played = temp;
                break;
            case 7:
                printf("Enter the new rating: ");
                scanf(" %d", &temp);
                current->Rating = temp;
                break;
            }
            break;

        }
        current = current->pNext;
        choice = 0;
    }
}

void rate(struct record* head)
{
    struct record* cur = head;
    int choice = 0;
    char search_artist[25];

    printf("Enter Artist to Rate");
    getchar();
    fgets(search_artist, 25, stdin);

    while ((cur != NULL) & (choice == 0))
    {
        if (strcmp(search_artist, cur->Artist) == 10)
        {
            int new_rating = 0;
            do
            {
                printf("Enter Your rating for the Song between 1 and 5:");
                scanf("%d", new_rating);
            } while ((new_rating >= 1) & (new_rating <= 5));

            cur->Rating = new_rating;
            printf("The New rating is now: %d", cur->Rating);
            return;

        }
        cur = cur->pNext;
        choice = 0;
    }

}


void play(struct record* pHead)
{
    struct record* pCur = pHead;
    char choice[50];
    int play = 0;

    //Gets song choice
    printf("Enter a song to start with: ");
    getchar();
    fgets(choice, 50, stdin);
    choice[strlen(choice) - 1] = '\0';


    while (pCur != NULL)
    {

        if (strcmp(choice, pCur->Song) == 0)
        {
            int counter = 0;
            while (counter < 5)
            {
                printf("Artist %s", pCur->Artist);
                printf("Album %s", pCur->Album);
                printf("Song %s", pCur->Song);
                printf("Genre %s", pCur->Genre);
                printf("Duration %d:%d", pCur->Length.minutes, pCur->Length.seconds);
                printf("Times Player %d", pCur->times_played);
                printf("Rating %d", pCur->Rating);

                //Sleep function will run for 1 seconds then go into the next count
                Sleep(1000);
                counter++;
            }

            system("clear");
        }
        pCur = pCur->pNext;

    }

}

void shuffle(struct record* pHead)
{
    system("clear");
    int size = 0;
    Record* pCur = pHead;
    while (pCur != NULL)
    {
        pCur = pCur->pNext;
        size++;
    }
    pCur = pHead;
    int* played_songs = (int*)malloc(sizeof(int) * size + 1);
    int count = 1, random = 1, check = 0;
    while (count < size + 1)
    {

        random = (rand() % size) + 1;
        while (played_songs[random] != 0)
        {
            random = (rand() % size) + 1;
        }
        //checks if song has been played and goes onto next sone within the shuffle
        int loops = 1;
        while (loops != random && pCur->pNext != NULL)
        {
            pCur = pCur->pNext;
            loops += 1;
        }

        //Same coding used within Play function

        pCur->times_played += 1;
        int counter = 0;
        while (counter < 5)
        {
            printf("Artist %s", pCur->Artist);
            printf("Album %s", pCur->Album);
            printf("Song %s", pCur->Song);
            printf("Genre %s", pCur->Genre);
            printf("Duration %d:%d", pCur->Length.minutes, pCur->Length.seconds);
            printf("Times Player %d", pCur->times_played);
            printf("Rating %d", pCur->Rating);
            Sleep(1000);
            counter++;
        }

        system("clear");
    }
    system("clear");
    printf("All songs played\n");
    free(played_songs);
}



int insert(Record** pHead, FILE* infile)
{
    Record* newSong = malloc(sizeof(Record));

    getchar();

    char temp[100];
    printf("Please enter the new artist");
    fgets(temp, 100, stdin);
    strcpy(newSong->Artist, temp);


    printf("Please enter the New Album");
    fgets(temp, 100, stdin);
    strcpy(newSong->Album, temp);


    printf("Please enter the New Song Title");
    fgets(temp, 100, stdin);
    strcpy(newSong->Song, temp);


    printf("Please enter the New Genre");
    fgets(temp, 100, stdin);
    strcpy(newSong->Genre, temp);


    int min = 0, sec = 0;
    printf("Please Enter the Amount of Minutes");
    scanf("%d", &min);
    newSong->Length.minutes = min;
    printf("Please Enter the Amount of Seconds");
    scanf("%d", &min);
    newSong->Length.seconds = sec;

    int timesPlayed = 0;
    printf("Please enter how many times you have played the song");
    scanf("%d", &timesPlayed);
    newSong->times_played = timesPlayed;

    int rating = 0;
    printf("Please enter your intial rating");
    scanf("%d", &rating);
    newSong->Rating = rating;

    insert_at_front(newSong, infile);


}

void delete(Record** pHead)
{
    char temp[100];

    printf("Enter Artist to Delete");
    getchar();
    fgets(temp, 100, stdin);

    if (strcmp(temp, (*pHead)->Song) == 10)
    {
        Record* temp = *pHead;
        *pHead = (*pHead)->pNext;
        free(temp);

    }
    else
    {
        printf("Song not Found");
    }


}

void exit(struct node* pHead, FILE* infile)
{

    struct record* current = pHead;

    while (current->pNext != NULL)
    {
        current = current->pNext;
    }

    while (current->pNext != NULL)
    {
        fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d", current->Artist, current->Album, current->Song, current->Genre, current->Length.minutes, current->Length.seconds, current->times_played, current->Rating);

        current = current->pPrev;
    }
}

