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

#include "forms.h"

cll_node::cll_node(): communicate(NULL), communication_identifier(0), next(NULL) 
{

}

cll_node::cll_node(const cll_node &obj)
{

}
       
//deletes the communication pointer which is set in each node
cll_node::~cll_node() 
{
    if(communicate)
    {
        delete communicate;
        communicate = NULL;
    }
}

cll_node *& cll_node::go_next(){return next;}

//sets the abstract base class pointer to point to derived class object for use of dynamic binding
//sets the communication identifier to recognize the account being used
void cll_node::set_account(int choice)
{
    if(choice == 1)
    {
       communicate = new facebook;
       communication_identifier = choice;
    }
    else if(choice == 2)
    {
        communicate = new text;
        communication_identifier = choice;
    }
    else if(choice == 3)
    {
        communicate = new email;
        communication_identifier = choice;
    }
    else if(choice == 4)
    {
        communicate = new tinder;
        communication_identifier = choice;
    }
}

//gets the identifier which identifies the type of account in each node
int cll_node::get_identifier() 
{
    if(this && this->communication_identifier) 
        return this->communication_identifier;
    else
        return 0;
}

//sets the person by calling abstract base class function which calls address book function
void cll_node::set_person(char *first, char *last)
{
    communicate->add_person(first, last); 
}

//displays the address book through the abstract base class
int cll_node::display_contacts()
{
    return communicate->display_people();
}

//sends message
int cll_node::message()
{
    communicate->sendMessage();
    return 1;
}

//deletes message
int cll_node::delete_m()
{
    communicate->deleteMessage();
    return 1;
}

//deletes the address book for a communication method
int cll_node::delete_address_book()
{
    return communicate->delete_book();
}

//deallocates the whole tree once program use is done
void cll_node::call_communicate_delete()
{
    communicate->deallocate_tree();
}

void cll_node::share()
{
    facebook *ptr = dynamic_cast<facebook *>(communicate);
    if(ptr)
    {
        ptr->share_pic();
    }
}

CLL::CLL(): rear(NULL) {}

CLL::CLL(const CLL& obj) {}

//cll destructor calls recursive delete of all node
CLL::~CLL() 
{
    if(rear)
    {
        cll_node *temp = rear;
        rear = rear->go_next();
        temp->go_next() = NULL;
        deallocate_circular(rear);
        if(rear)
            rear = NULL; 
    }

}

//recursive deallocation of circular nodes but deallocates address book before deleting 
//circular list nodes
void CLL::deallocate_circular(cll_node *&rear)
{
    if(!rear)
        return;

    deallocate_circular(rear->go_next());
    if(rear)
    {
        rear->call_communicate_delete();
        delete rear;
        rear = NULL;
    }

}

//calls recursive function to add a form of communication for user to use
int CLL::add_communication(int pick)
{
    if(pick == 0)
        return 0;
    
    return add_communication(rear, pick);
}

//recursive function which creates the CLL with users choice of communication
int CLL::add_communication(cll_node *& rear, int pick)
{
    if(!rear)
    {
        rear = new cll_node;
        rear->set_account(pick);
        rear->go_next() = rear;
        return 1;
    }
    
    else if(rear->go_next() == rear)
    {
        cll_node *temp = rear;
        rear->go_next() = new cll_node;
        rear = rear->go_next();
        rear->set_account(pick);
        rear->go_next() = temp;
        return 1;
    }
    
    else
    {
        cll_node *temp = rear->go_next();
        rear->go_next() = new cll_node;
        rear = rear->go_next();
        rear->set_account(pick);
        rear->go_next() = temp;
        return 1;
    }
return 0;
}

//calls the recursive display which displays all accounts user has so far
int CLL::display_accounts()
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return display_accounts(temp);
}

//recursive display of all acounts user has created
int CLL::display_accounts(cll_node *temp)
{
    if(!temp)
        return 0;

    if(temp == rear)
    {
        if(temp->get_identifier() == 1)
            cout << "Facebook" << endl;
        else if(temp->get_identifier() == 2)
            cout << "Text" << endl;
        else if(temp->get_identifier() == 3)
            cout << "Email" << endl;
        else if(temp->get_identifier() == 4)
            cout << "Tinder" << endl;
        return 1;
    }
    if(temp->get_identifier() == 1)
        cout << "Facebook" << endl;
    else if(temp->get_identifier() == 2)
        cout << "Text" << endl;
    else if(temp->get_identifier() == 3)
        cout << "Email" << endl;
    else if(temp->get_identifier() == 4)
        cout << "Tinder" << endl;
        
    return display_accounts(temp->go_next()); 
}

//calls recursive function to add a person to the BST
int CLL::add_person(char *firstname, char *lastname, int acc)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return add_person(temp, firstname, lastname, acc); 
}

//recursive function which adds a person to the BST
int CLL::add_person(cll_node *temp, char *firstname, char *lastname, int acc)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == acc)
        {
            temp->set_person(firstname, lastname);
            return 1;
        }
        else
            return 0;
    }
    if(temp->get_identifier() == acc)
    {
        temp->set_person(firstname, lastname);
        return 1;
    }

    return add_person(temp->go_next(), firstname, lastname, acc);
}

//calls recursive display to display the address book for a form of communication
int CLL::display_book(int pick)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return display_book(temp, pick);
}

//recursive function which goes through and displays the address book
int CLL::display_book(cll_node *temp, int pick)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == pick)
        {
            if(temp->display_contacts())
                return 1;
        }
        return 0;
    }
    if(temp->get_identifier() == pick)
    {
        if(temp->display_contacts())
            return 1;
        else
            return 0;
    }
    return display_book(temp->go_next(), pick);

}

//calls recursive function which goes through and sends a message from a communication which user has picked
int CLL::send_message(int pick)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return send_message(temp, pick);
}

//recursive function which sends the message through the communication platform of user's choice
int CLL::send_message(cll_node *temp, int pick)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == pick)
        {
                temp->message();
                return 1;
        }
        return 0;
    }
    if(temp->get_identifier() == pick)
    {
        temp->message();
        return 1;
    }
    return send_message(temp->go_next(), pick); 
}

//calls the recursive function which deletes a message for user on specific platform
int CLL::delete_message(int pick)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return delete_message(temp, pick);

}

//recursive function which goes through and deletes a message for user on a specific platform
int CLL::delete_message(cll_node *temp, int pick)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == pick)
        {
            temp->delete_m();
            return 1;
        }
        return 0;
    }
    if(temp->get_identifier() == pick)
    {
        temp->delete_m();
        return 1;
    }
    return delete_message(temp->go_next(), pick);
}

//deletes a form of communication for user
//this is a wrapper function which takes care if the node to be deleted is the first node
//or if there is only one node. if neither of these criteria is met, it calls the recursive function
//which looks for the node to delete
int CLL::delete_form(int pick)
{
    if(!rear)
    {
        return 0;
    }

    if(rear->go_next() == rear)
    {
        if(rear->get_identifier() == pick)
        {
            if(rear->delete_address_book())
                cout << "Address book has been deleted for communication!" << endl;
            delete rear;
            rear = NULL;
            return 1;
        }
        else
            return 0;
    }

    cll_node *temp = rear->go_next();

    if(temp->get_identifier() == pick)
    {
        rear->go_next() = temp->go_next();
        if(temp->delete_address_book())
            cout << "Address book has been delete for communication!" << endl;
        delete temp;
        temp = NULL;
        return 1;
    }

    return delete_form(temp, pick);
}

//recursive function goes through and looks for the node to delete 
int CLL::delete_form(cll_node *&temp, int pick)
{
    if(temp->go_next() == rear)
    {
        if(rear->get_identifier() == pick)
        {
            temp->go_next() = rear->go_next();
            if(rear->delete_address_book())
                cout << "Address book has been deleted for communication!" << endl;
            delete rear;
            rear = NULL;
            rear = temp;
            return 1;
        }
        else if(temp->get_identifier() == pick)
        {
            cll_node *hold2 = temp->go_next();
            cll_node *hold = temp;
            temp = temp->go_next();
            if(temp->delete_address_book())
                cout << "Address book has been deleted for communication!" << endl;
            delete hold;
            hold = NULL;
            temp = hold2;
            return 1;
        }
            return 0;
    }

    else
    {
        if(temp->get_identifier() == pick)
        {
            cll_node *hold2 = temp->go_next();
            cll_node *hold = temp;
            temp = temp->go_next();
            if(temp->delete_address_book())
                cout << "Address book has been deleted for communication!" << endl;
            delete hold;
            hold = NULL;
            temp = hold2;
            //return delete_form(temp, pick);
            return 1;
        }
    }
    return delete_form(temp->go_next(), pick);
   
}

//calls the recursive function which will delete address book for user's choice of platform
int CLL::DeleteAdd(int pick)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return DeleteAdd(temp, pick);
}

//recursive function which deletes the address book for user's choice of communication
int CLL::DeleteAdd(cll_node *temp, int pick)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == pick)
        {
            if(temp->delete_address_book())
            {
                return 1;
            }
        }
        return 0;
    }
    if(temp->get_identifier() == pick)
    {
        if(temp->delete_address_book())
        {
            return 1;
        }
    }
    return DeleteAdd(temp->go_next(), pick);
}

int CLL::share_photo(int pick)
{
    if(!rear)
        return 0;

    cll_node *temp = rear->go_next();
    return share_photo(temp, pick);
}

int CLL::share_photo(cll_node *temp, int pick)
{
    if(temp == rear)
    {
        if(temp->get_identifier() == pick)
        {
            temp->share();
            return 1;
        }
        return 0;
    }
    if(temp->get_identifier() == pick)
    {
        temp->share();
        return 1;
    }
    return share_photo(temp->go_next(), pick);
}
