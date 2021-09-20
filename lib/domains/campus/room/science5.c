#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

int PreExit(mixed args...){
    object who = this_player();
    write("You are scanned by a beam of light from the sliding door.");
    say(who->GetName()+" is scanned by a beam of light from the sliding door.");
    if(!present_file("/domains/campus/armor/badge2",who)){
        write("The door does not open.");
        return 0;
    }
    else {
        write("The door opens, letting you through.\n");
        say("The door lets "+who->GetName()+" through.\n");
        return 1;
    }
}

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Secondary Science Hallway East");
    SetLong("This is the secondary hallway in the LPC University Science Building. The hallway runs east and west from here. To the south is a sliding door. North of here is a classroom.");
    SetClimate("indoors");
    SetItems( ([
                ({ "door","sliding door" }) : "A strange, metallic sliding door.",
                ]) );
    SetExits( ([
                "north" : "/domains/campus/room/classroom1",
                "east" : "/domains/campus/room/science4",
                "west" : "/domains/campus/room/science6",
                ]) );
    AddExit("south", "/domains/campus/room/medlab", (: PreExit :));
}
void init(){
    ::init();
}
