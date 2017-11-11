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

int main()
{
	//rules of the game
	maze Maze;	
	Maze.create_maze();
	cout << "\n\t\t\t - - - WELCOME TO THE MAZE GAME! - - - " << endl;
	cout << "\n - Every team needs to have two players." << endl;
	cout << " - Only one team (2 players) can be in the maze at a time." << endl;
	cout << " - Players will start randomly in the maze. 'Z' indicates where you start." << endl;
	cout << " - 'F' indicates the end of the maze." << endl;
	cout << " - Every checkpoint, spin for a reward and use it. The rewards are: " << endl;
	cout << "\t1) Player gets to move to their opponent's position." << endl;
	cout << "\t2) Player gets to ask their opponent for advice." << endl;
	cout << "\t3) Player gets to go again." << endl; 
	cout << " - First player to make it to end will win." << endl;
	cout << " - The maze is randomly generated each time the game is played." << endl;
	cout << " - PLOT TWIST: there may be no winners, in which case it will be a draw." << endl;
	cout << " - You have a maximum of 10 moves. After that game will cease." << endl;
	cout << "\n" << endl;

	//starts the player off at random positions	
	Maze.start_players_random();

	//while loop loops until there is a winner or moves are done
	//check to see if we have winner or the amount of moves are done
	while(Maze.get_moves() < 11)
	{
		if(Maze.get_moves() == 10)
		{
			cout << "\nThe game was a draw, neither player was able to finish! Better luck next time!" << endl;
			return 0;
		}
			
		if(!Maze.move_player1()) 
		{
			if(Maze.get_moves() == 10)
			{
				cout << "\nThe game was a draw, neither player was able to finish! Better luck next time!" << endl;
				return 0;
			}
			else 
				return 0;
		}
	
		if(!Maze.move_player2())
		{
			if(Maze.get_moves() == 10)
			{
				cout << "\nThe game was a draw, neither player was able to finish! Better luck next time!" << endl;
				return 0;
			}
			else
				return 0;
		}
	}
	

return 0;
}
