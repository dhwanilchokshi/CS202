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

//this .h file takes care of the "hub" class which has 4 classes derived from it. Main use is to use it for dynamic binding

#include "address_book.h"

//communication is the "hub" abstract base class which contains virtual functions for dynamic binding to take place
//the derived class are facebook, text, email, and tinder
class communications
{
    public:
        communications();           
        virtual ~communications();
        void add_person(char *, char *);                //calls the addressbook function to add person to the address book
        int display_people();                          //displays the people in the address book
        void deallocate_tree();                         //deallocates the tree when the use of program is over
        int delete_book();                              //deletes the address book for a certain communication
        virtual int sendMessage() = 0;                  //pure virtual function which is self similar in hierarchy to send message
        virtual int deleteMessage() = 0;                //pure virtual function which is self similar to delete a message
    protected:
        address_book book; 

};

class facebook: public communications
{
    public:
        facebook();
        ~facebook();
        int sendMessage();
        int deleteMessage();
        void share_pic();                       //RTTI function which shares a photo for facebook     
    protected:

};

class text: public communications
{
    public:
        text();
        ~text();
        int sendMessage();
        int deleteMessage();

    protected:

};

class email: public communications
{
    public:
        email();
        ~email();
        int sendMessage();
        int deleteMessage();

    protected:

};

class tinder: public communications
{
    public:
        tinder();
        ~tinder();
        int sendMessage();
        int deleteMessage();

    protected:

};
