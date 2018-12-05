
//Project includes 
#include "TextObject.h"

TextObject::TextObject()
	: GameObject() //Always initialise your parent class in your constructor
	, m_Text()
{

}

void TextObject::Draw(sf::RenderTarget& _Target)
{
	_Target.draw(m_Text);
}

void TextObject::SetPosition(sf::Vector2f _Position)
{
	m_Text.setPosition(_Position);
}

void TextObject::SetPosition(float _X, float _Y)
{
	m_Text.setPosition(_X, _Y);
}