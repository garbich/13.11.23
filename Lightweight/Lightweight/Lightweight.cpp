#include <iostream>
#include <unordered_map>

using namespace std;

class Character {
public:
    char symbol;

    Character(char s) : symbol(s) {}

    void display(int size, const string& font) const {
        cout << "Symbol: " << symbol << ", Size: " << size << ", Font: " << font << endl;
    }
};

class CharacterFactory {
private:
    unordered_map<char, Character*> characters;

public:
    Character* getCharacter(char symbol) {
        if (characters.find(symbol) == characters.end()) {
            characters[symbol] = new Character(symbol);
        }
        return characters[symbol];
    }
};

class TextEditor {
private:
    CharacterFactory characterFactory;

public:
    void addCharacter(char symbol, int size, const string& font) {
        Character* character = characterFactory.getCharacter(symbol);
        character->display(size, font);
    }
};

int main() {
    TextEditor textEditor;

    textEditor.addCharacter('A', 12, "Arial");
    textEditor.addCharacter('B', 14, "Times New Roman");
    textEditor.addCharacter('A', 16, "Courier New");

  
}
