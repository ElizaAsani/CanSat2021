//arduino files
#include <Wire.h>
#include <Arduino.h>   // required before wiring_private.h
#include "wiring_private.h" // pinPeripheral() function
#include "Adafruit_BMP3XX.h"
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "SerialDefinitions.h"

//BMP
#define BMP_SCK 13 //26 on micro
#define BMP_MISO 12 //28
#define BMP_MOSI 11 //25
#define BMP_CS 10 //27

//THERMISTOR
#define THERMISTORPIN A2        
#define NUMSAMPLES 10
#define SERIESRESISTOR 10000    // the value of the 'other' resistor

#define TEMPERATURENOMINAL 25 // temp. for nominal resistance (almost always 25 C)
#define BCOEFFICIENT 3950 // The beta coefficient of the thermistor (usually 3000-4000)

float bmpSamples[NUMSAMPLES];
float bnoSamples[NUMSAMPLES];
float bnoXSamples[NUMSAMPLES];
float bnoYSamples[NUMSAMPLES];
float thermSamples[NUMSAMPLES];

//CONSTANT VALUE DEFINITIONS
#define SEALEVELPRESSURE_HPA 1013.25
#define PI 3.1415926535897932384626433832795

//DEFINE PAYLOAD PACKET VARS
const int teamID = 2617;
String missionTime = "00:00:00"; //hh:mm:ss
int packetCount = 0; //total transmitted packets from payload to ground
int openLogCount = 0;

//INITIALIZE ALT CORRECTION
int altCorrection = 0;

//SENSOR VARS
float alt = 0;
float rotation_x = 0;
float rotation_y = 0;
float rotation_z = 0;
float thermTemp = 0;

//OTHER GLOBAL VARS
float pres = 0;

