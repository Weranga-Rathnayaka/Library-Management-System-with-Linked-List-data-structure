/*======================================================================================
DSA Course Work Project - Group - BY : MAHDSE212F-003 | WERANGA RATHNAYAKA
                                       MAHDSE212F-004 | CHANAKA SANJAYA BANDARA
                                       MAHDSE212F-012 | LAKSI SANDEEPANI
======================================================================================*/

#include <iostream>
#include <conio.h>
#include<windows.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

/*======================================================================================
    FUNCTIONS
======================================================================================*/
int MainMenu();
int timeANDdate();
void LoadingBar();

char q=178,g=219,h=258;

/*======================================================================================
    POSITION
======================================================================================*/
int location (int x, int y)
{
    COORD NIBM212F;
    NIBM212F.X=x;
    NIBM212F.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),NIBM212F);
    return 0;
}

/*======================================================================================
    CLASS LIBRARY
======================================================================================*/
class Library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node *next_add;
    };
public:
    Node *head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void Delete();
    void sort();
    void show();
};


/*======================================================================================
    MENU
======================================================================================*/
void Library::menu()
{
p:
    location(60,27);
    system("cls");
    int choice;
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n 1. Insert new record";
    cout<<"\n\n 2. Search new records";
    cout<<"\n\n 3. Update new records";
    cout<<"\n\n 4. Delete new records";
    cout<<"\n\n 5. Show all records";
    cout<<"\n\n 6. Exit";
    cout<<"\n\n ++ Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        Delete();
        break;
    case 5:
        sort();
        show();
        break;
    case 6:

        MainMenu();
        system("cls");
        break;
    default:
        cout<<"\n\n Invalid choice...Press ENTER to please Try Again...";
    }
    getch();
    goto p;
}


/*======================================================================================
    INSERT RECORDS
======================================================================================*/
void Library::insert()
{
    system("cls");
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";
    Node *new_node = new Node;
    cout<<"\n\n Book ID : ";
    cin>>new_node -> id;
    cout<<"\n\n Book Name : ";
    cin>>new_node -> name;
    cout<<"\n\n Author Name : ";
    cin>>new_node -> author;
    cout<<"\n\n Publisher Name : ";
    cin>>new_node -> publisher;
    new_node -> next_add = NULL;
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *ptr = head;
        while(ptr -> next_add != NULL)
        {
            ptr = ptr -> next_add;
        }
        ptr -> next_add = new_node;
    }
    cout<<"\n\n\t\t New Book Inserted Successfully...";
    location(14,40);
    cout<<"Press any key to return BACK...";
}


/*======================================================================================
    SEARCH RECORDS
======================================================================================*/
void Library::search()
{
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";
    if(head == NULL)
    {
        cout<<"\n\n Linked List is Empty...";
    }
    else
    {
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        Node *ptr= head;
        while(ptr != NULL)
        {
            if(t_id == ptr -> id)
            {
                system("cls");
                cout<<"\n\n\t\t======================================\n\n\t\t";
                cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
                cout<<"\n\n\t\t======================================\n\n\t\t";
                cout<<"\n\n Book ID : "<<ptr -> id;
                cout<<"\n\n Book Name : "<<ptr -> name;
                cout<<"\n\n Author Name : "<<ptr -> author;
                cout<<"\n\n Publisher Name : "<<ptr -> publisher;
                found++;
            }
            ptr = ptr -> next_add;
        }
        if(found==0)
        {
            cout<<"\n\n Book ID is Invalid...";
        }

    }

    location(14,40);
    cout<<"Press any key to return BACK...";

}


/*======================================================================================
    UPDATE RECORDS
======================================================================================*/
void Library::update()
{
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";
    if(head == NULL)
    {
        cout<<"\n\n Linked List is Empty...";
    }
    else
    {
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        Node *ptr= head;
        while(ptr != NULL)
        {
            if(t_id == ptr -> id)
            {
                system("cls");
                cout<<"\n\n\t\t======================================\n\n\t\t";
                cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
                cout<<"\n\n\t\t======================================\n\n\t\t";
                cout<<"\n\n Book ID : ";
                cin>>ptr -> id;
                cout<<"\n\n Book Name : ";
                cin>>ptr -> name;
                cout<<"\n\n Author Name : ";
                cin>>ptr -> author;
                cout<<"\n\n Publisher Name : ";
                cin>>ptr -> publisher;
                found++;
                cout<<"\n\n\t\t Update Book Successfully...";
            }

            ptr = ptr -> next_add;

        }
        if(found == 0)
        {
            cout<<"\n\n Book ID is Invalid...";
        }
        location(14,40);
        cout<<"Press any key to return BACK...";
    }
}


/*======================================================================================
    DELETE RECORDS
======================================================================================*/
void Library::Delete()
{
    system("cls");
    int t_id,found=0;
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";
    if(head == NULL)
    {
        cout<<"\n\n Linked List is Empty...";
    }
    else
    {
        cout<<"\n\n Book ID : ";
        cin>>t_id;
        if(t_id == head -> id)
        {
            Node *ptr = head;
            head = head -> next_add;
            delete ptr;
            cout<<"\n\n Delete Book Successfullly...";
        }
        else
        {
            Node *pre = head;
            Node *ptr = head;
            while(ptr != NULL)
            {
                if(t_id == ptr -> id)
                {
                    pre -> next_add = ptr -> next_add;
                    delete ptr;
                    cout<<"\n\n Delete Book Successfully...";
                    found++;
                    break;
                }

                pre = ptr;
                ptr = ptr -> next_add;

            }
            if(found == 0)
            {
                cout<<"\n\n Book ID is Invalid...";

            }
        }
    }
    location(14,40);
    cout<<"Press any key to return BACK...";
}


/*======================================================================================
    SORT RECORDS
======================================================================================*/
void Library::sort()
{
    if(head == NULL)
    {
        system("cls");
        cout<<"\n\n\t\t======================================\n\n\t\t";
        cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
        cout<<"\n\n\t\t======================================\n\n\t\t";
        cout<<"\n\n Linked List is Empty...";
        getch();
        menu();
    }
    int t_id,count=0;
    string t_name,t_author,t_publisher;
    Node *ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next_add;
    }
    for(int i=1; i<=count; i++)
    {
        Node *ptr= head;
        for(int j=1; j<count; j++)
        {
            if(ptr -> id > ptr -> next_add -> id)
            {
                //save data into temporary variables
                t_id = ptr -> id;
                t_name = ptr -> name;
                t_author = ptr -> author;
                t_publisher = ptr -> publisher;
                ptr -> id = ptr -> next_add -> id;
                ptr -> name = ptr -> next_add -> name;
                ptr -> author = ptr -> next_add -> author;
                ptr -> publisher = ptr -> next_add -> publisher;
                //save data into current node
                ptr -> id = ptr -> next_add -> id;
                ptr -> name = ptr -> next_add -> name;
                ptr -> author = ptr -> next_add -> author;
                ptr -> publisher = ptr -> next_add -> publisher;
                //save data into next node
                ptr -> next_add -> id = t_id;
                ptr -> next_add -> name = t_name;
                ptr -> next_add -> author = t_author;
                ptr -> next_add -> publisher = t_publisher;
            }
            ptr = ptr -> next_add;
        }
    }
}


/*======================================================================================
    SHOW RECORDS
======================================================================================*/
void Library::show()
{
    system("cls");
    cout<<"\n\n\t\t======================================\n\n\t\t";
    cout<<"\n\n\t\t==== + LIBRARY MANAGEMENT SYSTEM + ====\n\n\t\t";
    cout<<"\n\n\t\t======================================\n\n\t\t";

    Node *ptr= head;
    while(ptr != NULL)
    {
        cout<<"\n\n Book ID : "<<ptr -> id;
        cout<<"\n\n Book Name : "<<ptr -> name;
        cout<<"\n\n Author Name : "<<ptr -> author;
        cout<<"\n\n Publisher Name : "<<ptr -> publisher;
        cout<<"\n\n =====================================";
        ptr = ptr -> next_add;
    }
    cout<<"\n\n\nPress any key to return BACK...";
}


/*======================================================================================
    DECORATE TOPIC
======================================================================================*/
void DecorateTopic()
{
    system("cls");
    location(67,1);
    timeANDdate();
    location(23,4);
    cout<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<endl;
    //cout<<"\t\t\t====================================================================================================================== "<<endl;
    cout<<"\n\t\t\t                        oo       oooooooo oooooooo oooooooo      oo      oooooooo  oo   oo   "<<endl;
    cout<<"\t\t\t                        oo          oo    o      o oo    oo     o  o     o          oo oo    "<<endl;
    cout<<"\t\t\t                        oo          oo    oooooooo oooooooo    oooooo    oooooooo    oo      "<<endl;
    cout<<"\t\t\t                        oo          oo    o      o oo oo     oo     oo   oo oo       oo      "<<endl;
    cout<<"\t\t\t                        oooooooo oooooooo oooooooo oo    oo oo       oo  oo    oo    oo      "<<endl;
    cout<<"\t\t\t       ========================================================================================================   "<<endl;
    cout<<"\t\t\t       oo       oo     oo     oo      oo     oo     oooooooooo oooooooo oo       oo oooooooo oo     oo oooooooo                "<<endl;
    cout<<"\t\t\t       oo oo oo oo    o  o    oo o    oo    o  o    oo         oo       oo oo oo oo oo       oo o   oo    oo                   "<<endl;
    cout<<"\t\t\t       oo  oo   oo   oooooo   oo  oo  oo   oooooo   oo  oooooo oooooooo oo   oo  oo oooooooo oo  oo oo    oo                   "<<endl;
    cout<<"\t\t\t       oo       oo  oo    oo  oo    o oo  oo    oo  oo  oooo o oo       oo   oo  oo oo       oo   o oo    oo                   "<<endl;
    cout<<"\t\t\t       oo       oo oo      oo oo      oo oo      oo oooooooo o oooooooo oo   oo  oo oooooooo oo     oo    oo                   "<<endl;
    cout<<"\t\t\t       =========================================================================================================   "<<endl;
    cout<<"\t\t\t                              oooooooo oo   oo oooooooo oooooooo oooooooo oo       oo                                    "<<endl;
    cout<<"\t\t\t                              oo        oo oo  oo          oo    oo       oo oo oo oo                                    "<<endl;
    cout<<"\t\t\t                              oooooooo   oo    oooooooo    oo    oooooooo oo  oo   oo                                    "<<endl;
    cout<<"\t\t\t                                    oo   oo          oo    oo    oo       oo  oo   oo                                    "<<endl;
    cout<<"\t\t\t                              oooooooo   oo    oooooooo    oo    oooooooo oo  oo   oo                                    "<<endl;
    cout<<"\t\t\t                              =======================================================  "<<endl;
    cout<<"\t\t\t                                        +++ THE READING CORNER +++"<<endl;
    location(23,25);
    cout<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<h<<endl;
    location(23,5);
    cout<<h<<endl;
    location(23,6);
    cout<<h<<endl;
    location(23,7);
    cout<<h<<endl;
    location(23,8);
    cout<<h<<endl;
    location(23,9);
    cout<<h<<endl;
    location(23,10);
    cout<<h<<endl;
    location(23,11);
    cout<<h<<endl;
    location(23,12);
    cout<<h<<endl;
    location(23,13);
    cout<<h<<endl;
    location(23,14);
    cout<<h<<endl;
    location(23,15);
    cout<<h<<endl;
    location(23,16);
    cout<<h<<endl;
    location(23,17);
    cout<<h<<endl;
    location(23,18);
    cout<<h<<endl;
    location(23,19);
    cout<<h<<endl;
    location(23,20);
    cout<<h<<endl;
    location(23,21);
    cout<<h<<endl;
    location(23,22);
    cout<<h<<endl;
    location(23,23);
    cout<<h<<endl;
    location(23,24);
    cout<<h<<endl;

    location(141,5);
    cout<<h<<endl;
    location(141,6);
    cout<<h<<endl;
    location(141,7);
    cout<<h<<endl;
    location(141,8);
    cout<<h<<endl;
    location(141,9);
    cout<<h<<endl;
    location(141,10);
    cout<<h<<endl;
    location(141,11);
    cout<<h<<endl;
    location(141,12);
    cout<<h<<endl;
    location(141,13);
    cout<<h<<endl;
    location(141,14);
    cout<<h<<endl;
    location(141,15);
    cout<<h<<endl;
    location(141,16);
    cout<<h<<endl;
    location(141,17);
    cout<<h<<endl;
    location(141,18);
    cout<<h<<endl;
    location(141,19);
    cout<<h<<endl;
    location(141,20);
    cout<<h<<endl;
    location(141,21);
    cout<<h<<endl;
    location(141,22);
    cout<<h<<endl;
    location(141,23);
    cout<<h<<endl;
    location(141,24);
    cout<<h<<endl;

}


/*======================================================================================
    ABOUT US
======================================================================================*/
int AboutUs()
{
    system("cls");
    system("color 09");
    DecorateTopic();

    location(14,33);
    cout<<"Address : The Reading Corner,\n\t\t\tNo : 50,\n\t\t\tKumarathunga Mawatha,,\n\t\t\tMatara.\n\n";
    location(14,30);
    cout<<"TP : 0412 225 225\n\n\n\n\n\n\n\n\n";
    location(14,40);
    cout<<"Press any key to return to main menu...";
    getch();
    MainMenu();
}
/*======================================================================================
    MAIN MENU
======================================================================================*/
int MainMenu()
{
    system("cls");
    system("color 0E");
    DecorateTopic();
    Sleep(500);

    location(60,29);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<" MAIN MENU " <<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    location(60,31);
    cout<<g<<g<<g<<g<<q<<" 1. LIBRARY SECTION";
    location(60,33);
    cout<<g<<g<<g<<g<<q<<" 2. ABOUT US ";
    location(60,35);
    cout<<g<<g<<g<<g<<q<<" 0. EXIT";
    location(60,37);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    location(60,40);
    cout<<"Enter your choice: ";

    switch(getch())
    {
    case '1':
        system("color 0B");
        Library();
        break;
    case '2':
        system("color 0C");
        AboutUs();
        break;
    case '0':
        system("cls");
        system("color 0A");
        location(23,7);
        cout<<"Are You sure!!!!\n\t\t\t\tThen Press (y) or (n)...";
        if(getch()=='y' | getch()=='Y')
        {
            system("cls");
            location(20,6);
            cout<<"PROGRAMMERS....";
            location(20,9);
            cout<<"MAHDSE212F-004     | CHANAKA SANJAYA BANDARA\n\n";
            location(20,10);
            cout<<"MAHDSE212F-003     | WERANGA RATHNAYAKA\n\n";
            location(20,11);
            cout<<"MAHDSE212F-012     | LAKSI SANDEEPANI\n\n";
            Sleep(1000);
            location(20,15);
            cout<<"...................THANK YOU...................";
            location(50,23);
            cout<<"Exiting in 10 second...........";
            Sleep(10000);
            system("cls");
            exit(0);
        }
        else
        {
            MainMenu();
            system("cls");
        }

    default :
        system("cls");
        location(20,5);
        cout<<"\aWrong Entry!!\n\n\t\t\tPlease re-entered correct option";
        getch();
        system("cls");
        MainMenu();
        break;
    }
    return 0;
}


/*======================================================================================
    DATE AND TIME
======================================================================================*/
int timeANDdate()
{
    time_t t;
    t=time(NULL);
    cout<<asctime(localtime(&t));
    return 0;
}

/*======================================================================================
    LOADING BAR
======================================================================================*/
void LoadingBar()
{
    system("color 0A");
    location(67,1);
    timeANDdate();

    cout<<"\n\t\t\t\t\t\t==========================================================";
    char des=219;
    location(65,21);
    cout<<"Loading...";
    for(int j=0; j<=100; j++)
    {

        location(65,23);
        cout<<j<<"%"<<endl;
        location(70,23);


        for(int i=1; i<=j; i++)
        {

            if(i%3==0)
            {
                cout<<des;
            }
        }
        cout<<endl;
        Sleep(30);
    }
    Sleep(1000);
}


/*======================================================================================
    MAIN
======================================================================================*/
int main()
{
    LoadingBar();
    MainMenu();
    Library obj;
    obj.menu();
}
