#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>
#include "Graph.h"

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

Graph graph(&tft);

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);

  tft.fillScreen(BLACK);
  graph.initGraph();
  int width = tft.width();

  for(long x = 1; x<= width; x++) {
    plotOnGraph(graph, x);
  }
}

void plotOnGraph(Graph graph, int x) {
  int graphXMin1 = graph.graphX(x-1);
  int graphX = graph.graphX(x);
  graph.drawLine(graphXMin1, plotFunction(graphXMin1), graphX, plotFunction(graphX));
}

long plotFunction(long x) {
  float x_rad = x * M_PI / 180;
  return 20*cos(20*x_rad);
}

void loop() {

}