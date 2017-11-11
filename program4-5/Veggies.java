/*
        Veggie class is a derived class from Toppings. This class is has methods which create the special order
        and add them to the veggie string array. It also creates the normal orders and get the user input
        for their choice of toppings of veggie string array.
 */
package com.company;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Veggies extends Topping {
    protected static Scanner input = null;
    protected String[] veggies;
    protected static int veggie_index;
    protected static int veggieCalories = 24;
    public Veggies()
    {
        input = new Scanner(System.in);
        veggies = new String[10];
        veggie_index = 0;
        for(int i = 0; i < 10; ++i)
        {
            veggies[i] = null;
        }
    }

    //creates the special
    public int create_special(int lines, int special_number) throws IOException
    {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try {
            File file_in = new File("veggie.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while (index < lines) {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n", "");
                ++index;
            }
            //manually added by the programmer
            if(special_number == 1) {
                veggies[veggie_index] = topping_choice[3];
                ++veggie_index;
            }
            else if(special_number == 2)
            {
                veggies[veggie_index] = topping_choice[4];
                ++veggie_index;
                veggies[veggie_index] = topping_choice[4];
                ++veggie_index;
            }
            else if(special_number == 3)
            {
                veggies[veggie_index] = topping_choice[1];
                ++veggie_index;
            }
        }
        catch (IOException e)
        {
            System.err.println("File couldn't be opened!");
        }
        return 1;
    }

    //counts lines of the text file and returns the number of lines.
    public int count_lines() throws IOException
    {
        int number_of_lines = 0;
        try{
            BufferedReader fin = new BufferedReader(new FileReader("veggie.txt"));
                while (fin.readLine() != null)
                    ++number_of_lines;
                fin.close();
        }
        catch(IOException e)
        {
            System.err.println("File could not be found!");
        }
        return number_of_lines;
    }

    //creates the veggie toppings by getting user input into the array of
    //string of the veggies.
    public int create(int lines) throws IOException
    {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try
        {
            File file_in = new File("veggie.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while(index < lines)
            {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n","");
                ++index;
            }
            System.out.println("You choice for veggies are: ");
            for(int i = 0; i < index; ++i)
            {
                System.out.println((i + 1) + "-" + topping_choice[i]);
            }

            System.out.print("What is your choice to add: ");
            choice = input.nextInt();
            System.out.println("Adding: " + topping_choice[choice - 1]);

            System.out.println("VIndex: " + veggie_index);
            veggies[veggie_index] = topping_choice[choice - 1];
            ++veggie_index;
        }
        catch(IOException e)
        {
            System.err.println("File could not be opened!");
        }
        return 1;
    }

    //loops through and displays the veggie string, if it contains
    //the veggie toppings.
    public int display_list()
    {
        for(int i = 0; i < 5; i++)
        {
            if(veggies[i] != null)
            {
                System.out.println("Veggie: " + veggies[i]);
            }
        }
        return 1;
    }
    //loops through and gets the calories for the veggies. For the sake of
    //simplicity, all veggie toppings have the same amount of calories.
    public int get_calories()
    {
        int count = 0;
        for(int i = 0; i < 5; ++i)
        {
            if(veggies[i] != null)
            {
                ++count;
            }
        }
        veggieCalories = count * veggieCalories;
        return veggieCalories;
    }

}
