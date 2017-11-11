#include "bst.h"

class category
{
    public:
        category();
        ~category();
        int set_type(char *);
        String &get_type();
        void display();
    protected:
        String type;

    private:
};


class lll_node: public category
{
    public:
        lll_node();
        lll_node(const lll_node &);
        ~lll_node();
        lll_node *& go_next();
        int wrapper_insert(String &, String &, String &, String &, int &);
        int case1(bst_node *);         // check if root is red
        int case2(bst_node *);       // check for black parent
        int case3(bst_node *);         // making parent and uncle black
        int case4(bst_node *);       // check case if node added inside
        int case5(bst_node *);         // check case if node added outside
        int rotate_left(bst_node *);     // rotates the tree left
        int rotate_right(bst_node *);  // rotates the tree rightR
        int display_apps();
        int get_sum();
        int display_abv_avg();
        lll_node &operator=(const lll_node &);
        void copy_in_temp(lll_node *, lll_node *&);
        void to_add(lll_node *, lll_node *&);


    protected:
        lll_node *next;
        bst_node *root;

    private:
        int display_apps(bst_node *);
        int get_sum(bst_node *);
        int display_abv_avg(bst_node *);
        int display_above(bst_node *, int);
        int overloaded_equal_bst(bst_node *, bst_node *&);
        void deallocate_tree(bst_node*&);
        int wrapper_insert(bst_node *&, bst_node*, String &, String &, String &, String &, int&); // insert func
        int add_to_the_bst(bst_node *, bst_node *&);
};

class manager
{
    public:
        manager();
        manager(const manager &);
        ~manager();
        int read_from_file(char *, String &, String &, String &, String &, int &);
        int add_to_list(char *, String &, String &, String &, String &, int &);
        int display_type();
        int rearrange();
        int get_user_input(char *, String &, String &, String &, String &, int &);
        int above_average();
        manager &operator=(const manager&);
        manager operator+(const manager&) const;
        bool operator==(const manager &) const;
        bool operator!=(const manager &) const;
        bool operator<(const manager &) const;
        bool operator<=(const manager &) const;
        bool operator>(const manager &) const;
        bool operator>=(const manager &) const;

    protected:
        lll_node *head;
        int things_added;

    private:
        int display_type(lll_node *&);
        int rearrange(lll_node *&);
        int above_average(lll_node *, char *);
        int platforms(lll_node *);
        int check_for_equality(const manager &) const;
        int overloaded_equal(lll_node *, lll_node *&);
        void deallocate_all(lll_node *&);
        int add_to_list(lll_node *&, char *, String &, String &, String &, String &, int &);
        int less_than(const manager &) const;
        int less_than_equal_to(const manager &) const;
        int greater_than(const manager &) const;
        int greater_than_equal_to(const manager &) const;
        int check_not_equal(const manager &) const;
};
