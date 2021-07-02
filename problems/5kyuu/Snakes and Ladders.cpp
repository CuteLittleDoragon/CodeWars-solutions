#include <map>

using namespace std;

class SnakesLadders
{
    private:
        int active_player{}, waiting_player{};
        bool turn{}, game_over{};
        map<int, int> board;
    public:
        SnakesLadders()
        : board{{2, 38}, {7, 14}, {8, 31}, {15, 26}, {16, 6},
            {21, 42}, {28, 84}, {36, 44}, {46, 25}, {49, 11}, {51, 67},
            {62, 19}, {64, 60}, {71, 91}, {74, 53}, {78, 98}, {87, 94}, 
            {89, 68}, {92, 88}, {95, 75}, {99, 80}}
        {
            for (size_t i = 1; i <= 100; ++i)
            {
                if (board.find(i) == board.end()) board[i] = i;
            }
            
        }
        string play(int die1, int die2)
        {
            if (game_over) return "Game over!";
            
            int sum = active_player + die1 + die2;
            active_player = board[sum > 100 ? (200 - sum) : sum];
            
            if (active_player == 100) 
            {
                game_over = true;
                return "Player " + to_string(turn + 1) + " Wins!";
            }
            
            string output{"Player " + to_string(turn + 1) + 
                " is on square " + to_string(active_player)};
            
            if (die1 != die2) 
            {
                swap(active_player, waiting_player);
                turn = !turn;
            }
            
            return output;
        }
};
