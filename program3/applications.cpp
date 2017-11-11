#include "applications.h"

applications::applications()
{

}

applications::~applications()
{
}

//set the data into the respective members of the applications class
int applications::add_apps(String &t_name, String &t_info, String &t_date, String &t_sess, int &f)
{
    name_application = t_name;
    information = t_info;
    date = t_date;
    session_length = t_sess;
    usage = f;
    return 1;
}

//display the data
int applications::display_applications()
{
    cout << "\nName: " << name_application;
    cout << "Information: " << information;
    cout << "Date: " << date;
    cout << "Session Length: " << session_length;
    cout << "Frequency Usage: " << usage << endl << endl;
    return 1;
}

//returns the frequency for each type of app,
//used to get the sum of all bst node to determine which category has highest frequency
int applications::get_usage_sum()
{
    return usage;
}
    
//copies the date for when the = is overloaded for the linear linked list and bst
int applications::apps_copy(applications &obj)
{
    name_application = obj.name_application;
    information = obj.information;
    date = obj.date;
    session_length = obj.session_length;
    usage = obj.usage;
    return 1;
}

//uses the overloaded less than operator to check is less than to be able
//to add at the correct spot in the tree
int applications::check(String &t_name)
{
    return t_name < name_application;
}
