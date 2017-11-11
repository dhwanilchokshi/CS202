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

#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int SIZE = 100;
const int table_size = 20;

//name class is responsible for storing the player names and is responsible for the functions which copy the player info
//and paste the player info into their new indices. Also it has the display function to display each player
class name
{
	public:
		name();
		name(const name &obj);
		~name();
		void set_name(char name[]);				//sets the name of the players at the beginning of the game
		void display_name(int);					//displays the name of the players before the game starts
		void player1_copy(class player *obj);			//copies player 1 info 
		void player2_copy(class player *obj2);			//copies player 2 info
		void player1_paste(class player *paste);		//pastes the player 1 into their new index
		void player2_paste(class player *paste2);		//pastes the player 2 into their new index
		void display_check();					//displays info for player 1
		void display_check2();					//displays info for player 2
	protected:
		char *player_name;
};

//l_node is responsible for setting the rewards of arrays, therefore it has a pointer to rewards class, and 
//randomly generating a random prize to send back to the player when they hit a new checkpoint. 
class l_node
{
	public:
		l_node();
		~l_node();
		l_node *& go_next();
		void set_array_rewards();		//sets the dynamically allocated array
		int random_prize(int &);		//generates a random prize
	protected:			
		class rewards *reward;			//pointer to rewards to generate a random reward
		l_node *next;				

};

//player class has no major functionality other than it is used to call the functions of its parent(name). 
class player: public name
{
	public:
		player();
		player(const player &obj);
		~player();
	protected:
}; 

//rewards class is responsible for creating the linear linked list of arrays, and getting the reward from
//randomly generated number. 
class rewards: public player
{
	public:
		rewards();
		rewards(const rewards &obj);
		~rewards();
		int get_reward();			//gets the randomly generated reward
	protected:
		l_node *head;				//to create the LLL of arrays
		int top_index;				//to keep track of when to add a new node
		void remove(l_node *&);			//for recursive deallocation of memory.
};
