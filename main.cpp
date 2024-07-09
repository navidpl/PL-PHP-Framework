#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
// print line of ######
void print_line(int);
// print main menu
void paragraph();
// read json file (core.json)
json read_from_json(string);
// write in file
int put_in_file(string, string, string, bool);
//  input selection for main menu
void mainchoose();
int choose();
// go back to main menu
void back_to_main_menu();
// print with endline before and after
void print_common(string);

vector<string> msg{"0 - instalation info", "1 - DB connection", "2 - create .htaccess", "3 - create session and loggedin function"};
int choice;
string phpStart = "<?php\n";

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

void mainchoose()
{
    switch (choose())
    {
    case 1:
    {
        const json temp1 = read_from_json("core.json");
        cout << "DB info please:\n name of data base:";
        string dbname, username, password;
        cin >> dbname;
        cout << "\n username:";
        cin >> username;
        cout << "\n password:";
        cin >> password;
        string jeejee = "$mysql_db =\"" + dbname + "\"";
        jeejee += ";\n$mysql_user =\"" + username + "\"";
        jeejee += ";\n$mysql_pass =\"" + password + "\";\n";
        put_in_file("core/connect.inc.php", phpStart + jeejee, temp1["config"]["DB"]["connection"], 0);

        back_to_main_menu();
    }
    /* code */
    break;
    case 0:
    {
        print_line(1);
        print_common("For DB connection write: require_once('/core/connect.inc.php'); ");
        print_common("For Authentication write:  require_once('/core/core.inc.php'); ");
        back_to_main_menu();
    }
    break;
    case 2:
    {

        const json temp1 = read_from_json("core.json");
        put_in_file(".htaccess", "", temp1["config"]["htaccess"], 0);

        back_to_main_menu();
    }
    break;
    case 3:
    {
        const json temp1 = read_from_json("core.json");
        put_in_file("core/core.inc.php", "", temp1["config"]["session"], 0);

        back_to_main_menu();
    }
    break;
    default:
        break;
    }
    print_line(2);
    paragraph();
    print_line(1);
    mainchoose();
}

json read_from_json(string address)
{
    // string line;
    ifstream myfile(address);
    // cout <<value;
    json config = json::parse(myfile);

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
int put_in_file(string address, string extracontent, string value, bool position)
{
    if (position < 1)
    {
        value = extracontent + value;
    }
    else
    {
        value = value + extracontent;
    }
    std::ofstream outfile(address);

    outfile << value << std::endl;

    outfile.close();
    return 0;
}

int choose()
{
    cout << "Enter your selection :   ";
    cin >> choice;

    return choice;
}
void print_line(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("#############################");
        cout << endl;
    }
}
void paragraph()
{
    for (const string &word : msg)
    {
        cout << "     " << word << " ";
        cout << endl;
    }
}
void back_to_main_menu()
{
    print_line(2);
    cout << endl
         << endl
         << " For going back to main menu enter 0:";
    string habit;
    cin >> habit;
}
void print_common(string chap)
{
    print_line(1);
    cout << endl
         << "" << endl;
}