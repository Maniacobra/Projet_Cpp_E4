#pragma once

//NOTE::Sub Tags like ennemy types are contained within a component
enum class EntityTag {
    None,
    Player,
    Enemy,
    PlayerMissile
};

typedef  long         arch;   //pointer size 32 bit for 32 bit architecture and 64 for 64 one
typedef  unsigned int uint32;
