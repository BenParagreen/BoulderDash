//Library includes
#include <assert.h>

//project include
#include "AssetManager.h"

//inititlise the static reference to our instance - to Nullpointer(AKA zero)
AssetManager* AssetManager::s_instance = nullptr;

// constructor
AssetManager::AssetManager()
	:m_textures      ()
	,m_soundBuffers  ()
	,m_fonts         ()
{
	//throw an error and stop execution(in debug mode)
	//if a copy of this class already exists

	assert(s_instance == nullptr);
	//^says if s_instance is not a null pointer, then stop exectution

	//Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}

//get a texture based on a file name
sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_textures.find(_fileName);
	//"auto" in this case is eqivalent to writting std::map<std::string:sf::texture>::iterator
	//this keyword "auto" can be used in cases where the compiler can figure out the type of variable for you
	//YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS
	
	//did we find the texure? (aka was it already loaded?)
	//(iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_textures.end())
	{
		//YES! we found it!
		return keyValuePair->second;
	}
	else
	{
		//NO we didn't find it!

		//lets create it

		//create a new key value pair using the file name
		//the subscript operator creates an entry in the map if there is not already one there
	
		sf::Texture& texture = s_instance->m_textures[_fileName];
		//blank texture has been created
		//now just load it from file using SFML

		texture.loadFromFile(_fileName);
		

		//return the texture to the calling code
		return texture;
	}
}

//get a soundbuffer based on a file name
sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	//create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_soundBuffers.find(_fileName);
	//"auto" in this case is eqivalent to writting std::map<std::string:sf::soundbuffer>::iterator
	//this keyword "auto" can be used in cases where the compiler can figure out the type of variable for you
	//YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//did we find the sound buffer? (aka was it already loaded?)
	//(iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_soundBuffers.end())
	{
		//YES! we found it!
		return keyValuePair->second;
	}
	else
	{
		//NO we didn't find it!

		//lets create it

		//create a new key value pair using the file name
		//the subscript operator creates an entry in the map if there is not already one there

		sf::SoundBuffer& soundbuffer = s_instance->m_soundBuffers[_fileName];
		//blank sound buffer has been created
		//now just load it from file using SFML

		soundbuffer.loadFromFile(_fileName);


		//return the sound buffer to the calling code
		return soundbuffer;
	}
}

//get a font based on a file name
sf::Font& AssetManager::GetFont(std::string _fileName)
{
	//create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_fonts.find(_fileName);
	//"auto" in this case is eqivalent to writting std::map<std::string:sf::font>::iterator
	//this keyword "auto" can be used in cases where the compiler can figure out the type of variable for you
	//YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//did we find the font? (aka was it already loaded?)
	//(iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_fonts.end())
	{
		//YES! we found it!
		return keyValuePair->second;
	}
	else
	{
		//NO we didn't find it!

		//lets create it

		//create a new key value pair using the file name
		//the subscript operator creates an entry in the map if there is not already one there

		sf::Font& font = s_instance->m_fonts[_fileName];
		//blank font has been created
		//now just load it from file using SFML

		font.loadFromFile(_fileName);


		//return the font to the calling code
		return font;
	}
}