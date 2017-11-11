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

#include "csmaze.h"
//checkpoint constructor with initialization list
checkpoint::checkpoint(): players(NULL), prize(NULL), position('\0')
{
}

checkpoint::checkpoint(const checkpoint &obj)
{
}
//destructor deallocated memory of players class array and reward class arrays, both of which are
//dynamically allocated
checkpoint::~checkpoint()
{
	if(players)
	{
		delete [] players;
		players = NULL;
	}
	if(prize)
	{
		delete [] prize;
		prize = NULL;
	}
}

//gets the random index from the shuffled array, and places random characters generated at checkpoints 
void checkpoint::place_position(char var)
{
	position = var;
}

//displays the checkpoint information
//z = starting checkpoint
//f = ending checkpoint
void checkpoint::display()
{
	if(position == 'f')
		cout << 'F' << " ";
	else
		cout << position << " ";
}

//displays player 1's information
void checkpoint::display_check1()
{
	players[0].display_check();
}

//displays player 2's information
void checkpoint::display_check_2()
{
	players[1].display_check2();
}

//sets the player information and stores it in the name class, prior to the
//game starting. Creates two dynamically stored players class for 2 players
void checkpoint::set_player_info()
{
	char player1[SIZE];
	char player2[SIZE];

	cout << "What is the name of the player #1: ";
	cin.get(player1, SIZE, '\n');
	cin.ignore(100, '\n');

	cout << "What is the name of the player #2: ";
	cin.get(player2, SIZE, '\n');
	cin.ignore(100, '\n');

	players = new player[2];
	players[0].set_name(player1);
	players[1].set_name(player2);

}

//displays the player info prior to the beginning of the game
void checkpoint::display_player_info()
{
	for(int i = 0; i < 2; i++)
	{
		players[i].display_name(i);
	}
}

//returns the position of the checkpoint
char checkpoint::get_position()
{
	return position;
}

//copies the player 1 info from the index where they will be moved on
void checkpoint::copy_player1(player *player1_obj)
{
	players[0].player1_copy(player1_obj);	
}

//copies the player 2 info from the index where they be moved on
void checkpoint::copy_player2(player *player2_obj)
{
	players[1].player2_copy(player2_obj);
}

//pastes the player 1 info into the new index where they have moved
void checkpoint::paste_player1(player *to_paste)
{
	if(!players)
	{
		players = new player[2];		
		players[0].player1_paste(to_paste);
	}
	else
		players[0].player1_paste(to_paste);
}

//pastes the player 2 info into the new index where they have moved
void checkpoint::paste_player2(player *to_paste2)
{
	if(!players)
	{
		players = new player[2];
		players[1].player2_paste(to_paste2);
	}
	else
		players[1].player2_paste(to_paste2);
}

//sets the prizes at the index when the player is about to be moved.
void checkpoint::set_prizes()
{
	if(!prize)
	{
		prize = new rewards[2];
		cout << "New prizes have been set at checkpoint!" << endl;
	}
	else
		cout << "Prizes exist in the checkpoint already!" << endl;
}

//gets the randomly generated prize for player 1, and returns the number to see which prize it is
int checkpoint::get_player1_prize()
{
	int collect;
	collect = prize[0].get_reward();
	return collect;
}

//gets the randomly generated prize for player 2, and returns the number to see which prize it is
int checkpoint::get_player2_prize()
{
	int pick;
	pick = prize[1].get_reward();
	return pick;
}

vertex::vertex(): head(NULL)
{
	srand(time(0));
}

vertex::vertex(const vertex & obj)
{
}

//calls the recursive delete all function which goes through and deletes everything
vertex::~vertex()
{
	if(head)
		delete_all(head);	
}

//recursive deletes for deleting all the nodes
void vertex::delete_all(node *&head)
{
	if(!head)
		return;
	
	delete_all(head->go_next());
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//wrapper for the recursive function to create the doubly linked list. randomly assigns a letter
//to each node of the doubly linked list
void vertex::create_list(vertex *connection1, char save[])
{
	int length = strlen(save);
	random_shuffle(&save[0], &save[length]);
	int num = rand() % length;
	char to_place = save[num];
	while(to_place == 'f')
	{
		num = rand() % length;
		to_place = save[num];
	}
	return create_list(head, connection1, to_place);
}

//recusrive adding to the doubly linked list
void vertex::create_list(node *&head, vertex *connection1, char &letter)
{
	
	if(!head)
	{
		node *temp = new node;
		temp->get_adjacent() = connection1;
		temp->go_previous() = NULL;
		temp->go_next() = NULL;
		temp->place_position(letter);
		connection1->head = temp;
		return;
	}
/*
	else if(!head->go_next())
	{
		node *temp = new node;
		node *current = connection1->head;
		temp->get_adjacent() = connection1;
		temp->go_previous() = current;
		current->go_next() = temp;
		temp->go_next() = NULL;
		temp->place_position(letter);
		return;
	}
*/
	else
	{
		node *current = traverse(head);
		node *temp = NULL;
		temp = new node;
		temp->get_adjacent() = connection1;
		temp->go_previous() = current;
		current->go_next() = temp;
		temp->go_next() = NULL;
		temp->place_position(letter);
		return;
	}
			
}
//recursive traversal function which traverses and returns the node
node *vertex::traverse(node *head)
{
	if(!head)
		return head;

	if(!head->go_next())
		return head;

	return traverse(head->go_next());
}

//gets the location of where the user is going to move based on their pick
char vertex::get_location(int &move_point)
{
	char to_get;
	if(move_point == 1)
	{
		node *current = head;
		if(current)
			to_get = current->get_position();
	}
	else if(move_point == 2)
	{
		node *current = head->go_next();
		if(current)
			to_get = current->get_position();
	}
	else if(move_point == 3)
	{
		node *current = head->go_next()->go_next();
		if(current)
			to_get = current->get_position();
	}
	return to_get;	
}

node::node(): adjacent(NULL), previous(NULL), next(NULL)
{
}

node::node(const node &obj)
{
}
		
node::~node()
{

}

node *& node::go_previous()
{
	return previous;
}

node *& node::go_next()
{
	return next;
}
	
node *& vertex::return_head()
{
	return head;
}

vertex*& node::get_adjacent()
{
	return adjacent;
}
//calls the recursive function which traverses through and displays the checkpoint info in nodes
void vertex::display_vertex(vertex *some)
{
	move(head);
}
//recursive function which traverses and displays
void vertex::move(node *head)
{
	if(!head)
		return;

	head->display();
	move(head->go_next());
}

//constructor sets up the adjacency list head pointers to null and sets other data members to their respective starting values
maze::maze(): Players_Copy(NULL), random_index(0), player_1_index(0), player_2_index(0), turns(0), moves(0)
{
	srand(time(0));
	adjacency_list = new vertex[table_size];
	for(int i = 0; i < table_size; i++)
	{
		adjacency_list[i].return_head() = NULL;
	}	
}

maze::maze(const maze &obj)
{
}

//for loops through the adj list and calls vertex destructor to deallocate memory
//deletes the instance Players_Copy used to copy and paste player information
maze::~maze()
{
	if(adjacency_list)
	{
		for(int i = 0; i < table_size; i++)
		{
			adjacency_list[i].~vertex();
			adjacency_list[i].~checkpoint();
		}
		delete [] adjacency_list;
		adjacency_list = NULL;
	}
	if(Players_Copy)
	{
		delete Players_Copy;
		Players_Copy = NULL;
	}
}

//randomly shuffles the characters and assigns them to their checkpoints for the adj list
//if the value of letter is 'f' then we dont want a doubly linked list because you cant traverse
//anywhere once u reach the finish positions
//adds three nodes of doubly linked list each time
void maze::create_maze()
{
	char position[21]; 
	char saver[21];

	for(int i = 0; i < 21; i++)
	{
		position[i] = i + 'a';
	}

	random_shuffle(&position[0], &position[20]);

	for(int i = 0; i < table_size; i++)
	{
		adjacency_list[i].place_position(position[i]);
		saver[i] = position[i];				//copying original array in another one to pass around
	}
	
	for(int i = 0; i < table_size; i++)
	{
		if(position[i] != 'f')
		{
			//to make sure to add only three nodes per index of adj list
			for(int j = 0; j < 3; j++)
			{
				adjacency_list[i].create_list(&adjacency_list[i], saver);
			}
		}
	}
}

//function starts the player at random assigning them random indices and setting them at that position
void maze::start_players_random()
{
	random_index = rand() % 20;
	adjacency_list[random_index].place_position('Z');	//places 'z' where the starting position is

	cout << "HERE IS YOUR MAZE: " << endl;
	display_maze();		//displays the maze

	adjacency_list[random_index].set_player_info();		//creates the players and sets them at the random index
	adjacency_list[random_index].display_player_info();	//displays the information of the player at the index
	player_1_index = random_index;				//player 1 index is now random index
	player_2_index = random_index;				//and so is player 2's index
}

//function that moves player 1 to their desired position by copying their informatio into a player object
//and pasting their information into the new index
int maze::move_player1()
{
	if(moves == 10)						//move limit is 10, so if move limit is reached, then exit
		return 0;
	int move = 0;	//not move, but player choice of where they want to move
	char player1_loc;	
	int collect_prize;
	cout << '\n'; adjacency_list[player_1_index].display_check1();
	cout << " where would you like to move?" << endl;
	cout << "1 - Left Checkpoint" << endl;
	cout << "2 - Right Checkpoint" << endl;
	cout << "3 - Down Checkpoint" << endl;	
	cout << "Choice: ";
	cin >> move;
	cin.ignore();
	++moves;		//increment move

	//turns is 0 in beginning so we want to copy and paste player in their new index
	if(turns == 0)
	{
		Players_Copy = new player;		
		adjacency_list[random_index].copy_player1(Players_Copy);
		player1_loc = adjacency_list[random_index].get_location(move);		//player1_loc gets character of checkpoint

		if(player1_loc == 'f')							//if 'f' has been reached, game has been won
		{	
			adjacency_list[random_index].display_check1();
			cout << " has won the game!" << endl;	
			return 0;
		}
		//find the index position that the player has chosen to move to
		//once that position has been found, save it in player_1_index
		for(int i = 0; i < table_size; i++)
		{
			if(adjacency_list[i].get_position() == player1_loc)
			{
				adjacency_list[i].paste_player1(Players_Copy);
				player_1_index = i;
			}
		}	
		adjacency_list[player_1_index].place_position('z');
		//displays the moving of player to their new checkpoint
		adjacency_list[random_index].display_check1();
		cout << " moving to position: " << player1_loc << endl << endl;
		
		//set the prizes at the new index
		adjacency_list[player_1_index].set_prizes();	
		collect_prize = adjacency_list[player_1_index].get_player1_prize();
		if(collect_prize == 1)
		{
			move_player1_to_player2(player_1_index, player_2_index);
		}
		else if(collect_prize == 2)
		{
			ask_player_advice();
		}
		else
		{
			go_again();
		}
//		display_maze();
	
	}
	//else statement executes if the turns is greater than 0 and does same as above if statement
	else
	{
		adjacency_list[player_1_index].copy_player1(Players_Copy);	
		player1_loc = adjacency_list[player_1_index].get_location(move);

		if(player1_loc == 'f')
		{
			adjacency_list[player_1_index].display_check1(); cout << " has won the game!" << endl;	
			return 0;
		}

		for(int i = 0; i < table_size; i++)
		{
			if(adjacency_list[i].get_position() == player1_loc)
			{
				adjacency_list[i].paste_player1(Players_Copy);
				player_1_index = i;	
			}
		}
		adjacency_list[player_1_index].display_check1();
		cout << " moving to position: " << player1_loc << endl << endl;

		adjacency_list[player_1_index].set_prizes();
		collect_prize = adjacency_list[player_1_index].get_player1_prize();
		if(collect_prize == 1)
		{
			move_player1_to_player2(player_1_index, player_2_index);
		}
		else if(collect_prize == 2)
		{
			ask_player_advice();
		}
		else
		{
			go_again();
		}
	}
//	display_maze();

return 1;
}

//moves the player 2 by copyin their information from the desired index and moving it to their new index position
int maze::move_player2()
{
	if(moves == 10)
		return 0;
	int move_choice = 0;
	char player2_loc;
	int collect;
	cout << '\n'; adjacency_list[player_2_index].display_check_2();
	cout << " where would you like to move?" << endl;
	cout << "1 - Left Checkpoint" << endl;
	cout << "2 - Right Checkpoint" << endl;
	cout << "3 - Down Checkpoint" << endl;
	cout << "Choice: ";
	cin >> move_choice;
	cin.ignore();
	++moves;

	if(turns == 0)
	{
		adjacency_list[random_index].copy_player2(Players_Copy);
		player2_loc = adjacency_list[random_index].get_location(move_choice);

		if(player2_loc == 'f')
		{
			adjacency_list[random_index].display_check_2(); cout << " has won the game!" << endl;	
			return 0;
		}

		for(int i = 0; i < table_size; i++)
		{
			if(adjacency_list[i].get_position() == player2_loc)
			{
				adjacency_list[i].paste_player2(Players_Copy);
				player_2_index = i;	
			}	
		}
		++turns;
		adjacency_list[player_2_index].display_check_2();
		cout << " moving to position: " << player2_loc << endl << endl;

		adjacency_list[player_2_index].set_prizes();
		collect = adjacency_list[player_2_index].get_player2_prize();
		if(collect == 1)
		{
			move_player2_to_player1(player_1_index, player_2_index);
		}
		else if(collect == 2)
		{
			ask_player1_advice();
		}
		else
		{
			player2_again();
		}
//		display_maze();
	}
	else
	{
		adjacency_list[player_2_index].copy_player2(Players_Copy);	
		player2_loc = adjacency_list[player_2_index].get_location(move_choice);	

		if(player2_loc == 'f')
		{
			adjacency_list[random_index].display_check_2(); cout << " has won the game!" << endl;	
			return 0;
		}

		for(int i = 0; i < table_size; i++)
		{
			if(adjacency_list[i].get_position() == player2_loc)
			{
				adjacency_list[i].paste_player2(Players_Copy);
				player_2_index = i;
				adjacency_list[player_2_index].set_prizes();
			}
		}	
		adjacency_list[player_2_index].display_check_2();
		cout << " moving to position: " << player2_loc << endl << endl;
		adjacency_list[player_2_index].set_prizes();
		collect = adjacency_list[player_2_index].get_player2_prize();
		if(collect == 1)
		{
			move_player2_to_player1(player_1_index, player_2_index);
		}
		else if(collect == 2)
		{
			ask_player1_advice();
		}
		else
		{
			player2_again();
		}
	}
//	display_maze();
return 1;	
}

//reward that moves the player 1 to the position of player2
void maze::move_player1_to_player2(int &index1, int &index2)
{
	cout << "\nCongratulations "; adjacency_list[index1].display_check1(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[index1].display_check1(); cout << " moves to ";
	adjacency_list[index2].display_check_2(); cout << "'s spot!" << endl;

	adjacency_list[index1].copy_player1(Players_Copy);		
	adjacency_list[index2].paste_player1(Players_Copy);

	index1 = index2;

	adjacency_list[index1].display_check1(); cout << " has moved to ";
	adjacency_list[index2].display_check_2(); cout << "'s position!" << endl;

	adjacency_list[index1].display_check1(); cout << " is at position " << adjacency_list[index1].get_position() << endl;
	adjacency_list[index2].display_check_2(); cout << " is at position " << adjacency_list[index2].get_position() << endl;	
}

//reward that moves player 2 to the position of player 1
void maze::move_player2_to_player1(int &player_1, int &player_2)
{
	cout << "\nCongratulations "; adjacency_list[player_2].display_check_2(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[player_2].display_check_2(); cout << " moves to ";
	adjacency_list[player_1].display_check1(); cout << "'s spot!" << endl;


	adjacency_list[player_2].copy_player2(Players_Copy);		
	adjacency_list[player_1].paste_player2(Players_Copy);

	player_2 = player_1;	

	adjacency_list[player_2].display_check_2(); cout << " has moved to ";
	adjacency_list[player_1].display_check1(); cout << "'s position!" << endl;
	
	adjacency_list[player_1].display_check1(); cout << " is at position " << adjacency_list[player_1].get_position() << endl;
	adjacency_list[player_2].display_check_2(); cout << " is at position " << adjacency_list[player_2].get_position() << endl;
}

//reward where player 1 can ask player 2 for advice
void maze::ask_player_advice()
{
	char advice[SIZE];

	cout << "\nCongratulations "; adjacency_list[player_1_index].display_check1(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[player_2_index].display_check_2(); cout << " will give you advice where to move on the next move!" << endl;
	adjacency_list[player_2_index].display_check_2(); cout << " where should "; 
	adjacency_list[player_1_index].display_check1(); cout << " move on next turn (left, right, down): ";
	cin.get(advice, SIZE, '\n');
	cin.ignore(100, '\n');	
	adjacency_list[player_1_index].display_check1(); cout << ", "; 
	adjacency_list[player_2_index].display_check_2(); cout << " advises you to move " << advice << " on your next turn!" << endl;
}

//reward where player 2 gets to ask player 1 for advice
void maze::ask_player1_advice()
{
	char advice[SIZE];

	cout << "\nCongratulations "; adjacency_list[player_2_index].display_check_2(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[player_1_index].display_check1(); cout << " will give you advice where to move on the next move!" << endl;
	adjacency_list[player_1_index].display_check1(); cout << " where should "; 
	adjacency_list[player_2_index].display_check_2(); cout << " move on next turn (left, right, down): ";
	cin.get(advice, SIZE, '\n');
	cin.ignore(100, '\n');	
	adjacency_list[player_2_index].display_check_2(); cout << ", "; 
	adjacency_list[player_1_index].display_check1(); cout << " advises you to move " << advice << " on your next turn!" << endl;

}

//reward where player 1 gets to go again
void maze::go_again()
{
	cout << "\nCongratulations "; adjacency_list[player_1_index].display_check1(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[player_1_index].display_check1(); cout << " gets to go again!" << endl;
	move_player1();	
}

//reward where player 2 gets to go again
void maze::player2_again()
{
	cout << "\nCongratulations "; adjacency_list[player_2_index].display_check_2(); cout << "! You won a reward!" << endl;
	cout << "Reward: "; adjacency_list[player_2_index].display_check_2(); cout << " gets to go again!" << endl;	
	move_player2();
}

//returns the moves
int maze::get_moves()
{
	return moves;
}

//displays the maze
void maze::display_maze()
{
	for(int i = 0; i < table_size; i++)
	{
		adjacency_list[i].display();
		adjacency_list[i].display_vertex(&adjacency_list[i]);
		cout << endl;
	}
}
