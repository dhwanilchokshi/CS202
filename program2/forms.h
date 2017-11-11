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

//this .h file has direct interaction with main, and is used to create the circular list of nodes which will hold the 
//communication and abstract base class pointers to derived classes for dynamic binding to take place.
#include "communication.h"

//cll node class is responsible for holding a pointer to the abstract base class to ensure that every node 
//is able to point to a different derived class object, it has a communication identifier which is the pick
//the user selects from main to make, delete, or access a certain account
class cll_node
{
    public:
        cll_node();
        ~cll_node();
        cll_node *& go_next();
        cll_node(const cll_node &obj);
        void set_account(int);                                  //sets the account of user using base class to point to derived object
        int get_identifier();                                   //returns the identifier for comparision in CLL class below
        void set_person(char *, char *);                        //sets the person in address book
        int display_contacts();                                //displays the address book
        int message();                                          //uses dynamic binding to call send message function for a specific communication
        int delete_m();                                         //uses dynamic binding to call delete message function
        int delete_address_book();                              //deletes the address book for a certain communication
        void call_communicate_delete();                         //calls the abstract class delete for destructor purposes
        void share();
    protected:
        communications *communicate;                            //abstract base class pointer
        int communication_identifier;                           //identifies the sort of communication user has picked from main
        cll_node *next;     
};

//CLL has direct connection to main. Is responsible for starting all the other class functions to do the job
class CLL
{
    public:
        CLL();
        CLL(const CLL&);
        ~CLL();
        int add_communication(int);                                 //adds a form of communication to the CLL
        int display_accounts();                                     //displays the accounts created so far by the user
        int add_person(char *, char *, int);                        //adds a person to the address book
        int display_book(int);                                      //displays the address book for a certain form of commmunication
        int send_message(int);                                      //sends a message through specific means of communication 
        int delete_message(int);                                    //deletes a message from user's communication they may have sent
        int delete_form(int);                                       //deletes the form of communication user has created
        int DeleteAdd(int);                                         //deletes address book for a certain type of communication
        int share_photo(int);                                       //RTTI function for facebook
    protected:
        cll_node *rear;

    //private class functions to keep pointers hidden and to use recursion
    private:
        int add_communication(cll_node *&, int);
        int display_accounts(cll_node *);
        int add_person(cll_node *, char *, char *, int);
        int display_book(cll_node *, int);
        int send_message(cll_node *, int);
        int delete_message(cll_node *, int);
        int delete_form(cll_node *&, int);
        int DeleteAdd(cll_node *, int);
        int share_photo(cll_node *, int);                       
        void deallocate_circular(cll_node *&);
};
