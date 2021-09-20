#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("yellow spice");
    SetId(({"spice","stick","stick of yellow spice","slender"}));
    SetShort("a stick of yellow spice");
    SetAdjectives(({"yellow","spice"}));
    SetLong("A slender stick of yellow spice.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",8);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("You eat a stick of yellow spice. You feel a little stronger and healthier.",
            "$N eats a stick of yellow spice.");
    SetDuration(300);
    SetPoints( ([ "HP" : 300 ]) );
    SetStats( ([ "strength" : 5 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
