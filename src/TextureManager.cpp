//  TextureManager.cpp - source file for TextureManager class

#include <SDL_image.h>
#include <stdexcept>

#include "TextureManager.h"
#include "Game.h"

std::vector<SDL_Texture*> TextureManager::textures;
std::unordered_map<std::string, TextureID> TextureManager::name_to_index;
std::unordered_map<TextureID, std::string> TextureManager::index_to_name;

SDL_Texture* TextureManager::loadTexture(std::string file_path, std::string texture_name)
{
    if (name_to_index.find(texture_name) != name_to_index.end())
    {
        throw std::runtime_error("Texture name \"" + texture_name + "\" has already been registered.\n");
    }

    SDL_Texture* texture = IMG_LoadTexture(Game::renderer, file_path.c_str());
    if (!texture)
    {
        throw std::runtime_error("Could not load texture \"" + texture_name + "\".\n");
    }

    printf("Loaded texture \"%s\" from file path %s.\n", texture_name.c_str(), file_path.c_str());

    textures.push_back(texture);
    addToMap(texture_name, textures.size() - 1);

    return texture;
}

SDL_Texture* TextureManager::getTexture(TextureID texture_id)
{
    if (texture_id >= textures.size())
    {
        throw std::runtime_error("Texture index " + std::to_string(texture_id) + " is not currently associated to a texture.\n");
    }

    return textures[texture_id];
}

SDL_Texture* TextureManager::getTexture(std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" not loaded.\n");
    }

    return textures[name_to_index[texture_name]];
}

void TextureManager::releaseTexture(TextureID texture_id)
{
    std::size_t size = textures.size();

    if (texture_id >= size)
    {
        throw std::runtime_error("Texture index " + std::to_string(texture_id) + " is not currently associated to a texture.\n");
    }

    std::string last_texture = index_to_name[size - 1];
    std::string old_texture = index_to_name[texture_id];

    //  swap dead texture with last texture in textures
    textures[texture_id] = textures[size - 1];
    //  update maps for last texture
    name_to_index[last_texture] = texture_id;
    index_to_name[texture_id] = last_texture;
    //  erase dead texture
    textures.pop_back();
    //  remove dead texture from maps
    name_to_index.erase(old_texture);
    index_to_name.erase(size - 1);
}

void TextureManager::releaseTexture(std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" has not been registered.");
    }

    releaseTexture(name_to_index[texture_name]);
}

void TextureManager::draw(TextureID index, SDL_Rect source, SDL_Rect destination)
{
    if (index >= textures.size())
    {
        printf("Texture index %zu out of valid range.\n", index);
        return;
    }
    
    SDL_RenderCopy(Game::renderer, textures[index], &source, &destination);
}

void TextureManager::draw(std::string texture_name, SDL_Rect source, SDL_Rect destination)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" has not been registered.");
    }

    SDL_RenderCopy(Game::renderer, textures[name_to_index[texture_name]], &source, &destination);
}

void TextureManager::addToMap(std::string texture_name, TextureID texture_id)
{
    if (name_to_index.find(texture_name) != name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" already registered");
    }

    name_to_index[texture_name] = texture_id;
    index_to_name[texture_id] = texture_name;

    printf("Registered texture \"%s\" with ID %zu.\n", texture_name.c_str(), texture_id);
}

void TextureManager::removeFromMap(std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        printf("Texture \"%s\" was never registered.\n", texture_name.c_str());
        return;
    }

    index_to_name.erase(name_to_index[texture_name]);
    name_to_index.erase(texture_name);
}

void TextureManager::removeFromMap(TextureID texture_id)
{
    if (index_to_name.find(texture_id) == index_to_name.end())
    {
        printf("Texture ID #%zu was never registered.\n", texture_id);
        return;
    }

    name_to_index.erase(index_to_name[texture_id]);
    index_to_name.erase(texture_id);
}

TextureID TextureManager::getTextureId(std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture name \"" + texture_name + "\" was never registered.\n");
    }

    return name_to_index[texture_name];
}

std::string TextureManager::getTextureName(TextureID texture_id)
{
    if (index_to_name.find(texture_id) == index_to_name.end())
    {
        throw std::runtime_error("Texture ID #\"" + std::to_string(texture_id) + "\" was never registered.\n");
    }

    return index_to_name[texture_id];
}