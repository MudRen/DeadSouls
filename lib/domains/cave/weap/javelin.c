#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("javelin");
    SetAdjectives( ({"throwing", "small", "light"}) );
    SetId( ({"spear"}) );
    SetShort("a javelin");
    SetLong("This is a small, light throwing spear.");
    SetMass(50);
    SetBaseCost("silver",20);
    SetVendorType(VT_WEAPON);
    SetClass(5);
    SetDamageType(PIERCE);
    SetWeaponType("projectile");
}

void init(){
    ::init();
    add_action("podcast","podcast");
}

int podcast(){
    write("Somehow the javelin just doesn't seem to do that now.");
    return 1;
}
