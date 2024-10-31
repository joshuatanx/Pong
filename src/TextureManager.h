//  TextureManager.h - header file for TextureManager class

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <string>
#include <vector>
#include <cstddef>
#include <unordered_map>

#include "Types.h"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(std::string file_path, std::string texture_name);
    static SDL_Texture* getTexture(TextureID texture_id);
    static SDL_Texture* getTexture(std::string texture_name);
    static void releaseTexture(TextureID texture_id);
    static void releaseTexture(std::string texture_name);

    static void draw(TextureID index, SDL_Rect source, SDL_Rect destination);
    static void draw(std::string texture_name, SDL_Rect source, SDL_Rect destination);

    static TextureID getTextureId(std::string texture_name);
    static std::string getTextureName(TextureID texture_id);

private:
    static std::vector<SDL_Texture*> textures;
    static std::unordered_map<std::string, TextureID> name_to_index;
    static std::unordered_map<TextureID, std::string> index_to_name;

    static void addToMap(std::string texture_name, TextureID texture_id);
    static void removeFromMap(std::string texture_name);
    static void removeFromMap(TextureID texture_id);
};

#endif //   TEXTUREMANAGER_H