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

//class checkpoint is the top of the hierarchy, this class consist of information such as
//checkpoint names, calls the display of player functions to display the name of the player
//and has functionality to copy and paste players into different indices when they want to move
//this class also has a pointer to players and rewards to create an array of those classes to have
//two players and two rewards. "position" indicates the name of the checkpoint which is a random
//character
class checkpoint
{
	public:
		checkpoint();
		checkpoint(const checkpoint &);
		~checkpoint();
		void place_position(char var);			//places the position of the adjacency_list after randomly generating 
		void display();					//displays the maze with starting position of player and ending position to win
		void display_check1();				//displays information about player1
		void display_check_2();				//displays information about player2
		void set_player_info();				//sets the information of both players prior to starting game
		void display_player_info();			//displays the information of both players prior to starting game
		char get_position();				//returns the position of a certain checkpoint
		void copy_player1(player *);			//copies information of player one from the index they are at
		void copy_player2(player *);			//copies information of player two from the index they are at
		void paste_player1(player *);			//pastes the information of player one into new index
		void paste_player2(player *);			//pastes the information of player two into new index
		void set_prizes();				//sets up the prizes prior to player moving to the index
		int get_player1_prize();			//gets the prize of player one from random generator and returns
		int get_player2_prize();			//gets the prize of player two from random generator and returns
	protected: 
		player *players;				//player pointer to create an array of 2 player class
		rewards *prize;					//rewards pointer to create an array of 2 reward class
		char position;					//position indicates name of checkpoint
};

//the node class is responsible for returning the next, previous, and adjacent
//pointers since they are protected members. 
class node: public checkpoint
{
	public:
		node();
		node(const node &obj);
		~node();
		node *& go_previous();				//returns previous pointer to go to previous node
		node *& go_next();				//returns next pointer to go to next node
		class vertex *&get_adjacent();			//returns the adjacent pointer
	protected:
		class vertex *adjacent;
		node *previous;
		node *next;
};

//vertex class is responsible for returning the head pointer so we can make all head pointers of the adj list
//to null in the beginning. Also the vertex is responsible for creating the list, which is the doubly linked list.
//Vertex also displays the vertex information when we want to display the maze. The get location function of the
//vertex returns the location of the checkpoint name when the player wants to move, indicating the position they
//are going to be moving at.
class vertex: public checkpoint
{
	public:
		vertex();
		vertex(const vertex & obj);
		~vertex();
		node *& return_head();				//returns the head pointer to set it to null
		void create_list(vertex *connection1, char save[]);		//creates the doubly linked list connected to adj list
		void display_vertex(vertex *some);				//displays the doubly linked list checkpoint info
		char get_location(int&);						//gets location player moves to by taking in the move as arg
	protected:
		node *head;							//head pointer because used to create the doubly linked list
		void create_list(node *&head, vertex* connection1, char &letter);	//private function because passing in head for recursion	
		void move(node *);						//recursive traverse to display checkpoint in doubly linked list
		node *traverse(node *);						//traverses returning the node, so we know where to add recursively
		void delete_all(node *&);					//for the destructor to deallocate all the memory

};

//the most important class of this game is the maze class. This class is responsivle for creating the maze.
//This class is also responsible for moving both the players, and all the rewards that the player gets to use
//upon reaching checkpoints. Maze class has a pointer to vertex to create the adjacency list, it has a pointer
//to a player so we can pass around player obj to copy and paste information into the new indices. There is random
//index which is what the user is assigned when they begin. There are both the player index so it keeps track of 
//where all the players are at at all times. There is turns and moves which keep track of when the game should end
//if a certain number of moves are exceeded.
class maze: public vertex
{
	public:
		maze();
		maze(const maze &obj);
		~maze();
		void create_maze();					//creates the maze randomly each time
		void start_players_random();				//starts the player at random positions
		int move_player1();					//moves player 1 to their desired index
		int move_player2();					//moves player 2 to their desired index
		void move_player1_to_player2(int&, int&);		//reward: moving player 1 to player 2 position
		void move_player2_to_player1(int&, int&);		//reward: moving player 2 to player 1 position
		void ask_player_advice();				//reward: player 1 asks player 2 for advice
		void ask_player1_advice();				//reward: player 2 asks player 1 for advice
		void go_again();					//player 1 gets to go again
		void player2_again();					//player 2 gets to go again
		int get_moves();					//returns the moves, to make sure we dont exceed specified move limit
		void display_maze();					//displays the maze
	protected:
		vertex *adjacency_list;					//creates the list
		player *Players_Copy;					//obj to pass around to copy and paste player info
		int random_index;					//random_index to get the players started at random positions
		int player_1_index;					//player 1 index to know where player 1 is at
		int player_2_index;					//player 2 index to know where player 2 is at
		int turns;						//turns to keep track of player turns
		int moves;						//keeps the moves to make sure we dont exceed move limit
};

