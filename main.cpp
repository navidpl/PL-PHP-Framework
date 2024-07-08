#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void print_line(int );
void paragraph();
json read_from_json(string );
int put_in_file(string,string,string,bool);
void mainchoose();
int choose();





vector<string> msg{"1 - DB connection", "2 - world"};
int choice;
string phpStart="<?php\n";

int main()
{
    

cout << endl;

print_line(2);
paragraph();
print_line(1);
mainchoose();


system("mkdir core");
system("clear");
return 0;
} 







void mainchoose(){
switch (choose())
{
case 1:
{
const json temp1 = read_from_json("core.json");
cout << "DB info please:\n name of data base:";
string dbname,username,password;
cin >> dbname;
cout << "\n username:";
cin >> username;
cout << "\n password:";
cin >> password;
string jeejee="$mysql_db =\""+dbname+"\"";
jeejee += ";\n$mysql_user =\""+username+"\"";
jeejee += ";\n$mysql_pass =\""+password+"\";\n";
put_in_file("core/connect.inc.php",phpStart+jeejee,temp1["config"]["DB"]["connection"],0);
//cout <<temp1["config"]["DB"]["connection"];
}
    /* code */
    break;
case 2:
break;
default:
    break;
}
print_line(2);
paragraph();
print_line(1);
mainchoose();
}

json read_from_json(string address){
    // string line;
  ifstream myfile(address);
//cout <<value;
     json config=json::parse(myfile);
     
    
  
//   if (myfile.is_open())
//   {
//     // while ( getline (myfile,line) )
//     // {
//     //   cout << line << '\n';
//     // }
//     myfile >> config;
//     myfile.close();["config"]["DB"]["connection"]
//   }


return config;
}
int put_in_file(string address,string extracontent,string value,bool position){
    if(position<1){
value=extracontent+value;

    }else{
value=value+extracontent;
    }
    std::ofstream outfile (address);

outfile << value << std::endl;

outfile.close();
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
