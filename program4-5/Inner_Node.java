package com.company;

/*
PROGRAM 5 FILE
        This file contains the inner node class, which contains the name of the pizza and its price, plus
        other setter and getter functions.
 */

public class Inner_Node {
    protected String pizza_name;
    protected String price_of_pizza;
    protected Inner_Node left;
    protected Inner_Node right;

    public Inner_Node()
    {
        pizza_name = new String();
        price_of_pizza = new String();
        this.left = null;
        this.right = null;
    }

    //compare the pizza we have to what is being passed in
    public boolean compare_pizza(String to_compare)
    {
        int result = to_compare.compareTo(pizza_name);
        if(result < 0)
            return true;
        return false;
    }


    //sets the pizza and its price.
    public void set_pizza(String pizza, String price)
    {
        pizza_name = pizza;
        price_of_pizza = price;
    }
    public Inner_Node go_left(){
        return left;
    }

    public Inner_Node go_right()
    {
        return right;
    }

    public void set_left(Inner_Node current){
        this.left = current;
    }

    public void set_right(Inner_Node current){
        this.right = current;
    }

    //displays the pizza
    public void display_pizzas()

    {
        System.out.println("PIZZA: " + pizza_name + ", PRICE: " + price_of_pizza);
    }
}
