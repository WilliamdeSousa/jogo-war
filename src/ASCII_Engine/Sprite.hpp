#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include <string>
#include <iostream>

#include "Core/SpriteBase.hpp"

class Sprite : public SpriteBase
{
	friend class SpriteAnimado;
	
	friend std::ostream &operator<<(std::ostream &, const Sprite &);
	
public:
	Sprite(std::string, COR::Cor = COR::PADRAO, bool transparent = false);
	Sprite(std::ifstream &, int = -1, COR::Cor = COR::PADRAO, bool transparent = false);
	virtual ~Sprite(){}
	
	//SpriteBase
	virtual void putAt(const SpriteBase &, int = 0, int = 0);
	virtual SpriteBase *copia() const { return new Sprite(*this);}
	
	//RenderBase
	virtual void init() {};
	virtual void update() {};

    void reset() {  }
	

private:
	std::vector<std::string> sprt;
	
	void loadFromFile(std::string);
	void loadFromFile(std::ifstream &, int = -1);
	
	//SpriteBase
	virtual std::string getLinha(unsigned) const;
};

#endif // SPRITE_HPP
