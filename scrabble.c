#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter, A-Z
int POINTS[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Get a word from each player
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate each player's score
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Calculate the Scrabble score of a word
int compute_score(string word)
{
    int score = 0;

    // Check each character in the word
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Only count letters
        if (isalpha(word[i]))
        {
            // Convert the letter to uppercase
            char letter = toupper(word[i]);

            // Find the letter's position in POINTS
            int index = letter - 'A';

            // Add the letter's value to the score
            score += POINTS[index];
        }
    }

    return score;
}
