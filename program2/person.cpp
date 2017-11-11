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

#include "person.h"

//name constructor with an initialization list
name::name(): first_name(NULL), last_name(NULL)
{
}

name::name(const name&){}

//name destructor deallocating the elements which were dynamically allocated
name::~name()
{
    if(first_name)
    {
        delete [] first_name;
        first_name = NULL;
    }

    if(last_name)
    {
        delete [] last_name;
        last_name = NULL;
    }
}

//sets the person first name and last name in the address book
void name::place(char *first, char *last)
{
    first_name = new char[strlen(first) + 1];
    strcpy(first_name, first);

    last_name = new char[strlen(last) + 1];
    strcpy(last_name, last);
}

//sets the first name and last name of duplicate people in the address book
void name::place_repeat(char *first, char *last)
{
    first_name = new char[strlen(first) + 1];
    strcpy(first_name, first);

    last_name = new char[strlen(last) + 1];
    strcpy(last_name, last);
}

//compares if last name is less and root to know which side of bst to add to
int name::compare_for_less(char *lastname)
{
    if(strcmp(lastname, last_name) < 0)
        return 1;
    else
        return 0;
}

//compares the last name for equality to recognize there is a duplicate
int name::compare_for_equal(char *lastname)
{
    if(strcmp(lastname, last_name) == 0)
        return 1;
    else
        return 0;
}

//compares the first and last name for equality... for when you want to deliver
//a message to a special person in the bst or in a LLL
int name::compare_first_last(char *first, char *last)
{
    if(strcmp(first, first_name) == 0 && strcmp(last, last_name) == 0)
        return 1;
    else
        return 0;
}

//display function displays the first and last name
void name::display_all()
{
    cout << "\nFirst name: " << first_name << endl;
    cout << "Last name: " << last_name << endl;
}

person::person(): text_message(NULL){}


person::person(const person& obj) {}
//deletes the memory allocated for the text sent to person
person::~person()
{
    if(text_message)
    {
        delete [] text_message;
        text_message = NULL;
    }
}

//copies and pastes the text message sent to a person
//if there exists a text message in the position already, it removes
//the memory before allocating so we dont have too many allocation
//of memory and loss of memory
void person::send(char *message)
{
    if(text_message)
    {
        delete [] text_message;
        text_message = NULL;
    }

    text_message = new char[strlen(message) + 1];
    strcpy(text_message, message);
}

//adds text message for duplicate people in the address book
void person::add_dupli(char *message)
{
    if(text_message)
    {
        delete [] text_message;
        text_message = NULL;
    }

    text_message = new char[strlen(message) + 1];
    strcpy(text_message, message);
}

//display the text message for the people
void person::display_texts()
{
    if(text_message)
    {
        cout << "Text: " << text_message << endl;
    }
}

//deletes the text message sent to a specific person in the address book
int person::deleteText()
{
    if(text_message)
    {
        delete [] text_message;
        text_message = NULL;
        return 1;
    }
    else
        return 0;
}

//deletes the duplicate text message sent to a specific person who might be
//in the LLL
int person::delete_dupli()
{
    if(text_message)
    {
        delete [] text_message;
        text_message = NULL;
        return 1;
    }
    else
        return 0;
}

lll_node::lll_node(): next(NULL) {}

lll_node::~lll_node()
{
}


lll_node *& lll_node::go_next(){return next;}

//places the duplicate person in the address book by calling the person object "duplicate"
void lll_node::place_duplicate(char *first, char *last)
{
   duplicate.place_repeat(first, last); 
}

//displays the duplicate people in the address book
void lll_node::display_duplicate()
{
    duplicate.display_all();
    duplicate.display_texts();
}

//compares the first and last name for equality and returns 1 if equal
int lll_node::compare_firstLast(char *first, char *last)
{
    return duplicate.compare_first_last(first, last);
}

//adds a message sent to a person in the LLL who is a duplicate
void lll_node::add_message_duplicate(char *message)
{
    duplicate.add_dupli(message);
}

//deletes a message that has been sent to a duplicate person who is in the LLL
int lll_node::delete_message_duplicate()
{
    if(duplicate.delete_dupli())
        return 1;
    else
        return 0;
}
