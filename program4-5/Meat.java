/*
    Meat is a derived class, derived from toppings. It contains the same methods and variables as
    veggies.
 */
package com.company;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Meat extends Topping {
    protected static Scanner input = null;
    protected static int MeatCal = 213;
    protected static String[] meats;
    protected static int meat_index;
    public Meat()
    {
        input = new Scanner(System.in);
        meat_index = 0;
        meats = new String[10];
        for(int i = 0; i < 10; ++i)
        {
            meats[i] = null;
        }
    }

    public int create_special(int lines, int special_number) throws IOException
    {
        int index = 0;
        int choice;
        String []topping_choice = new String[lines];
        Scanner read_in;
        try {
            File file_in = new File("meat.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while (index < lines) {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n", "");
                ++index;
            }
            if(special_number == 2)
            {
                meats[meat_index] = topping_choice[0];
                ++meat_index;
                meats[meat_index] = topping_choice[0];
                ++meat_index;
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
            if(meats[i] != null)
            {
                System.out.println("Meat: " + meats[i]);
            }
        }
        return 1;
    }

    public int count_lines() throws IOException
    {
        int number_of_lines = 0;
        try{
            BufferedReader fin = new BufferedReader(new FileReader("meat.txt"));
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
        String[] topping_choice = new String[lines];
        Scanner read_in;
        try {
            File file_in = new File("meat.txt");
            read_in = new Scanner(file_in);
            read_in.useDelimiter(";");
            while (index < lines) {
                topping_choice[index] = read_in.next().replaceAll("\\r\\n", "");
                ++index;
            }
            System.out.println("You choice for meat are: ");
            for (int i = 0; i < index; ++i) {
                System.out.println((i + 1) + "-" + topping_choice[i]);
            }

            System.out.print("What is your choice to add: ");
            choice = input.nextInt();

            System.out.println("Adding: " + topping_choice[choice - 1]);
            System.out.println("MINDEX: " + meat_index);
            meats[meat_index] = topping_choice[choice - 1];
            ++meat_index;

        } catch (IOException e) {
            System.err.println("File could not be opened!");
        }
        return 1;
    }

    public int get_calories()
    {
        int count = 0;
        for(int i = 0; i < 5; ++i)
        {
            if(meats[i] != null)
                ++count;
        }
        MeatCal = count * MeatCal;
        return MeatCal;
    }


}
