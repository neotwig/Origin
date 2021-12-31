#ifndef __ORIGINCONFIG_H__
#define __ORIGINCONFIG_H__

// Configuration for Origin

///////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////   SET THESE VALUES PRIOR TO PROGRAMMING THE ARDUINO   ////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

const int NUM_SWITCHES = 6; // the number of connected HDMI switches

///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////   ARDUINO PIN USAGE DEFINITIONS   //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

const byte NEXTION_TX2 = 16;
const byte NEXTION_RX2 = 17;

const byte SWX1_POWERLED = 22;
const byte SWX1_INPUT1 = 24;
const byte SWX1_INPUT2 = 26;
const byte SWX1_INPUT3 = 28;
const byte SWX1_INPUT4 = 30;
const byte SWX1_INPUT5 = 32;
const byte SWX1_POWERBUTTON = 34;
const byte SWX1_CHANGEINPUT = 36;

const byte SWX2_POWERLED = 23;
const byte SWX2_INPUT1 = 25;
const byte SWX2_INPUT2 = 27;
const byte SWX2_INPUT3 = 29;
const byte SWX2_INPUT4 = 31;
const byte SWX2_INPUT5 = 33;
const byte SWX2_POWERBUTTON = 35;
const byte SWX2_CHANGEINPUT = 37;

const byte SWX3_POWERLED = 38;
const byte SWX3_INPUT1 = 39;
const byte SWX3_INPUT2 = 40;
const byte SWX3_INPUT3 = 41;
const byte SWX3_INPUT4 = 42;
const byte SWX3_INPUT5 = 43;
const byte SWX3_POWERBUTTON = 44;
const byte SWX3_CHANGEINPUT = 45;

const byte SWX4_POWERLED = A8; // 62
const byte SWX4_INPUT1 = A9; // 63
const byte SWX4_INPUT2 = A10; // 64
const byte SWX4_INPUT3 = A11; // 65
const byte SWX4_INPUT4 = A12; // 66
const byte SWX4_INPUT5 = A13; // 67
const byte SWX4_POWERBUTTON = A14; // 68
const byte SWX4_CHANGEINPUT = A15; // 69

const byte SWX5_POWERLED = A0; // 54
const byte SWX5_INPUT1 = A1; // 55
const byte SWX5_INPUT2 = A2; // 56
const byte SWX5_INPUT3 = A3; // 57
const byte SWX5_INPUT4 = A4; // 58
const byte SWX5_INPUT5 = A5; // 59
const byte SWX5_POWERBUTTON = A6; // 60
const byte SWX5_CHANGEINPUT = A7; // 61

const byte SWX6_POWERLED = 7;
const byte SWX6_INPUT1 = 6;
const byte SWX6_INPUT2 = 5;
const byte SWX6_INPUT3 = 4;
const byte SWX6_INPUT4 = 3;
const byte SWX6_INPUT5 = 2;
const byte SWX6_POWERBUTTON = 9;
const byte SWX6_CHANGEINPUT = 8;

// IR receiver pin settings
const byte IR_RECV_DATA = 48;
const byte IR_RECV_POWER = 49;

// SD reader pin settings
const byte SD_MISO = 50;
const byte SD_MOSI = 51;
const byte SD_SCK = 52;
const byte SD_CS = 53;

const int NUM_PORTS = (NUM_SWITCHES * 4) + 1;

#endif