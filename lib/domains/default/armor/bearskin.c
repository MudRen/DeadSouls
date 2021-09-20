#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;
static void create(){
    armor::create();
    SetKeyName("bearskin");
    SetId(({"bearskin","bear skin"}));
    SetAdjectives(({"thick","shaggy"}));
    SetShort("a thick, shaggy bearskin");
    SetLong("This is a thick bearskin which can be worn "+
            "as armor. Unfortunately the hide "+
            "has not been tanned, so it's rather "+
            "foul-smelling.");
    SetItems( ([
                "hide" : "It is untanned and subject "+
                "to natural decomposition."
                ]) );
    SetSmell( ([ "default" : "It reeks of death." ]) );
    SetMass(75);
    SetDamagePoints(100);
    SetProtection(BLUNT,1);
    SetProtection(BLADE,10);
    SetProtection(KNIFE,10);
    SetArmorType(A_CLOAK);
}
string GetAffectLong(object ob) {
    if(!ob || !living(ob)) return 0;
    return ob->GetName() + " reeks of death and decay.";
}
