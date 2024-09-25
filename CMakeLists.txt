cmake_minimum_required(VERSION 3.29)
project(jogo_war)

set(CMAKE_CXX_STANDARD 20)

add_executable(jogo_war src/main.cpp
        src/Game.h
        src/ASCII_Engine/SpriteBuffer.cpp
        src/ASCII_Engine/Cores.hpp
        src/ASCII_Engine/Fase.cpp
        src/ASCII_Engine/ObjetoDeJogo.cpp
        src/ASCII_Engine/Sound.cpp
        src/ASCII_Engine/Sound.hpp
        src/ASCII_Engine/Sprite.cpp
        src/ASCII_Engine/SpriteAnimado.cpp
        src/ASCII_Engine/TextSprite.cpp
        src/ASCII_Engine/Core/ColorHandler.cpp
        src/ASCII_Engine/Core/Cores_base.cpp
        src/Constants.h
        src/KeyBoard.h
        src/BattleFase.h
        src/BattleFase.cpp
        src/Cursor.h
        src/Unit.h
        src/Tank.h
        src/Soldier.h
        src/Bazuca.h
        src/Helicopter.h
        src/Tile.h
        src/City.h
        src/Road.h
        src/Menu.h
)
