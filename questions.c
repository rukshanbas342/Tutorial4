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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Questions for Programming

    // Copies/Stores the Category name as a String into the category field of the question
    strcpy(questions[0].category, "Programming");
    // Copies/Stores the the Question as a String into the question field of the question
    strcpy(questions[0].question, "What does 'OOP' stand for?");
    // Copies/Stores the answer as a string into the answer field of the question
    strcpy(questions[0].answer, "Object-Oriented Programming");
    // Declares the points collected for this question
    questions[0].value = 100;
    // Declares the question as unaswered intially
    questions[0].answered = false;

    strcpy(questions[1].category, "Programming");
    strcpy(questions[1].question, "Which language is known for web development alongside HTML and CSS?");
    strcpy(questions[1].answer, "JavaScript");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "Programming");
    strcpy(questions[2].question, "What is the output of printf(\"%d\", 5+3);?");
    strcpy(questions[2].answer, "8");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "Programming");
    strcpy(questions[3].question, "What keyword is used to define a constant in C?");
    strcpy(questions[3].answer, "const");
    questions[3].value = 400;
    questions[3].answered = false;

    // Questions for Algorithms
    strcpy(questions[4].category, "Algorithms");
    strcpy(questions[4].question, "What is the time complexity of binary search?");
    strcpy(questions[4].answer, "O(log n)");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "Algorithms");
    strcpy(questions[5].question, "Which algorithm technique divides a problem into smaller subproblems and solves each recursively?");
    strcpy(questions[5].answer, "Divide & Conquer");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "Algorithms");
    strcpy(questions[6].question, "What does DFS stand for in graph traversal?");
    strcpy(questions[6].answer, "Depth-First Search");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "Algorithms");
    strcpy(questions[7].question, "What type of algorithm is Dijkstra's algorithm?");
    strcpy(questions[7].answer, "Shortest Path Algorithm");
    questions[7].value = 400;
    questions[7].answered = false;

    // Questions for Databases
    strcpy(questions[8].category, "Databases");
    strcpy(questions[8].question, "What does SQL stand for?");
    strcpy(questions[8].answer, "Structured Query Language");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "Databases");
    strcpy(questions[9].question, "Which SQL command is used to retrieve data from a database?");
    strcpy(questions[9].answer, "SELECT");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "Databases");
    strcpy(questions[10].question, "What is a primary key?");
    strcpy(questions[10].answer, "A unique identifier for each record in a table");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "Databases");
    strcpy(questions[11].question, "Which type of database is MongoDB?");
    strcpy(questions[11].answer, "NoSQL");
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
    // Iterates through each question within the array to find the question with the given category and value
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Compares the category and checks the point value
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            // If both are true, it will print the question and exit the function
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    // If a matching question is not found, it will print an error message
    printf("Question not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Iterates through each question within the array to find the question with the given category and value
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Compares the category and checks the point value
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            // If both are true, it will compare the answer with the users attempt (Case Insensitive)
            return strcasecmp(questions[i].answer, answer) == 0;
        }
    }
    // If a matching question is not found, it will return false
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // Iterates through each question within the array to find the question with the given category and value
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Compares the category and checks the point value
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            // If both are true, it will return status of the question (answered or unaswered)
            return questions[i].answered;
        }
    }
    // If the question isn't found, it will assume that it is unanswered
    return false;
}
