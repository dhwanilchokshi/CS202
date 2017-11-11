/*
        Cheeese is derived from Toppings. It has the same methods and variables as veggies.
 */
package com.company;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Cheeses extends Topping {
    protected static Scanner input = null;
    protected static int CheeseCal = 402;
    protected static String []cheese;
    protected static int cheese_index;
    public Cheeses()
    {
        input = new Scanner(System.in);
        cheese_index = 0;
        cheese = new String[10];
        for(int i = 0; i < 10; ++i)
        {
            cheese[i] = null;
        }
    }

    public int create_special(int lines, int special_number) throws IOException
    {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try {
            File file_in = new File("cheeses.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while (index < lines) {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n", "");
                ++index;
            }
            if(special_number == 1) {
                cheese[cheese_index] = topping_choice[0];
                ++cheese_index;
                cheese[cheese_index] = topping_choice[0];
                ++cheese_index;
            }
            else if(special_number == 3)
            {
                cheese[cheese_index] = topping_choice[3];
                ++cheese_index;
            }
        }
        catch (IOException e)
        {
            System.err.println("File couldnt be opened!");
        }
        return 1;
    }

    public int display_list()
    {
        for(int i = 0; i < 5; ++i)
        {
            if(cheese[i] != null)
                System.out.println("Cheese: " + cheese[i]);
        }
        return 1;
    }

    public int count_lines() throws IOException
    {
        int number_of_lines = 0;
        try{
            BufferedReader fin = new BufferedReader(new FileReader("cheeses.txt"));
                while (fin.readLine() != null)
                    ++number_of_lines;
                fin.close();
        }
        catch (IOException e) {
            System.err.println("File could not be opened");
        }
        return number_of_lines;
    }

    @Override
    int create(int lines) {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try
        {
            File file_in = new File("cheeses.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while(index < lines)
            {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n","");
                ++index;
            }
            System.out.println("Your choice for cheeses are: ");
            for(int i = 0; i < index; ++i)
            {
                System.out.println((i + 1) + "-" + topping_choice[i]);
            }

            System.out.print("What is your choice to add: ");
            choice = input.nextInt();

            System.out.println("Adding: " + topping_choice[choice - 1]);
            System.out.println("CINDEX" + cheese_index);
            cheese[cheese_index] = topping_choice[choice - 1];
            ++cheese_index;
        }
        catch(IOException e)
        {
            System.err.println("File could not be opened!");
        }
        return 1;
    }

    public int get_calories()
    {
        int count = 0;
        for(int i = 0; i < 5; ++i)
        {
            if(cheese[i] != null)
                ++count;
        }
        CheeseCal = count * CheeseCal;
        return CheeseCal;
    }

}
