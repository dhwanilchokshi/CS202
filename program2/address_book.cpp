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

#include "address_book.h"

bst_node::bst_node(): head(NULL), left(NULL), right(NULL) {}


bst_node::bst_node(const bst_node &obj) {}

//bst node destructor calls recursive deallocate function to deallocate the LLL if there is one
bst_node::~bst_node()
{
    if(head)
    {
        deallocate_list(head);
    }         
    if(head)
        head = NULL;
    if(tail)
        tail = NULL;
}

//recursive deallocation of LLL memory
void bst_node::deallocate_list(lll_node *&head)
{
    if(!head)
        return;

    deallocate_list(head->go_next());
    if(head)
    {
        delete head;
        head = NULL;
    }
}

bst_node *& bst_node::go_left(){return left;}

bst_node *& bst_node::go_right(){return right;}

//places the person who is going to be added to address book
void bst_node::place_person(char *first, char *last)
{
   Person.place(first, last); 
}

//compares if last name is less than root
int bst_node::compare_less(char *lastname)
{
    return Person.compare_for_less(lastname);
}

//compares the last name for equality
int bst_node::compare_equal(char *lastname)
{
    return Person.compare_for_equal(lastname);
}

//compares the first and last name for equality, then compares recursively in the LLL
int bst_node::compare_firstLast(char *first, char *last)
{
    if(Person.compare_first_last(first, last))
        return 1;
    else if(head)
    {
        if(search_list(head, first, last))
            return 2;
    }
    return 0;
}

//recursive search of LLL to compare the first and last name in LLL for duplicates
int bst_node::search_list(lll_node *head, char *first, char *last)
{
    if(!head)
        return 0;

    if(head->compare_firstLast(first, last))
        return 1;

    return search_list(head->go_next(), first, last);
}

//calls the function which creates the LLL for duplicates
int bst_node::create_linkedList(char *first, char *last)
{
    return create_linkedList(head, first, last); 
}

//functions creates the LLL for each duplicate in the address book by appending tail pointer
int bst_node::create_linkedList(lll_node *&head, char *first, char *last)
{
    if(!head)
    {
        head = new lll_node;
        head->place_duplicate(first, last);
        head->go_next() = NULL;
        tail = head;
        return 1;
    }
    else
    {
        tail->go_next() = new lll_node;
        tail = tail->go_next();
        tail->place_duplicate(first, last);
        tail->go_next() = NULL;
        return 1;
    }
}

//displays the person name and their text, goes to check if duplicates, and if there are then it
//displays their info as well
void bst_node::display_cont()
{
    Person.display_all();
    Person.display_texts();
    if(head)
    {
        display_duplicate_contact(head);
    }
}

//displays the info of duplicate people in the LLL
void bst_node::display_duplicate_contact(lll_node *head)
{
    if(!head)
        return;

    head->display_duplicate();
    display_duplicate_contact(head->go_next());
}

//delivers the message
void bst_node::deliver(char *message)
{
   Person.send(message); 
}

//delivers the person if the person is a duplicate in LLL
int bst_node::deliver_to_list(char *first, char *last, char *message)
{
    if(!head)
        return 0;

    return deliver_to_list(head, first, last, message);
}

//recursive function to deliver the message in LLL for duplicate people
int bst_node::deliver_to_list(lll_node *head, char *first, char *last, char *message)
{
    if(!head)
        return 0;

    if(head->compare_firstLast(first, last))
    {
        head->add_message_duplicate(message);
        return 1;
    }
    return deliver_to_list(head->go_next(), first, last, message);
}

//deletes the text of a person in bst
int bst_node::delete_text()
{
    if(Person.deleteText())
        return 1;

    else
        return 0;
}

//calls recursive function to delete the text of duplicates in LLL
int bst_node::delete_from_list(char *first, char *last)
{
    if(!head)
        return 0;

    return delete_from_list(head, first, last);
}

//recursive function which goes through and deletes the text for matched people in duplicate list of LLL
int bst_node::delete_from_list(lll_node *head, char *first, char *last)
{
    if(!head)
        return 0;

    if(head->compare_firstLast(first, last))
    {
        if(head->delete_message_duplicate())
            return 1;
        else
            return 0;
    }
    return delete_from_list(head->go_next(), first, last);
}

//checks if there is head, if there is, it calls delete to delete linear linked list when user wants to
//delete a form of his/her communication, or address book
int bst_node::check_linear()
{
    if(!head)
        return 0;

    check_linear(head);
    if(head)
        head = NULL;
    if(tail)
        tail = NULL;
    return 1;
}

//recursive delete of the LLL
int bst_node::check_linear(lll_node *&head)
{
    if(!head)
        return 0;

    check_linear(head->go_next());
    if(head)
    {
        delete head;
        head = NULL;
    }
    return 1;
}

address_book::address_book(): root(NULL) {}

address_book::address_book(const address_book& obj){}

//calls recursive deallocation of address book
address_book::~address_book() 
{
    deallocate(root);
    if(root)
        root = NULL;
}

//recursive goes through and deletes all the node of bst, it calls destructor of BST node to 
//go through and delete the LLL at each node before deleting the node.
void address_book::deallocate(bst_node *&root)
{
    if(!root)
        return;

    deallocate(root->go_left());
    deallocate(root->go_right());
    if(root)
    {
        root->~bst_node();
        delete root;
        root = NULL;
    }

}

//calls the recursive function which adds the person to the address book bst
int address_book::add_contact(char *f_name, char *l_name)
{
    if(!f_name && !l_name)
        return 0;

    return add_contact(root, f_name, l_name);
}

//recursive function which checks the data and adds in bst respectively.
//if data is duplicate, it creates a linear linked list and saves data in there
int address_book::add_contact(bst_node *&root, char *first, char *last)
{
    if(!root)
    {
        root = new bst_node;
        root->place_person(first, last);
        root->go_left() = root->go_right() = NULL;
        return 1;
    }

    if(root->compare_equal(last))
    {
       root->create_linkedList(first, last); 
       return 1;
    }
   
    if(root->compare_less(last))
        return add_contact(root->go_left(), first, last);
    
    else
        return add_contact(root->go_right(), first, last);
}

//calls the recursive display of address book
int address_book::display_addressBook()
{
    if(!root)
        return 0;

    display_addressBook(root);
    return 1;
}

//recursively displays address book in alphabetical order
int address_book::display_addressBook(bst_node *root)
{
    if(!root)
        return 0;

    display_addressBook(root->go_left());
    root->display_cont();
    display_addressBook(root->go_right());

return 1;
}

//calls the recursive search to search the person in the address book
int address_book::search_person(char *first, char *last)
{
    if(!root)
        return 0;

    return search_person(root, first, last);
}

//recursively goes through and compares the first and last name, if match is seen it returns 1
int address_book::search_person(bst_node *root, char *first, char *last)
{
    if(!root)
        return 0;

    if(root->compare_firstLast(first, last))
        return 1;

    if(root->compare_less(last))
        return search_person(root->go_left(), first, last);

    else
        return search_person(root->go_right(), first, last);

}

//calls the recursive function which delivers message to person of choice
int address_book::deliver_message(char *First, char *Last, char *message)
{
    if(!root)
        return 0;

    return deliver_message(root, First, Last, message);
}

//recursive function goes through and once the person to send text to is found, it delivers the text,
//also searches the duplicate list, if message is to be sent to a duplicate person
int address_book::deliver_message(bst_node *root, char *First, char *Last, char *message)
{
    if(!root)
        return 0;

    if(root->compare_firstLast(First, Last) == 1)
    {
        root->deliver(message); 
        return 1;
    }

    if(root->compare_firstLast(First, Last) == 2)
    {
        root->deliver_to_list(First, Last, message);
        return 1;
    }

    if(root->compare_less(Last))
        return deliver_message(root->go_left(), First, Last, message);

    else
        return deliver_message(root->go_right(), First, Last, message);
}

//calls the recursive function which deletes message for a person
int address_book::delete_message(char *first, char *last)
{
    if(!root)
        return 0;

    return delete_message(root, first, last);
}

//recursive function which checks the bst and lll to see where the person is.
//once the person is found, it deletes their message
int address_book::delete_message(bst_node *root, char *first, char *last)
{
    if(!root)
        return 0;

    if(root->compare_firstLast(first, last) == 1)
    {
        if(root->delete_text())
            return 1;

        else
            return 0;
    }

    if(root->compare_firstLast(first, last) == 2)
    {
        if(root->delete_from_list(first, last))
            return 1;

        else
            return 0;
    }
    
    if(root->compare_less(last))
        return delete_message(root->go_left(), first, last);

    else
        return delete_message(root->go_right(), first, last);
}

//calls recursive function to delete the whole address book
int address_book::delete_whole_book()
{
    if(!root)
        return 0;

    return delete_whole_book(root);
}

//recursive function goes throught and deletes the whole address books but checks before
//if there is linear linked list of duplicates to delete
int address_book::delete_whole_book(bst_node *& root)
{
    if(!root)
        return 0;

    delete_whole_book(root->go_left());
    delete_whole_book(root->go_right());
    if(root)
    {
        root->check_linear();
        delete root;
        root = NULL;
    }
    return 1;
}
