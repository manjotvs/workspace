#include <iostream>
#include <string.h>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Required prototype and main
void parse(char c);
int main() {
  string input;
  cin >> input;
  cout << "Cmd: ";
  for(char& c : input) {
    parse(c);
  }
  return 0;
}

// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------


void parse(char c)
{
  static uint8_t itr;
  static bool check_header;
  static uint8_t len;
  
  // Check the message header
  if(!check_header)
  {
    if(c == MSG_HEADER[0])
      itr=1;
    else if(c == MSG_HEADER[itr])
      itr++;
    if(itr==MSG_HEADER.length())
      check_header=1;
  }
  else
  {
    // Store length
    if(isdigit(c))
    {
      len= c - '0';
    }
    else
    {
      check_header = 0;
      return;
    }
    
    // Find the Command Type
    static uint8_t command_type;
    
    switch(c)
    {
      case 'L':
        command_type = 0;
        break;
      case 'R':
        command_type = 1;
        break;
      case 'F':
        command_type = 2;
        break;
      case 'B':
        command_type = 3;
        break;
      default:
        check_header = 0;
        return;
    }
    cout<<"Command Found"<<command_type;
    return;
    // Now check the remaining characters of command
    if(command_type)
    {
      
    }
      
      
  }
    
    
  
  
}