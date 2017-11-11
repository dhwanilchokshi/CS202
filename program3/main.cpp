/*
Dhwanil Chokshi
CS202
Program 3

        The purpose of this assignment was to use operator overloading with balanced tree and linked list
        to build a program that takes care of application usage and info. I decided to implement the Red Black
        tree since it was the closest to a bst. This program lets to load data about apps from external files 
        and stores it in the tree. Each linked list node has a category, and apps can fit into one of 
        three categories: social, game, and educational. Each category stores app, and the categories are displayed
        based on the highest frequency category first (self organizing list). You can also decide to not load data
        from the external file and enter your own data about the app. You can display the platforms with all apps
        for that platform. Also, you can display the above average apps which are apps for a category that have 
        above average usage/frequency.
 */
#include "lll.h"

int main()
{
    manager interface;

    //temp string vars
    char t_type[SIZE];
    String t_name;
    String t_info;
    String t_date;
    String t_sess;
    int freq;

    int choice;
    char repeat;
        
    cout << "\n\t\t\tWelcome to the application manager!" << endl;
    do
    {
        cout << "\n1 - Read apps from external file." << endl;
        cout << "2 - Enter new application information." << endl;
        cout << "3 - Display platforms and all apps (SORTED: Highest Frequency -> Lowest Frequency)." << endl;
        cout << "4 - Display apps with above average frequency for a platform." << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        //read data from the file
        if(choice == 1)
        {
            if(interface.read_from_file(t_type, t_name, t_info, t_date, t_sess, freq))
                cout << "Apps have been loaded!" << endl;
            else
                cout << "Apps could not be loaded!" << endl;
        }
    
        //get user input about the apps
        else if(choice == 2)
        {
            if(interface.get_user_input(t_type, t_name, t_info, t_date, t_sess, freq))
                cout << "App info has been added!" << endl;
        }

        //displays type of app and app info
        else if(choice == 3)
        {
            if(!interface.display_type())
                cout << "Nothing to display!" << endl;
        }

        //displays the above average frequency apps for a platform
        else if(choice == 4)
        {
            interface.above_average();
        }

        cout << "Return to main menu? (y/n): ";
        cin >> repeat;
        cin.ignore();

    }while(repeat == 'y');

    cout << "Goodbye!" << endl;

return 0;
}
