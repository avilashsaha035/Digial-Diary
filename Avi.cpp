#include<bits/stdc++.h>
using namespace std;

void info();
void search(char ID[]);
void display();


int main()
{
    while (1) {

        printf("1. Add my today's activity.\n");
        printf("2. Select a day.\n");
        printf("3. Exit.\n");

        int choice;
        cin >> choice;
        switch(choice) {
        case 1:
            info();
            break;

        case 2:
            display();
            break;

        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}


void info() {

    FILE *write;
    write = fopen("info.txt", "a");

    printf("Enter information:\n");
    char date[100], a[100], b[100], c[200], d[200];

    printf("Enter date: ");  scanf("%s", date);
    printf("Event 1: ");     scanf("%s", a);
    printf("Event 2: ");     scanf("%s", b);
    printf("Event 3: ");     scanf("%s", c);
    printf("Event 4: ");     scanf("%s", d);

    fprintf(write, "%s %s %s %s %s\n", date, a, b, c, d);
    printf("Ok. Add the date!\n");
    fclose(write);
}

void display() {
    printf("\n\nDisplaying Information:\n");

    char ID[20];
    printf("Enter a day: ");      scanf("%s", ID);
    search(ID);
}

void search(char ID[]) {
    FILE *read;
    read = fopen("info.txt", "r");

    char date[100], a[100], b[100], c[200], d[200];
    bool flag = true;

    int cnt = 0;
    while(fscanf(read, "%s", date) == 1) {
        fscanf(read, "%s", a);
        fscanf(read, "%s", b);
        fscanf(read, "%s", c);
        fscanf(read, "%s", d);

        if (strcmp(ID, date) == 0) {
            printf("%s\n\n\n", date);
            printf("Event 1 : %s\n", a);
            printf("Event 2 : %s\n", b);
            printf("Event 3 : %s\n", c);
            printf("Event 4 : %s\n\n\n", d);

            flag = false;
            break;
        }
    }

    if (flag) {
        printf("NO Events. Please enter your events.\n\n\n");
    }

}




