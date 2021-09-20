#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("green spice");
    SetId(({"spice","stick","stick of green spice","slender"}));
    SetShort("a stick of green spice");
    SetAdjectives(({"green","spice"}));
    SetLong("A slender stick of green spice.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",12);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("You eat a stick of green spice. You feel stronger, healthier, and more vigorous.",
            "$N eats a stick of green spice.");
    SetDuration(600);
    SetStats( ([ "durability" : 5, "strength" : 5 ]) );
    SetPoints( ([ "SP" : 450, "HP" : 450 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
