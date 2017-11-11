/*
        Pizza class has an array of toppings and array of special toppings which refers to the same
        toppings but only if it is a special order. The Pizza class has the functions which get the toppings
        if the order is just a normal order. This is where dynamic binding takes place where we have an
        array of toppings referring to the respective derived classes (veggies, sauce, cheese, meat). It then
        calls the functions of those class to open the file and save the user's topping choices. The get
        special function does the same thing as the get toppings except it points to specific classes and gets
        the toppings required for the special order.
 */
package com.company;

import java.io.IOException;
import java.util.Scanner;

public class Pizza {
    protected static Scanner input = null;
    protected static int SIZE = 100;
    protected Topping []toppings;
    protected Topping []special_toppings;
    protected int v_index;
    protected int s_index;
    protected int c_index;
    protected int m_index;
    public Pizza()
    {
        input = new Scanner(System.in);
        toppings = new Topping[4];
        special_toppings = new Topping[4];
        for(int i = 0; i < 4; ++i)
        {
            toppings[i] = null;
            special_toppings[i] = null;
        }
        v_index = 0;
        s_index = 0;
        c_index = 0;
        m_index = 0;
    }
    //special order
    public void get_special(int special_number) throws IOException {
        int lines = 0;
        try {
            //special order number, makes sure the veggie index is 0 so we dont keep
            //creating new veggie objects.
            if(special_number == 1) {
                if (v_index == 0) {
                    special_toppings[0] = new Veggies();
                    ++v_index;
                }
                //counts lines of the file
                lines = special_toppings[0].count_lines();
                special_toppings[0].create_special(lines, special_number);

                if (s_index == 0) {
                    special_toppings[1] = new Sauces();
                    ++s_index;
                }
                lines = special_toppings[1].count_lines();
                special_toppings[1].create_special(lines, special_number);

                if(c_index == 0)
                {
                    special_toppings[2] = new Cheeses();
                    ++c_index;
                }
                lines = special_toppings[2].count_lines();
                special_toppings[2].create_special(lines, special_number);
            }
            //if special order number is 2 then build that order
            else if (special_number == 2) {
                if (v_index == 0) {
                    special_toppings[0] = new Veggies();
                    ++v_index;
                }
                lines = special_toppings[0].count_lines();
                special_toppings[0].create_special(lines, special_number);

                if(m_index == 0)
                {
                    special_toppings[3] = new Meat();
                    ++m_index;
                }
                lines = special_toppings[3].count_lines();
                special_toppings[3].create_special(lines, special_number);
            }
            //if special order number is 3 then build that order
            else if(special_number == 3)
            {
                if(v_index == 0)
                {
                    special_toppings[0] = new Veggies();
                    ++v_index;
                }
                lines = special_toppings[0].count_lines();
                special_toppings[0].create_special(lines, special_number);

                if(s_index == 0)
                {
                    special_toppings[1] = new Sauces();
                    ++s_index;
                }
                lines = special_toppings[1].count_lines();
                special_toppings[1].create_special(lines, special_number);

                if(c_index == 0)
                {
                    special_toppings[2] = new Cheeses();
                    ++c_index;
                }
                lines = special_toppings[2].count_lines();
                special_toppings[2].create_special(lines, special_number);
            }
        }
        catch(IOException e)
        {
            System.err.println("Could not create special!");
        }
    }
    //gets the toppings for the normal order, and displays the calories of the toppings
    //picked by the user.
    public void get_toppings() throws IOException {
        int topping_pick = 0;
        int lines = 0;
        char repeat_choice;

        int veggie_cal_total = 0;
        int sauce_cal_total = 0;
        int cheese_cal_total = 0;
        int meat_cal_total = 0;

        toppings = new Topping[4];
        for(int i = 0; i < 4; ++i)
            toppings[i] = null;

        do
        {
            System.out.println("1 - Veggies");
            System.out.println("2 - Sauces");
            System.out.println("3 - Cheeses");
            System.out.println("4 - Meat");
            System.out.print("What is your topping choice(1-4): ");
            topping_pick = input.nextInt();
            if(topping_pick == 1)
            {
                if(v_index == 0)
                {
                    toppings[0] = new Veggies();
                    ++v_index;
                }
                lines = toppings[0].count_lines();
                toppings[0].create(lines);
                veggie_cal_total = toppings[0].get_calories();
            }
            else if(topping_pick == 2)
            {
                if(s_index == 0)
                {
                    toppings[1] = new Sauces();
                    ++s_index;
                }
                lines = toppings[1].count_lines();
                toppings[1].create(lines);
                sauce_cal_total = toppings[1].get_calories();
            }
            else if(topping_pick == 3)
            {
                if(c_index == 0)
                {
                    toppings[2] = new Cheeses();
                    ++c_index;
                }
                lines = toppings[2].count_lines();
                toppings[2].create(lines);
                cheese_cal_total = toppings[2].get_calories();
            }
            else if(topping_pick == 4)
            {
                if(m_index == 0)
                {
                    toppings[3] = new Meat();
                    ++m_index;
                }
                lines = toppings[3].count_lines();
                toppings[3].create(lines);
                meat_cal_total = toppings[3].get_calories();
            }
            System.out.print("Do you want to pick another topping? (y/n): ");
            repeat_choice = input.next().charAt(0);

        }while(repeat_choice == 'y');


        int TotalCal = veggie_cal_total + sauce_cal_total + cheese_cal_total + meat_cal_total;
        System.out.println("Your total calories for toppings picked: " + TotalCal);

    }

    //for loops through and displays the normal orders of the user
    //and also displays the special order of the user.
    public void display_most_recent()
    {
        if(this.toppings != null)
        {
            for(int i = 0; i < 4; ++i)
            {
                if(toppings[i] != null) {
                    toppings[i].display_list();
                }
            }
            for(int i = 0; i < 4; ++i)
            {
                if(special_toppings[i] != null)
                    special_toppings[i].display_list();
            }
        }
    }

}
