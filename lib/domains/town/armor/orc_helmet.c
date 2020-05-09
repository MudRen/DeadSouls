#include <lib.h>
#include <armor_types.h>
#include <damage_types.h>
inherit LIB_ARMOR;

varargs int CheckOrc(object who, mixed where);

static void create(){
    armor::create();
    SetKeyName("orc helmet");
    SetId(({"helmet","skull"}));
    SetAdjectives(({"bear","bone","skull","orc"}));
    SetShort("a bear skull helmet");
    SetLong("This is a helmet made of the hard bone of a bear, "+
            "treated with some sort of thick resin to "+
            "prevent shattering.");
    SetMass(150);
    SetBaseCost("silver",100);
    SetArmorType(A_HELMET);
    SetProtection(BLUNT, 20);
    SetProtection(BLADE, 20);
    SetProtection(KNIFE, 20);
    SetWear( (: CheckOrc :) );
}

varargs int CheckOrc(object who, mixed where){
    string race = who->GetRace();
    object env = environment(who);
    if( race == "orc"  || race == "half-orc"){
        who->eventPrint("You can almost feel the power of the bear as you "+
                "wear its skull.");
        if(env) tell_room(env, who->GetName()+" wears "+
                GetShort()+".", ({who}));
        return 1;
    }
    else {
        who->eventPrint("The helmet appears designed for orcish anatomy. "+
                "It does not fit you.");
        return 0;
    }
}

void init(){
    ::init();
}
