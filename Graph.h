#ifndef GRAPH_h
#define GRAPH_h

#include <Arduino.h>
#include <Elegoo_TFTLCD.h>

class Graph {
  private:
    int width;
    int height;
    int offsetX;
    int originX;
    int originY;
    Elegoo_TFTLCD* tft;
    int translateX(int x);
    int translateY(int y);

  public:
    Graph(Elegoo_TFTLCD* _tft, int _offsetX = 0, int _offsetY = 0);
    int graphX(int x);
    void initGraph();
    void drawPoint(int x, int y);
    void drawLine(int x1, int y1, int x2, int y2);
};

#endif
