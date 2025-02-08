/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
char category[50];
int categoryValue;


// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i = 0; i<NUM_PLAYERS; i++){
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);  // Get player name
        players[i].name[strcspn(players[i].name, "\n")] = '\0';  // Remove the newline character at the end of input
        players[i].score = 0;  // Initialize score to 0 for each player
    }
    

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        display_categories();
        fgets(category, sizeof(category), stdin);  // Read input from the user
        category[strcspn(category, "\n")] = 0;  // Remove the newline character if it exists

        // Ask the user to input the point value for the question
         printf("Enter the point value (100, 200, 300, etc.): ");
          scanf("%d", &categoryValue);

        // Display the corresponding question based on the selected category and value
         display_question(category, categoryValue);

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
