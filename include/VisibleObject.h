#pragma once

class VisibleObject{
 public:
  VisibleObject();
  virtual ~VisibleObject();

  virtual float GetHeight() const;
  virtual float GetWidth() const;

  virtual sf::Rect<float> GetBoundingRect() const;
  
  // chargement d'une texture
  virtual void Load(std::string filename);
  // dessiner à l'écran
  virtual void Draw(sf::RenderWindow & window);
  // mise à jour
  virtual void Update();
  
  // changer la position de l'objet
  virtual void SetPosition(float x, float y);
  // récupérer la position
  virtual sf::Vector2f GetPosition() const;
  virtual bool IsLoaded() const;

 protected:
  sf::Sprite& GetSprite();

 private:
  //sprite de l'objet
  sf::Sprite  _sprite;
  sf::Texture _image;
  std::string _filename;
  sf::Color   _color;
  bool _isLoaded;
  
};
