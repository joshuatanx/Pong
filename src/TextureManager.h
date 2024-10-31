//  TextureManager.h - header file for TextureManager class

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <cstddef>
#include <map>
#include <SDL.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "Types.h"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const std::string file_path, const std::string texture_name);
    static SDL_Texture* getTexture(const TextureID texture_id);
    static SDL_Texture* getTexture(const std::string texture_name);
    static void releaseTexture(const TextureID texture_id);
    static void releaseTexture(const std::string texture_name);

    static bool loadFontStyle(const std::string file_path, const std::string font_name, const float font_size, const SDL_Colour font_colour);
    static void unloadCurrentFontStyle();
    static SDL_Texture* loadTextTexture(const std::string text, const Uint32 wrap_length);
    static void releaseTextTexture(const std::string text);
    static void releaseTextTexture(const TextureID texture_id);
    static void renderText(const std::string text, const SDL_Rect destination);

    static void draw(const TextureID index, const SDL_Rect source, const SDL_Rect destination);
    static void draw(const std::string texture_name, const SDL_Rect source, const SDL_Rect destination);

    static TextureID getTextureId(const std::string texture_name);
    static std::string getTextureName(const TextureID texture_id);

    static void quit();

private:
    static std::vector<SDL_Texture*> textures;
    static std::unordered_map<std::string, TextureID> name_to_index;
    static std::unordered_map<TextureID, std::string> index_to_name;

    static void addToMap(const std::string texture_name, const TextureID texture_id);
    static void removeFromMap(const std::string texture_name);
    static void removeFromMap(const TextureID texture_id);

    static TTF_Font* current_font;
    static std::string current_font_name;
    static SDL_Colour current_font_colour;
    static std::vector<SDL_Texture*> text_textures;
    static std::unordered_map<std::string, TextureID> text_to_texture;
};

#endif //   TEXTUREMANAGER_H