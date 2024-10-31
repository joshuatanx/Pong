//  TextureManager.cpp - source file for TextureManager class

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdexcept>

#include "TextureManager.h"
#include "Game.h"

std::vector<SDL_Texture*> TextureManager::textures;
std::unordered_map<std::string, TextureID> TextureManager::name_to_index;
std::unordered_map<TextureID, std::string> TextureManager::index_to_name;

TTF_Font* TextureManager::current_font;
std::string TextureManager::current_font_name;
SDL_Colour TextureManager::current_font_colour;
std::vector<SDL_Texture*> TextureManager::text_textures;
std::unordered_map<std::string, TextureID> TextureManager::text_to_texture;

SDL_Texture* TextureManager::loadTexture(const std::string file_path, const std::string texture_name)
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

bool TextureManager::loadFontStyle(const std::string file_path, const std::string font_name, const float font_size, const SDL_Colour font_colour)
{
    if (current_font)
    {
        printf("Could not load font style \"%s\" as another font is already open.\n", font_name.c_str());
        return false;
    }

    current_font = TTF_OpenFont(file_path.c_str(), font_size);
    if (!current_font)
    {
        printf("Could not load font style \"%s\" from file path \"%s\". SDL_ttf error: %s.\n", font_name.c_str(), file_path.c_str(), TTF_GetError());
        return false;
    }

    current_font_name = font_name;
    current_font_colour = font_colour;
    return true;
}

void TextureManager::unloadCurrentFontStyle()
{
    if (!current_font)
    {
        current_font_name = "";
        return;
    }

    TTF_CloseFont(current_font);
    current_font = NULL;
    current_font_name = "";
    current_font_colour = (SDL_Colour) {0, 0, 0};
}

SDL_Texture* TextureManager::loadTextTexture(const std::string text, Uint32 wrap_length)
{
    if (text_to_texture.find(text) != text_to_texture.end())
    {
        return text_textures[text_to_texture[text]];
    }

    SDL_Surface* text_surface = TTF_RenderText_Solid_Wrapped(current_font, text.c_str(), current_font_colour, wrap_length);
    if(!text_surface)
    {
        throw std::runtime_error("Could not render text surface. SDL_ttf error: " + std::string(TTF_GetError()) + ".\n");
    }

    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(Game::renderer, text_surface);
    if (!text_texture)
    {
        throw std::runtime_error("Could not create texture from rendered text. SDL error: " + std::string(SDL_GetError()) + ".\n");
    }

    text_textures.push_back(text_texture);
    text_to_texture[text] = text_textures.size() - 1;

    SDL_FreeSurface(text_surface);

    return NULL;
}

void TextureManager::releaseTextTexture(const std::string text)
{
    if (text_to_texture.find(text) == text_to_texture.end())
    {
        return;
    }

    releaseTextTexture(text_to_texture[text]);
}

void TextureManager::releaseTextTexture(const TextureID texture_id)
{
    if (texture_id >= text_textures.size())
    {
        return;
    }
    SDL_DestroyTexture(text_textures[texture_id]);
    text_textures[texture_id] = NULL;
}

void TextureManager::renderText(const std::string text, const SDL_Rect destination)
{
    if (text_to_texture.find(text) == text_to_texture.end())
    {
        printf("Could not find texture for text: %s.\n", text.c_str());
        return;
    }

    SDL_Texture* texture = text_textures[text_to_texture[text]];
    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &source.w, &source.h);
    SDL_RenderCopy(Game::renderer, texture, &source, &destination);
}

SDL_Texture* TextureManager::getTexture(const TextureID texture_id)
{
    if (texture_id >= textures.size())
    {
        throw std::runtime_error("Texture index " + std::to_string(texture_id) + " is not currently associated to a texture.\n");
    }

    return textures[texture_id];
}

SDL_Texture* TextureManager::getTexture(const std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" not loaded.\n");
    }

    return textures[name_to_index[texture_name]];
}

void TextureManager::releaseTexture(const TextureID texture_id)
{
    std::size_t size = textures.size();

    if (texture_id >= size)
    {
        throw std::runtime_error("Texture index " + std::to_string(texture_id) + " is not currently associated to a texture.\n");
    }

    SDL_DestroyTexture(textures[texture_id]);

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

void TextureManager::releaseTexture(const std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" has not been registered.");
    }

    releaseTexture(name_to_index[texture_name]);
}

void TextureManager::draw(const TextureID index, const SDL_Rect source, const SDL_Rect destination)
{
    if (index >= textures.size())
    {
        printf("Texture index %zu out of valid range.\n", index);
        return;
    }
    
    SDL_RenderCopy(Game::renderer, textures[index], &source, &destination);
}

void TextureManager::draw(const std::string texture_name, const SDL_Rect source, const SDL_Rect destination)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" has not been registered.");
    }

    SDL_RenderCopy(Game::renderer, textures[name_to_index[texture_name]], &source, &destination);
}

void TextureManager::addToMap(const std::string texture_name, const TextureID texture_id)
{
    if (name_to_index.find(texture_name) != name_to_index.end())
    {
        throw std::runtime_error("Texture \"" + texture_name + "\" already registered");
    }

    name_to_index[texture_name] = texture_id;
    index_to_name[texture_id] = texture_name;

    printf("Registered texture \"%s\" with ID %zu.\n", texture_name.c_str(), texture_id);
}

void TextureManager::removeFromMap(const std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        printf("Texture \"%s\" was never registered.\n", texture_name.c_str());
        return;
    }

    index_to_name.erase(name_to_index[texture_name]);
    name_to_index.erase(texture_name);
}

void TextureManager::removeFromMap(const TextureID texture_id)
{
    if (index_to_name.find(texture_id) == index_to_name.end())
    {
        printf("Texture ID #%zu was never registered.\n", texture_id);
        return;
    }

    name_to_index.erase(index_to_name[texture_id]);
    index_to_name.erase(texture_id);
}

TextureID TextureManager::getTextureId(const std::string texture_name)
{
    if (name_to_index.find(texture_name) == name_to_index.end())
    {
        throw std::runtime_error("Texture name \"" + texture_name + "\" was never registered.\n");
    }

    return name_to_index[texture_name];
}

std::string TextureManager::getTextureName(const TextureID texture_id)
{
    if (index_to_name.find(texture_id) == index_to_name.end())
    {
        throw std::runtime_error("Texture ID #\"" + std::to_string(texture_id) + "\" was never registered.\n");
    }

    return index_to_name[texture_id];
}

void TextureManager::quit()
{
    for (auto& [text, texture_id] : text_to_texture)
    {
        releaseTextTexture(texture_id);
    }
    unloadCurrentFontStyle();
}