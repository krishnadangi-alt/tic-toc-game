#include<iostream>
#include<string>
#include<ctime>
using namespace std;

void board( char *spaces);

  void playermove(char *spaces,char player);
  void computermove(char *spaces,char computer);
  bool checkwinner(char *spaces,char player,char computer);
  bool tie(char *spaces);


int main(){
  char spaces[9]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player ='x';
  char computer ='o';
  bool running = true;

  board(spaces);

  while(running){
    playermove(spaces,player);
    board(spaces);
    if(checkwinner(spaces,player,computer)){
       running = false;
       break;
    }
    else if(tie(spaces)){
      running = false ;
      break;
    }



    computermove(spaces, computer);
    board(spaces);

  }
  return 0;
  }

void board( char *spaces){
 cout<<"     |     |     "<<endl;
 cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"  "<<endl;
 cout<<"_____|_____|_____"<<endl;
 cout<<"     |     |     "<<endl;
 cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"  "<<endl;
 cout<<"_____|_____|_____"<<endl;cout<<"     |     |     "<<endl;
 cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"  "<<endl;
}
void playermove(char *spaces,char player){
     int num;
     do{
     cout<<"enter the number [1-9] : "<<endl;
     cin>>num;
     num--;
     if(num >= 0 && num < 9 && spaces[num] == ' '){
       spaces[num] = player;
       break;
     }
    }
     while(true);

}
void computermove(char *spaces,char computer){
     int num;
     srand (time(0));
     while(true){
     num = rand() % 9 ;
     if(spaces[num]== ' '){
        spaces[num] = computer;
        break;
     }
     }
}
bool checkwinner(char *spaces,char player,char computer){
     if (spaces[0]!= ' '&&spaces[0] == spaces[1]&& spaces[1]==spaces[2]){
        spaces[0] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
   return true;
      }     if (spaces[3]!= ' '&&spaces[3] == spaces[4]&& spaces[4]==spaces[5]){
         spaces[3] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;
    
       }     if (spaces[6]!= ' '&&spaces[6] == spaces[7]&& spaces[7]==spaces[8]){
         spaces[0] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }     if (spaces[0]!= ' '&&spaces[0] == spaces[3]&& spaces[3]==spaces[6]){
         spaces[0] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }     if (spaces[1]!= ' '&&spaces[1] == spaces[4]&& spaces[4]==spaces[7]){
         spaces[1] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }     if (spaces[2]!= ' '&&spaces[2] == spaces[5]&& spaces[5]==spaces[8]){
         spaces[2] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }if (spaces[0]!= ' '&&spaces[0] == spaces[4]&& spaces[4]==spaces[8]){
         spaces[0] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }if (spaces[2]!= ' '&&spaces[2] == spaces[4]&& spaces[4]==spaces[6]){
         spaces[2] == player ? cout<<"you win"<<endl : cout <<"you lose"<<endl;
         return true;

       }
       else{
        return false ;
       }
       return true;
}
bool tie(char *spaces){
  for(int i = 0;i<9;i++){
    if (spaces[i] == ' '){
     return false;
    }
  }
  cout<<"its a TIE!"<<endl;
  return true;
}
