/*
        Topping class is the abstract base class for the dynamic binding to take place. It holds
        the abstract methods which correspond to pure virtual functions in c++. The derived class from
        toppings include veggies, sauces, cheeses, and meat.
 */
package com.company;
import java.io.*;
import java.nio.Buffer;
import java.io.IOException;
import java.util.Scanner;

abstract class Topping {
    protected static Scanner input = null;
    public Topping()
    {
        input = new Scanner(System.in);
    }

    abstract int display_list();
    abstract int create(int lines) throws IOException;
    abstract int count_lines() throws IOException;
    abstract int get_calories();
    abstract int create_special(int lines, int special_number) throws IOException;
}
