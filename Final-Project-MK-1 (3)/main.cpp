 //changed struct to class=100points /
//changed to arrays=100 points/
//classes public/private=25 points/
//proper indentation=50 points/
//map=50 points
//getter/setter= 50
//retheme= 50/ (horror theme mixed with humor/unexpected)
//constructors= 50/ 
//making constructors=around 12 points/
//expand number of rooms= 25 points/ 


#include <iostream>
#include <string> 
#include <vector> 
#include <cctype>

using namespace std; 

enum en_DIRS {NORTH, EAST, SOUTH, WEST}; 
	
enum en_ROOMS {CIRCUS, MOVIETHEATER, AMUSEMENTPARK, DEADMALL, FOODCOURT, MALLHALL, MALLOFFICE, FOOTLOCKER, TRASHAREA, ALIENLAIR, SKATEPARK, WALMART, HAUNTEDMANSION, GRAVEYARD, CURSEDHIGHSCHOOL, SUPERMARKET, INSANEASYLUM, HAUNTEDSTREET, OLDLADIEHOUSE, SERIALKILLERHOUSE, DEVILHOUSE, KILLERROBOTHOUSE, LAKE, BUSINESSBUILDING, BANK, CLAIRS, THIRDPLANET, BURGERBUDDY, DANCECLUB, CONCERTHALL }; 
	
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK}; 
	
//Added code
enum en_NOUNS {MALL_DOOR, TRASH_CAN, FERRIS_WHEEL, POPPER, STALE_POP, ACROBAT}; 
//....



const int NONE = -1;
const int DIRS= 4; 
const int ROOMS=30; 
const int VERBS= 8; 

//added code 
const int NOUNS =6; 
bool debug = true;

//....
//changing to class (100 points)
class words 
{
public: 
	words(string w, int c) 
	{
		word = w; 
		code =c; 
	}
	string getWords () 
	{
		return word;
	}
	int getCode () 
	{
		return code; 
	}
	void setWord (string givenWord) 
	{
		word=givenWord; 
	}

private:  
	string word;  
	int code; 
};


class room
{
public: 
	room(string desc, int n, int e, int s, int w) 
	{
		description = desc;  
		exits_to_room[NORTH]= n;
		exits_to_room[EAST]= e; 
		exits_to_room[SOUTH]= s; 
		exits_to_room[WEST]=w;   
	}
	string getDescription()
	{
		return description; 
	} 

	int getExits(int DIR) 
	{
			return exits_to_room[DIR]; 
	}
	void setExit(int DIR, int room)
	{
			exits_to_room[DIR]=room; 
	} 

private: 
	string description;
	int exits_to_room[DIRS];  
}; 


//added code 
class noun 
{
public:
	noun(string wo, string desc, int co, int loc, bool ca) 
	{
		word = wo; 
		description = desc; 
		code = co; 
		location = loc; 
		can_carry = ca;  
	}

	string getWord()
	{
		return word; 
	}
	string getDescription()
	{
		return description; 
	}
	void setDesc (string givenDescription) {
		description = givenDescription; 
	} 
	int getLocation() 
	{
		return location; 
	}
	int getCode()
	{
		return code; 
	}
	void setLocation (int givenLocation)
	{
		location=givenLocation;  
	}

private: 
	string word; 
	string description; 
	int code; 
	int location; 
	bool can_carry; 
};
//...

//-----------------------------------------------------------

void set_rooms(vector<room>& rms) 
{ 
											//north       //east  //south       //west
	rms.push_back(room("left behind circus",HAUNTEDSTREET, NONE, AMUSEMENTPARK, HAUNTEDMANSION)); 

	rms.push_back(room("hypnotizing movie theater", NONE, NONE, DEADMALL,NONE )); 

	rms.push_back(room("abandoned amusement park",CIRCUS, DEADMALL, LAKE, GRAVEYARD)); 

	rms.push_back(room("dead mall",MOVIETHEATER, FOODCOURT, MALLHALL, AMUSEMENTPARK)); 

	rms.push_back(room("food court with poisoned food",NONE, NONE, NONE, DEADMALL));  

	rms.push_back(room("mall hall",DEADMALL, THIRDPLANET, FOOTLOCKER, CLAIRS)); 

	rms.push_back(room("locked mall office",NONE, NONE, NONE, NONE));  

	rms.push_back(room("Foot Locker",MALLHALL, TRASHAREA, NONE, NONE)); 

	rms.push_back(room("trash area",NONE, NONE, NONE, FOOTLOCKER)); 

	rms.push_back(room("alien lair",NONE, GRAVEYARD, SKATEPARK, NONE));

	rms.push_back(room("skate park where kids disappear", ALIENLAIR, CURSEDHIGHSCHOOL, NONE, NONE));	

	rms.push_back(room("walmart", NONE, HAUNTEDSTREET, HAUNTEDSTREET, NONE));

	rms.push_back(room("haunted mansion", WALMART, CIRCUS, GRAVEYARD, NONE));

	rms.push_back(room("grave yard", HAUNTEDMANSION, AMUSEMENTPARK, CURSEDHIGHSCHOOL, ALIENLAIR));

	rms.push_back(room("cursed high school", GRAVEYARD, LAKE, SUPERMARKET, SKATEPARK));	

	rms.push_back(room("robbed super market", CURSEDHIGHSCHOOL, BUSINESSBUILDING, INSANEASYLUM, NONE));

	rms.push_back(room("insane asylum", SUPERMARKET, BANK, NONE, NONE));	
	
	rms.push_back(room("haunted street", NONE, KILLERROBOTHOUSE, CIRCUS, SERIALKILLERHOUSE));
	
	rms.push_back(room("crazy old lady's house", NONE, HAUNTEDSTREET, NONE, SERIALKILLERHOUSE));

	rms.push_back(room("house full of serial killers", OLDLADIEHOUSE, HAUNTEDSTREET, NONE, NONE));

	rms.push_back(room("the devil's house", NONE, NONE, KILLERROBOTHOUSE, HAUNTEDSTREET));

	rms.push_back(room("house full of killer robots", DEVILHOUSE, NONE, NONE, HAUNTEDSTREET));

	rms.push_back(room("foggy lake", AMUSEMENTPARK, NONE, BUSINESSBUILDING, CURSEDHIGHSCHOOL));

	rms.push_back(room("business building with men in suits", LAKE, NONE, BANK, INSANEASYLUM));

	rms.push_back(room("bank with loan officers from hell", BUSINESSBUILDING, NONE, NONE, INSANEASYLUM));

	rms.push_back(room("Clair's home of cannibals", MALLHALL, NONE, NONE, NONE));

	rms.push_back(room("3rd planet", MALLHALL, NONE, NONE, NONE));	
					
	rms.push_back(room("nasty burger joint", BANK, NONE, NONE, NONE));

	rms.push_back(room("dance club of death", BURGERBUDDY, NONE, NONE, NONE));

	rms.push_back(room("Concert hall with a vampire",NONE , ALIENLAIR, NONE, NONE));		
		

}
//----------------------------------------------------------
void set_directions(vector<words>& dir) 
{
	dir.push_back(words("NORTH",NORTH));

	dir.push_back(words("EAST",EAST));

	dir.push_back(words("SOUTH",SOUTH));
	  
	dir.push_back(words("WEST",WEST));  
}
//-----------------------------------------------------------
void set_verbs (vector<words>& vbs)
{
	//enum en_verrbs {GET,DROP,USE,OPEN,CLOSE,EXAMINE, INVENTORY,LOOK};
	vbs.push_back(words("GET",GET)); 

	vbs.push_back(words("DROP",DROP));

	vbs.push_back(words("USE",USE));

	vbs.push_back(words("OPEN",OPEN));

	vbs.push_back(words("CLOSE",CLOSE)); 

	vbs.push_back(words("EXAMINE",EXAMINE));

	vbs.push_back(words("INVENTORY", INVENTORY));

	vbs.push_back(words("LOOK",LOOK)); 
}
//-----------------------------------------------------------
//added code 
void set_nouns(vector<noun>& nns) 
{
   //enum en_nouns {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD}
   	nns.push_back(noun("DOOR","closed store room door", MALL_DOOR, MALLHALL, false));  
	
	nns.push_back(noun("TRASHCAN","trash can", TRASH_CAN, TRASHAREA, false));  

	nns.push_back(noun("FERRISWHEEL","broken ferris wheel", FERRIS_WHEEL, AMUSEMENTPARK, false));  

	nns.push_back(noun("POPPER","popcorn popper", POPPER, MOVIETHEATER, false));  

	nns.push_back(noun("STALEPOPCORN","some stale popcorn", STALE_POP, MOVIETHEATER, true));  

	nns.push_back(noun("ACROBAT","actobat throwing knives", ACROBAT, CIRCUS, false));  
}
//----------------------------------------------------------
void section_command(string Cmd, string &wd1, string &wd2)
{
	if (debug){
		cout << "Cmd = " << Cmd << ", wd1 = " << wd1 << ", wd2 = " << wd2 << " \n";
	}
	string sub_str;
	vector<string>words; 
	char search = ' '; 
	size_t i, j; 
	
	for(i=0; i < Cmd.size(); i++)
	{
		if(Cmd.at(i) !=search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i)); 
		}
		if(i==Cmd.size()-1)
		{
			words.push_back(sub_str); 
			sub_str.clear(); 
		}
		if(Cmd.at(i)==search)
		{
			words.push_back(sub_str);
			sub_str.clear(); 
		}
	}
	for(i=words.size()-1; i>0; i--) 
	{
		if(words.at(i)=="")
		{
			words.erase(words.begin()+i); 
		}
	}
	for(i= 0; i <words.size(); i++)
	{
		for(j=0; j< words.at(i).size(); j++)
		{
			if(islower(words.at(i).at(j)))
			{
				words.at(i).at(j)=toupper(words.at(i).at(j)); 
			}
		}
	}
	if(words.size()==0)
	{
	cout<<"No command given"<<endl; 
	}
	if(words.size()==1)
	{
	wd1 = words.at(0); 
	}
	if(words.size()==2)
	{
	wd1 = words.at(0);
	wd2 = words.at(1); 
	}
	if(words.size()>2) 
	{
	cout<<"command too long. Only type one or two words (direction or verbs and noun)"<<endl; 
	}
}
//---------------------------------------------------------
//code runs 100% up to this point
void look_around(int loc, vector<room>& rms, vector<words>& dir, /*added parameter*/ vector<noun>& nns) //work with these pointers
{
	int i; 
	cout<< "I am in a(n) "<< rms[loc].getDescription()<< "."<<endl;
	for(i= 0; i <DIRS; i++) 
	{
		if(rms[loc].getExits(i) != NONE) 
		{
		cout<<"There is an exit "<<dir[i].getWords()<<" to a(n) "<< rms [rms[loc].getExits(i)].getDescription()<<"."<<endl; 
		}
	}
	//added code 
	//the look command should check wich objects nouns are in the current roo, and report them to the player
	for (i =0; i <NOUNS; i++)
	{
		if (nns[i].getLocation() ==loc)
		{
		cout<<"I see a(n)"<<nns[i].getDescription()<<"."<<endl; 
		}
	}
}

//---------------------------------------------------------
bool parser(int &loc, string wd1, string wd2, vector<words>& dir, vector<words>& vbs, vector<room>& rms, /* added paramerer */ vector<noun>& nns) 
{

	if(debug) {
		cout << "wd1 = " << wd1 << " and wd2 = " << wd2 << endl;
	}
  //added code
  static bool door_state = false; // false is a closed door. 
  //...
  int i;
  for(i = 0; i<DIRS; i++) 
    {
      if (wd1 == dir[i].getWords())
      {
        if (rms[loc].getExits(dir[i].getCode()) !=NONE)
        {
          loc= rms[loc].getExits(dir[i].getCode()); 
          cout<<"I am now in a(n) "<<rms[loc].getDescription()<<"."<<endl;
          //added code. A special case for the corridor storeroom door. 
          if(loc == MALLOFFICE || loc == MALLHALL) 
          {
            nns[MALL_DOOR].setLocation(loc); 
          }
          //............
          return true;
        } 
        else 
        {
          cout<<"No exit this way."<<endl; 
          return true; 
        }
      }
    }
    //added code
    int NOUN_MATCH= NONE; 
    //...
    int VERB_ACTION = NONE; 

    for(i=0; i < VERBS; i++)
    {
      if(wd1 == vbs[i].getWords())
      {
      VERB_ACTION =vbs[i].getCode(); 
      break;
      }
    }
    //added code 
    if(wd2 !="")
    {
      for (i = 0; i < NOUNS; i++)
      {
        if(wd2 == nns[i].getWord())
        {
			NOUN_MATCH = nns[i].getCode(); 
			break;
        } 
      }
    }
    if(VERB_ACTION ==NONE)
    {
      cout<<"No valid command entered."<<endl;
      return true; 
    }
    if(VERB_ACTION == LOOK)
    {
      look_around(loc, rms, dir, /*added parameter nns */ nns); 
      return true; 
    }

	if(debug) {
		cout << "noun = " << NOUN_MATCH << endl;
		cout << "StoreDoor = " << MALL_DOOR << endl;
		cout << "nns[0] = '" << nns[0].getWord() << "'.\n";
	}

    //added code 
    //actions for usage of verb open 
    if (VERB_ACTION == OPEN)
    {
      if(NOUN_MATCH == MALL_DOOR)
      {
        if(loc == MALLHALL || loc ==MALLOFFICE)
        {
          if(door_state == false)
          {
            door_state =true; 
            rms[MALLHALL].setExit (EAST, MALLOFFICE);
            rms[MALLOFFICE].setExit(WEST, MALLHALL);
            //nns[STORE_DOOR].getDescription().clear();
            nns[MALL_DOOR].setDesc("an open room door"); 
            cout<<"I have opened the door."<<endl; 
            return true; 
          }
          else if(door_state ==true)
          {
            cout<<"The door is already open."<<endl; 
            return true; 
          }
        }
        else 
        {
          cout<<"There is no door to open here"<<endl;
          return true; 
        }
      }
      else 
      {
        cout<<"opening that is not possible."<<endl;
        return true; 
      }
    }
      //...
      return false; 
    } 

    //-------------------------------------------------


    //--------------------------------------------------

int main()
{
	string command; 
	string word_1; 
	string word_2; 

	vector<room> rooms; 
	set_rooms(rooms);
	

	vector <words> directions; 
	set_directions(directions); 

	vector<words> verbs;
	set_verbs(verbs); 
	//added code
	vector<noun> nouns;
	set_nouns(nouns); 
	//....

	int location = AMUSEMENTPARK;
	while(word_1 !="QUIT")
	{
		command.clear(); 
		cout<<"what shall I do? "; 
		getline(cin,command); 

		word_1.clear(); 
		word_2.clear();

		section_command(command, word_1, word_2);
		if(word_1 !="Quit")
		{
			parser(location, word_1, word_2, directions, verbs, rooms, /*Added parameter */ nouns); 
		} 
	}
	return 0; 
} 