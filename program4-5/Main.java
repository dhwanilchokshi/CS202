/*
Dhwanil Chokshi
CS202
Program 5
           Program 5 is a continuation of program 4. In this program, you can choose to order your own
           pizza, or you can load the pizzas and pizzerias from a text file and see the specialty pizzas
           for a certain pizzeria. The pizzas are loaded in a random manner for the pizzerias. This means
           that every time you load the contents of the file, the order of the specialty pizzas is going to
           be different for the pizzerias. This program allows you to load pizzerias and pizzas from file,
           display the pizzerias and pizzas, find the closest pizzeria to the user (based on zip code), search
           for a certain pizzeria and see it's specialties, delete all the pizzerias, or delete a specific
           pizzeria. All the functionality of program 5 is contained in manager class, outer node class, and
           inner node class.
 */
package com.company;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    protected static Scanner input = null;

    public Main() {
        input = new Scanner(System.in);
    }

    public static void main(String[] args) throws IOException {
        // write your code here

        Manager manager = new Manager();
        //welcome user kickstarts everything
        manager.welcome_user();

    }
}
