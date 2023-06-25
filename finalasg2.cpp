#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime> //for time() in srand( time(NULL) );
#include <unistd.h> //for Sleep()
//#include <windows.h> // for Sleep()

using namespace std;

class Mars
{
    private:
        vector < vector<char> > map1;
        vector < vector<char> > map2;
        int dimX, dimY;
        int gold;
    public:
        Mars()
        {
            init();
        }
        void init();
        void display();
        void displayQmap();
        int getDimX() const;
        int getDimY() const;
        char getObject(int, int) const; 
        void setObjectmars(int,int,char);
        void setObjectQmap(int,int,char);
        bool isEmpty(int, int);
        bool isInsideMap(int, int);
        bool isGold(int, int);
        int totalGold() const;

        
        vector < vector<char> > getMap();
};

void Mars::init()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
    'X', '#', 'X', ' ' };
    int noOfObjects = 10; //number of objects in the objects array

    
    cout<< "Mars Dimension X => ";
    cin>> dimX; 
    cout<< "Mars Dimension Y => ";
    cin>> dimY;

    cout<<"Number of Golds: ";
    cin>> gold;
    cout << endl;



    //ORIGINAL MAP

    //create dynamic 2D array using vector
    map1.resize(dimY); //create rows
        for (int i=0; i<dimY; ++i){
        map1[i].resize(dimX); //resize each rows
        }
    //put random chars into the vector array
        for (int i=0; i<dimY; ++i){
            for (int j=0; j<dimX; ++j){
                int objNo = rand() % noOfObjects;
                map1[i][j] = objects[ objNo ];
            }
        }


    //? MAP
    map2.resize(dimY);
        for (int i=0;i<dimY; ++i){
            map2[i].resize(dimX);
        }
        for (int i=0; i<dimY; ++i){
            for (int j=0; j<dimX; ++j){
                map2[i][j] = '?';
            }
        }

    

    int numGold = 0;
    while (numGold < gold)
    {
        int no1 = rand() % map1.size();
        int no2 = rand() % map1.size();
        if ((map1[no1][no2] == '#') || (map1[no1][no2] == 'X'))
        {
            numGold++;
            map1[no1][no2] = '$';
        }
    }

}


void Mars::display()
{
    system("cls");
    cout << " --_--------------" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " ---------------" << endl;
    for (int i=0; i<dimY; ++i)
    {
        cout << " ";
        for (int j=0; j<dimX; ++j){
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(1) << (dimY-i);
        for (int j=0; j<dimX; ++j){
            cout << "|" << map1[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int j=0; j<dimX; ++j){
    cout << "+-";
    }
    cout << "+" << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    int digit = (j+1)/10;
    cout << " ";
    if (digit==0)
    cout << " ";
    else
    cout << digit;
    }
    cout << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    cout << " " << (j+1)%10;
    }
    cout << endl << endl;
}

void Mars::displayQmap()
{
    system("cls");
    //cout << "display was called" << endl;
    cout << " -----------------" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " ---------------" << endl;

    int dimY = getDimY();
    int dimX = getDimX();

    for (int i=0; i<dimY; ++i)
    {
        cout << " ";
        for (int j=0; j<dimX; ++j){
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(1) << (dimY-i);
        for (int j=0; j<dimX; ++j){
            cout << "|" << map2[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int j=0; j<dimX; ++j){
    cout << "+-";
    }
    cout << "+" << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    int digit = (j+1)/10;
    cout << " ";
    if (digit==0)
    cout << " ";
    else
    cout << digit;
    }
    cout << endl;

    cout << " ";
    for (int j=0; j<dimX; ++j)
    {
    cout << " " << (j+1)%10;
    }
    cout << endl << endl;
}



    int Mars::getDimX() const{
        return dimX;
        }

    int Mars::getDimY() const{
        return dimY;
        }

    char Mars::getObject(int x, int y) const 
    {
        return map1[dimY-y][x-1];
    }      

    void Mars::setObjectmars(int x, int y, char c)
    {
        map1[dimY-y][x-1] = c;
    }

    void Mars::setObjectQmap(int x, int y, char c)
    {
        map2[dimY-y][x-1] = c;
    }



bool Mars::isEmpty(int x, int y)
{
    if(map1[dimY-y][x-1]== ' ')
        return true;
    else
        return false;
}

bool Mars::isInsideMap(int x, int y)
{
    if((y > 0 && y <= dimY) && (x > 0 && x <= dimX))
        return true;
    else
        return false;
}

bool Mars::isGold(int x, int y)
{
    //checks if position given has gold
    if(map1[dimY-y][x-1]== '$')
        return true;
    else
        return false;
};

int Mars::totalGold() const{
    return gold;
}

class Rover 
{
    protected:
        int x,y;
    public:
        Rover()
        {
            //cout << "constructor was called" << endl;
        }
        void land(Mars& mars);
        void turnRight(Mars& mars);
        void turnLeft(Mars& mars);
        void basicmove (Mars& mars, char);
        void move (Mars& mars);
        int getDimX() const;
        int getDimY() const;
        void setDimX(int dimx);
        void setDimY(int dimy); 
        char ObjAhead(Mars);
        void setHeading(char c);
        void roverVision(Mars&);
        void input(Mars&);
        int goldAcquired() const;
        bool boolTrap() const;
    protected:
        bool trap = false;
        int gold = 0;
        char heading;
};


void Rover::land(Mars& mars)
{

    char possibleHeading[] = {'^', '>', '<', 'v'};
    x = (mars.getDimX() +1) / 2;
    y = (mars.getDimY() +1) / 2;  //mar.getDimY()
    heading = possibleHeading[ rand() % 4 ]; 
    mars.setObjectQmap(x,y,heading); 
    cout << " land was called " ;
}

void Rover::turnLeft(Mars& mars){
    cout << "turn left was called" << endl;
    char posiObj = heading;
    if(posiObj=='^'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'<');
        setHeading('<');
    }
    if(posiObj=='<'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'v');
        setHeading('v');
    }
    if(posiObj=='v'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'>');
        setHeading('>');
    }
    if(posiObj=='>'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'^');
        cout << "facing right was called" << endl;
        setHeading('^');
    }
    else{}
}

void Rover::turnRight(Mars& mars){
    if(heading=='^'){
       //Sleep(1200);
        mars.setObjectQmap(x,y,'>');
        setHeading('>');
    }
    else if(heading=='<'){
       //Sleep(1200);
        mars.setObjectQmap(x,y,'^');
        setHeading('^');
    }
    else if(heading=='v'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'<');
        setHeading('<');
    }
    else if(heading=='>'){
        //Sleep(1200);
        mars.setObjectQmap(x,y,'v');
        setHeading('v');
    }
    else{}
    cout << "turn right was called" << endl;
}


void Rover::setDimX(int dimx){
    x = dimx;
}
void Rover::setDimY(int dimy){
    y = dimy;
}

void Rover::setHeading(char ch){
    heading = ch;
}

void Rover::basicmove(Mars& mars, char ahead){
    //this function will move the rover
        int bx = x;
        int by = y;
        char posiObj = heading;

        if(posiObj == '>' && mars.isInsideMap(bx+1,by))
        {
            
            setDimX(x+1);
            mars.setObjectQmap(bx+1,by, ahead);
            mars.setObjectQmap(bx,by,' ');
            mars.setObjectmars(bx+1,by, ahead);
            mars.setObjectmars(bx,by,' ');
            //Sleep(1200);
            
        }
        else if(posiObj == '<' && mars.isInsideMap(bx-1,by))
        {
            
            setDimX(x-1);
            mars.setObjectQmap(bx-1,by, ahead);
            mars.setObjectQmap(bx,by,' ');
            mars.setObjectmars(bx-1,by, ahead);
            mars.setObjectmars(bx,by,' ');
            //Sleep(1200);
            
        }
        else if(posiObj == 'v' && mars.isInsideMap(bx,by-1))
        {
            
            setDimY(y-1);
            mars.setObjectQmap(bx,by-1, ahead);
            mars.setObjectQmap(bx,by,' ');
            mars.setObjectmars(bx,by-1, ahead);
            mars.setObjectmars(bx,by,' ');
            //Sleep(1200);
            
        }
        else if(posiObj == '^' && mars.isInsideMap(bx,by+1))
        {
            
            setDimY(y+1);
            mars.setObjectQmap(bx,by+1, ahead);
            mars.setObjectQmap(bx,by,' ');
            mars.setObjectmars(bx,by+1, ahead);
            mars.setObjectmars(bx,by,' ');
            //Sleep(1200);
            
        }
}

void Rover::move(Mars& mars){
    //this function will check whats infront of the rover and move it
        char ahead = ObjAhead(mars);
        int mx =x;
        int my= y;
        char curdir = heading; //rovers current direction (<,>,v,^)
        if( curdir != '#' && ahead == ' '){
            basicmove(mars, curdir);
        }
        else if(ahead == 'X'){
            //trap
            basicmove(mars, '@');
            //game over ?
            trap = true;
        }
        else if(ahead == '$'){
            basicmove(mars, curdir);
            gold++;
        }
        else if(ahead == '#'){
            cout<<"Theres a hill infront, please choose another direction"<<endl;
            //(doesnt move)
        }

     cout << "move was called" << endl;       
}

int Rover::getDimX() const{
    return x;
}

int Rover::getDimY() const{
    return y;
}


char Rover::ObjAhead(Mars mars)
{
    // returns what the rover is facing
    int objx = x;
    int objy = y;
    char posiObj = heading;
        if(posiObj == '>' && mars.isInsideMap(x+1,y))
        {
            return mars.getObject(objx+1,objy);
        }
        if(posiObj == '<' && mars.isInsideMap(x-1,y))
        {
            return mars.getObject(objx-1,objy);
        }
        if(posiObj == '^' && mars.isInsideMap(x,y+1))
        {
            return mars.getObject(objx,objy+1);
        }
        if(posiObj == 'v' && mars.isInsideMap(x,y-1))
        {
            return mars.getObject(objx,objy-1);
        }
}


void Rover::roverVision(Mars& mars){
    int dimx = getDimX();
    int dimy = getDimY();
        if (heading == '>'){
            for(int i=0; i<3; i++){
                if(mars.isInsideMap(dimx+1,dimy+(i-1))){
                    mars.setObjectQmap(dimx+1,dimy+(i-1),mars.getObject(dimx+1,dimy+(i-1)));
                }
            }
        }
        else if (heading == 'v'){
            for(int i=0; i<3; i++){
                if(mars.isInsideMap(dimx+(i-1),dimy-1)){
                    mars.setObjectQmap(dimx+(i-1),dimy-1,mars.getObject(dimx+(i-1),dimy-1));
                }
            }
        }
        else if (heading == '<'){
            for(int i=0; i<3; i++){
                if(mars.isInsideMap(dimx-1,dimy+(i-1))){
                    mars.setObjectQmap(dimx-1,dimy+(i-1),mars.getObject(dimx-1,dimy+(i-1)));
                }
            }
        }
        else if (heading == '^'){
            for(int i=0; i<3; i++){
                if(mars.isInsideMap(dimx+(i-1),dimy+1)){
                    mars.setObjectQmap(dimx+(i-1),dimy+1,mars.getObject(dimx+(i-1),dimy+1));
                }
            }
        }
    }

int Rover::goldAcquired() const{ return gold; }

bool Rover::boolTrap() const{ return trap; }

class Game : Mars, Rover
{  	//class Game uses/imports class Mars
	private:
    char quit = ' ';
    int score = 0;
    int totalcommands = 0;
    int totalCommSeq = 0;
    public:
    void gameFunction();
    void input(Mars&);
    int scoreCalculate();
    void scoreDisplay();
    void timerDisplay(int, int);
    void countDown();
};

void Game::gameFunction(){
    Mars planet;
    Rover curiosity;
    land(planet);
    roverVision(planet);
    displayQmap();

    cout << "Mission: obtain all gold. beware of traps." << endl;
    cout << "-commands-" << endl
         << "L:Turn left, R:Turn right, M:Move forward, Q:Quit" << endl;
    cout << "-map key-"<< endl
         << "#: Hill  X: Trap  $: Gold" << endl << endl;
    
    cout << "x coordinate: " << Rover::x << endl 
         << "y coordinate: " << Rover::y << endl
         << "current direction: " << Rover::heading << endl << endl;

    
    do{
        input(planet);
        totalCommSeq += 1;
        //countDown();
    }while( (boolTrap() == false) && ( goldAcquired() < totalGold() ) && quit != 'Q' );

    if(goldAcquired()==totalGold()){ cout << "good job. mission accomplished." << endl << endl; }
    else if(boolTrap() == true){ cout << "be careful next time." << endl << endl; }

    scoreDisplay();
}

void Game::input(Mars &mars){
    
    string command;
    cout << "input plsss: " << endl;
    cin >> command;
    cout << command;

        for(int i = 0; i < command.length(); ++i) 
        {
        command[i] = toupper(command[i]);
        }
    
        for(int i = 0; i < command.length(); ++i) 
        {
            if     (command[i]=='L'){ turnLeft(mars);    }
            else if(command[i]=='R'){ turnRight(mars);   }
            else if(command[i]=='M'){ move(mars);        }
            else if(command[i]=='Q'){ quit = 'Q';        }
            roverVision(mars);
            mars.displayQmap();
        }
        totalcommands += command.length();
}

int Game::scoreCalculate(){
    score = goldAcquired()*50 - totalCommSeq*5 - totalcommands;
    return score;
}

void Game::scoreDisplay()
{
    cout << "Total Command Sequences = "<< totalCommSeq << " [S]" << endl;
    cout << "Total Commands = " << totalcommands << " [C]" << endl;
    cout << "Total Golds = " << goldAcquired() << " [G]" << " out of " << totalGold() << endl;
    cout << "total score = [G] x 50 - [S] x 5 - [C] x 1" << endl << endl
     << "your score = "
     << goldAcquired() <<"[G] x 50"
     <<" - "
     << totalCommSeq <<"[S] x 5"
     <<" - "
     << totalcommands <<"[C] x 1"
     <<" = "
     << scoreCalculate() << endl;
}


void Game::timerDisplay(int minutes, int seconds)
{
    cout << "---------------------" << endl;
    cout << "|    Count Down     |" << endl;
    cout << "---------------------" << endl;
    cout << "|   " << minutes << " min" << " | " << seconds << " sec" << "  |"  << endl;
    cout << "---------------------" << endl;
}

void Game::countDown()
{
    int minutes = 1;
    int seconds = 59;
    while(true)
    {
        //system("cls");
        timerDisplay(minutes, seconds);

        sleep(1);

        seconds--;

        if(seconds == 0)
        {
            minutes--;
            seconds = 60;
            seconds--;
            if(minutes==0)
            {
                seconds = 60;
                seconds--;
            }
                if(seconds==0)
                break;

        break;    
        }
    }
}

int main()
{
    //srand( time(NULL) );
    srand(1);
    Game g;
    cout << "Confirming planet dimensions. Please re-enter" << endl;
    cout<<endl;
    g.gameFunction();
    

    return 0;
}
