/*
        The DLL node class contains the pizza object because each time the user orders a pizza
        or a special combo, we want to create a new pizza object and call the correct function to
        add the toppings.
 */
package com.company;
import java.io.IOException;
import java.util.Scanner;

public class DLL_node {
    protected static Scanner input = null;
    protected Pizza pizzas;
    protected DLL_node next;
    protected DLL_node previous;
    public DLL_node()
    {
        this.next = null;
        this.previous = null;
        this.pizzas = null;
        input = new Scanner(System.in);
    }

    public DLL_node go_next() {return next;}
    public DLL_node go_previous() {return previous;}

    //for connecting the nodes correctly
    public void set_next(DLL_node current){this.next = current;}
    //for connecting the previous correctly
    public void set_previous(DLL_node current){this.previous = current;}

    //function which creates a new pizza object and calls the function to get
    //the toppings.
    //If its a special combo, then the pizza creates another object and calls
    //respective functions
    public int get_order(boolean special, int special_number) throws IOException {

        if(special == false && special_number == 0) {
            System.out.println("You are about to make an order!");
            pizzas = new Pizza();
            pizzas.get_toppings();
            return 1;
        }
        //if the order is special
        else if(special == true)
        {
            System.out.println("Your special is made!");
            pizzas = new Pizza();
            pizzas.get_special(special_number);
            return 1;
        }
        return 1;
    }

    public void display_recent()
    {
        if(this.pizzas != null)
        {
            System.out.println("Pizza: ");
            pizzas.display_most_recent();
        }
    }


}
