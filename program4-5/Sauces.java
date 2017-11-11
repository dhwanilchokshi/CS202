/*
        Sauces is a derived class, derived from Toppings. it contains the same functions and methods as veggies
 */
package com.company;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Sauces extends Topping {
    protected static Scanner input = null;
    protected static int SauceCal = 65;
    protected static String[] sauce;
    protected static int sauce_index;
    public Sauces()
    {
        input = new Scanner(System.in);
        sauce_index = 0;
        sauce = new String[10];
        for(int i = 0; i < 10; ++i)
        {
            sauce[i] = null;
        }
    }

    public int create_special(int lines, int special_number) throws IOException
    {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try {
            File file_in = new File("sauce.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while (index < lines) {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n", "");
                ++index;
            }
            if(special_number == 1) {
                sauce[sauce_index] = topping_choice[0];
                ++sauce_index;
            }
            else if(special_number == 3)
            {
                sauce[sauce_index] = topping_choice[2];
                ++sauce_index;
            }
        }
        catch (IOException e)
        {
            System.err.println("File couldn't be opened!");
        }
        return 1;
    }

    public int display_list()
    {
        for(int i = 0; i < 5; ++i)
        {
            if(sauce[i] != null)
                System.out.println("Sauce: " + sauce[i]);
        }
        return 1;
    }

    public int count_lines() throws IOException
    {
        int number_of_lines = 0;
        try{
            BufferedReader fin = new BufferedReader(new FileReader("sauce.txt"));
                while (fin.readLine() != null)
                    ++number_of_lines;
                fin.close();
        }
        catch (IOException e) {
            System.err.println("File could not be opened");
        }
        return number_of_lines;
    }

    int create(int lines) {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try
        {
            File file_in = new File("sauce.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while(index < lines)
            {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n","");
                ++index;
            }
            System.out.println("You choice for sauces are: ");
            for(int i = 0; i < index; ++i)
            {
                System.out.println((i + 1) + "-" + topping_choice[i]);
            }

            System.out.print("What is your choice to add: ");
            choice = input.nextInt();

            System.out.println("Adding: " + topping_choice[choice - 1]);
            sauce[sauce_index] = topping_choice[choice - 1];
            ++sauce_index;
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
            if(sauce[i] != null)
                ++count;
        }
        SauceCal = count * SauceCal;
        return SauceCal;
    }

}
