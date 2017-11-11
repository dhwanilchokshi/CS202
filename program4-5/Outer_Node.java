package com.company;

/*
PROGRAM 5 FILE
        Outer node contains the pizzeria name (vendor), their zipcode, and the inner root, which will
        be the randomly assigned pizza to the pizzerias.
 */
public class Outer_Node {
    protected Inner_Node inner_root;
    protected String vendor;
    protected int zip_code;
    protected Outer_Node left;
    protected Outer_Node right;

    public Outer_Node()
    {
        this.inner_root = null;
        vendor = null;
        zip_code = 0;
        this.left = null;
        this.right = null;
    }

    //deletes the inner root pizzas when all the pizzas have to be deleted
    public int delete_pizzas()
    {
        if(inner_root != null)
            inner_root = null;

        return 1;
    }

    //compare the vendor name in the node to what is passed in
    public boolean compare_names(String to_compare)
    {
        return this.vendor.equals(to_compare);
    }

    //compare zip code of the root, and what the user enters
    public boolean compare_zips(int zip)
    {
        if(zip < zip_code)
            return true;
        return false;
    }

    public Outer_Node go_left(){
        return left;
    }

    public void set_left(Outer_Node current)
    {
        this.left = current;
    }

    public void set_right(Outer_Node current)
    {
        this.right = current;
    }

    public Outer_Node go_right(){
        return right;
    }

    public int get_zip()
    {
        return zip_code;
    }

    //add the inner data of pizzas
    public int add_inner(String pizza, String price)
    {
        inner_root = add_inner(inner_root, pizza, price);
        return 1;
    }

    //add the pizza and it's respective price
    private Inner_Node add_inner(Inner_Node inner_root, String pizza, String price)
    {
        if(inner_root == null)
        {
            inner_root = new Inner_Node();
            inner_root.set_pizza(pizza, price);
            inner_root.set_left(null);
            inner_root.set_right(null);
            return inner_root;
        }

        else if(inner_root.compare_pizza(pizza))
            inner_root.set_left(add_inner(inner_root.go_left(), pizza, price));

        else
            inner_root.set_right(add_inner(inner_root.go_right(), pizza, price));

        return inner_root;
    }

    //add data calls the add inner function 5 times to add the pizza and it's price to the inner node
    public int add_data(String location, String[]to_send, String[]price_to_send, int zip)
    {
        vendor = new String(location);
        zip_code = zip;

        for(int i = 0; i < 5; ++i) {
            add_inner(to_send[i], price_to_send[i]);
        }
        return 1;
    }

    //displays the vendor and its price, and calls the recursive function to display inner node data
    //of the randomly added pizzas
    public int display_pizzeria()
    {
        System.out.println("\nVENDOR: " + vendor + ", ZIPCODE: " + zip_code);
        return display_pizzas(inner_root);
    }

    //recursive function to display the random pizzas per pizzeria
    public int display_pizzas(Inner_Node inner_root)
    {
        if(inner_root == null)
            return 0;

        inner_root.display_pizzas();
        return display_pizzas(inner_root.go_left()) + display_pizzas(inner_root.go_right());
    }
}
