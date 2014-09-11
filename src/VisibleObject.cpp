#include "stdafx.h"
#include "VisibleObject.h"

VisibleObject::VisibleObject(): _isLoaded(false)
{
}

VisibleObject::~VisibleObject()
{
}

float VisibleObject::GetHeight() const
{
  return _sprite.getLocalBounds().height;
}

float VisibleObject::GetWidth() const
{
  return _sprite.getLocalBounds().width;
}

sf::Rect<float> VisibleObject::GetBoundingRect() const
{
  return _sprite.getGlobalBounds();
}

void VisibleObject::Load(std::string filename)
{
  if(_image.loadFromFile(filename) == false)
    {
      _filename = "";
      _isLoaded = false;
    }
  else
    {
      _image.setSmooth(true);
      _filename = filename;
      _sprite.setTexture(_image);
      _isLoaded = true;
    }
}

void VisibleObject::Draw(sf::RenderWindow & renderWindow)
{
  if(_isLoaded)
    {
      renderWindow.draw(_sprite);
    }
}

void VisibleObject::Update()
{
}

void VisibleObject::SetPosition(float x, float y)
{
  if(_isLoaded)
    {
      _sprite.setPosition(x, y);
    }
}

sf::Vector2f VisibleObject::GetPosition() const
{
  if(_isLoaded)
    {
      return _sprite.getPosition();
    }
  return sf::Vector2f();
}

sf::Sprite& VisibleObject::GetSprite()
{
  return _sprite;
}

bool VisibleObject::IsLoaded() const
{
  return _isLoaded;
}
