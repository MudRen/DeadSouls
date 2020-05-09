#include <lib.h>

inherit LIB_ROOM;

static void create() {

    room::create();
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("a creator's workroom");
    SetLong("You are standing in the workroom of a creator."+
            " The start room is down from here.");
    SetItems( ([ 
                "workroom" : "It looks very nice.",
                ]) );
    SetInventory(([
                ]));
    SetObviousExits("down");
    SetExits( ([ "down" : "/domains/default/room/start.c",
                ]) );
}

