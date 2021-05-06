#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace translator
{
    string aToBin(string aCommand)
    {
        int val = stoi(aCommand);
        string out = "0";

        if((val - 16384) >= 0)
        {
            val -= 16384;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 8192) >= 0)
        {
            val -= 8192;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 4096) >= 0)
        {
            val -= 4096;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 2048) >= 0)
        {
            val -= 2048;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 1024) >= 0)
        {
            val -= 1024;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 512) >= 0)
        {
            val -= 512;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 256) >= 0)
        {
            val -= 256;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 128) >= 0)
        {
            val -= 128;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 64) >= 0)
        {
            val -= 64;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 32) >= 0)
        {
            val -= 32;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 16) >= 0)
        {
            val -= 16;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 8) >= 0)
        {
            val -= 8;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 4) >= 0)
        {
            val -= 4;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 2) >= 0)
        {
            val -= 2;
            out += "1";
        }
        else {
            out += "0";
        }

        if((val - 1) >= 0)
        {
            val -= 1;
            out += "1";
        }
        else {
            out += "0";
        }

        return out;
    }

    string cToBin(string cCommand)
    {
        string out = "111";
        string comp;
        string dest;
        string jump;
        // Finding comp
        int equals = cCommand.find("=", 0);
        if(equals > -1 && equals < cCommand.length())
        {
            if(cCommand.substr(equals + 1, 3) == "D|M")
                comp = "1010101";
            else if(cCommand.substr(equals + 1, 3) == "D|A")
                comp = "0010101";
            else if(cCommand.substr(equals + 1, 3) == "D&A")
                comp = "0000000";
            else if(cCommand.substr(equals + 1, 3) == "D&M")
                comp = "1000000";
            else if(cCommand.substr(equals + 1, 3) == "A-D")
                comp = "0000111";
            else if(cCommand.substr(equals + 1, 3) == "M-D")
                comp = "1000111";
            else if(cCommand.substr(equals + 1, 3) == "D+1")
                comp = "0011111";
            else if(cCommand.substr(equals + 1, 3) == "A+1")
                comp = "0110111";
            else if(cCommand.substr(equals + 1, 3) == "M+1")
                comp = "1110111";
            else if(cCommand.substr(equals + 1, 3) == "D-1")
                comp = "0001110";
            else if(cCommand.substr(equals + 1, 3) == "A-1")
                comp = "0110010";
            else if(cCommand.substr(equals + 1, 3) == "M-1")
                comp = "1110010";
            else if(cCommand.substr(equals + 1, 3) == "D+A")
                comp = "0000010";
            else if(cCommand.substr(equals + 1, 3) == "D+M")
                comp = "1000010";
            else if(cCommand.substr(equals + 1, 3) == "D-A")
                comp = "0010011";
            else if(cCommand.substr(equals + 1, 3) == "D-M")
                comp = "1010011";
            else if(cCommand.substr(equals + 1, 2) == "-1")
                comp = "0111010";
            else if(cCommand.substr(equals + 1, 2) == "!D")
                comp = "0001101";
            else if(cCommand.substr(equals + 1, 2) == "!A")
                comp = "0110001";
            else if(cCommand.substr(equals + 1, 2) == "!M")
                comp = "1110001";
            else if(cCommand.substr(equals + 1, 2) == "-D")
                comp = "0001111";
            else if(cCommand.substr(equals + 1, 2) == "-A")
                comp = "0110011";
            else if(cCommand.substr(equals + 1, 2) == "-M")
                comp = "1110011";
            else if(cCommand.substr(equals + 1, 1) == "0")
                comp = "0101010";
            else if(cCommand.substr(equals + 1, 1) == "1")
                comp = "0111111";
            else if(cCommand.substr(equals + 1, 1) == "D")
                comp = "0001100";
            else if(cCommand.substr(equals + 1, 1) == "A")
                comp = "0110000";
            else if(cCommand.substr(equals + 1, 1) == "M")
                comp = "1110000";
        }
        else
        {
            if(cCommand.find("D|M", 0) >= 0 && cCommand.find("D|M", 0) < cCommand.length())
                comp = "1010101";
            else if(cCommand.find("D|A", 0) >= 0 && cCommand.find("D|A", 0) < cCommand.length())
                comp = "0010101";
            else if(cCommand.find("D&A", 0) >= 0 && cCommand.find("D&A", 0) < cCommand.length())
                comp = "0000000";
            else if(cCommand.find("D&M", 0) >= 0 && cCommand.find("D&M", 0) < cCommand.length())
                comp = "1000000";
            else if(cCommand.find("A-D", 0) >= 0 && cCommand.find("A-D", 0) < cCommand.length())
                comp = "0000111";
            else if(cCommand.find("M-D", 0) >= 0 && cCommand.find("M-D", 0) < cCommand.length())
                comp = "1000111";
            else if(cCommand.find("D+1", 0) >= 0 && cCommand.find("D+1", 0) < cCommand.length())
                comp = "0011111";
            else if(cCommand.find("A+1", 0) >= 0 && cCommand.find("A+1", 0) < cCommand.length())
                comp = "0110111";
            else if(cCommand.find("M+1", 0) >= 0 && cCommand.find("M+1", 0) < cCommand.length())
                comp = "1110111";
            else if(cCommand.find("D-1", 0) >= 0 && cCommand.find("D-1", 0) < cCommand.length())
                comp = "0001110";
            else if(cCommand.find("A-1", 0) >= 0 && cCommand.find("A-1", 0) < cCommand.length())
                comp = "0110010";
            else if(cCommand.find("M-1", 0) >= 0 && cCommand.find("M-1", 0) < cCommand.length())
                comp = "1110010";
            else if(cCommand.find("D+A", 0) >= 0 && cCommand.find("D+A", 0) < cCommand.length())
                comp = "0000010";
            else if(cCommand.find("D+M", 0) >= 0 && cCommand.find("D+M", 0) < cCommand.length())
                comp = "1000010";
            else if(cCommand.find("D-A", 0) >= 0 && cCommand.find("D-A", 0) < cCommand.length())
                comp = "0010011";
            else if(cCommand.find("D-M", 0) >= 0 && cCommand.find("D-M", 0) < cCommand.length())
                comp = "1010011";
            else if(cCommand.find("-1", 0) >= 0 && cCommand.find("-1", 0) < cCommand.length())
                comp = "0111010";
            else if(cCommand.find("!D", 0) >= 0 && cCommand.find("!D", 0) < cCommand.length())
                comp = "0001101";
            else if(cCommand.find("!A", 0) >= 0 && cCommand.find("!A", 0) < cCommand.length())
                comp = "0110001";
            else if(cCommand.find("!M", 0) >= 0 && cCommand.find("!M", 0) < cCommand.length())
                comp = "1110001";
            else if(cCommand.find("-D", 0) >= 0 && cCommand.find("-D", 0) < cCommand.length())
                comp = "0001111";
            else if(cCommand.find("-A", 0) >= 0 && cCommand.find("-A", 0) < cCommand.length())
                comp = "0110011";
            else if(cCommand.find("-M", 0) >= 0 && cCommand.find("-M", 0) < cCommand.length())
                comp = "1110011";
            else if(cCommand.find("0", 0) >= 0 && cCommand.find("0", 0) < cCommand.length())
                comp = "0101010";
            else if(cCommand.find("1", 0) >= 0 && cCommand.find("1", 0) < cCommand.length())
                comp = "0111111";
            else if(cCommand.find("D", 0) >= 0 && cCommand.find("D", 0) < cCommand.length())
                comp = "0001100";
            else if(cCommand.find("A", 0) >= 0 && cCommand.find("A", 0) < cCommand.length())
                comp = "0110000";
            else if(cCommand.find("M", 0) >= 0 && cCommand.find("M", 0) < cCommand.length())
                comp = "1110000";
        }
        // Finding jump
        int semi = cCommand.find(";", 0);
        if(cCommand.substr(semi+1,3) == "JGT")
            jump ="001";
        else if(cCommand.substr(semi + 1,3) == "JEQ")
            jump = "010";
        else if(cCommand.substr(semi + 1,3) == "JGE")
            jump = "011";
        else if(cCommand.substr(semi + 1,3) == "JLT")
            jump = "100";
        else if(cCommand.substr(semi + 1,3) == "JNE")
            jump = "101";
        else if(cCommand.substr(semi + 1,3) == "JLE")
            jump = "110";
        else if(cCommand.substr(semi + 1,3) == "JMP")
            jump = "111";
        else
            jump = "000";
        // Finding dest
        if(equals > -1 && equals < cCommand.length())
        {
            string d3, d2, d1;
            int findM = cCommand.find("M", 0);
            if(findM > -1 && findM < equals) 
            {
                d3 = "1";
            }
            else 
            {
                d3 = "0";
            }
            int findD = cCommand.find("D", 0);
            if(findD > -1 && findD < equals)
            {
                d2 = "1";
            }
            else
            {
                d2 = "0";
            }
            int findA = cCommand.find("A", 0);
            if(findA > -1 && findA < equals)
            {
                d1 = "1";
            }
            else
            {
                d1 = "0";
            }
            dest = d1 + d2 + d3;
        }
        else
            dest = "000"; // No equal sign
        out = out + comp + dest + jump;
        return out;
    }
}

int main(int argc, char *argv[])
{
    // Opening asm file to read and hack file to write with the same name
    ifstream fin(argv[argc - 1]);
    string file = argv[argc - 1];
    int dotLocation = file.find(".", 0);
    string hackFile = file.substr(0, dotLocation) + ".hack";
    ofstream fout(hackFile.c_str());
    
    // Starting to parse
    int PC = 0;
    int RAMLocation = 16;
    string command, hack_command;
    while(getline(fin,command))
    {
        if(command.substr(0, 1) == "/" || command.substr(0, 1) == "") // comments or blank line, do nothing
        {
            ;
        }
        else if(command.substr(0, 1) == "@")
        {
            hack_command=translator::aToBin(command.substr(1,command.length()-1));
            fout << hack_command << endl;
            PC++;
        }
        else
        {
            hack_command=translator::cToBin(command);
            fout << hack_command << endl;
            PC++;
        }
    }
 
    // Closing files
    fin.close();
    fout.close();
    return 0;
}