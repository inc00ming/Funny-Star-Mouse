#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>      // std::pair, std::make_pair
#define WIDTH  50
#define HEIGHT 50

using namespace std;

enum PEN{penUp=1, penDown=2};
enum TURN{turnRight=3, turnLeft=4};
enum DIRECTION{EAST=0, SOUTH=2, WEST=3, NORTH=4};

void printArray(char array[][50] )
{
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++)
            cout << array[i][j];
        cout << endl;
    }
}
bool isStepValid(std::pair <int,int> &position, enum DIRECTION direction){
    bool valid = false;
    switch (direction) {
        case EAST:
            if(position.first < 49){
                valid = true;
                position.first += 1;
            }
            break;
        case SOUTH:
            if(position.second < 49){
                valid = true;
                position.second += 1;
            }
            break;
        case WEST:
            if(position.first > 0){
                valid = true;
                position.first -= 1;
            }
            break;
        case NORTH:
            if(position.second > 0){
                valid = true;
                position.second -= 1;
            }
            break;
        default:
            cout << "can not be seen" << endl;
            break;
    }
    return valid;
}

int main(){
    std::pair <int,int> position (0,0);
    ifstream inputFile("shape1.txt");
    string line;
    char array[50][50];
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++)
            array[i][j] = ' ';
    }
    //printArray(array);

    enum DIRECTION direction = EAST;
    int spaceStep;
    int cmd = 0;
    enum PEN pen;
    enum TURN turn;
    while(getline(inputFile, line) && cmd != 9){

        stringstream ss(line);
        ss >> cmd;
        switch (cmd) {
            case 1:
                pen = penUp;
                //cout << "pen is up" << endl;
                break;
            case 2:
                pen = penDown;
                //cout << "pen is down" << endl;
                break;
            case 3:
                turn = turnRight;
                if(direction == EAST)
                    direction = SOUTH;
                else if(direction == SOUTH)
                    direction = WEST;
                else if(direction == WEST)
                    direction = NORTH;
                else
                    direction = EAST;
                break;
            case 4:
                turn = turnLeft;
                if(direction == EAST)
                    direction = NORTH;
                else if(direction == SOUTH)
                    direction = EAST;
                else if(direction == WEST)
                    direction = SOUTH;
                else
                    direction = WEST;
                break;
            case 5:
                ss.ignore();
                ss >> spaceStep;
                for(int i = 0; i<spaceStep; i++){
                    if(isStepValid(position, direction)){
                        if(pen == penDown){
                            array[position.first][position.second] = '*';
                        }
                    }
                }
                break;
            case 6:
                printArray(array);
                break;
            case 9:
                break;
            default:
                cout <<  "can not be seen" << endl;
                break;
        }
    }
    return 0;
}
