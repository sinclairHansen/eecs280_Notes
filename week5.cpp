

//Notes for week 5
// File I/O Streams wee woo
// Sinclair Hansen
// September 22, 2025


#include <iostream>
#include <fstream> // This is needed for file operations
using namespace std;

int main(){
    ifstream fin("text.txt"); //When opening a file, check if it opened
    if(!fin.is_open())
    {
        cout<<"open failed" <<endl;
        return 1;// If not, return a fail message
    }

    string item; //creates a string variable
    fin >> item; //extracts a string from the txt file

    double weight; // creates a double object
    fin >> weight;// extracts the double from the txt
    fin.close(); // close the file after using it. Not always necessary if forgotten



    // File Output: ofstream

    ofstream fout("text.txt");
    if(!fin.is_open())
    {
        cout<<"open failed" <<endl;
        return 1;// If not, return a fail message
    }
    for (int i = 1; i < 1000; i++)
    {
        fout << i << endl; //Sends the value of i to the file. Each output creates a new line
    }
    string word;
    while(fin >> word) // reads until end of file
    {
        if(word == "bee"){fout << "cat" << endl;}
        else {fout << word << endl;}


    } //When the loop exits, we know we made it to the end of the file.

    while(fin) // This would compile, but it is not reccomended because it will repeat the last word twice. It doesn't check if the extraction is
    // successful until after the word gets printed.
    {
        fin >> word;
        cout << word << endl;
    }

    string line;
    getline(fin, line);
    cout << line << endl; // This is also something to be weary of if you are getting string from the line. Only use for printing whole lines. 


    /*Exit codes
    When a process finishes execution, it passes back an integer "exit status"
    or "exit code"

    At the terminal, $? gives the exit status of the previous command. Use echo $?
    to see it. Code 0 indicate success.

    */
   fin >> item >> weight; // Multiple read operations on one line. 


    //String streams and testing
    //istringstream 
    // an input stream that uses a string as its source.
    // useful for simulating stream input from a "hardcoded" string

    //ostringstream
    //  an output stream that writes into a string.
    //  useful for capturing output as a string that can be checked for corectness

    return 0;
}
//argv and argc
// Two parameters to main:
//  argc - the number of arguments
//  argv - an array of the arguments (sort of)

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        cout << "Usage: ./redact WORD INFILE OUTFILE NUM_STARS"<<endl;
        return 1;
    }
    //Use caution when comparing elements of argv.

    //BAD, compares addresses
    if(argv[1] == "--debug"){}
    //OK, wrap one in a std::string
    if (std::string(argv[1] == "--debug")){}

    //OK, ""s suffix creates a std::string
    if(argv[1] == "debug"s){}

    

    //stoi() parses an integer encoded in a string
    #include <string> // needed for stoi() and stod()
    int numStars = stoi(argv[4]);//Yes - parse string "10" to int 10

    //stod() parses a double encoded in a string
    

}