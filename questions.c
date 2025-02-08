/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
 
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12
#define MAX_ANSWER_LEN 256
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "questions.h"

// Function prototype for to_lowercase()
void to_lowercase(char *str);

question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
// Questions for Programming

    // Copies/Stores the Category name as a String into the category field of the question
    strcpy(questions[0].category, "Programming");
    // Copies/Stores the the Question as a String into the question field of the question
    strcpy(questions[0].question, "What does 'OOP' stand for?");
    // Copies/Stores the answer as a string into the answer field of the question
    strcpy(questions[0].answers[0], "Object-Oriented Programming");
    strcpy(questions[0].answers[1], "Object Oriented Programming");
    // Declares the points collected for this question
    questions[0].value = 100;
    // Declares the question as unanswered initially
    questions[0].answered = false;

    strcpy(questions[1].category, "Programming");
    strcpy(questions[1].question, "Which language is known for web development alongside HTML and CSS?");
    strcpy(questions[1].answers[0], "JavaScript");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "What is the output of printf(\"%d\", 5+3);?");
    strcpy(questions[2].answers[0], "8");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "Programming");
    strcpy(questions[3].question, "What keyword is used to define a constant in C?");
    strcpy(questions[3].answers[0], "const");
    questions[3].value = 400;
    questions[3].answered = false;

    // Questions for Algorithms
    strcpy(questions[4].category, "Algorithms");
    strcpy(questions[4].question, "What is the time complexity of binary search?");
    strcpy(questions[4].answers[0], "O(log n)");
    strcpy(questions[4].answers[1], "O(logn)");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "Algorithms");
    strcpy(questions[5].question, "Which algorithm technique divides a problem into smaller subproblems and solves each recursively?");
    strcpy(questions[5].answers[0], "Divide & Conquer");
    strcpy(questions[5].answers[1], "Divide and Conquer");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "Algorithms");
    strcpy(questions[6].question, "What does DFS stand for in graph traversal?");
    strcpy(questions[6].answers[0], "Depth-First Search");
    strcpy(questions[6].answers[1], "Depth First Search");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "Algorithms");
    strcpy(questions[7].question, "What type of algorithm is Dijkstra's algorithm?");
    strcpy(questions[7].answers[0], "Shortest Path Algorithm");
    questions[7].value = 400;
    questions[7].answered = false;

    // Questions for Databases
    strcpy(questions[8].category, "Databases");
    strcpy(questions[8].question, "What does SQL stand for?");
    strcpy(questions[8].answers[0], "Structured Query Language");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "Databases");
    strcpy(questions[9].question, "Which SQL command is used to retrieve data from a database?");
    strcpy(questions[9].answers[0], "SELECT");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "Databases");
    strcpy(questions[10].question, "What is a primary key?");
    strcpy(questions[10].answers[0], "A unique identifier for each record in a table");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "Databases");
    strcpy(questions[11].question, "Which type of database is MongoDB?");
    strcpy(questions[11].answers[0], "NoSQL");
    questions[11].value = 400;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // Displays Categories as a header to the console
    printf("Categories:\n");
    // Iterates and displays each category in the categories array
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s: ", categories[i]);
        // Iterates and displays each question value for the current category that has not been answered
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            // Compares the question category with the current category and checks if the question has not been answered
            if (strcmp(questions[j].category, categories[i]) == 0 && !questions[j].answered) {
                // If both are true, it will print the questions point values
                printf("%d ", questions[j].value);
            }
        }
        // Prints a new line
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    char category_lower[MAX_LEN];
    strcpy(category_lower, category);
    to_lowercase(category_lower);  // Convert input category to lowercase

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char stored_category[MAX_LEN];
        strcpy(stored_category, questions[i].category);
        to_lowercase(stored_category);  // Convert stored category to lowercase

        if (strcmp(stored_category, category_lower) == 0 && questions[i].value == value) {
            if (questions[i].answered) {
                printf("This question has already been answered. Choose another.\n");
                return;
            }

            printf("Question: %s\n", questions[i].question);
            return;  // Do NOT mark it answered here
        }
    }
    printf("Question not found.\n");
}

// Helper function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Returns true if any answer in the array matches the user input
bool valid_answer(char *category, int value, char *answer)
{
    char category_lower[MAX_LEN];
    strcpy(category_lower, category);
    to_lowercase(category_lower);  // Convert input category to lowercase

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char stored_category[MAX_LEN];
        strcpy(stored_category, questions[i].category);
        to_lowercase(stored_category);  // Convert stored category to lowercase

        if (strcmp(stored_category, category_lower) == 0 && questions[i].value == value) {
            
            // Strip "What is"/"Who is"
            char *parsed_answer = answer;
            if (strncasecmp(answer, "what is ", 8) == 0) {
                parsed_answer += 8;
            } else if (strncasecmp(answer, "who is ", 7) == 0) {
                parsed_answer += 7;
            }

            char user_answer[MAX_ANSWER_LEN];
            strcpy(user_answer, parsed_answer);
            to_lowercase(user_answer);

            for (int j = 0; j < MAX_ANSWERS; j++) {
                if (strlen(questions[i].answers[j]) == 0) continue;  

                char correct_answer[MAX_ANSWER_LEN];
                strcpy(correct_answer, questions[i].answers[j]);
                to_lowercase(correct_answer);

                if (strcmp(correct_answer, user_answer) == 0) {
                    questions[i].answered = true;  // Mark the question as answered
                    return true;  
                }
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    char category_lower[MAX_LEN];
    strcpy(category_lower, category);
    to_lowercase(category_lower);  // Convert input category to lowercase
    // Iterates through each question within the array to find the question with the given category and value
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char stored_category[MAX_LEN];
        strcpy(stored_category, questions[i].category);
        to_lowercase(stored_category);  // Convert stored category to lowercase
        // Compares the category and checks the point value
        if (strcmp(stored_category, category_lower) == 0 && questions[i].value == value) {
            // If both are true, it will return status of the question (answered or unanswered)
            return questions[i].answered;
        }
    }
    // If the question isn't found, it will assume that it is unanswered
    return false;
}
