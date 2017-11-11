/*
Dhwanil Chokshi
CS202
Program1
		The purpose of this program was to create a maze game with functionality of rewards and movement
		with the implementation of data structures of graph, doubly linked list, and linear linked list
		of arrays. The game should allow the players to move from checkpoint to checkpoint, allowing the
		players to be able to get rewards at each checkpoint. 

		note to grader: run the program multiple times.
*/

#include "player.h"

name::name(): player_name(NULL)
{
}

name::name(const name &obj)
{

}
//destructor for name deallocates the memory for name
name::~name()
{
	if(player_name)
	{
		delete [] player_name;
		player_name = NULL;
	}
}

//sets the name of the players before the game is going to start
void name::set_name(char name[])
{
	if(player_name)
	{
		delete [] player_name;
		player_name = NULL;
	}
	player_name = new char[strlen(name) + 1];
	strcpy(player_name, name);
		
}

//Displays the name of the players prior to game starting	
void name::display_name(int index)
{
	cout << "Name of player #" << index + 1 << ": " << player_name << endl;
}

//copies the player one information into obj to send to the next index
void name::player1_copy(player *obj)
{
	if(obj->player_name)
	{
		delete [] obj->player_name;
		obj->player_name = NULL;
	}
	if(this->player_name)
	{
		obj->player_name = new char[strlen(this->player_name) + 1];
		strcpy(obj->player_name, this->player_name);
	}
}

//copies the player 2 information into obj2 to send to the new index
void name::player2_copy(player *obj2)
{
	if(obj2->player_name)
	{
		delete [] obj2->player_name;
		obj2->player_name = NULL;
	}

	if(this->player_name)
	{
		obj2->player_name = new char[strlen(this->player_name) + 1];
		strcpy(obj2->player_name, this->player_name);
	}
}

//pastes the player 1 info into the new index
void name::player1_paste(player *paste)
{
	if(!this->player_name)
	{
		this->player_name = new char[strlen(paste->player_name) + 1];
		strcpy(this->player_name, paste->player_name);
	}
	else
	{
		strcpy(this->player_name, paste->player_name);	
	}
}

//pastes the player 2 information into the new index
void name::player2_paste(player *paste2)
{
	if(!this->player_name)
	{
		this->player_name = new char[strlen(paste2->player_name) + 1];
		strcpy(this->player_name, paste2->player_name);
	}
	else
		strcpy(this->player_name, paste2->player_name);

}

//displays the player 1's name
void name::display_check()
{
	cout << player_name;
}

//dsplays the player 2's name
void name::display_check2()
{
	cout << player_name;
}

l_node::l_node(): reward(NULL), next(NULL)
{
	srand(time(0));
}

//deletes the reward class array allocated
l_node::~l_node()
{
	if(reward)
	{
		delete [] reward;
		reward = NULL;
	}
}

l_node *& l_node::go_next()
{
	return next;
}

//sets the array of rewards
void l_node::set_array_rewards()
{
	reward = new rewards[1];
}

//generates a random prize
int l_node::random_prize(int &prize)
{
	prize = rand() % 3 + 1;
	return prize;
}

player::player() 
{

}

player::player(const player &obj)
{

}

player::~player()
{
	
}

rewards::rewards(): head(NULL), top_index(0)
{

}
//calls the recursive function to delete memory of LLL of arrays
rewards::~rewards()
{
	if(head)
		remove(head);
}
//recursive delete which does tail recursion delete on the nodes
void rewards::remove(l_node *&head)
{
	if(!head)
		return;
	remove(head->go_next());
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//randomly generates a reward and creates a LLL of arrays and sends it out
int rewards::get_reward()
{
	int prize_number = 0;
	if(!head)
	{
		head = new l_node;
		head->set_array_rewards();
		prize_number = head[top_index].random_prize(prize_number);	
		head->go_next() = NULL;		
		++top_index;
		return prize_number;
	}
	if(top_index == 1)
	{
		l_node *temp = new l_node;
		temp->set_array_rewards();
		prize_number = temp[top_index].random_prize(prize_number);
		temp->go_next() = head;
		head = temp;
		top_index = 0;
		return prize_number;
	}
	else
	{
		l_node *temp = new l_node;
		temp->set_array_rewards();
		prize_number = temp[top_index].random_prize(prize_number);
		temp->go_next() = head;
		head = temp;
		++top_index;
		return prize_number;
	}
}

