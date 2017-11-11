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

//this .h file places sets the name of the people that are to be stores in the BST, and stores the name of people who
//are duplicates stored in the Linear Linked List of arrays. It also has a person class derived from name which
//will take care of the text messages which are sent to that duplicate person. This file also has the LLL node
//which is used to create the LLL

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int SIZE = 100;
const int TEXT_SIZE = 150;

//name class is responsible for holding the name and placing the incoming first and last name of people
//who are added to the address book
//it is the parent of person
class name
{
    public:
        name();
        name(const name&);
        ~name();
        void place(char *, char *);                                     //place the person by creating memory and copying it over
        void place_repeat(char *, char *);                              //place the repeated person
        int compare_for_less(char *);                                   //compares last name to add to bst
        int compare_for_equal(char *);                                  //compares last name for equality
        int compare_first_last(char *, char *);                         //compares first and last name to know who to send message to
        void display_all();                                             //displays the first and last name

    protected:
        char *first_name;
        char *last_name;
};

//person class is derived from name class and is responsible for holding the text messages of specific people
//it has functions to add and delete text for people in bst and duplicates in LLL
class person: public name
{
    public:
        person();
        person(const person& obj);
        ~person();
        void send(char *);                                          //saves the message that the user has sent to a person
        void display_texts();                                       //displays the text that have been sent to user
        void add_dupli(char *);                                     //adds the text recieved for a duplicate person
        int deleteText();                                           //delete a text sent to a user
        int delete_dupli();                                         //delete text sent to a person in duplicate list
    
    protected:
        char *text_message;
};

//LLL node to create the duplicates in the node of BST, it has a person object to copy their first and last name,
//and to deal with the text messages sent to people who are duplicates
class lll_node
{
    public:
        lll_node();
        ~lll_node();
        lll_node *& go_next();
        void place_duplicate(char *, char *);                   //places the duplicate person in the LLL
        void display_duplicate();                               //displays the first and last name and text of duplicates
        int compare_firstLast(char *, char *);                  //compares the first and last name of duplicate people for equality
        void add_message_duplicate(char *);                     //adds a message for duplicates
        int delete_message_duplicate();                         //deletes a message for duplicates

    protected:
        person duplicate;                                       //duplicate person for each LLL node
        lll_node *next;
};
