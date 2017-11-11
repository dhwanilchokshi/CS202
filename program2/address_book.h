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

//this .h file takes care of the address book which creates a BST of people that are in a specific address book
#include "person.h"

//BST node takes care of creating the linked list for duplicate data, placing a person in an
//address book, and displaying the necessary data for the address book.
class bst_node
{
    public:
        bst_node();
        bst_node(const bst_node &obj);
        ~bst_node();
        bst_node *& go_left();
        bst_node *& go_right();
        void place_person(char *, char *);                  //places the person in the address book for a certain social platform
        int compare_less(char *);                           //compares the last name, if less then adds to left of root
        int compare_equal(char *);                          //compares the last name, if equal then it knows to add to the LLL
        int compare_firstLast(char *, char *);              //compares the first and last name to see exactly who to send message to
        int create_linkedList(char *, char *);              //creates the linked list when there is a duplicate name in BST node
        void display_cont();                                //displays the contacts which is the address book for communication
        void display_duplicate_contact();                   //displays the duplicate contacts which are in the LLL
        void deliver(char *);                               //delivers the message to a person in the address book
        int deliver_to_list(char *, char *, char *);        //delivers the message to a person if they are duplicate in LLL
        int delete_text();                                  //deletes the text message sent to a person in the BST
        int delete_from_list(char *, char *);               //deletes the text message sent to a person if the person was a duplicate in LLL 
        int check_linear();                                 //checks the linear list if there exists duplicates for deletion
    protected:
        person Person;                                      //every BST node has a person who has a name and their text sent to them by user
        lll_node *head;                                     //head pointer for LLL for when there is a duplicate person 
        lll_node *tail;                                     //tail pointer for LLL to append at the end of the LLL
        bst_node *left;
        bst_node *right;
        //private function to keep the pointers to data structure hidden for recursion
    private:
        int create_linkedList(lll_node *&, char *, char *);             
        void display_duplicate_contact(lll_node *);                     
        int search_list(lll_node *, char *, char *);        
        int deliver_to_list(lll_node *, char *, char *, char *);
        int delete_from_list(lll_node *, char *, char *);
        int check_linear(lll_node *&);
        void deallocate_list(lll_node *&);                  //deallocates the list
};

//address book handles the root pointer so it is responsible for creating and adding to the BST
//also it has shared functionality with the bst node class above for searching, delivering message, deleting messages etc.
class address_book
{
    public:
        address_book();
        address_book(const address_book&);
        ~address_book();
        int add_contact(char *, char *);                            //adds a contact to the BST, for a form of communication
        int display_addressBook();                                  //display the whole address book for a certain form of communication
        int search_person(char *, char *);                          //searched for a specific person by last name and first name
        int deliver_message(char *, char *, char *);                //delivers the message to the specific person
        int delete_message(char *, char *);                         //deletes message the user has sent to specific people
        int delete_whole_book();                                    //deletes the whole address book for a certain communication
    protected:
        bst_node *root;

    //private functions to keep pointers to data structures hidden and for recursion
    private:
        int add_contact(bst_node *&, char *, char *);
        int display_addressBook(bst_node *);
        int search_person(bst_node *, char *, char *);
        int deliver_message(bst_node *, char *, char *, char *);
        int delete_message(bst_node *, char *, char *);
        int delete_whole_book(bst_node *&);
        void deallocate(bst_node *&);                           //deallocates the whole bst in the end
};
