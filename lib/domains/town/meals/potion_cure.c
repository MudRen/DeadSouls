#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>

inherit LIB_POTION;

static void create() {
    potion::create();
    SetKeyName("curative");
    SetId( ({ "vial","bottle", "cure","philtrum","cure light disease","cure disease" }) );
    SetAdjectives( "curative","cure" );
    SetShort("a vial of curative");
    SetLong("A vial containing a clear blue liquid that counteracts disease.");
    SetMass(20);
    SetMealType(MEAL_DRINK);
    SetStrength(5);
    SetMealMessages("You drink from the vial.",
            "$N drinks from a vial.");
    SetBaseCost("silver",200);
    SetEmptyName("vial");
    SetEmptyShort("an empty vial");
    SetEmptyLong("This empty vial once contained some liquid.");
    SetVendorType(VT_TREASURE);
}
void init(){
    ::init();
}

mixed eventDrink(object who) {
    mixed stuff = all_inventory(who);
    mixed germs, ret;
    int results = 0;
    germs = filter(stuff, (: $1->isGerm() :) );

    if(sizeof(germs)){
        foreach(object germ in germs){
            string type = germ->GetType();
            int cure = germ->GetCure();
            int output = germ->eventCure(who, cure, type);
            results += output;
        }
    }

    switch(results){
        case 0: tell_player(who, "You don't feel much difference.");break;
        case 1: tell_player(who, "You feel better.");break;
        default: tell_player(who, "You feel much better.");
    }
    ret = ::eventDrink(who);
    return ret;
}

