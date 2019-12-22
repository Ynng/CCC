    #include <iostream>
    using namespace std;
    int input[4][4];

    void solveA()
    {
        for (int i = 0; i < 3; i++)
        {
            if (input[i][3] == 1)
            {
                if (input[i][0] == -1)
                {
                    input[i][0] = input[i][1] - (input[i][2] - input[i][1]);
                    input[3][0]--;
                }
                else if (input[i][1] == -1)
                {
                    input[i][1] = input[i][0] + (input[i][2] - input[i][0]) / 2;
                    input[3][1]--;
                }
                else if (input[i][2] == -1)
                {
                    input[i][2] = input[i][1] + (input[i][1] - input[i][0]);
                    input[3][2]--;
                }

                input[i][3]--;
            }
            if (input[3][i] == 1)
            {
                if (input[0][i] == -1)
                {
                    input[0][i] = input[1][i] - (input[2][i] - input[1][i]);
                    input[0][3]--;
                }
                else if (input[1][i] == -1)
                {
                    input[1][i] = input[0][i] + (input[2][i] - input[0][i]) / 2;
                    input[1][3]--;
                }
                else if (input[2][i] == -1)
                {
                    input[2][i] = input[1][i] + (input[1][i] - input[0][i]);
                    input[2][3]--;
                }
                input[3][i]--;
            }
        }
    }

    bool checkA(){
        for (int i = 0; i < 3; i++)
        {
            if (input[i][3] == 1)
            {
                return true;
            }
            if (input[3][i] == 1)
            {
                return true;
            }
        }
        return false;
    }

    int main()
    {
        string temp;
        for (int i = 0; i < 3; i++)
        {
            input[i][3] = 0;
            input[3][i] = 0;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> temp;
                if (temp == "X")
                {
                    input[i][j] = -1;
                    input[i][3]++;
                    input[3][j]++;
                }
                else
                    input[i][j] = std::stoi(temp, nullptr);
            }
        }
        while(checkA()){
            solveA();
        }

        // for (int i = 0; i < 4; i++)
        // {
        //     printf("%d %d %d %d\n", input[i][0], input[i][1], input[i][2], input[i][3]);
        // }
        for (int i = 0; i < 3; i++)
        {
            printf("%d %d %d\n", input[i][0], input[i][1], input[i][2]);
        }
        return 0;
    }