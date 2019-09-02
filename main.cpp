#include <iostream>

class Gameboard
{
    char gameSpace[4][4];
public:
    char getState(int, int);
    void forceSetState(int, int, char);
    int setState(int, int, char);
    int isFinished();
    void printGameSpace();
    Gameboard();
};

char Gameboard::getState(int row, int column)
{
    return gameSpace[row][column];
}

void Gameboard::forceSetState(int row, int column, char state)
{
    gameSpace[row][column] = state;
}

int Gameboard::setState(int row, int column, char state) // (1) successful   (0) not successful
{
    if (gameSpace[row][column] == '-')
    {
        gameSpace[row][column] = state;
        return 1;
    }

    return 0;
}

int Gameboard::isFinished() // (0) Not Finished   (1) winner x   (2) winner o
{
    if (gameSpace[0][0] == gameSpace[1][1] && gameSpace[1][1] == gameSpace[2][2] && gameSpace[2][2] == gameSpace[3][3])
    {
        switch (gameSpace[0][0])
        {
            case 'x':
                return 1;
            case 'o':
                return 2;
        }
    }

    if (gameSpace[0][3] == gameSpace[1][2] && gameSpace[1][2] == gameSpace[2][1] && gameSpace[2][1] == gameSpace[3][0])
    {
        switch (gameSpace[0][3])
        {
            case 'x':
                return 1;
            case 'o':
                return 2;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (gameSpace[i][0] == gameSpace[i][1] && gameSpace[i][1] == gameSpace[i][2] && gameSpace[i][2] == gameSpace[i][3])
        {
            switch (gameSpace[i][0])
            {
                case 'x':
                    return 1;
                case 'o':
                    return 2;
            }
        }

        if (gameSpace[0][i] == gameSpace[1][i] && gameSpace[1][i] == gameSpace[2][i] && gameSpace[2][i] == gameSpace[3][i])
        {
            switch (gameSpace[0][i])
            {
                case 'x':
                    return 1;
                case 'o':
                    return 2;
            }
        }
    }

    return 0;
}

void Gameboard::printGameSpace()
{
    for (int i = 0; i < 16; i++)
    {
        std::cout<<gameSpace[i/4][i%4]<<"\t";
        if (i%4 == 3)
        {
            std::cout<<std::endl;
        }
    }
}

Gameboard::Gameboard()
{
    for (int i = 0; i < 16; i++)
    {
        gameSpace[i/4][i%4] = '-';
    }
}




int main()
{
    std::string playerX, playerO;
    Gameboard gBoard;
    int row, column;

    std::cout<<"The game has started!"<<std::endl;

    std::cout<<"Player for x shall enter a name: "<<std::endl;
    std::cin>>playerX;
    std::cout<<"Player for o shall enter a name: "<<std::endl;
    std::cin>>playerO;


    while (true)
    {
        gBoard.printGameSpace();

        do
        {
            std::cout<<"It is your turn, "<<playerX<<". What's your move?"<<std::endl;
            std::cout<<"Enter row and column: "<<std::endl;
            scanf("%d%d", &row, &column);
        }
        while (gBoard.setState(row, column, 'x') == 0);

        if (gBoard.isFinished() == 1)
        {
            gBoard.printGameSpace();
            std::cout<<std::endl<<std::endl<<playerX<<" has won!"<<std::endl;
            break;
        }

        gBoard.printGameSpace();

        do
        {
            std::cout<<"It is your turn, "<<playerO<<". What's your move?"<<std::endl;
            std::cout<<"Enter row and column: "<<std::endl;
            scanf("%d%d", &row, &column);
        }
        while (gBoard.setState(row, column, 'o') == 0);

        if (gBoard.isFinished() == 2) {
            gBoard.printGameSpace();
            std::cout << std::endl << std::endl << playerO << " has won!" << std::endl;
            break;
        }
    }



    return 0;
}