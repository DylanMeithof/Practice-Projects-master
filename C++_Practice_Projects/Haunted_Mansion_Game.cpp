#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//stuff needed to be declared before classes
int energy = 100;
int turn_track = 0;

//classes
class Item {
    protected:
    string name;
    bool in_inventory = false;
    
    public:
    void set_name(string new_name) {name = new_name;}
    void put_in_inventory() {in_inventory = true;}
    void take_out_inventory() {in_inventory = false;}
};

class Furniture {
	string name;
    vector<Item> items;
    
    public:
    string get_name() {return name;}
    Item get_items(int x) {return items[x];}
};

class Room {
    string name;
    string clear_description;
    string unclear_description;
    int floor_level;
    vector<string> clear_choices;
    vector<string> unclear_choices;
    vector<Furniture> furniture;
    bool entered = false;
    string updated_choice;
    
    public:
    Room(string new_name, string new_clear_description, string new_unclear_description, int new_floor_level, vector<string> new_clear_choices, vector<string> new_unclear_choices, vector<Furniture> new_furniture)
        : name(new_name), clear_description(new_clear_description), unclear_description(new_unclear_description), floor_level(new_floor_level), clear_choices(new_clear_choices), unclear_choices(new_unclear_choices), furniture(new_furniture) {}
    string get_name() {return name;}
    string get_clear_description() {return clear_description;}
    string get_unclear_description() {return unclear_description;}
    int get_level() {return floor_level;}
    string get_clear_choice(int x) {return clear_choices[x];}
    string get_unclear_choice(int x) {return unclear_choices[x];}
    Furniture get_furniture(int x) {return furniture[x];}
    
};

class Food: public Item {
    int nutrition = 0;
    
    public:
    Food(int new_nutrition) : nutrition(new_nutrition) {}
    void eat() {energy += nutrition;}
};

class Flashlight: public Item {
    bool on = false;
    
    public:
    void turn_on() {on = true;}
    void turn_off() {on = false;}
};

class Watch: public Item {
    public:
    void get_time() {
        
    }
};

class Battery: public Item {
    int battery_life = 25;
    
    public:
    void using_battery() {battery_life--;}
};

class Paper: public Item {
    string words;
    
    public:
    void write(string new_words) {words += new_words;}
    string read() {return words;}
};

Room Main_Hall("Main Hall", "BEEFY DESCRIPTION", "BEEFY VAGUE DESCRIPTION", 1,
    vector<string> {"go up the stairs", "go into the room on the left", "go into the room on the right", "exit the mansion"},
    vector<string> {"???", "???", "???", "exit the mansion"}, vector<Furniture> {});

//functions
void intro_1();
void directions();
void intro_2();

void pause(int len = 1);
void explode();
void mapout();

void update_choices();

//variables
string location;
int floor_level;

string player_name;
string in;
vector<string> items;

int health = 100;
//energy = 100;
int luck = 3;

int anger_lvl = 0;

int main()
{
    intro_1();
    intro_2();
    return 0;
}

void intro_1()
{
    cout << "Welcome, to \"The Haunted Mansion\". Choose your name:" << endl;
    getline(cin, player_name);
    cout << "Welcome " << player_name << ". Do you know how to play already? (y = yes, n = no)" << endl;
    line_intro1_1:
    getline(cin, in);
    if (in == "y") {
        cout << "Fantastic! Now I don't have to drone on and on about boring stuff." << endl;
    }
    else if (in == "n") {
        directions();
    }
    else {
        explode();
        cout << "Ha, ha, very funny. Enter either a y or an n now." << endl;
        goto line_intro1_1;
    }
    
    cout << "Are you ready? (As always, y = yes, n = no)" << endl;
    line_intro1_2:
    getline(cin, in);
    if (in == "y") {
        cout << "Excellent. The adventure begins...\n" << endl;
    }
    else if (in == "n") {
        cout << "Huh? You're not ready? Okay, fine; but, when you are ready, enter a y." << endl;
        goto line_intro1_2;
    }
    else {
        explode();
        cout << "Wow, aren't you a clever one. Enter y or n." << endl;
        goto line_intro1_2;
    }
}

void directions()
{
    cout << "You are playing an RPG style game using only C++ code and a terminal.\n"
        "So, if you were expecting fancy graphics, try somewhere else.\n" << endl;
    pause(2);
    cout << "Did you notice that pause? I put that pause in there so you have time to read.\n"
        "Just because it's sitting there doesn't mean you need to enter anything. Just so you know.\n" << endl;
    pause(2);
    cout << "In this game, you have certain stats that, if they run out, you die. The End!\n"
        "These stats are health, energy, and luck. Health and energy are both out of 100.\n"
        "If you run out of health, you die. When you run out of energy, your health decreases until you die. Don't die.\n" << endl;
    pause(3);
    cout << "Luck is less of a stat and more of a special card you can play any time during the game.\n"
        "If you use luck, something good almost always happens; so, if your in a tough spot, you can use one (1) luck.\n"
        "Be warned, however! You can only use luck three (3) times, so use it wisely!\n" << endl;
    pause(3);
    cout << "To access your stats at any time, just type in \"stats\" into the terminal\n"
        "If you want to use luck, type in \"use luck\" into the terminal.\n" << endl;
    pause(2);
    cout << "Also, whenever you enter something in, PLEASE, use ONLY lower case (except for your name; that's fine).\n"
        "Otherwise, I will get angry and tell you to enter it correctly. So just do it the first time.\n"
        "If you ever want to quit, type \"QUIT\" (all caps) into the terminal.\n" << endl;
    pause(2);
    cout << "Besides your stats, you also have an inventory, where you can store items for later use.\n"
        "There are 5 slots in your inventory, so if you run out of space, you will need to get rid of an item.\n"
        "It doesn't matter how big or small the item is in real life; they will take up the same space.\n" << endl;
    pause(3);
    cout << "To look at your inventory, simply type \"look inventory\" into the terminal.\n"
        "To put an item in your inventory, simply type the item into the terminal, type a space, and say,\"inventory\".\n"
        "If it was successful, a message saying \"(Item) added to inventory!\" will show up.\n" << endl;
    pause(3);
    cout << "To discard an item in your inventory, type \"discard (item)\", and you will get rid of it.\n"
        "If you try to put an item in your inventory when it is full, a message saying \"Inventory is full!\" will pop up.\n"
        "I will then ask you to choose an item to get rid of out of the six you have. You cannot progress until you do so.\n" << endl;
    pause(3);
    cout << "That's all you need to know right now. More information will be given here and there." << endl;
}

void intro_2()
{
    cout << "You have been dared to stay in your town's haunted mansion alone overnight by one of your friends.\n"
        "In order to beat your friend's dare, you must enter the mansion before dusk and exit after dawn.\n"
        "This should be no problem, but, about a year ago, three teenagers entered the mansion at night and never came out again.\n" << endl;
    pause(3);
    cout << "Remember your inventory slots? Now's the time to fill them.\n"
        "Here are your options. If you want one of them, enter it into the terminal.\n" 
        "Remember the correct format, however! Type the item, then a space, then \"inventory\"." << endl;
    pause(3);
    cout << "Here they are:\nflashlight   watch   batteries (compatible w/ all electronic devices)\n"
        "rope   pocket knife   BB gun (includes ammo)   screwdriver\n\"How to Survive a Night in a Haunted Mansion\" book (type \"book\" if you want it)\n"
        "camera   granola bar   jerky   water bottle (w/ water)\npaper   pencil   pen\n" << endl;
    pause(3);
    cout << "You can take multiples of all the items, but remember; they each take up 1 inventory slot\n"
        "If you don't want to use up all your slots, type \"finished\" when you are done.\n" << endl;
    items.push_back("flashlight"); items.push_back("watch"); items.push_back("batteries"); items.push_back("rope");
    items.push_back("pocket knife"); items.push_back("BB gun"); items.push_back("book"); items.push_back("screwdriver");
    items.push_back("granola bar"); items.push_back("jerky"); items.push_back("water bottle");
    items.push_back("paper"); items.push_back("pencil");
    
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter the item you want:" << endl;
        getline(cin,in);
        if (in == "finished") {
            break;
        }
    }
    
    cout << "Here is your inventory:" << endl;
    pause(1);
    cout << "Is this what you want?" << endl;
    line3:
    getline(cin, in);
    if (in == "y") {
        cout << "Good, you're a very decisive person." << endl;
    }
    else if (in == "n") {
        cout << "Fine. Use the correct format (\"discard \" + item) to get rid of the items you don't want,\n"
            "and use the correct format (item + \" inventory\") to add the items you actually want.\n"
            "When you are done (for sure), type \"finished\" into the console. Don't take too long." << endl;
        while (in != "finished") {
            getline(cin, in);
        }
    }
    else {
        explode();
        cout << "Seriously! Just enter a y for yes and an n for no! It's not that difficult!" << endl;
        goto line3;
    }
    
    items.clear();
    cout << "Now you are prepared to enter the mansion. Good luck..." << endl;
}

void pause(int len)
{
    for (int b = 0; b < 3000000; b++) {
        for (int c = 0; c < len * 130; c++) {
             
        }
    }
}

void explode()
{
    anger_lvl++;
    if (anger_lvl >= 10) {
        cout << "You know what? I'm sick of dealing with people like you." << endl;
        pause(1);
        cout << "So you know what? Game Over. You lose because you made me mad!" << endl;
        exit (EXIT_FAILURE);
    }
    else if (anger_lvl == 7) {
        cout << "Just letting you know, have a very low patience meter.\n"
           "So, if you keep doing the wrong thing, I'm just going to give up. Don't make me." << endl;
    }
    else if (anger_lvl == 9) {
        cout << "This is your last warning before I am just done.\n"
           "So, JUST S T O P!" << endl;
    }
}

void mapout()
{
   if (floor_level == -1) {
    cout << "            Bunker\n"
            "┏---------------------------┓\n"
            "|             | (To Heating |\n"
            "|    Safe          Room)    |\n"
            "|    Room     |             |\n"
            "|-------------|             |\n"
            "|             |    Main     |\n"
            "|   Storage   |   Bunker    |\n"
            "|    Room     |             |\n"
            "|                           |\n"
            "|             |             |\n"
            "┗---------------------------┛ \n" << endl;
   }
   if (floor_level == 0) {
    cout << "                   Basement\n"
            "┏-----------------------------------------------┓\n"
            "|                      | | | | |  |     ??      |\n"
            "|                      (1st Fl)   |             |\n"
            "|                   -------------------------   |\n"
            "|                   |             |             |\n"
            "|                   |   Laundry   |   Heating   |\n"
            "|       Main             Room          Room     |\n"
            "|       Area        |             |             |\n"
            "|                   |---------------------------|\n"
            "|                   |                           |\n"
            "|                             Pantry            |\n"
            "|                   |                           |\n"
            "┗-----------------------------------------------┛\n" << endl;
   }
   if (floor_level == 1) {
    cout << "                     Floor 1\n"
            "┏-----------------------------------------------┓\n"
            "| Kitchen  | Dining |  | | | | |  |             |\n"
            "|             Room  | (Basement)  |    Rec      |\n"
            "|------- H ------   -----------|  |    Room     |\n"
            "|Closet  a |                   |  |             |\n"
            "|------- l |        ??         |  |--------   --|\n"
            "|Bathrm  l |                   |     Hall 2     |\n"
            "|------- 1 --------------------------------   --|\n"
            "|               |  -- (2nd Fl.)    |            |\n"
            "|    Living     |  --              |   Guest    |\n"
            "|     Room         --   Main            Room    |\n"
            "|               |       Hall       |            |\n"
            "┗-----------------------------------------------┛\n" << endl;
   }
   if (floor_level == 2) {
    cout << "                     Floor 2\n"
            "┏-----------------------------------------------┓\n"
            "|           |                      |            |\n"
            "|  Bedroom  |        Library            Study   |\n"
            "|     1     |                      |            |\n"
            "|  -----|   |---------   ----------|----   -----|\n"
            "|Closet1|   |                      |            |\n"
            "|-------|             Loft             Lounge   |\n"
            "|Closet2|   |                      |            |\n"
            "|  -----|   |----------------------|-   -----   |\n"
            "|           |      (To 1st Fl.)    |Bath-|      |\n"
            "|  Bedroom  |                      |Room |  ?   |\n"
            "|     2     |                      |  2  |      |\n"
            "┗-----------------------------------------------┛\n" << endl;
   }
   if (floor_level == 3) {
    cout << "                      Attic\n"
            "┏-----------------------------------------------┓\n"
            "|                                               |\n"
            "|                                               |\n"
            "|                                               |\n"
            "|                                               |\n"
            "|                                               |\n"
            "|                                               |\n"
            "┗-----------------------------------------------┛\n" << endl;
   }
}

