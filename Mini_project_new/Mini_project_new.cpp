#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>		// for using roundf()		
#include <windows.h>  // for using Sleep()

using namespace std;

int return_scanf;
char return_getchar;

typedef struct student
{
    char name[50];
    char id[15];
    short year;
    char address[80];
    char faculity[20];
    char major[20];
    float entry;
    float accumulation;
}student; // struct for information of one student

typedef struct node
{
    student info;
    node* next; // pointer which point to the previous element of the list
}node; // struct for one element in the list

node* top = NULL; // set the bottom of the list 

void f_showdata(node* node);
void f_display();
void f_push();
void f_pop();
void f_clear();
void f_thetop();
void f_searchName(char* name);
void f_searchid(char* id);
void f_delenter(char s[]);
void f_redundant(char s[]);	// declaration for all the functions 
void f_firstupper(char s[]);
void f_bubblesortlistid();
void f_bubblesortlistname();
void f_removerandomid(char* s);
void f_removerandomname(char* s);
void f_readcsvfile();
void f_exportfilecsv();
void f_scrollingtext(const char* s);
void f_reverselist();
void f_modifyname(char* name);
void f_modifying(node* temp);

int main()
{
    int c;
    char* s;
    do
    {
        system("cls");     // clear the console for easier input
        printf("***************************************************************************\n");
        printf("**\t                                                                 **\n");
        printf("**\t      STUDENT MANAGEMENT MENU                                    **\n");
        printf("**\t                                                                 **\n");
        printf("**\t1. Add a student to the list                                     **\n");
        printf("**\t2. Take the latest infomation of student                         **\n");
        printf("**\t3. Show all infomation in the list                               **\n");
        printf("**\t4. clear the list                                                **\n");	// Menu of the list
        printf("**\t5. Show the latest infomation of the student                     **\n");	// with all the cases below
        printf("**\t6. Find information with ID                                      **\n");
        printf("**\t7. Find information with name                                    **\n");
        printf("**\t8. Modify score for student by name                              **\n");
        printf("**\t9. Delete an element in the list with the ID number              **\n");
        printf("**\t10. Delete an element in the list with the name                  **\n");
        printf("**\t11. Sort information by ID and display all                       **\n");
        printf("**\t12. Sort information by name and display all                     **\n");
        printf("**\t13. Read csvfile and load data to the list (arbitrary filename)  **\n");
        printf("**\t14. Export csv file with data in the list (arbitrary filename)   **\n");
        printf("**\t15. Reverse the list and show the result                         **\n");
        printf("**\t0. Stop the program                                              **\n");
        printf("***************************************************************************\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\n\t\tEnter your choice : ");
        return_scanf = scanf("%d", &c);
        switch (c)
        {
        case 0:
            f_scrollingtext("\n\t\t\t\t***SHUT DOWN***\n\n\t\t\t SEE YOU AGAIN ");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 1:
            f_push();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 2:
            f_pop();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 3:
            f_display();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");						// use switch case for run the menu
            cin.ignore();
            return_getchar = getchar();
            break;
        case 4:
            f_clear();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 5:
            f_thetop();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 6:
            s = (char*)calloc(40, sizeof(char)); // dynamic allocation for using up the memory
            cin.ignore(1, '\n');
            printf("\nEnter student ID to search for information : ");
            fgets(s, 40, stdin);		// get the id for searching
            f_delenter(s);
            f_searchid(s);
            free(s);
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 7:
            s = (char*)calloc(50, sizeof(char)); // dynamic allocation for using up the memory
            cin.ignore(1, '\n');
            printf("\nEnter student's name to search for information : ");
            fgets(s, 50, stdin);		// get the name for searching
            f_delenter(s);
            f_searchName(s);
            free(s);		// free memory for the program
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 8:
            s = (char*)calloc(100, sizeof(char)); // dynamic allocation for using up the memory
            cin.ignore(1, '\n');
            printf("\nEnter student's name to search for modifying : ");
            fgets(s, 100, stdin);		// get the id for searching
            f_delenter(s);
            f_modifyname(s);
            free(s);		// free memory for the program
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 9:
            s = (char*)calloc(40, sizeof(char)); // dynamic allocation for using up the memory
            cin.ignore(1, '\n');
            printf("\nEnter student ID to search for information : ");
            fgets(s, 40, stdin);		// get the id for searching
            f_delenter(s);
            f_removerandomid(s);
            free(s);
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 10:
            s = (char*)calloc(50, sizeof(char)); // dynamic allocation for using up the memory
            cin.ignore(1, '\n');
            printf("\nEnter student's name to search for information : ");
            fgets(s, 50, stdin);		// get the name for searching
            f_delenter(s);
            f_removerandomname(s);
            free(s);		// free memory for the program
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 11:
            f_bubblesortlistid();
            f_display();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 12:
            f_bubblesortlistname();
            f_display();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 13:
            f_readcsvfile();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 14:
            f_exportfilecsv();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        case 15:
            f_reverselist();
            printf("\n\n\t\t\t\t\t\tPress any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;         
        default:
            f_scrollingtext("\n\n\t\t\t***Invalid choice, please reselect another choice***\n");
            printf("\n\n\t\t\t\t\t\t Press any key to continue !");
            cin.ignore();
            return_getchar = getchar();
            break;
        }
    } while (c != 0); // when choose 0 mean stopping running the program
}

void f_redundant(char s[])	// used to remove redundant blank of the string Bui minh chau
{
    size_t length = strlen(s), i, j;
    for (i = 0; i < length; i++)
    {
        if (s[0] == ' ')	// if blank is in the beginning, remove all
        {
            for (i = 0; i < (length - 1); i++)
                s[i] = s[i + 1];	//if having blank, shift the string to the left 
            s[i] = '\0';
            length--;// everytime shifting,decrease the length 
            i = -1; // set i to return for the loop "for", after that i=0 then start again
            continue;
        }
        if (s[i] == ' ' && s[i + 1] == ' ')// check if  2 consecutive blank or more 
        {
            for (j = i; j < (length - 1); j++)
            {
                s[j] = s[j + 1];
            }
            s[j] = '\0';	//shift and decrease the length of string
            length--;
            i--;	// decrease for match with the string when shifting
        }
    }
    if (s[strlen(s) - 1] == ' ')
    {
        s[strlen(s) - 1] = '\0'; // clear the space at the end of the string
    }
}

void f_firstupper(char s[])
{					// make the right format for all the words
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')	// character is not a blank, then lower all character
        {
            s[i] = tolower(s[i]);
            if (s[i - 1] == ' ' || i == 0)
            {
                s[i] = toupper(s[i]); // if before this character is a blank, then upper the character
            }
        }
    }
}

void f_delenter(char s[])
{
    size_t len = strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

void f_scrollingtext(const char* s)
{   					// this function makes the text scrolling on the console   
    int i;
    long long size;
    size = strlen(s);		// here we don't print all the string, we print each character in the string
    for (i = 0; i < size; i++)
    {
        Sleep(5); 			// set delay time for everytime printing a character, here is 5 miliseconds delay
        printf("%c", s[i]);
    }
}

void f_showdata(node* node)
{
    printf("\n - Name : %s", node->info.name);
    printf("\n - ID : %s", node->info.id);
    printf("\n - Year : %d", node->info.year);
    printf("\n - Hometown : %s", node->info.address);
    printf("\n - Faculity : %s", node->info.faculity);
    printf("\n - Major : %s", node->info.major);
    printf("\n - Entry point : %0.2f", node->info.entry);
    printf("\n - accumulated point : %0.2f", node->info.accumulation);
}

void f_push()	// this function is used to push an element into the list
{
    node* nptr; // dynamic allocation for new element
    node* temp;
    int i;
    do
    {
        nptr = (node*)calloc(1, sizeof(node));	// dynamic allocation for new element

        printf("\nEnter name of the student : ");
        cin.ignore(1, '\n');
        fgets(nptr->info.name, 50, stdin);
        f_delenter(nptr->info.name);
        f_redundant(nptr->info.name);
        f_firstupper(nptr->info.name);

        printf("Enter ID number of the student : ");		// get the name and ID of the student
        fgets(nptr->info.id, 15, stdin);
        f_delenter(nptr->info.id);

        temp = top;	// reset the temp
        i = 0;			// reset the count variable
        while (temp != NULL)
        {
            if (strcmp(nptr->info.id, temp->info.id) == 0)
            {
                i++;
            }
            temp = temp->next;					// Scan if the ID already exists or not	
        }										//if yes, type again until the ID is accepted
        if (i != 0)
        {
            f_scrollingtext("\n\t\t\t\tThe ID number already exists, please type again!!!\n");
            free(nptr);
        }
    } while (i != 0);

    printf("Enter the birthyear : ");	
    return_scanf = scanf("%hd", &nptr->info.year);

    printf("Enter address : ");		
    cin.ignore(1, '\n');
    fgets(nptr->info.address, 80, stdin);
    f_delenter(nptr->info.address);

    printf("Enter faculty : ");
    fgets(nptr->info.faculity, 20, stdin);
    f_delenter(nptr->info.faculity);

    printf("Enter major : ");
    fgets(nptr->info.major, 20, stdin);
    f_delenter(nptr->info.major);

    printf("Enter the entry score : ");
    return_scanf = scanf("%f", &nptr->info.entry);
    nptr->info.entry = roundf(nptr->info.entry * 100) / 100; //round to 2 decimal places

    printf("Enter the accumulation score : ");
    return_scanf = scanf("%f", &nptr->info.accumulation);
    nptr->info.accumulation = roundf(nptr->info.accumulation * 100) / 100;  //round to 2 decimal places

    nptr->next = top;
    top = nptr;			// here we set the pointer point to the previous element, then set the top of list to the new element
    printf("\n\nThe information has just been added :\n");
    f_showdata(nptr);
}

void f_display()
{				// this function is used to display all elements in the list from the top to the bottom 
    int i = 1;
    node* temp;
    temp = top;			// information from the top
    if (top == NULL)
    {					// check for the bottom of the list
        printf("\n\n\t\t\t\tlist is empty !!!");
    }
    while (temp != NULL)
    {
        printf("\nMember %d :", i++);
        f_showdata(temp);
        temp = temp->next;	// next element of the list
    }
}

void f_clear()
{
    node* temp;
    temp = top;			// this function is the same with pop, but here we pop until the list is empty
    while (temp != NULL)
    {
        f_pop();
        temp = temp->next;  // check until all the elements are popped
    }
    f_scrollingtext("\n\n\t\t\t\t list has been cleared \n");
}

void f_pop()
{
    //pop an element out of the list
    if (top == NULL)
    {
        //check for the bottom of the list
        f_scrollingtext("\n\n\t\t\t\t List is empty !!!");
    }
    else
    {
        node* temp;
        temp = top;
        top = top->next;// move the top after pop
        // pop the top out of the list with all information of a student
        f_showdata(temp);
        free(temp);// after pop, delete that element
    }
}

void f_thetop()
{
    if (top == NULL)
    {
        //check for NULL of the list
        f_scrollingtext("\n\t\t\tTop is not available for an empty list \n");
    }
    else
    {
        // show the data of the top of the list without delete or add anything
        printf("\nTop of the list is :");
        f_showdata(top);
    }

}

void f_removerandomname(char* s)
{							//remove an element by name, can choose delete or not
    int i = 0, c = 0, p;
    cin.ignore(1, '\n'); // xóa bộ nhớ đệm
    f_redundant(s);
    f_firstupper(s);		// make the information match the format
    node* temp1, * temp2; // khai báo 2 biến con trỏ
    if (top == NULL)
    {					// check for the bottom of the list
        printf("\n\n\t\t\t\t list is empty !!!");
        return;
    }
    for (i = 0; strstr(top->info.name, s) != NULL && c != 2; i++)	// check the top until the information is not on the top 
    {
        printf("\n - Name : %s", top->info.name);
        printf("\n - ID : %s", top->info.id);
        printf("\n - Year : %d", top->info.year);
        printf("\n - Hometown : %s", top->info.address);			//check if match, diaplay all information then ask for deleting or not
        printf("\n - Faculity : %s", top->info.faculity);
        printf("\n - Major : %s", top->info.major);
        printf("\n - Entry point : %0.2f", top->info.entry);
        printf("\n - accumulated point : %0.2f", top->info.accumulation);
        do
        {
            printf("\n\n\t\t\tDo you want to delete this student's information ?\n");
            printf("\t\t\t\t1. Yes\t2. No\nYOUR CHOICE IS : ");
            return_scanf = scanf("%d", &c);
            if (c == 1)							// ask for delete or not
            {
                temp1 = top;
                top = top->next;			// if want to delete, do everything like pop function
                free(temp1);
                printf("\n\n\t\t\t\t The information has been deleted ");
                do
                {
                    printf("\n\n\t\t\t\tDo you want to continue or end of deleting ?\n");
                    printf("\t\t\t\t1. Continue\t2. End of deleting\nYOUR CHOICE IS : ");
                    return_scanf = scanf("%d", &p);
                    if (p == 2)
                        return;
                    if (p != 1 && p != 2)
                        printf("\n\n\t\t\t\t***Invalid choice, please select again ***");
                } while (p != 1);
            }
            else
            {
                if (c != 1 && c != 2)
                {
                    printf("\n\n\t\t\t***Invalid choice, please select again ***");
                }
            }
        } while (c != 1 && c != 2);
    }
    temp1 = top->next;
    temp2 = top;				// now the information we want to find not on the top
    while (temp1 != NULL)
    {
        if (strstr(temp1->info.name, s) != NULL)
        {
            printf("\n - Name : %s", temp1->info.name);
            printf("\n - ID : %s", temp1->info.id);
            printf("\n - Year : %d", temp1->info.year);
            printf("\n - Hometown : %s", temp1->info.address);			//check if match, diaplay all information then ask for deleting or not
            printf("\n - Faculity : %s", temp1->info.faculity);
            printf("\n - Major : %s", temp1->info.major);
            printf("\n - Entry point : %0.2f", temp1->info.entry);
            printf("\n - accumulated point : %0.2f", temp1->info.accumulation);
            i++;
            do
            {
                printf("\n\n\t\t\tDo you want to delete this student's information ?\n");
                printf("\t\t\t\t1. Yes\t2. No\nYOUR CHOICE IS : ");
                return_scanf = scanf("%d", &c);
                switch (c)
                {
                case 1:
                    temp2->next = temp1->next;
                    free(temp1);					// cases for deleting or not 
                    temp1 = temp2;
                    printf("\n\t\t\t\t (T^T) This student has been deleted (T^T) ");
                    do
                    {
                        printf("\n\n\t\t\t\tDo you want to continue or end of deleting ?\n");
                        printf("\t\t\t\t1. Continue\t2. End of deleting\nYOUR CHOICE IS : ");
                        return_scanf = scanf("%d", &p);
                        if (p == 2)
                            return;
                        if (p != 1 && p != 2)
                            printf("\n\n\t\t\t\t***Invalid choice, please select again ***");
                    } while (p != 1);
                    break;
                case 2:
                    break;
                default:
                    printf("\n\n\t\t\t***Invalid choice, please select again ***");
                    break;
                }
            } while (c != 1 && c != 2);

        }
        temp2 = temp1;
        temp1 = temp1->next;				// moving paralelly between temp1 and temp2, temp1 is always below the temp2 in the list	     
    }
    if (i == 0)
        printf("\n\t\t\t\tNo result for the name you want \n");
    else
        printf("\n\n\t\t\t\t This is the end of searching !!!" );
}

void f_removerandomid(char* s)
{							//remove an element by name, can choose delete or not
    int i = 0, c = 0, p;
    cin.ignore(1, '\n'); // xóa bộ nhớ đệm
    f_redundant(s);
    f_firstupper(s);		// make the information match the format
    node* temp1, * temp2; // khai báo 2 biến con trỏ
    if (top == NULL)
    {					// check for the bottom of the list
        printf("\n\n\t\t\t\t list is empty !!!");
        return;
    }
    for (i = 0; strstr(top->info.id, s) != NULL && c != 2; i++)	// check the top until the information is not on the top 
    {
        f_showdata(top);
        do
        {
            printf("\n\n\t\t\tDo you want to delete this student's information ?\n");
            printf("\t\t\t\t1. Yes\t2. No\nYOUR CHOICE IS : ");
            return_scanf = scanf("%d", &c);
            if (c == 1)							// ask for delete or not
            {
                temp1 = top;
                top = top->next;			// if want to delete, do everything like pop function
                free(temp1);
                printf("\n\n\t\t\t\t The information has been deleted !!! ");
                do
                {
                    printf("\n\n\t\t\t\tDo you want to continue or end of deleting ?\n");
                    printf("\t\t\t\t1. Continue\t2. End of deleting\nYOUR CHOICE IS : ");
                    return_scanf = scanf("%d", &p);
                    if (p == 2)
                        return;
                    if (p != 1 && p != 2)
                        printf("\n\n\t\t\t\t***Invalid choice, please select again ***");
                } while (p != 1);
            }
            else
            {
                if (c != 1 && c != 2)
                {
                    printf("\n\n\t\t\t***Invalid choice, please select again ***");
                }
            }
        } while (c != 1 && c != 2);
    }
    temp1 = top->next;
    temp2 = top;				// now the information we want to find not on the top
    while (temp1 != NULL)
    {
        if (strstr(temp1->info.id, s) != NULL)
        {
            f_showdata(temp1);
            i++;
            do
            {
                printf("\n\n\t\t\tDo you want to delete this student's information ?\n");
                printf("\t\t\t\t1. Yes\t2. No\nYOUR CHOICE IS : ");
                return_scanf = scanf("%d", &c);
                switch (c)
                {
                case 1:
                    temp2->next = temp1->next;
                    free(temp1);					// cases for deleting or not 
                    temp1 = temp2;
                    printf("\n\t\t\t\t This student has been deleted !!! ");
                    do
                    {
                        printf("\n\n\t\t\t\tDo you want to continue or end of deleting ?\n");
                        printf("\t\t\t\t1. Continue\t2. End of deleting\nYOUR CHOICE IS : ");
                        return_scanf = scanf("%d", &p);
                        if (p == 2)
                            return;
                        if (p != 1 && p != 2)
                            printf("\n\n\t\t\t\t***Invalid choice, please select again ***");
                    } while (p != 1);
                    break;
                case 2:
                    break;
                default:
                    printf("\n\n\t\t\t***Invalid choice, please select again ***");
                    break;
                }
            } while (c != 1 && c != 2);

        }
        temp2 = temp1;
        temp1 = temp1->next;				// moving paralelly between temp1 and temp2, temp1 is always below the temp2 in the list	     
    }
    if (i == 0)
        printf("\n\t\t\t\tNo result for the ID you want \n");
    else
        printf("\n\n\t\t\t\tThis is the end of searching !!! ");
}

void f_searchName(char* name)
{
    int i = 1;
    cin.ignore(1, '\n');
    f_redundant(name);
    f_firstupper(name);	// correct the format of the name you want to find
    node* temp;
    temp = top;
    while (temp != NULL)
    {
        if (strstr(temp->info.name, name) != NULL) // if the string name exist in the element, then show all information of that element
        {
            printf("\n\nMember %d :", i++);
            f_showdata(temp);
        }
        temp = temp->next;
    }
    if (i == 1)
        printf("\n\t\t\t\t No result for the name you want \n");
    else
        printf("\n\n\t\t\t\t This is the end of searching !!!");
}

void f_searchfaculity(char* faculity)
{
    int i = 1;
    node* temp;
    temp = top;
    while (temp != NULL)
    {
        if (strstr(temp->info.faculity, faculity) != NULL) // if the string faculity exist in the element, then show all information of that element
        {
            printf("\n\nMember %d :", i++);
            f_showdata(temp);
        }
        temp = temp->next;
    }
    if (i == 1)
        printf("\n\t\t\t\t No result for the faclity you want\n");
    else
        printf("\n\n\t\t\t\tThis is the end of searching !!!");
}

void f_searchid(char* id)
{
    int i = 1;
    node* temp;
    temp = top;
    while (temp != NULL)
    {
        if (strstr(temp->info.faculity, id) != NULL) // if the string faculity exist in the element, then show all information of that element
        {
            printf("\n\nMember %d :", i++);
            f_showdata(temp);
        }
        temp = temp->next;
    }
    if (i == 1)
        printf("\n\t\t\t\tNo result for the ID you want\n");
    else
        printf("\n\n\t\t\t\t This is the end of searching !!!");
}

void f_exportfilecsv()
{							// this function is used to take all data in the list then load to csv file
    char* filename;
    filename = (char*)calloc(100, sizeof(char));
    node* temp;
    int i = 1;
    if (top == NULL)
    {					// check for the bottom of the list
        printf("\n\n\t\t\t\t(~_~;) No data to export (~_~;)");
        return;
    }
    temp = top;
    cin.ignore(1, '\n');
    FILE* outfile;
    outfile = fopen("project.csv", "w+");
    fprintf(outfile, "%s, %s, %s, %s, %s, %s, %s\n", "name", "year", "address", "faculity", "major", "entry", "accumulation");
    while (temp != NULL)
    {					// load data to the file until meet the bottom
        fprintf(outfile, "%s, %d, %s, %s, %s, %0.2f, %0.2f\n", temp->info.name, temp->info.year, temp->info.address, temp->info.faculity, temp->info.major, temp->info.entry, temp->info.accumulation);
        temp = temp->next;
    }
    fclose(outfile);
    printf("\n\n\t\t\t\t (^o^) The data has been exported (^o^)");
    free(outfile);
}

void f_bubblesortlistid()
{
    // this function is used to sort the information by ascending id from the top of list to the bottom
    node* bigtemp, * smalltemp;
    student* tempstudent;//temp to store node data
    tempstudent = (student*)calloc(1, sizeof(student));
    bigtemp = top;		// bigtemp start from the top
    while (bigtemp != NULL)
    {
        smalltemp = top;
        while (smalltemp->next != NULL)//compare until the second last element 
        {
            if (strcmp(smalltemp->info.id, smalltemp->next->info.id) > 0) // compare the id 
            {
                memcpy(tempstudent, &smalltemp->info, sizeof(student));
                memcpy(&smalltemp->info, &smalltemp->next->info, sizeof(student)); // swap the data
                memcpy(&smalltemp->next->info, tempstudent, sizeof(student));
            }
            smalltemp = smalltemp->next;    //  next small node
        }
        bigtemp = bigtemp->next;    // next big node
    }
    free(tempstudent); // free the memory
}

void f_bubblesortlistname()
{
    // this function is used to sort the information by ascending name from the top of list to the bottom
    node* bigtemp, * smalltemp;
    student* tempstudent;//temp to store node data
    tempstudent = (student*)calloc(1, sizeof(student));
    bigtemp = top;
    while (bigtemp != NULL)
    {
        smalltemp = top;
        while (smalltemp->next != NULL)//check until the second last element
        {
            // compare the name, if same name -> compare year
            if (strcmp(smalltemp->info.name, smalltemp->next->info.name) > 0 || strcmp(smalltemp->info.name, smalltemp->next->info.name) == 0 && strcmp(smalltemp->info.id, smalltemp->next->info.id) > 0)
            {
                memcpy(tempstudent, &smalltemp->info, sizeof(student));
                memcpy(&smalltemp->info, &smalltemp->next->info, sizeof(student)); // swap the data
                memcpy(&smalltemp->next->info, tempstudent, sizeof(student));
            }
            smalltemp = smalltemp->next;    //  next smallnode
        }
        bigtemp = bigtemp->next;    // next bignode
    }
    free(tempstudent); //free the memory
}

void f_reverselist()
{
    node* temp1, * temp2;
    temp1 = temp2 = NULL;
    if (top == NULL)
    {					// check for the bottom of the list
        f_scrollingtext("\n\n\t\t\t\t(~_~;) list is empty (~_~;)");
        return;
    }
    else
    {
        while (top != NULL)
        {
            temp2 = top->next; //take the node and move it to the front of the top
            top->next = temp1;
            temp1 = top;		// then move the pointer top to the node which has just been moved until the top is the bottom of the old list
            top = temp2;
        }
        top = temp1;		// return the top to the right position
    }
    printf("\nThe list after reversing :\n");	// print the list after reverse
    f_display();
}

void f_readcsvfile()
{					// this function is used to read the csv file and load data to the list
    char* filename;
    filename = (char*)calloc(100, sizeof(char));
    char* content;
    char* line;
    int row = 0, column;
    cin.ignore(1, '\n');
    printf("\nEnter the csvfilename : ");
    fgets(filename, 100, stdin);	// get the filename
    f_delenter(filename);
    FILE* infile;
    fopen_s(&infile, strcat(filename,".csv"), "r");// open file with ".csv" to match the format
    if (infile == NULL)
    {
        f_scrollingtext("\n\t\t\t\tError! File is not available !!!"); // check if the file exists or not
    }
    while (infile != NULL && !feof(infile))
    {
        line = (char*)calloc(1024, sizeof(char));
        fgets(line, 1024, infile);		// take a line in the file until EOF
        if (row > 0 && !feof(infile))
        {
            node* nptr = (node*)calloc(1,sizeof(node));
            column = 1;;
            while ((content = strtok_s(line, ",", &line))) //csv means data separated by a comma so use strtok_s to split the data
            {
                switch (column)// check the column of the data from ordinal number to the scores
                {
                case 1:
                    break;
                case 2:
                    strcpy_s(nptr->info.name, content);
                    f_redundant(nptr->info.name);
                    f_firstupper(nptr->info.name);		//make the name match the format
                    break;
                case 3:
                    strcpy_s(nptr->info.id, content);
                    f_redundant(nptr->info.id);		//remove redundant blank in ID number if exist
                    break;
                case 4:
                    nptr->info.year = (short)strtof(content, NULL); // These steps is like the push function 
                    break;												// 	but here take the data from file and push into 	the list
                case 5:
                    strcpy_s(nptr->info.address, content);
                    break;
                case 6:
                    strcpy_s(nptr->info.faculity, content);
                    break;
                case 7:
                    strcpy_s(nptr->info.major, content);
                    break;
                case 8:
                    nptr->info.entry = strtof(content, NULL);
                    nptr->info.entry = roundf(nptr->info.entry * 100) / 100;
                    break;							// strtof to recognize the number, then round to 2 decimal places
                case 9:
                    nptr->info.accumulation = strtof(content, NULL);
                    nptr->info.accumulation = roundf(nptr->info.accumulation * 100) / 100;
                    break;							// strtof to recognize the number, then round to 2 decimal places		
                }
                column++;
            }
            nptr->next = top;
            top = nptr;
            free(line); // optimize the memory every line			
        }
        row++;
    }
    if (infile != NULL)
    {
        f_scrollingtext("\n\n\t\t\t\t The file has been load to the list ");
        fclose(infile);
    }
    free(filename);
}

void f_modifyname(char* name)
{
    int i = 0, c, p;
    cin.ignore(1, '\n');
    f_redundant(name);
    f_firstupper(name);
    node* temp;
    temp = top;
    while (temp != NULL)
    {
        if (strstr(temp->info.name, name) != NULL)	// check every element from top to bottom
        {
            printf("\nOld information :");
            f_showdata(temp);
            i++;
            do
            {
                printf("\n\n\t\t\tDo you want to modify information for %s ?\n", temp->info.name);
                printf("\t\t\t\t1. Yes\t2. No\nYOUR CHOICE IS : ");
                return_scanf = scanf("%d", &c);
                switch (c)							// ask if you want to modify
                {
                case 1:
                    cin.ignore();
                    f_modifying(temp);
                    f_scrollingtext("\n\n\t\t\t\t The information has been modified successfully ");
                    printf("\nNew information : ");
                    f_showdata(temp);
                    do
                    {
                        printf("\n\n\t\t\t\tDo you want to continue or end of modifying ?\n");
                        printf("\t\t\t\t1. Continue\t2. End of modifying\nYOUR CHOICE IS : ");
                        return_scanf = scanf("%d", &p);						// if there are more than one student, ask for continuing or not
                        if (p == 2)
                            return;
                        if (p != 1 && p != 2)
                            f_scrollingtext("\n\n\t\t\t\t***Invalid choice, please select again ***");
                    } while (p != 1);
                    break;
                case 2:
                    break;
                default:
                    f_scrollingtext("\n\n\t\t\t***Invalid choice, please select again ***");
                    break;
                }
            } while (c != 1 && c != 2);
        }
        temp = temp->next;	// goto next element
    }
    if (i == 0) // if there is no information matching then return no result
        f_scrollingtext("\n\t\t\t\t\t No result for the name \n");
    else
        f_scrollingtext("\n\n\t\t\t\tThis is the end of modifying !");
}

void f_modifying(node* temp)
{
    char c;
    char *str = (char*)calloc(80,sizeof(char));
    do
    {
        printf("\n\n\t\t\tWhich one do you want to modify for %s ?", temp->info.name);
        printf("\n\t\t\t1.Name");
        printf("\n\t\t\t2.ID");
        printf("\n\t\t\t3.Year of birth");
        printf("\n\t\t\t4.Address");
        printf("\n\t\t\t5.Faculty");
        printf("\n\t\t\t6.Major");
        printf("\n\t\t\t7.Entry score");
        printf("\n\t\t\t8.Accumulation score");
        printf("\n\t\t\t0.End of modifying this person");
        printf("\n\n\t\t\tEnter your choice : ");
        return_scanf = scanf("%c", &c);
        switch (c)
        {
        case 0 :
            break;
        case 1 :
            printf("\n\n\t\t Enter new name : ");
            cin.ignore(1, '\n');
            fgets(temp->info.name, 50, stdin);
            f_delenter(temp->info.name);
            f_redundant(temp->info.name);
            f_firstupper(temp->info.name);
            break;
        case 2 :
            printf("\n\n\t\t Enter new id : ");
            cin.ignore(1, '\n');
            fgets(temp->info.id, 15, stdin);
            f_delenter(temp->info.id);
            break;
        case 3 :
            printf("\n\n\t\t Enter new year of birth : ");
            return_scanf = scanf("%hd", &temp->info.year);
            break;
        case 4:
            printf("\n\n\t\t Enter new address : ");
            cin.ignore(1, '\n');
            fgets(temp->info.address, 80, stdin);
            f_delenter(temp->info.address);
            break;
        case 5:
            printf("\n\n\t\t Enter new faculty: ");
            cin.ignore(1, '\n');
            fgets(temp->info.faculity, 20, stdin);
            f_delenter(temp->info.faculity);
            break;
        case 6:
            printf("\n\n\t\t Enter new major : ");
            cin.ignore(1, '\n');
            fgets(temp->info.major, 20, stdin);
            f_delenter(temp->info.major);
            break;
        case 7:
            printf("\n\n\t\t Enter new entry score : ");
            return_scanf = scanf("%f", &temp->info.entry);
            temp->info.entry = roundf(temp->info.entry * 100) / 100;  //round to 2 decimal places
            break;
        case 8:
            printf("\n\n\t\t Enter new accumulation score : ");
            return_scanf = scanf("%f", &temp->info.accumulation);
            temp->info.accumulation = roundf(temp->info.accumulation * 100) / 100;  //round to 2 decimal places
            break;
        default :
            f_scrollingtext("\n\n\t\t\t\t***Invalid choice, please select again ***");
            break;
        }
    } while (c != 0);
    free(str);
}