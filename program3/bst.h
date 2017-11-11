#include "applications.h"

class bst_node: public applications
{
    public:
        bst_node();
        bst_node(const bst_node&);
        ~bst_node();
        bst_node *& get_left();
        bst_node *& get_right();
        int compare(String &);
        bst_node(applications&);   
        bst_node *& set_parent(bst_node * val); 
        bst_node *& get_parent();      
        bool set_isred(bool set);         
        bool get_isred();               
        bst_node *& get_gparent();       
        bst_node *& get_ggp();         
        bst_node *& get_uncle();         

    protected:
        bst_node *left;
        bst_node *right;
        bst_node *parent;
        bool isred;

    private:
};
