#pragma once

//library includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class AssetManager
{

public:
	//public interface/behaviours

	//asset mannager constructor
	AssetManager();

	//get a texture based on a file name
	static sf::Texture& GetTexture(std::string _fileName);

	//get a sound buffer based on a file name
	static sf::SoundBuffer& GetSoundBuffer(std::string _fileName);

	//get a Font based on a file name
	static sf::Font& GetFont(std::string _fileName);

private:
	//Private data for this class only

	// A pointer to the class itself for the singleton design pattern
	//for the one and only instance of this class
	static AssetManager* s_instance;

	//List of textures
	std::map<std::string, sf::Texture> m_textures;
	//list of sound buffers
	std::map<std::string, sf::SoundBuffer> m_soundBuffers;
	//list of Fonts
	std::map<std::string, sf::Font> m_fonts;

};