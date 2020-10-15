#include<iostream>
using namespace std;

void displayBoard(char board[])
{
    cout<<"---TIC TAC TOE---"<<endl;
    cout<<"\n\n";
    cout<<"   "<<board[1]<<"  |  "<<board[2]<<"  |  "<<board[3];
    cout<<"\n";
    cout<<"  "<<"____"<<"  "<<"____"<<"  "<<"____"<<endl;
    cout<<endl;
    cout<<"   "<<board[4]<<"  |  "<<board[5]<<"  |  "<<board[6];
    cout<<"\n";
    cout<<"  "<<"____"<<"  "<<"____"<<"  "<<"____"<<endl;
    cout<<endl;
    cout<<"   "<<board[7]<<"  |  "<<board[8]<<"  |  "<<board[9];
    cout<<"\n\n";
}
bool checkDraw(char board[])
{
    if(board[1]!='1' && board[2]!='2' && board[3]!='3' && board[4]!='4' && board[5]!='5' && board[6]!='6' && board[7]!='7' && board[8]!='8' && board[9]!='9')
    {
        return true;
    }
    else return false;
}
bool checkWin(char board[])
{
    if(board[1]==board[2] && board[2]==board[3]) return true;
    else if(board[4]==board[5] && board[5]==board[6]) return true;
    else if(board[7]==board[8] && board[8]==board[9]) return true;
    else if(board[1]==board[4] && board[4]==board[7]) return true;
    else if(board[2]==board[5] && board[5]==board[8]) return true;
    else if(board[3]==board[6] && board[6]==board[9]) return true;
    else if(board[1]==board[5] && board[5]==board[9]) return true;
    else if(board[3]==board[5] && board[5]==board[7]) return true;
    else return false;
}
int main()
{
    int points_X = 0, points_O = 0;
srt:char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    int i=1;
    displayBoard(board);
    do
    {
        int position;
        player = (i%2 ? 'X' : 'O');
 A:     cout<<player<<" : "<<"Choose your position : ";
        cin>>position;
        if(board[position]!='X' && board[position]!='O')
        {
           board[position] = player;
           i++;
        }
        else
        {
            cout<<"Invalid position"<<endl;
            goto A;
        }
        system("CLS");
        displayBoard(board);
        if(checkWin(board))
        {
            char ch;
            cout<<player<<" won the game..."<<endl;
            if(player == 'X') points_X++;
            else points_O++;
            cout << "SCORE" << endl;
            cout << "X : " << points_X << " and " <<"Y : " << points_O << endl;
            cout << "Would u like to play again? Enter Y / N : ";
            cin >> ch;
            if(ch == 'Y') {
                system("CLS");
                goto srt;
            }
            else break;

        }
        else if(checkDraw(board))
        {
            char ch;
            cout<<"The game is draw..."<<endl;
            cout << "Would u like to play again? Enter Y / N" << endl;
            cin >> ch;
            if(ch == 'Y') {
                system("CLS");
                goto srt;
            }
            else break;
        }

    }while(true);

    cout<<"\n           THANK YOU"<<endl;

}
