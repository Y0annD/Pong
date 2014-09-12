#ifndef SHAPE
#define SHAPE

class Shape{
 public:
 Shape(int x, int y, int width, int height, int orientation):_x(x), _y(y),
    _width(width),_height(height), _orientation(orientation){}

  virtual void draw()const{}
  
  // accesseurs
  inline int getX(){return _x;}
  inline int getY(){return _y;}
  inline int getWidth(){return _width;}
  inline int getHeight(){return _height;}
  inline int getOrientation(){return _orientation;}

  //mutateurs
  inline void setX(int x){_x = x;}
  inline void setY(int y){_y = y;}
  inline void setWidth(int width){_width = width;}
  inline void setHeight(int height){_height = height;}
  inline void setOrientation(int orientation){_orientation = orientation;}

 protected:
  // shape position
  int _x, _y;
  // shape size
  int _width, _height;
  //orientation
  int _orientation;
};

#endif
