class Solution {
public:
    string losingPlayer(int x, int y) {
         // Calculate the number of complete turns that can be made
    int moves = 0;

    // Each move needs at least one 75-value coin and four 10-value coins
    while (x > 0 && y >= 4) {
        x--; // Use one 75-value coin
        y -= 4; // Use four 10-value coins
        moves++;
    }

    // If we can make at least one move, the player making the last move wins
    if (moves % 2 == 1) {
        return "Alice"; // Odd number of moves, Alice makes the last move
    } else {
        return "Bob"; // Even number of moves, Bob makes the last move
    }
    }
};