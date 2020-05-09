#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
inherit LIB_BAIT_WITH;

static void create() {
    meal::create();
    SetKeyName("worm");
    SetId(({"bait","wriggler"}));
    SetAdjectives(({"small","wriggly","bait"}));
    SetShort("a worm");
    SetLong("This is a small worm, suitable for baiting a fishing pole.");
    SetMass(1);
    SetStrength(1);
    SetBaitStrength(200);
    SetBaseCost("silver",1);
    SetMealType(MEAL_FOOD);
    SetMealMessages("You eat a small wriggling worm. Yuck!",
            "$N eats $P little worm. Yuck!");
}
void init(){
    ::init();
}
