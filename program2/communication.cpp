/*
Dhwanil Chokshi
CS202
Program 2
                        The purpose of this program is to get experience with dynamic binding. In this program
                        I have implemented three data structures -- Circular Linked List of the type of social media
                        platform the user can have, BST of address book for each type of communication the user
                        decides to have, and a Linear Linked List inside each node of the BST to take care of the duplicate
                        names of people added to address book. In this program, you can add a form of communication,
                        add a person to your address book for a certain type of communication you have created,
                        send a message through a specific platform you have created to a specific person, delete a message
                        from your platform that you have sent to a person, view your social media accounts created so far,
                        view your address book for a specific social media account, delete one of the social media accounts,
                        and delete your whole address book for a specific social media account of choice.
*/

#include "communication.h"

communications::communications()
{

}

communications::~communications()
{

}

//calls book add function to add the person to the address book
void communications::add_person(char *firstn, char *lastn)
{
    book.add_contact(firstn, lastn);
}

//calls the book display function to display the people in the book
int communications::display_people()
{
    return book.display_addressBook();
}

//calls the book delete function to delete the whole address book
int communications::delete_book()
{
    return book.delete_whole_book();
}

//calls destructor for BST to go through and delete all nodes
void communications::deallocate_tree()
{
    book.~address_book();
}

facebook::facebook()
{

}

facebook::~facebook()
{

}

void facebook::share_pic()
{
    cout << "\nYour picture has been shared!" << endl;
}
//facebook send message function used through dynamic binding
int facebook::sendMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];
    char message[TEXT_SIZE];

    cout << "Drafting message for facebook!" << endl;
    cout << "\nHere is your address book for facebook: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person to send message to: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of the person to send message to: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    cout << "What is the message: ";
    cin.get(message, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.deliver_message(firstName, lastName, message))
        cout << "Message was sucessfully delivered!" << endl;

return 1;
}

//facebook delete message function used through dynamic binding
int facebook::deleteMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];

    cout << "Delete message for facebook!" << endl;
    cout << "\nHere is you address book for facebook: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person for which to delete message: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of person for which to delete message: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    if(book.delete_message(firstName, lastName))
        cout << "Message was successfully deleted!" << endl;

    else
    {
        cout << "No message was available to delete!" << endl;
        return 0;
    }

return 1;
}

text::text()
{

}
        
text::~text()
{

}

//text send message function used throught dynamic binding
int text::sendMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];
    char message[TEXT_SIZE];

    cout << "Drafting message for text!" << endl;
    cout << "\nHere is your address book for text: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person to send message to: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of the person to send message to: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    cout << "What is the message: ";
    cin.get(message, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.deliver_message(firstName, lastName, message))
        cout << "Message was sucessfully delivered!" << endl;

return 1;
}

//text delete message function used through dynamic binding
int text::deleteMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];

    cout << "Delete message for text!" << endl;
    cout << "\nHere is you address book for text: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person for which to delete message: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of person for which to delete message: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    if(book.delete_message(firstName, lastName))
        cout << "Message was successfully deleted!" << endl;

    else
    {
        cout << "No message was available to delete!" << endl;
        return 0;
    }
return 1;
}

email::email()
{

}

email::~email()
{

}

//sends message for email, used through dynamic binding
int email::sendMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];
    char message[TEXT_SIZE];

    cout << "Drafting message for email!" << endl;
    cout << "\nHere is your address book for email: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person to send message to: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of the person to send message to: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    cout << "What is the message: ";
    cin.get(message, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.deliver_message(firstName, lastName, message))
        cout << "Message was sucessfully delivered!" << endl;

    

return 1;
}

//deletes message for email, used through dynamic binding
int email::deleteMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];

    cout << "Delete message for email!" << endl;
    cout << "\nHere is you address book for email: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person for which to delete message: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of person for which to delete message: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    if(book.delete_message(firstName, lastName))
        cout << "Message was successfully deleted!" << endl;

    else
    {
        cout << "No message was available to delete!" << endl;
        return 0;
    }
return 1;
}

tinder::tinder()
{

}

tinder::~tinder()
{

}

//tinder send message used through dynamic binding
int tinder::sendMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];
    char message[TEXT_SIZE];

    cout << "Drafting message for tinder!" << endl;
    cout << "\nHere is your address book for tinder: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person to send message to: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of the person to send message to: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    cout << "What is the message: ";
    cin.get(message, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.deliver_message(firstName, lastName, message))
        cout << "Message was sucessfully delivered!" << endl;


return 1;
}

//tinder delete message used through dynamic binding
int tinder::deleteMessage()
{
    char firstName[SIZE];
    char lastName[SIZE];

    cout << "Delete message for tinder!" << endl;
    cout << "\nHere is you address book for tinder: " << endl;
    book.display_addressBook();

    cout << "\nFirst name of person for which to delete message: ";
    cin.get(firstName, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Last name of person for which to delete message: ";
    cin.get(lastName, SIZE, '\n');
    cin.ignore(100, '\n');

    if(book.search_person(firstName, lastName))
        cout << "Person was found in your address book!" << endl;

    else
    {
        cout << "Person could not be found in your address book!" << endl;
        return 0;
    }

    if(book.delete_message(firstName, lastName))
        cout << "Message was successfully deleted!" << endl;

    else
    {
        cout << "No message was available to delete!" << endl;
        return 0;
    }

return 1;
}
