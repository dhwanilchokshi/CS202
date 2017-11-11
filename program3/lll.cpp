#include "lll.h"

category::category()
{

}
        
category::~category()
{
}

//sets the type of each linear linked list node to be a platform
int category::set_type(char *type_app)
{
    type = type_app;
    return 1;
}

//displays the type of platform
void category::display()
{
    cout << "TYPE: " << type << endl;
}

//returns the type to check where app should be added for a platform
String &category::get_type()
{
    return type;
}

lll_node::lll_node(): next(NULL), root(NULL)
{

}

//copy constructor used to set root = to obj root -- used when overloading = for LLL
lll_node::lll_node(const lll_node &obj)
{
    root = obj.root;
}

//calls recursive function to deallocate the tree
lll_node::~lll_node()
{
    if(root)
        deallocate_tree(root);
}

//recursive function which deallocates the tree
void lll_node::deallocate_tree(bst_node *&root)
{
    if(!root)
        return;

    deallocate_tree(root->get_left());
    deallocate_tree(root->get_right());
    if(!root->get_left() && !root->get_right())
    {
        delete root;
        root = NULL;
    }
}

lll_node *&lll_node::go_next()
{
    return next;
}

//calls recursive wrapper insert
int lll_node::wrapper_insert(String &t_name, String &t_info, String &t_date, String &t_sess, int &f)
{

    return wrapper_insert(root, NULL, t_name, t_info, t_date, t_sess, f);
}

//adds to the red black tree and calls the function to set the data at each node
//also calls the cases to see if rotation is needed
int lll_node::wrapper_insert(bst_node *&root, bst_node* parent, String &t_name, String &t_info, String &t_date, String &t_sess, int&f)
{
    if(!root)
    {
        root = new bst_node;
        root->add_apps(t_name, t_info, t_date, t_sess, f);
        root->get_left() = root->get_right() = NULL;
        root->set_parent(parent);
        root->set_isred(true);
        return case1(root);
    }

    else if(!root->compare(t_name)) 
        return wrapper_insert(root->get_left(), parent, t_name, t_info, t_date, t_sess, f);

    else
        return wrapper_insert(root->get_right(), parent, t_name, t_info, t_date, t_sess, f);
}

int lll_node::case1(bst_node *root)        // check if root is red
{
    if(!root->get_parent())
    {
        root->set_isred(false);
        return 1;
    }

    else
        return case2(root);
}

int lll_node::case2(bst_node *root)       // check for black parent
{
    if(root->get_parent()->get_isred() == false)
        return 0;
    
    else
        return case3(root);
}

int lll_node::case3(bst_node *root)         // making parent and uncle black
{
    if(root->get_uncle() == root->get_parent())
        root->get_uncle() = root->get_parent()->get_parent()->get_right();

    if(root->get_uncle() != NULL && root->get_uncle()->get_isred() == true)
    {
        root->get_parent()->set_isred(false); 
        root->get_uncle()->set_isred(false); 
        root->get_gparent()->set_isred(true); 
        // check if there's a root
        return case1(root); 
    }

    else
        return case4(root);
}

int lll_node::case4(bst_node *root)       // check case if node added inside
{
    if(root == root->get_parent()->get_right() && root->get_parent() == root->get_parent()->get_parent()->get_left())
    {
        // pass it in for left rotation
        rotate_left(root); 
        
        // child's left
        return case5(root->get_left());
    }
    else
    {
        if(root == root->get_parent()->get_left() && root == root->get_parent()->get_parent()->get_right())
        {
            rotate_right(root); 
            return case5(root->get_right()); 
        }   
    }

    // Use the current to check rotation
    return case5(root);
}

int lll_node::case5(bst_node *root)         // check case if node added outside
{
    root->get_parent()->set_isred(false); 
    root->get_parent()->get_parent()->set_isred(true); 
    // If uncle, rotate right
    if(root == root->get_parent()->get_left()) 
        return rotate_right(root); 
    
    // Else rotate left
    else
        return rotate_left(root); 
}

int lll_node::rotate_left(bst_node *root)     // rotates the tree left
{
    bst_node * temp; 

    // Rotation for case 4
    if(root->get_parent()->get_parent()->get_left() == root->get_parent()) 
    {
        // rotating left logic
        temp = root->get_left(); 
        root->get_left() = root->get_parent(); 
        root->get_parent()->get_right() = temp; 
        root->get_parent() = root->get_gparent(); 
        root->get_left()->get_parent() = root; 
        root->get_parent()->get_left() = root; 
    }
    // Rotation for case 5
    else 
    {
        // If ggp right is a grandparent, set ggp right to 
        // parent
        if(root->get_ggp()->get_right() == root->get_gparent())
            root->get_ggp()->get_right() = root->get_parent(); 
        // else set ggp left to get_parent()
        else
            root->get_ggp()->get_left() = root->get_parent(); 
       
        // rotating left logic
        temp = root->get_parent()->get_left(); 
        root->get_parent()->get_left() = root->get_gparent(); 
        root->get_gparent() = root->get_ggp(); 
        root->get_parent()->get_left()->get_parent() = root->get_parent(); 
        temp->get_parent() = root->get_parent()->get_left(); 
        root->get_parent()->get_left()->get_right() = temp; 
    }

    return 1;
}

int lll_node::rotate_right(bst_node *root)  // rotates the tree rightR
{
    bst_node * temp;
    //Rotation for case 4
    if(root->get_parent()->get_parent()->get_right() == root->get_parent()) 
    {
        //rotating right logic
        temp = root->get_right(); 
        root->get_right() = root->get_parent(); 
        root->get_parent()->get_left() = temp; 
        root->get_parent() = root->get_gparent(); 
        root->get_right()->get_parent() = root; 
        root->get_parent()->get_right() = root; 
    }

    // Rotation for case 5
    else 
    {
        // If ggp right is a grandparent, set ggp right to 
        // parent
        if(root->get_ggp()->get_right() == root->get_gparent())
            root->get_ggp()->get_right() = root->get_parent(); 
        
        // else set ggp left to get_parent()
        else
            root->get_ggp()->get_left() = root->get_parent(); 
       
        // rotating right logic
        temp = root->get_parent()->get_right(); 
        root->get_parent()->get_right() = root->get_gparent(); 
        root->get_gparent() = root->get_ggp(); 
        root->get_parent()->get_right()->get_parent() = root->get_parent(); 
        temp->get_parent() = root->get_parent()->get_right(); 
        root->get_parent()->get_right()->get_left() = temp; 
    }
    return 1;

}

//calls the recursive function which display the apps
int lll_node::display_apps()
{
    if(!root)
        return 0;

    display_apps(root);
    return 1;
}

//recursive function goes through and displays the apps in each node of the tree
int lll_node::display_apps(bst_node *root)
{
    if(!root)
        return 0;

    display_apps(root->get_left());
    root->display_applications();
    return display_apps(root->get_right());
}

//gets the sum of the usage of each app for each category, function used to set the data
//based on highest frequency to lowest frequency
int lll_node::get_sum()
{
    if(!root)
        return 0;

    return get_sum(root);
}

//gets the sum of the data
int lll_node::get_sum(bst_node *root)
{
    if(!root)
        return 0;


    return get_sum(root->get_left()) + get_sum(root->get_right()) + root->get_usage_sum();
}

//function to display the apps which are used above average frequency for a specific type
//of category.
int lll_node::display_abv_avg()
{
    if(!root)
        return 0;

    int sum = get_sum(root);
    int nodes = display_abv_avg(root);
    int average = sum/nodes;
    return display_above(root, average);        //calls recursive display to display above avg
}

//returns the number of nodes in the tree for a certain platform
int lll_node::display_abv_avg(bst_node *root)
{
    if(!root)
        return 0;

    return display_abv_avg(root->get_left()) + display_abv_avg(root->get_right()) + 1;
}

//displays the above average frequency nodes for a specific platform
int lll_node::display_above(bst_node *root, int avg)
{
    if(!root)
        return 0;

    if(avg < root->get_usage_sum())
        root->display_applications();

    return display_above(root->get_left(), avg) + display_above(root->get_right(), avg);
}

//overloaded = operator which copies the whole bst into a dest
lll_node &lll_node::operator=(const lll_node &obj)
{
    bst_node *dest = NULL;
    overloaded_equal_bst(obj.root, dest);
    return *this;
}

//recursive copy of the tree
int lll_node::overloaded_equal_bst(bst_node *source, bst_node *&dest)
{
    if(!source)
    {
        dest = NULL;
        return 0;
    }
    dest = new bst_node;
    dest->apps_copy(*source);       //copy the data
    return overloaded_equal_bst(source->get_left(), dest->get_left()) +
    overloaded_equal_bst(source->get_right(), dest->get_right());
}

void lll_node::copy_in_temp(lll_node *source, lll_node *&dest)
{
    //uses overloaded = for bst
    source->root = dest->root;
}

//for overloading + operator
void lll_node::to_add(lll_node *source, lll_node *&temp)
{
    add_to_the_bst(source->root, temp->root);
}

//recursive function that adds to the temp passed in
int lll_node::add_to_the_bst(bst_node *source, bst_node *&dest)
{
    if(!source)
    {
        dest = new bst_node;
        dest->apps_copy(*source);
        dest->get_left() = dest->get_right() = NULL;
        return 1;
    }

    return add_to_the_bst(source->get_left(), dest->get_left()) +
    add_to_the_bst(source->get_right(), dest->get_right());
}

manager::manager(): head(NULL), things_added(0)
{

}
    
manager::manager(const manager &obj)
{

}

//calls recursive dealloation of the linked list
manager::~manager()
{
    if(head)
        deallocate_all(head);
}

//deallocates the list based on tail recursion
void manager::deallocate_all(lll_node *&head)
{
    if(!head)
        return;

    deallocate_all(head->go_next());
    if(head)
    {
        delete head;
        head = NULL;
    }
}

//opens the text file, reads the data, sends an application object to application class to load the contents
//in the application object and passes it to the LLL which builds the LLL and stores the data in the tree
int manager::read_from_file(char *t_type, String &t_name, String &t_info, String &t_date, String &t_session, int &f)
{
   char name[SIZE];
   char info[SIZE];
   char date[SIZE];
   char session[SIZE];

   ifstream file_in;
   file_in.open("apps.txt", ios::in);

   if(!file_in)
       return 0;

   while(file_in.get(t_type, SIZE, ':') && !file_in.eof())
   {
       file_in.ignore(100, ':');

       file_in.get(name, SIZE, ':');
       file_in.ignore(100, ':');
       t_name = name;


       file_in.get(info, SIZE, ':');
       file_in.ignore(100, ':');
       t_info = info;

       file_in.get(date, SIZE, ':');
       file_in.ignore(100, ':');
       t_date = date;

       file_in.get(session, SIZE, ':');
       file_in.ignore(100, ':');
       t_session = session;

       file_in >> f;
       file_in.ignore(100, '\n');
        
       //set_app_data(temp, temp_name, temp_info, temp_date, temp_session, freq); //loads content into the temp object
       //add_to_list(temp, type);     //creates the list and adds data to the tree
       add_to_list(t_type, t_name, t_info, t_date, t_session, f);
   }
   file_in.close();
   return 1;
}

//adds the data to the list, list is built based on the category of apps (social, game, educational)
//each list has a root pointer to balanced tree
int manager::add_to_list(char *t_type, String &temp_name, String &temp_info, String &temp_date, String &temp_session_length, int &freq)
{
    if(!head)
    {
        head = new lll_node;
        head->set_type(t_type);
        head->wrapper_insert(temp_name, temp_info, temp_date, temp_session_length, freq);
        head->go_next() = NULL;
        return 1;
    }
    //check to see if the app coming in fits the node already created, if node
    //go to end function call to add new node to the list
    else if(head)
    {
        if(head->get_type() == t_type)
        {
            head->wrapper_insert(temp_name, temp_info, temp_date, temp_session_length, freq);
            return 1;
        }
        if(head->go_next())
        {
            if(head->go_next()->get_type() == t_type)
            {
                head->go_next()->wrapper_insert(temp_name, temp_info, temp_date, temp_session_length, freq);
                return 1;
            }
        }
        if(head->go_next() && head->go_next()->go_next())
        {
            if(head->go_next()->go_next()->get_type() == t_type)
            {
                head->go_next()->go_next()->wrapper_insert(temp_name, temp_info, temp_date, temp_session_length, freq);
                return 1;
            }
        }
    }
    return add_to_list(head, t_type, temp_name, temp_info, temp_date, temp_session_length, freq);
}

//function to add a node
int manager::add_to_list(lll_node *&head, char *t_type, String &t_name, String &t_info, String &t_date, String &t_session, int &f)
{
    lll_node *temp = new lll_node;
    temp->set_type(t_type);
    temp->wrapper_insert(t_name, t_info, t_date, t_session, f);
    temp->go_next() = head;
    head = temp;
    return 1;
}


//calls recursive rearrange which rearranged the data of the linked list based on highest freq to lowest
int manager::rearrange()
{
    if(!head)
        return 0;

    rearrange(head);
    return 1;
}

//arranges the list nodes to display highest freq data first
int manager::rearrange(lll_node *&head)
{
    if(!head)
        return 0;

    if(!head->go_next())
        return 0;

    if(head && head->go_next())
    {
        lll_node *hold = head->go_next()->go_next();
        lll_node *temp = head->go_next();
        if(head->get_sum() < temp->get_sum())
        {
            head->go_next() = hold;
            temp->go_next() = head;
            head = temp;
            return rearrange(head->go_next());
        }
    }
    return rearrange(head->go_next());
}

//displays the "type" (social, game, educational) of each app and the app info. First rearranges the list
//so the list is sorted from high frequency to low frequency
int manager::display_type()
{
    if(!head)
        return 0;

    if(head && head->go_next())
    {
        rearrange();
    }
    display_type(head);
    return 1;
}

//recursive display, displays the type of platform and the apps for that platform
int manager::display_type(lll_node *&head)
{
    if(!head)
        return 0;

    head->display();
    head->display_apps();
    return display_type(head->go_next());
}

//gets the user input for app information and adds it to the tree and linked list. Similar
//to the function which reads from file (above) except this gets input from user
//int manager::get_user_input()

int manager::get_user_input(char *type, String &temp_name, String &temp_info, String &temp_date, String &temp_session, int &temp_freq)
{
    cout << "You can only choose from one of three type of application to add (social, game, educational)." << endl;

    do
    {
        cout << "What is the type of application (social, game, educational): ";
        cin.get(type, SIZE, '\n');
        cin.ignore(100, '\n');

        if(strcmp(type, "social") != 0 && strcmp(type, "educational") != 0 && strcmp(type, "game") != 0)
            cout << "Oops! Invalid input!" << endl;

    }while(strcmp(type, "social") != 0 && strcmp(type, "educational") != 0 && strcmp(type, "game") != 0);

    //overloaded >> operator saves input directly in string
    cout << "What is the name of the application: ";
    cin >> temp_name;

    cout << "Information about the usage: ";
    cin >> temp_info;

    cout << "Date of usage(MM/DD/YY): ";
    cin >> temp_date;

    cout << "What was the session length(Ex: 45mins): ";
    cin >> temp_session;

    do{
        cout << "Frequence of usage(1-10): ";
        cin >> temp_freq;
        cin.ignore();

        if(temp_freq > 10 || temp_freq < 0)
            cout << "Oops invalid output!" << endl;

    }while(temp_freq > 10 || temp_freq < 0);

    add_to_list(type, temp_name, temp_info, temp_date, temp_session, temp_freq); 

    return 1;
}

//calls recursive function which displays the above average freq nodes
int manager::above_average()
{
    if(!head)
        return 0;
    
    cout << "Platforms you have: " << endl;
    platforms(head);
    

    char temp[SIZE];
    cout << "For which type of app would you like to display (social, educational, game): ";
    cin.get(temp, SIZE, '\n');
    cin.ignore(100, '\n');

    return above_average(head, temp);
}

//calls the display to get above average frequency nodes and display them
int manager::above_average(lll_node *head, char *t_type)
{
    if(!head)
        return 0;

    if(head->get_type() == t_type)
    {
        head->display_abv_avg();
    }
    return above_average(head->go_next(), t_type);
}

//displays the platforms (social, game, educational)
int manager::platforms(lll_node *head)
{
    if(!head)
        return 0;

    head->display();
    return platforms(head->go_next());
}

//overloaded = operator for the linked list
manager &manager::operator=(const manager &obj)
{ 
    lll_node *dest = NULL;
    overloaded_equal(obj.head, dest);
    return *this;
}

//recursively copies the tree
int manager::overloaded_equal(lll_node *source, lll_node *&dest)
{
    if(!source)
    {
        dest = NULL;
        return 0;
    }

    dest = new lll_node(*source);

    return overloaded_equal(source->go_next(), dest->go_next());
}


//overloaded + operator for linked list, which calls the copy in temp function to copy
//the bst into temp head, then add the object bst to the temp bst
manager manager::operator+(const manager &obj) const
{
    manager temp;
    
    //temp.copy_in_temp(temp.root,this->root); // function that will copy everything into temp.root
    temp.head->copy_in_temp(this->head, temp.head);
    temp.head->to_add(obj.head, temp.head); // funtion will add each node in obj.root into temp.root one by one into the tree 
    
    return temp;
}

//checks equality for linked list category
bool manager::operator==(const manager &obj) const
{
    return check_for_equality(obj);
}

bool manager::operator!=(const manager &obj) const
{
    return check_not_equal(obj);
}

//checks if the category of current object is less than the object being compared to
bool manager::operator<(const manager &obj) const
{
    return less_than(obj);
}

//checks if the category of the current object is less than or equal to object being compared to
bool manager::operator<=(const manager & obj) const
{
    return less_than_equal_to(obj);
}

bool manager::operator>(const manager &obj) const
{
    return greater_than(obj);
}

bool manager::operator>=(const manager &obj) const
{
    return greater_than_equal_to(obj);
}

int manager::check_for_equality(const manager &obj) const
{
    if(this->head->get_type() == obj.head->get_type())
        return 1;

    return 0;
}

int manager::check_not_equal(const manager &obj) const
{
    return !(this->head->get_type() == obj.head->get_type());
}

int manager::less_than(const manager &obj) const
{
    if(this->head->get_type() < obj.head->get_type())
        return 1;
    return 0;
}

int manager::greater_than(const manager &obj) const
{
    return !(this->head->get_type() < obj.head->get_type());
}

int manager::less_than_equal_to(const manager &obj) const
{
    if(this->head->get_type() < obj.head->get_type() || this->head->get_type() == obj.head->get_type())
        return 1;

    return 0;
}

int manager::greater_than_equal_to(const manager &obj) const
{
    if(this->head->get_type() > obj.head->get_type() || this->head->get_type() == obj.head->get_type())
        return 1;
    return 0;
}
