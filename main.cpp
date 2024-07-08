#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void print_line(int );
void paragraph();
string read_from_json(string ,string );
int put_in_file(string,string,string,bool);

int choose();





vector<string> msg{"1 - hello", "2 - world"};
int choice;


int main()
{
    

cout << endl;

print_line(1);
paragraph();

string ki= read_from_json("core.json","1");
cout <<ki;
choose();
system("mkdir core");
system("clear");
return 0;
} 









string read_from_json(string address,string value){
    // string line;
  ifstream myfile(address);

     json config=json::parse(myfile);
//   if (myfile.is_open())
//   {
//     // while ( getline (myfile,line) )
//     // {
//     //   cout << line << '\n';
//     // }
//     myfile >> config;
//     myfile.close();
//   }


return config["config"]["DB"]["connection"];
}
int put_in_file(string address,string extracontent,string value,bool position){
return 0;
}



int choose(){
    cout <<"Enter your selection :   ";
cin >> choice;


return choice;
}
void print_line(int times){
for(int i=0;i<times;i++){
printf("#############################");
cout << endl;
}
}
void paragraph()
{
for (const string& word : msg)
    {
        cout <<"     "<< word << " ";
        cout << endl;
    }
}
