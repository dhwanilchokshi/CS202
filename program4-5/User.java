/*
        The user class has head of the DLL. This class is responsible for adding a new node each time
        the user orders a new pizza. The node is added at the beginning so we can quickly retrieve the
        most recent order of the user. The User class also has functions to display the most recent order,
        display all orders, delete more recent order, delete all orders.
 */
package com.company;
import java.io.IOException;

public class User {

    protected DLL_node head;

    public User()
    {
        this.head = null;
    }

    //displays most recent
    public void display_top()
    {
        if(this.head == null)
            return;

        head.display_recent();
    }

    //displays all the orders
    public int display_all()
    {
        int orders = 0;
        if(this.head == null)
            return 0;
        if(this.head.go_next() == null)
        {
            ++orders;
            System.out.println("Order #" + orders);
            head.display_recent();
            return 1;
        }
        return display_all(head, orders);
    }

    //recursive function which displays all node data
    //calls display_recent, because that function can go through
    //and display all, so we can use display recent to actually display recent
    //and to display all
    private int display_all(DLL_node head, int orders)
    {
        if(head == null)
            return 1;
        ++orders;
        System.out.println("Order #" + orders);
        head.display_recent();
        return display_all(head.go_next(), orders);
    }

    //adds a new node with the user order.
    public int add(boolean special, int special_number) throws IOException {
        if(this.head == null)
        {
            head = new DLL_node();
            head.get_order(special, special_number);
            head.set_next(null);
            head.set_previous(null);
            return 1;
        }
        head = add(head);
        head.get_order(special, special_number);
        return 1;
    }

    //adds a new node in the beginning if another node already exists
    private DLL_node add(DLL_node head) throws IOException {
        DLL_node temp = new DLL_node();
        temp.set_next(head);
        if(head != null)
            head.set_previous(temp);
        temp.set_previous(null);
        head = temp;
        return head;
    }

    //deletes the most recent order.
    public int delete_recent()
    {
        if(this.head == null)
            return 0;

        if(this.head.go_next() == null)
        {
            this.head = null;
            return 1;
        }

        head = delete_recent(head);
        return 1;
    }

    //private function which deletes the most recent node if other nodes exist
    public DLL_node delete_recent(DLL_node head)
    {
        DLL_node temp = head.go_next();
        head.go_next().set_previous(null);
        head = temp;
        return head;
    }

    //delete all orders of the user
    public int delete_all_orders()
    {
        if(this.head == null)
            return 0;

        this.head = null;
        return 1;
    }


}
