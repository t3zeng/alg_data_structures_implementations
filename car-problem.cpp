#include <iostream>
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
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define HEADER_SIZE (4)

// Create a buffer for each single command coming in
typedef struct {
  string header;
  uint8_t length;
  string cmd;
  char repeat;
  char checksum;
} packet_t;
static packet_t last_packet = {};

// Sorry not too familiar with C++ at this moment, setting this temp char array header
const char MSG_HEADER_C[5] = "ZOOX";
static char last_header[5] = "";
static uint8_t last_header_idx = 0;
static bool has_length = false;
static uint8_t pkt_read_idx = 0;
static string last_cmd = "";

/*
* Gathers characters until it gets a header
*/
bool parse_header(char c) {
  // we have received the header, we are now parsing
  if(strcmp(last_header, MSG_HEADER_C)==0) {
    return true;
  }
  
  // This is here just because the checksum doesn't check the header. It's to
  // handle scenarios where noise characters go in the middle of the header received
  if(MSG_HEADER_C[last_header_idx] == c) {
    last_header[last_header_idx] = c;
    last_header_idx++;
    if(last_header_idx == HEADER_SIZE) {
      last_header[last_header_idx] = '\0';
    }
  }
  
  return false;
}

void parse(char c) {
  // Parse each character until a header is found
  if (parse_header(c) == false) return;
  
  last_packet.header = last_header;
  
  // Header found, parsing length
  if(!has_length){
      last_packet.length = c-'0';
      has_length = true;
      return;
  }
  
  // Length found, parsing command
  if(pkt_read_idx < last_packet.length-1){
    // store characters in cmd slot
    last_cmd += c;
    pkt_read_idx++;
    last_packet.cmd = last_cmd;
    return;
  }
  else if(pkt_read_idx == last_packet.length-1){
    // store length
    last_packet.repeat = c;
    pkt_read_idx++;
    return;
  }
  else {
    // store checksum we received
    last_packet.checksum = c;
  }
  
  // Checking received data against checksum 
  if(last_packet.checksum ==
     checksum((char)(last_packet.length+'0')+last_packet.cmd+last_packet.repeat)) {
    // execute command and clear all metadata so more data can be acquired
    execute_packet_command(last_packet.cmd, (int)(last_packet.repeat-'0'));
    
    memset(&last_packet, 0, sizeof(last_packet));
    memset(&last_header, 0, sizeof(last_header));
    last_header_idx = 0;
    has_length = false;
    pkt_read_idx = 0;
    last_cmd = "";
  }
}