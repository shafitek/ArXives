// https://leetcode.com/problems/walking-robot-simulation/

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        enum Direction
        {
            NEG_X = 1,
            NEG_Y = 3,
            POS_X = 4,
            POS_Y = 2
        };
        Direction dir = POS_Y;
        set<int> obs_set;
        int x = 0, y = 0;
        short pos_neg = 1;
        int amt_to_inc = 0;
        int max_dist = 0;

        for (auto const &obs : obstacles)
            obs_set.insert(hash(obs[0], obs[1]));

        for (auto const &c : commands)
        {
            if (c == -2)
            {
                if (dir == POS_Y)
                    dir = NEG_X;
                else if (dir == NEG_X)
                    dir = NEG_Y;
                else if (dir == NEG_Y)
                    dir = POS_X;
                else if (dir == POS_X)
                    dir = POS_Y;
            }
            if (c == -1)
            {
                if (dir == POS_X)
                    dir = NEG_Y;
                else if (dir == NEG_Y)
                    dir = NEG_X;
                else if (dir == NEG_X)
                    dir = POS_Y;
                else if (dir == POS_Y)
                    dir = POS_X;
            }
            if (c > 0)
            {
                pos_neg = (dir % 2) ? -1 : 1;
                for (int s = 0; s < c; s++)
                {
                    if (dir == POS_X || dir == NEG_X)
                    {
                        amt_to_inc = x + pos_neg;
                        if (obs_set.count(hash(amt_to_inc, y)) > 0)
                            break;
                        x = amt_to_inc;
                    }
                    if (dir == POS_Y || dir == NEG_Y)
                    {
                        amt_to_inc = y + pos_neg;
                        if (obs_set.count(hash(x, amt_to_inc)) > 0)
                            break;
                        y = amt_to_inc;
                    }
                }
            }
            max_dist = std::max(x * x + y * y, max_dist);
        }

        return max_dist;
    }

    static uint32_t hash(int x, int y)
    {
        return ((uint32_t)(x + 30000) << 16) + (y + 30000);
    }
};