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


int main()
{
    CLL social;
    int choice;     //menu choice
    char repeat;    //repeat menu choice
    int comm;       //communication choice

    //4 possible forms of communication 
    //recommend only having one of each
    cout << "\nYou can have 4 forms of communication: " << endl;
    cout << "\t1)Facebook" << endl;
    cout << "\t2)Text" << endl;
    cout << "\t3)Email" << endl;
    cout << "\t4)Tinder" << endl;
    do
    {   
        cout << "\nMenu:" << endl;
        //recommended to have only one of each type of communication
        cout << "1 - Add a form of communication. (recommended as first action/step)" << endl;
        cout << "2 - Add a person to your address book on specific social platform." << endl;
        //will replace the message previously sent to the person. Person can only recieve a message at a time.
        cout << "3 - Send a message to another person through a social platform account." << endl;
        cout << "4 - Delete a message you sent to a person from your social platform account." << endl;
        cout << "5 - View your social media accounts created so far." << endl;
        cout << "6 - View your address book/text sent to people for specific account." << endl;
        cout << "7 - Delete one of your social media platforms you have created." << endl;
        cout << "8 - Delete your address book for one of you social media platform." << endl;
        //for RTTI, make sure to have a facebook account to use this.
        cout << "9 - Upload a picture to facebook." << endl;
        cout << "Choice (1-8): ";
        cin >> choice;
        cin.ignore();

        if(choice == 1)
        {
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "From the list above, which sort of communication would you like to add: ";
            cin >> comm;
            cin.ignore();
        
            if(social.add_communication(comm))
                cout << "Your account of choice is set up!" << endl;
            else
                cout << "Your account of choice could not be set up!" << endl;
        }

        else if(choice == 2)
        {
            char first[SIZE];
            char last[SIZE];

            cout << "What is the first name: ";
            cin.get(first, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "What is the last name: ";
            cin.get(last, SIZE, '\n');
            cin.ignore(100, '\n');
            
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "To which form of communication do you want to add them: ";
            cin >> comm;
            cin.ignore();

            if(social.add_person(first, last, comm))
                cout << first << " " << last << " has been added to your address book!" << endl; 

            else
                cout << first << " " << last << " could not be added to your address book!" << endl;
        }

        else if(choice == 3)
        {
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "On which account do you want to send a message from: ";
            cin >> comm;
            cin.ignore();

            social.send_message(comm);
        }

        else if(choice == 4)
        {
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "One which account do you want to delete a message from: ";
            cin >> comm;
            cin.ignore();

            social.delete_message(comm);
        }

        else if(choice == 5)
        {
            cout << "Here are your accounts: " << endl;
            if(!social.display_accounts())
                cout << "\nNo accounts to display!" << endl;

        }

        else if(choice == 6)
        {
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "For which form of communication would you like to view you address book: ";
            cin >> comm;
            cin.ignore();
        
            if(!social.display_book(comm))
                cout << "No address book to display!" << endl;
        }

        else if(choice == 7)
        {
            cout << "Your accounts so far: " << endl;
            if(!social.display_accounts())
            {
                cout << "\nNo accounts to display!" << endl;
            }

            else
            {
                cout << "\nAccount choices: " << endl;
                cout << "1)Facebook" << endl;
                cout << "2)Text" << endl;
                cout << "3)Email" << endl;
                cout << "4)Tinder" << endl;
            
                cout << "Pick the number of which communication to delete: ";
                cin >> comm;
                cin.ignore();
                
                if(!social.delete_form(comm))
                    cout << "Could not be deleted!" << endl;
                else
                    cout << "Account has been deleted!" << endl;
            }
        }

        else if(choice == 8)
        {
            cout << "\nAccount choices: " << endl;
            cout << "1)Facebook" << endl;
            cout << "2)Text" << endl;
            cout << "3)Email" << endl;
            cout << "4)Tinder" << endl;
            
            cout << "For which form of communication would you like to delete the address book: ";
            cin >> comm;
            cin.ignore();

            if(!social.DeleteAdd(comm))
                cout << "Could not empty address book for communication of your choice!" << endl;

            else
                cout << "Address book for communication has been emptied!" << endl;
        }
        //uses RTTI to call facebook unique function
        else if(choice == 9)
        {
            if(!social.share_photo(1))
                cout << "The photo could not be sent!" << endl;
        }
        
        cout << "Again? (y/n): ";
        cin >> repeat;
        cin.ignore();

    }while(repeat == 'y');

return 0;
}
