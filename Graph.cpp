#include "Graph.h"
//#include <Elegoo_TFTLCD.h>

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Graph::Graph(Elegoo_TFTLCD* _tft, int _offsetX = 0, int _offsetY = 0) {
  tft = _tft;
  offsetX = _offsetX;
  width = tft->width();
  height = tft->height();
  originX = width/2 + _offsetX;
  originY = height/2 + _offsetY;
}

void Graph::initGraph() {
  tft->drawLine(0, originY, width, originY, RED);
  tft->drawLine(originX, 0, originX, height, BLUE);
}

int Graph::translateX(int x) {
   return x + originX;
}

int Graph::translateY(int y) {
  return originY - y;
}

int Graph::graphX(int x) {
   return x - width/2 - offsetX;
}

void Graph::drawPoint(int x, int y) {
  int tX = translateX(x);
  int tY = translateY(y);
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(") -> (");
  Serial.print(tX);
  Serial.print(", ");
  Serial.print(tY);
  Serial.println(")");
  tft->drawPixel(tX, tY, YELLOW);
}

void Graph::drawLine(int x1, int y1, int x2, int y2) {
  tft->drawLine(translateX(x1), translateY(y1), translateX(x2), translateY(y2), YELLOW);
}
