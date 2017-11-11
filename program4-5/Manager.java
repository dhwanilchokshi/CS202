/*
PROGRAM 4-5 FILE
        This file contains the manager class which has a root pointer to a node for the outer
        tree which is going to be the tree of pizzerias, and the outer node has another root pointer
        to the inner tree which is the tree of pizza specialities for pizzas.
*/

package com.company;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.Buffer;
import java.util.Scanner;
import java.util.Random;
import java.lang.*;

public class Manager {

    protected User user;
    protected static Scanner input = null;
    protected String first_name;
    protected String last_name;
    protected int[] random_generated;
    protected float[] prices;
    protected int price_index;
    protected int SPECIALTIES;
    int random_generated_index;
    protected Outer_Node outer_root;

    public Manager() {
        input = new Scanner(System.in);
        user = new User();
        this.outer_root = null;
        random_generated_index = 0;
        SPECIALTIES = 5;
    }

    //wrapper function which calls the recursive delete and catches the return value in the
    //outer root.
    public int delete_specific(String to_delete)
    {
        if(outer_root == null)
            return 0;

        outer_root = delete_specific(outer_root, to_delete);
        return 1;
    }
    //recursive delete which checks and takes care of all the cases for deleting a specific
    //from the bst. Delete is based off the vendor name.
    private Outer_Node delete_specific(Outer_Node outer_root, String to_delete)
    {
        if(outer_root == null)
            return outer_root;

        if(outer_root.compare_names(to_delete)) {
            if (outer_root.go_left() == null && outer_root.go_right() == null) {
                outer_root = null;
            } else if (outer_root.go_left() == null) {
                outer_root = outer_root.go_right();
            } else if (outer_root.go_right() == null) {
                outer_root = outer_root.go_left();
            } else {
                Outer_Node left_hold = outer_root.go_left();
                Outer_Node right_hold = outer_root.go_right();
                outer_root = null;
                outer_root = get_ios(right_hold);
                if (outer_root != right_hold) {
                    right_hold.set_left(outer_root.go_right());
                    outer_root.set_right(right_hold);
                }
                outer_root.set_left(left_hold);
            }
            return outer_root;
        }
        outer_root.set_left(delete_specific(outer_root.go_left(), to_delete));
        outer_root.set_right(delete_specific(outer_root.go_right(), to_delete));
        return outer_root;
    }
    //gets the ios if needed
    private Outer_Node get_ios(Outer_Node ios)
    {
        if(ios == null || ios.go_left() == null)
            return ios;
        return get_ios(ios.go_left());
    }

    //deletes all pizzerias, setting outer root to null, and calls the recursive
    //function to set all the inner node root to null if there is an inner node.
    public int delete_all_pizzerias()
    {
        if(outer_root == null)
            return 1;
        delete_all(outer_root);
        outer_root = null;
        return 1;
    }

    //recursive function which sets all the inner root to null
    public int delete_all(Outer_Node outer_root)
    {
        if(outer_root == null)
            return 0;

        outer_root.delete_pizzas();
        delete_all(outer_root.go_left());
        return delete_all(outer_root.go_right());
    }

    //calls the recursive function which compares the name of the pizzeria sent in
    //to see if a match is found, if a match it found, set a reference there and display
    //the pizzeria and all of it's specialties.
    public int search(String to_search)
    {
        if(outer_root == null)
            return 0;

        Outer_Node temp = null;
        Outer_Node holder = search(outer_root, temp, to_search);
        if(holder != null) {
            System.out.println("A match has been found!");
            holder.display_pizzeria();
        }
        return 1;
    }

    //puts a reference if a match is found
    private Outer_Node search(Outer_Node outer_root, Outer_Node temp, String to_search)
    {
        if(outer_root == null)
            return temp;

        if(outer_root.compare_names(to_search))
        {
            temp = outer_root;
            return temp;
        }
        search(outer_root.go_left(), temp, to_search);
        return search(outer_root.go_right(), temp, to_search);
    }

    //calls the recursive function to find the closest pizzeria to the
    //user once the user enters their zip code. If match is found, display the
    //pizzeria and its specialties
    public int find_the_closest(int user_zip, int difference)
    {
        if(outer_root == null)
            return 0;

        Outer_Node temp = null;
        Outer_Node holder = copy_into(outer_root, temp, user_zip, difference);
        System.out.println("Closes pizzeria to you is: ");
        holder.display_pizzeria();
        return 1;
    }

    //recursive function which finds the closest pizzeria to the user.
    private Outer_Node copy_into(Outer_Node outer_root, Outer_Node temp, int user_zip, int difference)
    {
       if(outer_root == null)
           return temp;

       if((Math.abs(user_zip - outer_root.get_zip())) < difference)
       {
           difference = user_zip - outer_root.get_zip();
           temp = outer_root;
       }
       copy_into(outer_root.go_left(), temp, user_zip, difference);
       return copy_into(outer_root.go_right(), temp, user_zip, difference);
    }

    //calls the recursive function which displays the pizzerias
    public int display_all_info()
    {
        if(outer_root == null)
            return 0;

        return display_all_info(outer_root);
    }

    //recursive function which displays the pizzerias and the specialties.
    private int display_all_info(Outer_Node outer_root)
    {
        if(outer_root == null)
            return 1;

        display_all_info(outer_root.go_left());
        outer_root.display_pizzeria();
        return display_all_info(outer_root.go_right());
    }

    //checker function to make sure we generate unique numbers so we can place different
    //pizzas for each pizzerias and no pizza overlaps.
    public boolean checker(int number)
    {
        for(int i = 0; i < random_generated_index; ++i)
        {
            if(random_generated[i] == number)
                return true;
        }
        return false;
    }

    //calls the recursive function which adds pizzerias, random pizzas, pizzeria zip, and the prices.
    public int add_outer(String location, String[] to_send, String[]price_to_send, int zip)
    {
        outer_root = add_outer(outer_root, location, to_send, price_to_send, zip);
        return 1;
    }

    //adds the pizzerias, their respective zipcode, random pizzas, and the prices
    private Outer_Node add_outer(Outer_Node outer_root, String location, String[]to_send, String[]price_to_send, int zip) {
        if(outer_root == null) {
            outer_root = new Outer_Node();
            outer_root.add_data(location, to_send, price_to_send, zip);
            outer_root.set_left(null);
            outer_root.set_right(null);
            return outer_root;
        }

        else if(outer_root.compare_zips(zip)) {
            outer_root.set_left(add_outer(outer_root.go_left(), location, to_send, price_to_send, zip));
        }
        else {
            outer_root.set_right(add_outer(outer_root.go_right(), location, to_send, price_to_send, zip));
        }
        return outer_root;
    }

    //reads the information from the files about the pizzerias and the pizzas. Stores the pizzas
    //into an array of string in a random order and sends it to be added. Meaning that each pizzeria
    //has a unique set of pizza specialties with no overlaps.
    public int read_information() throws IOException
    {
        try {
            int pizzeria_lines = 0;
            int pizza_lines = 0;
            int pizzeria_index = 0;
            int pizza_index = 0;
            int price_index = 0;
            int zip_code;
            Random rand = new Random();

            //counting the number of lines in the pizzerias text file.
            Scanner read_in;
            BufferedReader fin = new BufferedReader(new FileReader("Pizzerias.txt"));
            while (fin.readLine() != null)
                ++pizzeria_lines;

            //counting the lines in the pizzas text file.
            BufferedReader Fin = new BufferedReader(new FileReader("Pizzas.txt"));
            while (Fin.readLine() != null)
                ++pizza_lines;

            //pizzeria string array is as big as how many lines there were
            String []Pizzerias = new String[pizzeria_lines];
            //pizzas string array is as big as how many lines there were
            String []Pizzas = new String[pizza_lines];
            //prices stored in string
            String []prices = new String[pizza_lines];
            //random generated array of ints to make sure we dont get
            //the same index twice
            random_generated = new int[pizza_lines];

            //opens the text file for pizzas to read the pizzas and their prices
            //storing them in the string arrays
            File in_file = new File("Pizzas.txt");
            read_in = new Scanner(in_file);
            read_in.useDelimiter(";");
            while(pizza_index < pizza_lines && price_index < pizza_lines)
            {
                Pizzas[pizza_index] = read_in.next().replaceAll("\\r\\n","");
                ++pizza_index;
                prices[price_index] = read_in.next().replaceAll("\\r\\n","");
                ++price_index;
            }

            //opening the pizzeria text file for reading the pizzerias
            File file_in = new File("Pizzerias.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            int send_index = 0;
            int random_number;
            while(pizzeria_index < pizzeria_lines)
            {
                //SPECIALTIES = 5, 5 special pizzas per restaurant
                String []pizzas_to_send = new String[SPECIALTIES];
                String []prices_to_send = new String[SPECIALTIES];
                send_index = 0;
                //while loops random generates 5 random indexes and stores
                //the pizzas and their prices in the array created above
                while(send_index < SPECIALTIES)
                {
                    random_number = rand.nextInt(pizza_lines);
                    //checker function checks to make sure the random number
                    //generated is not the same as what we have generated before
                    while(checker(random_number))
                    {
                        random_number = rand.nextInt(pizza_lines);
                    }
                    //save the random index into the integer array
                    random_generated[random_generated_index] = random_number;
                    ++random_generated_index;
                    //store the 5 random pizzas and their prices into the array of string
                    //created before
                    pizzas_to_send[send_index] = Pizzas[random_number];
                    prices_to_send[send_index] = prices[random_number];
                    ++send_index;
                }
                //reading in the pizzeria and the zipcode
                Pizzerias[pizzeria_index] = read_in.next().replaceAll("\\r\\n","");
                zip_code = read_in.nextInt();

                //add the pizzeria/zip, the 5 random pizzas, and their prices
                add_outer(Pizzerias[pizzeria_index], pizzas_to_send, prices_to_send, zip_code);
                ++pizzeria_index;
            }
        }
        catch (IOException e)
        {
            System.err.println("File could not be opened!");
        }
        random_generated_index = 0;
        return 1;
    }
    //welcomes the user and asks them for their choice
    public void welcome_user() throws IOException {
        char repeat;
        int choice;
        System.out.print("What is your first name: ");
        first_name = input.next().toString();

        System.out.print("What is your last name: ");
        last_name = input.next().toString();

        System.out.println("Welcome to the Pizza Ordering Application, " + first_name + " " + last_name + "!");
        do {
            System.out.println("\nPROGRAM 4 FUNCTIONALITY: ");
            System.out.println("1 - Make an order");
            System.out.println("2 - Display your most recent order");
            System.out.println("3 - Display all your orders");
            System.out.println("4 - Delete your most recent order");
            System.out.println("5 - Delete all your orders");
            System.out.println("6 - View/Order the Special Combos");

            System.out.println("\nPROGRAM 5 FUNCTIONALITY: ");
            System.out.println("7 - Load the Pizzerias and their Specialty Pizzas from file");
            System.out.println("8 - Display the Pizzerias and their Specialty Pizzas");
            System.out.println("9 - Find the closest pizzeria to your location");
            System.out.println("10 - Search for a certain Pizzeria");
            System.out.println("11 - Delete all the pizzerias");
            System.out.println("12 - Delete a specific pizzeria");
            System.out.print("Choice: ");
            choice = input.nextInt();

            if(choice == 1)
                create_order(false, 0);

            else if(choice == 2)
                display_top_order();

            else if(choice == 3)
                display_all_order();

            else if(choice == 4)
                delete_most_recent();

            else if(choice == 5)
                delete_all();

            //uses random generator to generate a random special combo
            //asks the user if they would like to have the special.
            else if(choice == 6)
            {
                Random rand = new Random();
                char special_choice;
                int random_pizza = rand.nextInt(3) + 1;
                if(random_pizza == 1)
                {
                    System.out.println("Our special today is double american cheese pizza with marinara and jalapenos!");
                    System.out.print("Would you like to go for our special?(y/n): ");
                    special_choice = input.next().charAt(0);
                    if(special_choice == 'y')
                    {
                        create_order(true, 1);
                    }
                }
                else if(random_pizza == 2)
                {
                    System.out.println("Our special today is double pepperoni with double mushroom!");
                    System.out.print("Would you like to go for our special?(y/n): ");
                    special_choice = input.next().charAt(0);
                    if(special_choice == 'y')
                    {
                        create_order(true, 2);
                    }
                }
                else if(random_pizza == 3)
                {
                    System.out.println("Our special today is BBQ sauce pizza with mozzarella and onions!");
                    System.out.print("Would you like to go for our special?(y/n): ");
                    special_choice = input.next().charAt(0);
                    if(special_choice == 'y');
                    {
                        create_order(true, 3);
                    }
                }
            }
            else if(choice == 7) {
                if (read_information() == 1)
                    System.out.println("Pizzerias and Pizzas have been loaded!");
                else
                    System.out.println("File contents couldn't be loaded");
            }

            else if(choice == 8) {
                if (display_all_info() == 0)
                    System.out.println("Nothing to display!(try loading the file contents first)");
            }

            else if(choice == 9)
            {
                int user_zip;
                int difference = 100000;
                System.out.print("What is your zip code: ");
                user_zip = input.nextInt();
                if(find_the_closest(user_zip, difference) == 0)
                    System.out.println("Load the Pizzerias first, by selecting menu choice 7");
            }

            else if(choice == 10)
            {
                Scanner in = new Scanner(System.in);
                String to_search = new String();
                System.out.print("Which pizzeria to search for(case sensitive): ");
                to_search = in.nextLine();
                if(search(to_search) == 0)
                    System.out.println("Load the Pizzerias first, by selecting menu choice 7");
            }

            else if(choice == 11)
            {
                if(delete_all_pizzerias() == 0)
                    System.out.println("Nothing to delete!");
                else
                    System.out.println("All pizzerias have been deleted!");
            }

            else if(choice == 12)
            {
                Scanner in = new Scanner(System.in);
                String pizzeria = new String();
                System.out.print("What is the name of the pizzeria to delete(case sensitive): ");
                pizzeria = in.nextLine();
                if(delete_specific(pizzeria) == 0)
                    System.out.println("Couldn't delete, try loading file contents first (menu choice 7)");
                else
                    System.out.println("Item has been deleted!");
            }

            System.out.print("Main menu again?(y/n): ");
            repeat = input.next().charAt(0);
        }while(repeat == 'y');
        System.out.println("GoodBye!");

    }

    //creates the normal order for the user, adding a new doubly linked list node to the beginning
    public void create_order(boolean special, int special_number) throws IOException {
        user.add(special, special_number);
    }

    //display the top order if it exists
    public void display_top_order()
    {
        user.display_top();
    }

    //displays all the orders of the order
    public void display_all_order()
    {
        if(user.display_all() == 0)
            System.out.println("Nothing to display!");
    }
    //deletes the most recent order
    public void delete_most_recent()
    {
        if(user.delete_recent() == 1)
            System.out.println("Most recent order has been deleted!");
        else
            System.out.println("No order to delete!");
    }

    //deletes all the orders
    public void delete_all()
    {
        if(user.delete_all_orders() == 1)
            System.out.println("All orders have been deleted!");
        else
            System.out.println("No orders to delete!");
    }

}
