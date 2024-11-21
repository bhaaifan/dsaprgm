#include<stdio.h>
#include<conio.h>
#include<string.h>

struct records {
    int flag, usn;
    char name[20];
} rec[15];

int hash(int m) {
    int slots = 15;
    int r;
    r = m % slots;
    return r;
}
int main() {
    int  k, usn, loc, i, n, j;
    char name[20];
    FILE *in, *outp;

    printf("\nEnter no of records to read from file: ");
    scanf("%d", &n);

    in = fopen("input.txt", "r");

    if (n <= 15) {
        for (k = 0; k < 15; k++)
            rec[k].flag = 0;

        for (i = 0; i < n; i++) {
            fscanf(in, "%s%d", name, &usn);
            loc = hash(usn);
            printf("\naddress: %d", loc);

            if (rec[loc].flag == 0) {
                strcpy(rec[loc].name, name);
                rec[loc].usn = usn;
                rec[loc].flag = 1;
            } else {
                for (j = loc + 1; j % 15 < 15; j++) {
                    if (rec[j % 15].flag == 0) {
                        strcpy(rec[j % 15].name, name);
                        rec[j % 15].usn = usn;
                        rec[j % 15].flag = 1;
                        break;
                    }
                }
            }
        }

        fclose(in);
        printf("\n\nThe Hash Table Content is: ");
        for (i = 0; i < 15; i++) {
            if (rec[i].flag == 1)
                printf("\n%s     %d ", rec[i].name, rec[i].usn);
            else
                printf("\n##");
        }

        outp = fopen("output.txt", "w");
        for (i = 0; i < 15; i++) {
            if (rec[i].flag == 0)
                fprintf(outp, "\n# | #");
            else
                fprintf(outp, "\n%s | %d ", rec[i].name, rec[i].usn);
        }
        fclose(outp);
    } else {
        printf("\n Please Provide less than 15 Records !! ");
    }
    
    getch();
}
