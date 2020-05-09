/*    /domains/Ylsrim/room/fighter_hall
 *    from the Dead Souls Object Library
 *    created by Descartes of Borg 960512
 */

#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetNoClean(1);
    SetTown("Ylsrim");
    SetClimate("indoors");
    SetAmbientLight(27);
    SetShort("the Hall of Fighters");
    SetLong("The Great Hall of Fighters was constructed many ages ago to "
            "act as a meeting place for all the fighters who come through "
            "Ylsrim.  In addition, it serves as a place to recruit new "
            "fighters into the fold.  A magnificent oak door stands north.");
    SetExits( ([
                "north" : "/domains/Ylsrim/room/fighter",
                "south" : "/domains/Ylsrim/room/kaliid5",
                ]) );
    SetInventory(([ "/domains/Ylsrim/npc/roshd" : 1 ]));
    SetItems( ([
                ({ "meeting","room","hall","fighter hall" }) : 
                "New adventurers may become fighters here.",
                ]) );
    SetDoor( "north", "/domains/Ylsrim/etc/fighter_door");
}

void init(){
    ::init();
}
