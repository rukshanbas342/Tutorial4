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
#include <ctype.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Function Prototypes
void get_category_and_value(char *category, int *value);
void show_results(player *players, int num_players);

int main(int argc, char *argv[])
{
    (void)argc;  // Suppress warnings
    (void)argv;  

    player players[NUM_PLAYERS];

    // Initialize the game
    initialize_game();
    
    int current_player_index = 0;
    char category[BUFFER_LEN];
    int categoryValue;

    // Prompt for player names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0';  
        players[i].score = 0;  
    }

    // Game loop
    while (1)
    {
        int unanswered_questions = 0;

        // Display available categories
        display_categories();

        // Get valid category and point value
        get_category_and_value(category, &categoryValue);

        // Display question
        display_question(category, categoryValue);

        // Ask the player for an answer
        char answer[BUFFER_LEN];
        printf("Your answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';

        // Validate answer
        if (valid_answer(category, categoryValue, answer)) {
            printf("\033[1;32mCorrect!\033[0m\n");
            update_score(players, NUM_PLAYERS, players[current_player_index].name, categoryValue);
        } else {
            printf("\033[1;31mIncorrect!\033[0m\n");
        }
        
        // Move to the next player
        current_player_index = (current_player_index + 1) % NUM_PLAYERS;

        // Check if all questions are answered
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (!questions[i].answered) {
                unanswered_questions++;
            }
        }
        if (unanswered_questions == 0) {
            printf("Game Over!\n");
            show_results(players, NUM_PLAYERS);
            break;
        }
    }

    return EXIT_SUCCESS;
}

// Function to get a valid category and point value from the user
void get_category_and_value(char *category, int *value)
{
    while (1) {
        printf("Enter a category: ");
        fgets(category, BUFFER_LEN, stdin);
        category[strcspn(category, "\n")] = '\0';

        printf("Enter the point value (100, 200, 300, etc.): ");
        if (scanf("%d", value) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        getchar(); // Consume newline

        if (!already_answered(category, *value)) {
            break;
        }
        printf("That question has already been answered. Choose another.\n");
    }
}

// Displays the game results for each player, ranked from highest to lowest score
void show_results(player *players, int num_players)
{
    // Sort players by score in descending order (Bubble Sort)
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Display final results
    printf("\nGame Over! Final Scores:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d points\n", i + 1, players[i].name, players[i].score);
    }
    printf("-----------------------------------\n");
}
