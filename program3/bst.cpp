#include "bst.h"

bst_node::bst_node():left(NULL), right(NULL), parent(NULL), isred(true)
{

}

bst_node::bst_node(const bst_node &obj)
{
}

bst_node::~bst_node()
{
}

//return left
bst_node *& bst_node::get_left(){return left;}

//return right
bst_node *& bst_node::get_right(){return right;}      

//sets parent equal to the val passed in
bst_node *& bst_node::set_parent(bst_node * val)
{
    parent = val;
    return parent;
}

//return the parent
bst_node *& bst_node::get_parent(){return parent;}

//set color flag
bool bst_node::set_isred(bool set)
{
    isred = set;
    return true;
}

//returns the color flag value
bool bst_node::get_isred()
{
    return isred;
}

//get grand parent
bst_node *& bst_node::get_gparent()
{
    return parent->get_parent();
}

//get great grand parent
bst_node *& bst_node::get_ggp()
{
    return parent->parent->get_parent();
}

//get the uncle
bst_node *& bst_node::get_uncle()
{
    bst_node *gparent = get_gparent();
    if(gparent->get_left() == parent)
        return gparent->get_right();
    else
        return gparent->get_left();

}

//compare and see if the data value is less to be added to left side of root
//or right side
int bst_node::compare(String &t_name)
{
    return check(t_name);
}
