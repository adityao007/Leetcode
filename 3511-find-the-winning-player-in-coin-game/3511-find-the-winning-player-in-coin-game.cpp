class Solution {
public:
    string losingPlayer(int x, int y) {
    int moves = 0;
    while (x > 0 && y >= 4) {
        x--;
        y -= 4; 
        moves++;
    }

  
    if (moves % 2 == 1) {
        return "Alice"; 
    } else {
        return "Bob"; 
    }
    }
};