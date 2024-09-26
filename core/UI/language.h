//
// Created by dargonrol on 6/23/2024.
//

#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <string>
#include <SDL.h>

class Language {
private:
    Language();
    Language(Language const& copy);
    Language& operator=(Language const& copy);

public:
    struct {
        struct {
            std::string newGame = "new game";
            std::string settings;
            std::string quit;
            std::string watchReplays;
        } buttons;

        struct {
            std::string story;
            std::string graphicDesign;
        } credits;

        struct {
            struct {
                std::string title = "main Menu.....";
            } mainMenuScene;

            struct {
                std::string Scenetitle;
            } settingsScene;
        } labels;
    } language;

    static void setLanguageValue(std::string key, std::string& value, const std::string category1, const std::string category2);
    static void setLanguageValue(std::string key, std::string value, const std::string category1);

    static Language& getInstance();
};

enum Languages {
    ENGLISH,
    GERMAN
};

inline std::string german = "german.lang";
inline std::string english = "english.lang";
#endif //LANGUAGE_H
