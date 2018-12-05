//project Includes
#include "GameObject.h"

GameObject::GameObject()
	: m_active(true)
{

}

void GameObject::Draw(sf::RenderTarget& _Target)
{

}

void GameObject::Update(sf::Time _FrameTime)
{

}

void GameObject::Input(sf::Event _GameEvent)
{

}

sf::FloatRect GameObject::GetBounds() //function for setting up bounding boxes
{
	return sf::FloatRect();//use default float rect value
}

void GameObject::Collide(GameObject& _Collider)
{


}

bool GameObject::IsActive()
{
	return m_active;
}

void GameObject::SetPosition(sf::Vector2f _Position)
{

}

void GameObject::SetPosition(float _X, float _Y)
{

}

sf::Vector2f GameObject::GetPosition()
{
	return sf::Vector2f();
}