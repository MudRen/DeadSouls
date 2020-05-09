#include <lib.h>
#include ROOMS_H
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_POTION;

static void create() {
    ::create();
    SetKeyName("blue spice");
    SetId(({"spice","stick","stick of blue spice","slender"}));
    SetShort("a stick of blue spice");
    SetAdjectives(({"blue","spice"}));
    SetLong("A slender stick of blue spice.");
    SetMass(1);
    SetStrength(1);
    SetBaseCost("gold",10);
    SetStrength(1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("You eat a stick of blue spice. Your magic powers seem slightly improved.",
            "$N eats a stick of blue spice.");
    SetDuration(300);
    SetStats( ([ "intelligence" : 2 ]) );
    SetPoints( ([ "MP" : 150 ]) );
    SetVendorType(VT_MAGIC);
}

void init(){
    ::init();
}
